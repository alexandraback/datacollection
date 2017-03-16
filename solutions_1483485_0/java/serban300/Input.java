/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlerese;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Serban
 */
public class Input {

    int T;
    Translator translator;
    PrintWriter out;

    public Input(String fileName, Translator translator) {
        this.translator = translator;
        //C-large-practice.in
        try {
            out = new PrintWriter(new File("result.txt"));
            Scanner scan = new Scanner(new File(fileName));
            T = scan.nextInt();
            scan.nextLine();
            for (int i = 0; i < T; i++) {
                String G = scan.nextLine();
                solve(G, i);
            }
            out.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private void solve(String G, int nr) throws IOException {
        out.print("Case #" + (nr + 1) + ": ");
        for (int i = 0; i < G.length(); i++) {
            out.print(translator.translate(G.charAt(i)));
            System.out.print(translator.translate(G.charAt(i)));
        }
        out.println();
        System.out.println();
        out.flush();
    }
}
