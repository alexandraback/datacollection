package com.forthgo.contest.g2013r1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
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
        long A = in.nextLong();
        int N = in.nextInt();
        long[] value = new long[N];
        for (int i = 0; i < value.length; i++) {
            value[i] = in.nextLong();
        }
        int best = N;
        if (A > 1) {
            int add = 0;
            Arrays.sort(value);
            for (int i = 0; i < N; i++) {
                while (A <= value[i]) {
                    A += A - 1;
                    add++;
                }
                A += value[i];
                if (add + (N - i - 1) < best) {
                    best = add + (N - i - 1);
                }
            }
        }
        out.print(best);
    }

}

