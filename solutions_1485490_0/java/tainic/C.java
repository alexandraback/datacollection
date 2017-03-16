package com.cuteants.problems.codejam.y2012.round1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class C {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C:\\Users\\aurel\\Downloads\\C-small-attempt1.in"));
//        Scanner in = new Scanner(
//            "4\n" +
//            "3 3\n" +
//            "10 1 20 2 25 3\n" +
//            "10 2 30 3 20 1\n" +
//            "3 5\n" +
//            "10 1 6 2 10 1\n" +
//            "5 1 3 2 10 1 3 2 5 1\n" +
//            "3 5\n" +
//            "10 1 6 2 10 1\n" +
//            "5 1 6 2 10 1 6 2 5 1\n" +
//            "1 1\n" +
//            "5000000 10\n" +
//            "5000000 100"
//        );
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = in.nextInt();
            int m = in.nextInt();
            long[] a = new long[n];
            int[] A = new int[n];
            long[] b = new long[m];
            int[] B = new int[m];
            for (int j = 0; j < n; j++) {
                a[j] = in.nextLong();
                A[j] = in.nextInt();
            }
            for (int j = 0; j < m; j++) {
                b[j] = in.nextLong();
                B[j] = in.nextInt();
            }

            long max = f(a, A, b, B, 0, 0);
            System.out.println("Case #" + i + ": " + max);
        }
    }

    private static long f(long[] a, int[] A, long[] b, int[] B, int i, int j) {
        long max = 0;
        if (i == A.length || j == B.length) {
            return 0;
        }
        if (A[i] == B[j]) {
            if (a[i] <= b[j]) {
                b[j] -= a[i];
                max += a[i] + f(a, A, b, B, i + 1, j);
            } else {
                a[i] -= b[j];
                max += b[j] + f(a, A, b, B, i, j + 1);
            }
        } else {
            for (int ki = i; ki < A.length; ki++) {
                int kj = j;
                while (kj < B.length && A[ki] != B[kj]) {
                    kj++;
                }
                if (ki < A.length && kj < B.length && A[ki] == B[kj]) {
                    long[] a2 = new long[a.length];
                    System.arraycopy(a, 0, a2, 0, a.length);
                    long[] b2 = new long[b.length];
                    System.arraycopy(b, 0, b2, 0, b.length);
                    max = Math.max(max, f(a2, A, b2, B, ki, kj));
                }
            }
        }
        return max;
    }


}
