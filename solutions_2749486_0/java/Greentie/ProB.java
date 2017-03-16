/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2013;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 *
 * @author admin
 */
public class ProB implements Problem {

    @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int c = in.nextInt();
        in.nextLine();
        String p = "WE";
        String m = "EW";
        String u = "SN";
        String d = "NS";
        for (int i = 1; i <= c; i++) {
            int x = in.nextInt();
            int y = in.nextInt();

            String output = "";
            if (x > 0) {
                for (int k = 0; k < x; k++) {
                    output += p;
                }
            } else {
                for (int k = 0; k < -x; k++) {
                    output += m;
                }
            }

            if (y >= 0) {
                for (int k = 0; k < y; k++) {
                    output += u;
                }
            } else {
                for (int k = 0; k < -y; k++) {
                    output += d;
                }
            }
            out.printf("Case #%d: %s\n", i, output);
            in.nextLine();
        }
    }

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int x = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= x; i++) {
            out.printf("Case #%d: %s\n", i, "");
            in.nextLine();
        }

    }

    public static void main(String[] args) throws FileNotFoundException {
        Problem B = new ProB();
        String prepath = "C:\\Documents and Settings\\GreenTie\\My Documents\\NetBeansProjects\\GoogleCodeJam2013-1\\";
        //prepath = downpath;
        String testname = "test";
        String smallname = "B-small-attempt0";
        String largename = "B-large";
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        File tin = new File(prepath + testname + ".txt");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        //B.solveSmall(new Scanner(tin), testo);
        B.solveSmall(new Scanner(sin), smallo);
        System.out.println(prepath + smallname + ".out");
        //B.solveLarge(new Scanner(lin), largeo);
        //System.out.println(prepath + largename + ".out");
    }
}
