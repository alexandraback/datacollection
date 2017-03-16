package com.cuteants.problems.codejam.y2013.round1A;

import java.io.*;
import java.util.Scanner;

public class B {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("/home/aurel/projects/cuteants/problems/src/com/cuteants/problems/codejam/y2013/round1A/B-small-attempt2.in"));
//        Scanner in = new Scanner(
//            "3\n" +
//            "5 2 2\n" +
//            "2 1\n" +
//            "5 2 2\n" +
//            "1 2\n" +
//            "3 3 4\n" +
//            "4 1 3 5"
//        );
        BufferedWriter out = new BufferedWriter(new FileWriter("/home/aurel/projects/cuteants/problems/src/com/cuteants/problems/codejam/y2013/round1A/B-small.txt"));
        //BufferedWriter out = new BufferedWriter(new FileWriter("/home/aurel/projects/cuteants/problems/src/com/cuteants/problems/codejam/y2013/round1/B-large.txt"));

        int tc = in.nextInt();
        for (int ti = 1; ti <= tc; ti++) {
            int e = in.nextInt();
            int r = in.nextInt();
            int n = in.nextInt();
            long[] v = new long[n];
            for (int i = 0; i < n; i++) {
                v[i] = in.nextLong();
            }

            long res = f(v, 0, e, r);

            out.write("Case #" + ti + ": " + res + "\n");
        }

        in.close();
        out.close();
    }

    private static long f(long[] v, int i, int e, int r) {
        if (i == v.length) {
            return 0;
        }
        if (r >= e) {
            return v[i] * e + f(v, i + 1, e, r);
        }
        long max = 0;
        for (int ei = r; ei <= e; ei++) {
            max = Math.max(max, v[i] * ei + f(v, i + 1, e + r - ei, r));
        }
        return max;
    }

}
