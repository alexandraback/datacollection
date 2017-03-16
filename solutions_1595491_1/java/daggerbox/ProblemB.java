package com.forthgo.google.g2012r0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by Xan Gregg.
 * Date: 4/14/12
 */
public class ProblemB {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("B.in"));
            PrintWriter out = new PrintWriter(new FileWriter("B.out"));
            //PrintWriter out = new PrintWriter(System.out);
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                int n = in.nextInt();
                int s = in.nextInt();
                int p = in.nextInt();
                int k = solve(in, n, s, p);
                out.printf("Case #%d: %d%n", i + 1, k);
                out.flush();
            }

        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static int solve(Scanner in, int n, int s, int p) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            int score = in.nextInt();
            int best = (score / 3) + (score % 3 > 0 ? 1 : 0);
            boolean surprise = score >= 2 && score <= 28 && score % 3 != 1;
            if (best >= p) {
                k++;
            }
            else if (s > 0 && best == p - 1 && surprise) {
                k++;
                s--;
            }
        }
        return k;
    }

}
