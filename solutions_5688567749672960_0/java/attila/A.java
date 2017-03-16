package de.jaki.codejam.two015.round1.B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {
    private static final String PATTERN = "CASE #%d: %s";
    private static final String PROBLEM = "A";

    //private static final String NAME = PROBLEM + ".in";
    private static final String NAME = PROBLEM + "-small-attempt0.in";
    //private static final String NAME = PROBLEM+"-large.in";
    //private static final String OUT = PROBLEM + ".out";
    private static final String OUT = PROBLEM + "-small-attempt0.out";
    //private static final String OUT = PROBLEM+"-large.out";

    private static int[] t;

    public static void mainPrev() {
        t = new int[1000001];
        t[0] = 9999999;
        for (int i = 1; i <= Math.pow(10, 6); i++) {
            solveSmall(t, i);
        }
    }

    private static void solveSmall(int[] t, int i) {
        if (i <= 19) {
            t[i] = i;
            return;
        }
        int a = t[i - 1];
        int b = t[rev(i)];
        if (b == 0) {
            b = 9999999;
        }
        t[i] = Math.min(a, b) + 1;
    }

    private static int rev(int n) {
        if (n % 10 == 0) {
            return 0;
        }
        int reverse = 0;
        while (n != 0) {
            reverse = reverse * 10;
            reverse = reverse + n % 10;
            n = n / 10;
        }
        return reverse;
    }

    public static void main(String[] args) throws FileNotFoundException {
        mainPrev();
        Scanner sc = new Scanner(new File(NAME));
        PrintWriter pw = new PrintWriter(OUT);
        int testCount = sc.nextInt();
        for (int i = 0; i < testCount; i++) {
            String sol = solve(sc);
            System.out.println(String.format(PATTERN, i + 1, sol));
            pw.println(String.format(PATTERN, i + 1, sol));
        }
        pw.flush();
        pw.close();
    }

    private static String solve(Scanner sc) {
        int x = sc.nextInt();
        return "" + t[x];
    }

}
