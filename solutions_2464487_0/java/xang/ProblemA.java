package com.forthgo.contest.g2013r1a;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class ProblemA {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A.in"));
            PrintWriter out = new PrintWriter(new FileWriter("A.out"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                out.printf("Case #%d: ", i + 1);
                solve(in, out);
                out.println();
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        BigInteger r = in.nextBigInteger();
        BigInteger t = in.nextBigInteger();
        BigInteger dd = r.multiply(r).multiply(BigInteger.valueOf(4)).subtract(r.multiply(BigInteger.valueOf(4)))
                        .add(BigInteger.ONE).add(t.multiply(BigInteger.valueOf(8)));
        BigInteger d = sqrt(dd);
        BigInteger n = (BigInteger.ONE.subtract(r.multiply(BigInteger.valueOf(2))).add(d)).divide(BigInteger.valueOf(4));
        out.print(n.toString());
    }

    public static BigInteger sqrt(BigInteger n) {
        if (n.equals(BigInteger.ZERO))
            return BigInteger.ZERO;
        BigInteger u1;
        BigInteger u0 = new BigDecimal(Math.sqrt(n.doubleValue())).toBigInteger();
        BigInteger TWO = BigInteger.valueOf(2);
        while (true) {
            // u1 = (u0 * u0 + n) / (2 * u0);
            u1 = (u0.add(n.divide(u0))).divide(TWO);
            if (u0.equals(u1))
                break;
            if (u1.equals(u0.subtract(BigInteger.ONE)) && u1.multiply(u1).compareTo(n) <= 0
                && n.compareTo(u0.multiply(u0)) < 0)
                break;
            u0 = u1;
        }
        return u1;
    }


}

