package de.jaki.codejam.two015.round1.B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A3 {
    private static final String PATTERN = "CASE #%d: %s";
    private static final String PROBLEM = "A";

    //private static final String NAME = PROBLEM + ".in";
    //private static final String NAME = PROBLEM + "-small-attempt0.in";
    private static final String NAME = PROBLEM+"-large.in";
    //private static final String OUT = PROBLEM + ".out";
    //private static final String OUT = PROBLEM + "-small-attempt0.out";
    private static final String OUT = PROBLEM+"-large.out";

    private static long rev(long n) {
        if (n % 10 == 0) {
            return 0;
        }
        long reverse = 0;
        while (n != 0) {
            reverse = reverse * 10;
            reverse = reverse + n % 10;
            n = n / 10;
        }
        return reverse;
    }

    public static void main(String[] args) throws FileNotFoundException {
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
        long x = sc.nextLong();
        return "" + ss(x);
    }

    private static long ss(long x) {
        if (x <= 10) {
            return x;
        }
        int digits = digits(x);
        long y = 1;
        for (int i = 0; i < (digits + 1) / 2; i++) {
            y *= 10;
        }
        long d = y;
        long rr = x / d * d + 1;
        long r2 = x - rr;
        if (r2 < 0) {
            return ss(x - 1) + 1;
        } else if (r2 == 0) {
            long rrr = rev(x);
            if (rrr == x) {
                return ss(x - 1) + 1;
            } else {
                return ss(rrr) + 1;
            }
        } else {
            return ss(rr) + r2;
        }
    }

    private static int digits(long x) {
        return (int) (Math.log10(x) + 1);
    }

}
