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

    public static int max = 0;

    @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int x = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= x; i++) {
            max=0;
            int E = in.nextInt();
            int R = in.nextInt();
            int t = in.nextInt();
            in.nextLine();
            int[] v = new int[t];
            for (int j = 0; j < t; j++) {
                v[j] = in.nextInt();
            }
            in.nextLine();
            solve(v, 0, E, R, 0,E);
            out.printf("Case #%d: %d\n", i,max);
        }
    }

    public void solve(int v[], int start, int E, int R, int value,int s) {
        if (start == v.length) {
            if (max <= value) {
                max = value;
            }
            return;
        }
        for (int i = 0; i <= E; i++) {
            if(E - i + R<=s)
            solve(v, start + 1,E - i + R , R, value + v[start] * i,s);
            else solve(v, start + 1,s , R, value + v[start] * i,s);
        }

    }

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
    }

    public static void main(String[] args) throws FileNotFoundException {
        Problem B = new ProB();
        String prepath = "C:\\Documents and Settings\\GreenTie\\My Documents\\NetBeansProjects\\GoogleCodeJam2013-1\\";
        //prepath = downpath;
        String testname = "test";
        String smallname = "B-small-attempt1";
        String largename = "B-large";
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        File tin = new File(prepath + testname + ".txt");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        B.solveSmall(new Scanner(sin), smallo);
        //System.out.println(prepath + smallname + ".out");
        //B.solveLarge(new Scanner(lin), largeo);
        //System.out.println(prepath + largename + ".out");
    }
}
