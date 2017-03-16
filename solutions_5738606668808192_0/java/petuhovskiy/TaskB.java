package com.petukhovsky.solve.tests;

import com.petukhovsky.solve.lib.FastScanner;

import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Random;

/**
 * Created by petuh on 2/1/2016.
 */
public class TaskB {
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner("input.txt");
        PrintWriter pw = new PrintWriter("output.txt");
        int n = 16;
        int j = 50;
        Random random = new Random();
        HashSet<String> set = new HashSet<>();
        while (j-- > 0) {
            System.err.println("new number");
            mda:
            while (true) {
                System.err.println("new iter");
                String e = "1";
                for (int i = 0; i < n - 2; i++)
                    if (random.nextBoolean()) e += "1";
                    else e += "0";
                e += "1";
                if (set.contains(e)) continue;
                set.add(e);
                String res = e;
                for (int st = 2; st <= 10; st++) {
                    BigInteger f = BigInteger.ZERO;
                    BigInteger t = BigInteger.ONE;
                    for (int z = e.length() - 1; z >= 0; z--) {
                        if (e.charAt(z) == '1') f = f.add(t);
                        t = t.multiply(BigInteger.valueOf(st));
                    }
                    //System.err.println(f);
                    int re = findDiv(f);
                    if (re == -1) continue mda;
                    res += " " + re;
                }
                pw.println(res);
                System.out.println(res);
                break;
            }
        }
        sc.close();
        pw.close();
    }

    private static int findDiv(BigInteger f) {
        for (int i = 3; i < 20000; i += 2) if (f.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) return i;
        return -1;
    }

    private static boolean correct(String s) {
        if (!s.contains(" ")) return true;
        if (s.length() % 2 == 1) {
            boolean correct = true;
            for (int i = 1; i < s.length(); i += 2) if (s.charAt(i) != ' ') correct = false;
            if (correct) return true;
        }
        s = s.replace(" + ", "+");
        s = s.replace(" - ", "-");
        return !s.contains(" ");
    }

    public static boolean isPrime(BigInteger b) {
        return b.isProbablePrime(100);
    }
}
