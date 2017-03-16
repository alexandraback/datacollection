package com.forthgo.contest.g2014r0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemD {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("D.in.txt"));
            PrintWriter out = new PrintWriter(new FileWriter("D.out.txt"));
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
        int N = in.nextInt();
        double[] a = new double[N];
        double[] b = new double[N];
        for (int i = 0; i < N; i++) {
            a[i] = in.nextDouble();
        }
        Arrays.sort(a);
        for (int i = 0; i < N; i++) {
            b[i] = in.nextDouble();
        }
        Arrays.sort(b);
        int bj = 0;
        int aw = 0;
        for (int ai = 0; ai < N; ai++) {
            if (a[ai] > b[bj]) {
                aw++;
                bj++;
            }
        }
        int aj = 0;
        int bw = 0;
        for (int bi = 0; bi < N; bi++) {
            if (b[bi] > a[aj]) {
                bw++;
                aj++;
            }
        }
        out.print(aw + " " + (N - bw));
    }

}

