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
public class ProblemA {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A.in"));
            PrintWriter out = new PrintWriter(new FileWriter("A.out"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                int nn = in.nextInt();
                out.printf("Case #%d:", i + 1);
                double p = solve(in, out, nn);
                out.printf("%n");
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static double solve(Scanner in, PrintWriter out, int n) {
        double[] s = new double[n];
        double[] y = new double[n];
        double sum = 0;
        for (int i = 0; i < n; i++) {
            s[i] = in.nextInt();
            sum += s[i];
        }
        int [] order = sortedIndices(s);
        for (int i = 0; i < n; i++) {
            double rem = 1;
            int k = 0;
            for (int j = 0; j < n; j++) {
                if (i == order[j])
                    continue;
                double tobeat = s[order[j]];
                double q = (tobeat + sum * rem / (k+1) - s[i]) / (sum + sum / (k+1));
                if (q < 0) {
                    y[i] = 0;
                    break;
//                    throw new RuntimeException();
                }
                if (q > rem)
                    break;
                y[i] = q;
//                if (k + 1 == n - 1) {
//                    break;
//                }
                int jnext = j + 1;
                if (jnext >= n)
                    break;
                if (order[jnext] == i)
                    jnext = j + 2;
                if (jnext >= n)
                    break;
                k++;

                rem -= k * (s[order[jnext]] - s[order[j]]) / sum;
                if (rem < 0) {
                    //throw new RuntimeException();
                    break;
                }
            }
            out.printf(" %f", y[i] * 100);
        }
        double e = 0;
        return e;
    }

    public static int[] sortedIndices(double[] x) {
        int[] ix = new int[x.length];
        int[] scratch = new int[x.length];
        for (int i = 0; i < ix.length; i++) {
            ix[i] = i;
        }
        mergeSortIndexed(x, ix, scratch, 0, x.length - 1);
        return ix;
    }

    private static void mergeSortIndexed(double[] x, int[] ix, int[] scratch, int lo, int hi) {
        if (lo == hi)
            return;
        int mid = (lo + hi + 1) / 2;
        mergeSortIndexed(x, ix, scratch, lo, mid - 1);
        mergeSortIndexed(x, ix, scratch, mid, hi);
        mergeIndexed(x, ix, scratch, lo, mid - 1, mid, hi);
    }

    private static void mergeIndexed(double[] x, int[] ix, int[] scratch, int lo1, int hi1, int lo2, int hi2) {
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

