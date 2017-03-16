package com.forthgo.google.g2012r1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by Xan Gregg.
 * Date: 4/27/12
 */
public class ProblemC {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C.in"));
            PrintWriter out = new PrintWriter(new FileWriter("C.out"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                int nn = in.nextInt();
                out.printf("Case #%d:%n", i + 1);
                solve(in, out, nn);
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static void solve(Scanner in, PrintWriter out, int n) {
        int [] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.nextInt();
        }
        int [] sums = new int[1 << n];
        for (int i = 0; i < sums.length; i++) {
            int j = 0;
            for (int k = i; k != 0; k >>= 1, j++) {
                if ((k & 1) != 0) {
                    sums[i] += s[j];
                }
            }
        }
        int [] x = sortedIndices(sums);
        for (int i = 1; i < sums.length; i++) {
            if ((x[i] & x[i-1]) == 0 && sums[x[i - 1]] == sums[x[i]]) {
                printset(out, x[i-1], s);
                printset(out, x[i], s);
                return;
            }
        }
        out.println("Impossible");
        }

    private static void printset(PrintWriter out, int k, int[] s) {
        boolean first = true;
        for (int i = 0; i < s.length; i++) {
            if ((k & (1 << i)) != 0) {
                if (!first)
                    out.print(" ");
                out.print(s[i]);
                first = false;
            }
        }
        out.println();
    }

    public static int[] sortedIndices(int[] x) {
        int[] ix = new int[x.length];
        int[] scratch = new int[x.length];
        for (int i = 0; i < ix.length; i++) {
            ix[i] = i;
        }
        mergeSortIndexed(x, ix, scratch, 0, x.length - 1);
        return ix;
    }

    private static void mergeSortIndexed(int[] x, int[] ix, int[] scratch, int lo, int hi) {
        if (lo == hi)
            return;
        int mid = (lo + hi + 1) / 2;
        mergeSortIndexed(x, ix, scratch, lo, mid - 1);
        mergeSortIndexed(x, ix, scratch, mid, hi);
        mergeIndexed(x, ix, scratch, lo, mid - 1, mid, hi);
    }

    private static void mergeIndexed(int[] x, int[] ix, int[] scratch, int lo1, int hi1, int lo2, int hi2) {
        int i = 0;
        int i1 = lo1;
        int i2 = lo2;
        int n1 = hi1 - lo1 + 1;
        int n2 = hi2 - lo2 + 1;
        while (i1 <= hi1 && i2 <= hi2) {
            if (x[ix[i1]] <= x[ix[i2]]) {
                scratch[i++] = ix[i1++];
            }
            else {
                scratch[i++] = ix[i2++];
            }
        }
        while (i1 <= hi1) {
            scratch[i++] = ix[i1++];
        }
        while (i2 <= hi2) {
            scratch[i++] = ix[i2++];
        }
        if (i != n1 + n2) {
            throw new RuntimeException();
        }
        for (int j = lo1; j <= hi1; j++) {
            ix[j] = scratch[j - lo1];
        }
        for (int j = lo2; j <= hi2; j++) {
            ix[j] = scratch[(j - lo2 + n1)];
        }
    }
}

