package de.jaki.codejam.two015.round0;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D2 {


    private static final String PATTERN = "CASE #%d: %s";
    //private static final String NAME = "d.in";
    //private static final String NAME = "D-small-attempt1.in";
    private static final String NAME = "D-large.in";
    //private static final String OUT = "d.out";
    //private static final String OUT = "D-small-attempt1.out";
    private static final String OUT = "D-large.out";

    private static final int MAX = 20;
    private static Boolean[][][] results = new Boolean[MAX + 1][MAX + 1][MAX + 1];

    public static void main(String[] args) throws FileNotFoundException {
        precalculate();
       // System.exit(-1);
        Scanner sc = new Scanner(new File(NAME));
        PrintWriter pw = new PrintWriter(OUT);
        int testCount = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < testCount; i++) {
            long t0 = System.currentTimeMillis();
            String sol = solve(sc);
            System.out.println(String.format(PATTERN, i + 1, sol));
            pw.println(String.format(PATTERN, i + 1, sol));
            long t1 = System.currentTimeMillis();
            System.out.println(t1 - t0);
        }
        pw.flush();
        pw.close();
    }

    private static void precalculate() {

        for (int x = 1; x <= MAX; x++) {
            for (int j = 1; j <= MAX; j++) {
                for (int k = 1; k <= MAX; k++) {
                    if (results[x][j][k] == null) {
                        if (results[x][j][k] != null) continue;

                        results[x][j][k] = solveInternal(x, j, k);

                    }
                }
            }
        }

        int missing = 0;
        for (int i = 1; i < MAX + 1; i++) {
            for (int j = 1; j < MAX + 1; j++) {
                for (int k = 1; k < MAX + 1; k++) {
                    if (results[i][j][k] == null) {
                        System.out.println(i + " " + j + "*" + k);
                        missing++;
                    }
                }
            }
        }
        System.out.println("missing: " + missing);
    }

    private static Boolean solveInternal(int x, int r, int c) {
        if (x == 1) return true;
        if (x >= 7) return false;
        if ((r * c) % x != 0) return false;
        if (x == 2) return true;
        if (r > c) return solveInternal(x, c, r);
        // r<=c
        if (r == 1 && x >= 3) return false;
        if (r < x && c < x) return false;

        if (x >= 4 && r == 2) return false;
        if (x == 3 && c >= 3 && r >= 3) return true;
        if (r <= 4 && c <= 4 && x <= 4) return true;

        if (x == 4 && r >= 4 && c >= 4) return true;
        if (x == 5 && r >= 5 && c >= 5) return true;
        if (x == 6 && r >= 6 && c >= 6) return true;


        if (x == 5 && r == 3 && c == 5) return false;
        if (x == 5 && r == 3 && c >= 10) return true;
        if (x == 5 && r == 4 && c >= 5) return true;
        if (x == 6 && r >= 4 && c >= 6) return true;
        if (x == 6 && r == 3) return false;

        if (x == 4 && r == 3 && c>=8) return true;

        if (x == 3) return true;

        return null;
    }

    private static String solve(Scanner sc) {
        int x = sc.nextInt();
        int r = sc.nextInt();
        int c = sc.nextInt();
        boolean ok = solve2(x, r, c);
        return ok ? "GABRIEL" : "RICHARD";
    }

    private static boolean solve2(int x, int r, int c) {
        return results[x][r][c];
    }


}
