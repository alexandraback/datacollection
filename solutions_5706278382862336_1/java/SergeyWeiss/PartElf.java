package com.google.codejam2014.round1c;

import java.io.*;
import java.util.StringTokenizer;

public class PartElf {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    PartElf() throws IOException {
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
        String[] pq = next().split("/");
        long p = Long.parseLong(pq[0]);
        long q = Long.parseLong(pq[1]);
        long g = gcd(p, q);
        p /= g;
        q /= g;
        if((q & q - 1) != 0) {
            writer.println("Impossible");
            return;
        }
        int ans = 0;
        while(p < q) {
            ans++;
            q /= 2;
        }
        writer.println(ans);
    }

    long gcd(long a, long b) {
        while(a > 0 && b > 0) {
            if(a > b) a %= b;
            else b %= a;
        }
        return a + b;
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new PartElf().solve();
    }
}
