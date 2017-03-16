package de.jaki.codejam.two015.round0;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

    private static final char[] STATES = new char[]{'i', 'j', 'k'};


    private static final String PATTERN = "CASE #%d: %s";
    //private static final String NAME = "c.in";
    private static final String NAME = "C-small-attempt0.in";
    //private static final String NAME = "C-large.in";
    //private static final String OUT = "c.out";
    private static final String OUT = "C-small-attempt0.out";
    //private static final String OUT = "C-large.out";

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
        int l = sc.nextInt();
        int x = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        boolean ok = solve2('1', "", s, x, 0);
        return ok ? "YES" : "NO";
    }

    private static boolean solve2(char ch, String current, String original, int times, int state) {
        while (true) {
            if (ch == '1' && state >= STATES.length && current.length() == 0 && times == 0) {
                return true;
            }
            if (state < STATES.length && ch == STATES[state]) {
                ch = '1';
                state++;
                continue;
            }
            if (current.length() == 0) {
                if (times == 0) {
                    return false;
                } else {
                    current += original;
                    times--;
                    continue;
                }
            }

            ch = multiply(ch, current.charAt(0));
            current = current.substring(1);
        }
    }

    private static char multiply(char a, char b) {
        if (a == '1') return b;
        if (b == '1') return a;
        if (a == b) return '2';
        if (upper(a) && upper(b)) {
            return multiply(switchSign(a), switchSign(b));
        }
        if (a == 'i' && b == 'j') return 'k';
        if (a == 'i' && b == 'k') return 'J';
        if (a == 'j' && b == 'i') return 'K';
        if (a == 'j' && b == 'k') return 'i';
        if (a == 'k' && b == 'i') return 'j';
        if (a == 'k' && b == 'j') return 'I';

        if (upper(a)) {
            return switchSign(multiply(switchSign(a), b));
        }
        if (upper(b)) {
            return switchSign(multiply(a, switchSign(b)));
        }

        throw new IllegalStateException("Not implemented multi: " + a + " * " + b);
    }

    private static char switchSign(char a) {
        if (a == 'K') return 'k';
        if (a == 'k') return 'K';
        if (a == 'I') return 'i';
        if (a == 'i') return 'I';
        if (a == 'J') return 'j';
        if (a == 'j') return 'J';
        if (a == '2') return '1';
        if (a == '1') return '2';
        throw new IllegalStateException("?? " + a);
    }

    private static boolean upper(char b) {
        return b == 'K' || b == 'I' || b == 'J' || b == '2';
    }


}
