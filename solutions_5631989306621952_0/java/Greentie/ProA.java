/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2016.round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 *
 * @author admin
 */
public class ProA implements Problem {

    @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int count = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= count; i++) {
            out.printf("Case #%d: %s\n", i, getLastWord(in.nextLine()));
        }
    }

    public String getLastWord(String input) {
        if (input.length() == 1) {
            return input;
        }
        char[] x = input.toCharArray();

        String a = input.substring(0, 1);
        for (int i = 1; i < x.length; i++) {
            String t = a;
            boolean found=false;
            for (int j = 0; j < t.length(); j++) {
                if (t.charAt(j) == x[i]) {
                    continue;
                } else {
                    if (x[i] > t.charAt(j)) {
                        a = x[i] + a;
                        found=true;
                        break;
                    } else {
                        a += x[i];
                        found=true;
                        break;
                    }
                }
                
            }
            if(!found){
            a += x[i];
            }
        }
        return a;

    }

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int count = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= count; i++) {
            out.printf("Case #%d: %d %d\n", i, 1, 1);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Problem A = new ProA();
        String prepath = "F:\\codejam\\A\\";
        //prepath = downpath;
        String testname = "test-A";
        String smallname = "A-small-attempt1";
        String largename = "A-large";
        File tin = new File(prepath + testname + ".txt");
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
       // A.solveSmall(new Scanner(tin), testo);
        //System.out.println(prepath + testname + ".out");
        A.solveSmall(new Scanner(sin), smallo);
        System.out.println(prepath + smallname + ".out");
        //  A.solveSmall(new Scanner(lin), largeo);
        // System.out.println(prepath + largename + ".out");
    }
}
