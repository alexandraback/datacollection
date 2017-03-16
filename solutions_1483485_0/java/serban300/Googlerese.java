/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlerese;

/**
 *
 * @author Serban
 */
public class Googlerese {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Translator tr = new Translator("input.txt", "output.txt");
        Input in = new Input("A-small-attempt1.in", tr);
    }
}
