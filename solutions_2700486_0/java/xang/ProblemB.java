package com.forthgo.contest.g2013r1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;


public class ProblemB {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("B.in"));
            PrintWriter out = new PrintWriter(new FileWriter("B.out"));
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
        int N = in.nextInt();
        int X = Math.abs(in.nextInt());
        int Y = in.nextInt();
        if ((X + Y) % 2 != 0) {
            out.print(0.0);
            return;
        }
        int h = 0;
        while (h * (2 * h + 3) + 1 <= N) {
            h++;
        }
        int n0 = (h - 1) * (2 * (h - 1) + 3) + 1;
        if ((X + Y) / 2 < h) {
            out.print(1.0);
            return;
        }
        if ((X + Y) / 2 >= (h + 1)) {
            out.print(0.0);
            return;
        }
        int n1 = (h) * (2 * (h) + 3) + 1;
        if (n1 <= N)
            throw new RuntimeException();
        n1 = Math.min(n1, N);
        int k = h + 1;
        if (Y >= k) {
            out.print(0.0);
            return;
//            throw new RuntimeException();
        }
        int nn = n1 - n0;
        if (nn > k) {
            int k0 = nn - k;
            if (Y < k0) {
                out.print(1.0);
                return;
            }
            k -= k0;
            nn -= 2 * k0;
            Y -= k0;
        }
        double [] p = new double[k];
        for (int n = 0; n < nn; n++) {
            double q = 0.5;
            for (int i = 0; i < k && q > 0; i++) {
                double pi = p[i];
                p[i] += q * (1 - pi);
                q *= pi;
            }
        }
        out.print(p[Y]);
    }

}

