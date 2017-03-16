package com.forthgo.contest.g2014.r1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class ProblemC {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C.in.txt"));
            PrintWriter out = new PrintWriter(new FileWriter("C.out.txt"));
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
        int M = in.nextInt();
        int[] zips = new int[N];
        for (int i = 0; i < N; i++) {
            zips[i] = in.nextInt();
        }
        boolean[][] flight = new boolean[N][N];
        for (int i = 0; i < M; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            flight[a][b] = true;
            flight[b][a] = true;
        }
        int[] plan = new int[N];
        int[] best = new int[N];
        int[] from = new int[N];
        best[0] = 999;
//        List<int[]> cur = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            plan[0] = i;
            from[0] = -1;
            fly(from, plan, 1, zips, flight, best);
        }
        for (int i = 0; i < N; i++) {
            out.print(zips[best[i]]);
        }
    }

    private static void fly(int[] from, int[] plan, int nextLeg, int[] zips, boolean[][] flight, int[] best) {
        if (nextLeg == plan.length) {
            boolean better = true;
            if (best[0] < 999) {
                for (int i = 0; i < plan.length; i++) {
                    if (zips[plan[i]] > zips[best[i]])
                        better = false;
                    if (plan[i] != best[i])
                        break;
                }
            }
            if (better)
                System.arraycopy(plan, 0, best, 0, plan.length);
        }
        else {
            city:
            for (int i = 0; i < zips.length; i++) {
                for (int j = 0; j < nextLeg; j++) {
                    if (plan[j] == i)
                        continue city;
                }
//                int [] rr = new int[from.length];
//                System.arraycopy(from, 0, rr, 0, nextLeg);
                int f = nextLeg - 1;
                while (f >= 0) {
                    if (flight[plan[f]][i]) {
                        plan[nextLeg] = i;
                        from[nextLeg] = f;
                        if (from[nextLeg] == nextLeg)
                            break;
//                        if (plan[nextLeg - 1] == i)
//                            throw new RuntimeException();
                        fly(from, plan, nextLeg + 1, zips, flight, best);
                    }
                    f = from[f];
                }
            }
        }
    }
}

