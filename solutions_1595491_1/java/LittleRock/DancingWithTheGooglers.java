/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.falidae;

import java.util.*;
import java.io.*;

/**
 *
 * @author LittleRock
 */
public class DancingWithTheGooglers {

    public DancingWithTheGooglers() {
    }

    public void init() {
    }

    public int solve(int[] scores, int s, int p) {
        int reval = 0;
        for (int score : scores) {
            int[] a = this.ananlys(score);
            if (a[0] >= p) {
                reval++;
            } else if (s > 0 && a[1] >= p) {
                reval++;
                s--;
            }
        }
        return reval;
    }

    public int[] ananlys(int score) {
        int[] reval = new int[2];
        int d = score / 3;
        int r = score % 3;
        if (r == 0) {
            reval[0] = d;
            if (d != 0) {
                reval[1] = d + 1;
            } else {
                reval[1] = d;
            }
        } else if (r == 1) {
            reval[0] = d + 1;
            reval[1] = d + 1;
        } else {
            reval[0] = d + 1;
            reval[1] = d + 2;
        }
        return reval;
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("in.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
        DancingWithTheGooglers solver = new DancingWithTheGooglers();

        int testCount = in.nextInt();
        for (int i = 0; i < testCount; i++) {
            solver.init();
            int n = in.nextInt();
            int s = in.nextInt();
            int p = in.nextInt();
            int[] scores = new int[n];
            for (int j = 0; j < n; j++) {
                scores[j] = in.nextInt();
            }
            printIndex(i, out);
            out.print(solver.solve(scores, s, p));
            out.println();
        }

        in.close();
        out.flush();
        out.close();
    }

    private static void printIndex(int i, PrintWriter out) {
        out.printf("Case #%d: ", i + 1);
    }
}