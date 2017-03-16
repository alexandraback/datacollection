package com.google2016.qual;

import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {

    static final String FILENAME = "c:\\Users\\Admin\\Downloads\\B-large";
    static final String IN = FILENAME + ".in";

    Scanner sc;
    static final String OUT = FILENAME + ".out";
    PrintStream out = System.out;

    private boolean allUpside(Boolean[] arrUpside) {
        for (Boolean b : arrUpside) {
            if (!b) {
                return false;
            }
        }
        return true;
    }

    private void flip(Boolean[] arrUpside, int n) {
        for (int i =0; i < n; i++) {
            arrUpside[i] = !arrUpside[i];
        }
    }


    private String solve(Boolean[] arrUpside) {
        if (allUpside(arrUpside)) {
            return "0";
        }
        long flips = 0;
        for (int j = arrUpside.length - 1; j >= 0; j--) {
            if (!arrUpside[j]) {
                flip(arrUpside, j);
                flips++;
            }
        }
        return String.valueOf(flips);
    }

    private void run() throws Exception {
        sc = new Scanner(new File(IN));
        out = new PrintStream(new FileOutputStream(OUT));
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            //System.out.println("Case #" + i + ": " + solve(sc.nextBigInteger()));
            String str = sc.next();
            Boolean[] arrUpside = new Boolean[str.length()];

            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) =='+') {
                    arrUpside[j] = Boolean.TRUE;
                } else {
                    arrUpside[j] = Boolean.FALSE;
                }
            }

            out.println("Case #" + i + ": " + solve(arrUpside));
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new B().run();
    }

}

