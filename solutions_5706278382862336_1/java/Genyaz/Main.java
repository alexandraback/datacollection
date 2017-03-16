package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    public static long gcd(long a, long b) {
        if (a == 0 || b == 0) return a + b;
        if (a > b) return gcd(b, a);
        return gcd(b % a, a);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
        PrintWriter out = new PrintWriter("A-large.out");
        StringTokenizer tokens = new StringTokenizer(in.readLine());
        int t = Integer.parseInt(tokens.nextToken());
        for (int tt = 1; tt <= t; tt++) {
            String[] ss = in.readLine().split("/");
            long p = Long.parseLong(ss[0]);
            long q = Long.parseLong(ss[1]);
            long gc = gcd(p, q);
            p /= gc;
            q /= gc;
            long qq = q;
            boolean correct = true;
            while (qq > 1) {
                correct &= qq % 2 == 0;
                qq /= 2;
            }
            out.print("Case #" + tt + ": ");
            if (correct) {
                while (p > 1) {
                    p /= 2;
                    q /= 2;
                }
                int answer = 0;
                while (q > 1) {
                    answer++;
                    q /= 2;
                }
                out.println(answer);
            } else {
                out.println("impossible");
            }
        }
        in.close();
        out.close();
    }
}
