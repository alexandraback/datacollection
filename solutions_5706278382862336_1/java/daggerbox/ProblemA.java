package com.forthgo.contest.g2014.r1c;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.regex.Pattern;


public class ProblemA {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A.in.txt"));
            PrintWriter out = new PrintWriter(new FileWriter("A.out.txt"));
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
            throw new RuntimeException(e);
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        String pq = in.nextLine();
        int slash = pq.indexOf('/');
        String ps = pq.substring(0, slash);
        String qs = pq.substring(slash + 1);
        long P = Long.valueOf(ps);
        long Q = Long.valueOf(qs);
        long g = gcd(P, Q);
        long p = P / g;
        long q = Q / g;
        if (q > (1L << 40) || Long.bitCount(q) != 1) {
            out.print("impossible");
            return;
        }
        long k = 1;
        while (q > 2 && p * 2 < q && k < 40) {
            if (q % 2 != 0) {
                out.print("impossible");
                return;
            }
            q /= 2;
            k ++;
        }
        if (p * 2 < q) {
            out.print("impossible");
            return;
        }
        out.print(k);

    }

    public static long gcd(long a, long b) {
        if (a < 0 || b < 0)
            return -1;
        while (b != 0) {
            long x = a % b;
            a = b;
            b = x;
        }
        return a;
    }

}

