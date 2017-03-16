package com.forthgo.google.g2012r0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by Xan Gregg.
 * Date: 4/14/12
 */
public class ProblemC {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C.in"));
            PrintWriter out = new PrintWriter(new FileWriter("C.out"));
            //PrintWriter out = new PrintWriter(System.out);
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                int k = solve(a, b);
                out.printf("Case #%d: %d%n", i + 1, k);
                out.flush();
            }

        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static int solve(int a, int b) {
        int k = 0;
        int nda = (int) (Math.log10(a) + 1);
        int ndb = (int) (Math.log10(b) + 1);
        Set<Long> pairs = new HashSet<Long>(b - a);
        for (int i = Math.max(2, nda); i <= ndb; i++) {
            k += solve(pairs, a, b, i);
        }
        return k;
    }

    private static int solve(Set<Long> pairs, int a, int b, int nd) {
        int k = 0;
        for (int i = 1; i <= nd / 2; i++)
            k += solve(pairs, a, b, nd, i);
        return k;
    }

    private static int solve(Set<Long> pairs, int a, int b, int nd, int ndc) {
        int c10 = (int) Math.pow(10, ndc);

        int ndd = nd - ndc;
        int d10 = (int) Math.pow(10, ndd);

        int c0 = a / d10;
        int d0 = a / c10;

        int k = 0;
        for (int c = c0; c < c10; c++) {
            if (c * d10 > b)
                break;
            int d00 = d0;
            if (ndc == ndd)
                d00 = Math.max(d00, c + 1);
            for (int d = d00; d < d10; d++) {
                if (d * c10 > b)
                    break;
                int x = c * d10 + d;
                int y = d * c10 + c;
                if (x != y && x >= a && x <= b && y >= a && y <= b) {
                    long xx = Math.min(x, y);
                    long yy = Math.max(x, y);
                    long pair = xx * c10 * d10 + yy;
                    if (!pairs.contains(pair)) {
                        k++;
                        pairs.add(pair);
//                        System.out.printf("%d %d%n", Math.min(x, y), Math.max(x, y));
                    }
                }
            }
        }
        return k;
    }

}
