package Gcj2013_1c;

import java.awt.Point;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Gcj2013_1c_b {
    final static String WORK_DIR = "C:\\eclipse\\workspace\\GoogleCodeJam\\IO\\2013_1c\\";

    void solve(Scanner sc, PrintWriter pw) {
        int X = sc.nextInt();
        int Y = sc.nextInt();
        Point p = new Point(0, 0);
        
        if (X > 0) {
            for (int i = 0; i < X; i++) {
                pw.print("WE");
            }
        } else {
            for (int i = 0; i < Math.abs(X); i++) {
                pw.print("EW");
            }
        }
        
        if (Y > 0) {
            for (int i = 0; i < Y; i++) {
                pw.print("SN");
            }
        } else {
            for (int i = 0; i < Math.abs(Y); i++) {
                pw.print("NS");
            }
        }
        pw.println();
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "B-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "B-small-attempt0.out"));
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            System.out.println("Processing test case " + (t + 1) + " of " + T);
            pw.print("Case #" + (t+1) + ": ");
            new Gcj2013_1c_b().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
    
    /*public class Coordinate() {
        
    }*/
}
