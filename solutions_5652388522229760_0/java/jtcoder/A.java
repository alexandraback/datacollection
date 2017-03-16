package com.google2016.qual;

import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class A {

    static final String FILENAME = "c:\\Users\\Admin\\Downloads\\A-small-attempt0";
    static final String IN = FILENAME + ".in";

    Scanner sc;
    static final String OUT = FILENAME + ".out";
    PrintStream out = System.out;

    private String solve(BigInteger number) {
        if (number.equals(BigInteger.ZERO)) {
            return "INSOMNIA";
        }
        BigInteger current = number;
        long n = 0;
        Set<Character> digits = new HashSet<>();
        while (digits.size() != 10) {
            n++;
            current = number.multiply(BigInteger.valueOf(n));
            String currStr = current.toString();
            for (int i = 0; i < currStr.length(); i++) {
                digits.add(currStr.charAt(i));
            }
        }
        return current.toString();
    }

    private void run() throws Exception {
        sc = new Scanner(new File(IN));
        out = new PrintStream(new FileOutputStream(OUT));
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            //System.out.println("Case #" + i + ": " + solve(sc.nextBigInteger()));
            out.println("Case #" + i + ": " + solve(sc.nextBigInteger()));
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new A().run();
    }

}

