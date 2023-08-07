#include <gtk/gtk.h>

#define UI_FILE "design.glade"

int main(int argc, char* argv[]) {
    GError* err = NULL;

    // GTK+ initialization
    gtk_init(&argc, &argv);

    GtkBuilder* builder = gtk_builder_new();

    // * UI file should be placed to the same directory as the application
    if (!gtk_builder_add_from_file(builder, UI_FILE, &err)) {
        g_warning("%s\n", err->message);
        g_free(err);
        return 1;
    }

    GtkWindow* topWindow = GTK_WINDOW(gtk_builder_get_object(builder, "topWindow"));

    gtk_widget_show_all(GTK_WIDGET(topWindow));
    gtk_main();

    return 0;
}
