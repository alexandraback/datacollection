package de.jaki.codejam.two015.round0;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {


    private static final String PATTERN = "CASE #%d: %s";
    //private static final String NAME = "d.in";
    private static final String NAME = "D-small-attempt1.in";
    //private static final String NAME = "D-large.in";
    //private static final String OUT = "d.out";
    private static final String OUT = "D-small-attempt1.out";
    //private static final String OUT = "D-large.out";

    public static void main(String[] args) throws FileNotFoundException {
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

    private static String solve(Scanner sc) {
        int x = sc.nextInt();
        int r = sc.nextInt();
        int c = sc.nextInt();
        boolean ok = solve2(x, r, c);
        System.out.println(x + " " + r + "*" + c + " = " + ok);
        return ok ? "GABRIEL" : "RICHARD";
    }

    private static boolean solve2(int x, int r, int c) {
        if (x == 1) return true;
        if (x >= 7) return false;
        if ((r * c) % x != 0) return false;
        if (x == 2) return true;
        if (r > c) return solve2(x, c, r);
        // r<=c
        if (r == 1 && x >= 3) return false;
        if (r < x && c < x) return false;

        if (r == 2 && c == 4 && x == 4) return false;
        return true;
    }


}
