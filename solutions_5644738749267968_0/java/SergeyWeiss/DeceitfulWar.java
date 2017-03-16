package com.google.codejam2014.qual;

import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class DeceitfulWar {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    DeceitfulWar() throws IOException {
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
        int n = nextInt();
        double[] naomi = new double[n];
        for(int i = 0; i < n; i++) {
            naomi[i] = nextDouble();
        }
        double[] ken = new double[n];
        for(int i = 0; i < n; i++) {
            ken[i] = nextDouble();
        }
        Arrays.sort(naomi);
        Arrays.sort(ken);
        int points2 = 0;
        int nb = 0, ne = n - 1;
        for(int i = 0; i < n; i++) {
            if(gt(naomi[ne], ken[n - 1 - i])) {
                points2++;
                ne--;
            }
            else {
                nb++;
            }
        }
        int points1 = 0;
        boolean[] used = new boolean[n];
        for(int i = 0; i < n; i++) {
            //find smallest winning for Ken
            int opt = -1;
            for(int j = n - 1; j >= 0; j--) {
                if(!used[j] && gt(ken[j], naomi[i])) opt = j;
            }
            if(opt == -1) {
                points1++;
                for(int j = 0; j < n; j++) {
                    if(!used[j]) {
                        opt = j;
                        break;
                    }
                }
            }
            used[opt] = true;
        }
        writer.println(points2 + " " + points1);
    }

    static final double eps = 1e-7;
    boolean eq(double a, double b) {
        return Math.abs(a - b) < eps;
    }
    boolean gt(double a, double b) {
        return a > b && !eq(a, b);
    }
    boolean ge(double a, double b) {
        return a > b || eq(a, b);
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new DeceitfulWar().solve();
    }
}
