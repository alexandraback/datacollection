package com.google.codejam2014.qual;

import java.io.*;
import java.util.*;

public class CookieClickerAlpha {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    CookieClickerAlpha() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    String next() throws IOException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            stringTokenizer = new StringTokenizer(reader.readLine());
        }
        return stringTokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    void solveTestCase(int testNumber) throws IOException {
        writer.printf("Case #%d: ", testNumber);
        double C = nextDouble(), F = nextDouble(), X = nextDouble();
        double ans = 0;
        double baseSpeed = 2;
        for(int factories = 0; ; factories++) {
            double t1 = X / (baseSpeed + factories * F);
            double t2 = C / (baseSpeed + factories * F) + X / (baseSpeed + factories * F + F);
            if(t1 < t2) {
                ans += X / (baseSpeed + factories * F);
                break;
            }
            ans += C / (baseSpeed + factories * F);
        }
        writer.println(String.format(Locale.US, "%.9f", ans));
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new CookieClickerAlpha().solve();
    }
}
