package com.google2016.qual;

import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class D {

    static final String FILENAME = "c:\\Users\\Admin\\Downloads\\D-small-attempt1";
    static final String IN = FILENAME + ".in";

    Scanner sc;
    static final String OUT = FILENAME + ".out";
    PrintStream out = System.out;

    private String solve(int k, int c, int s) {
        String positions = "1";
        BigInteger finalNumberOfTiles = BigInteger.valueOf(k).pow(c);
        BigInteger section = finalNumberOfTiles.divide(BigInteger.valueOf(k));
        for (int i = 1; i < k; i++) {
            positions = positions + " " + section.multiply(BigInteger.valueOf(i)).add(BigInteger.valueOf(1));
        }
        return positions;
    }


    private void run() throws Exception {
        sc = new Scanner(new File(IN));
        out = new PrintStream(new FileOutputStream(OUT));
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            int k = sc.nextInt();
            int c = sc.nextInt();
            int s = sc.nextInt();
            out.println("Case #" + i + ": " + solve(k, c, s));
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new D().run();
    }

}

