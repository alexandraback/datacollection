package com.forthgo.contest.g2013r1c;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;


public class ProblemC {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C.in"));
            PrintWriter out = new PrintWriter(new FileWriter("C.out"));
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
        int n = N;
        int center = 5000;
        long [] wall = new long[center * 2 + 1];
        Tribe [] tribe = new Tribe[N];
        long next = Long.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            tribe[i] = new Tribe(in);
            next = Math.min(next, tribe[i].d);
        }
        long breach = 0;
        while (next != Long.MAX_VALUE) {
            for (int i = 0; i < N; i++) {
                if (tribe[i].d == next) {
                    for (int j = tribe[i].w; j < tribe[i].e; j++) {
                        if (wall[center + j] < tribe[i].s) {
                            breach++;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                if (tribe[i].d == next) {
                    for (int j = tribe[i].w; j < tribe[i].e; j++) {
                        if (wall[center + j] < tribe[i].s) {
                            wall[center + j] = tribe[i].s;
                        }
                    }
                    if (tribe[i].n == 1 || tribe[i].s + tribe[i].ds <= 0) {
                        // last attack
                        tribe[i].d = Long.MAX_VALUE;
                    }
                    else {
                        tribe[i].d += tribe[i].dd;
                        tribe[i].w += tribe[i].dp;
                        tribe[i].e += tribe[i].dp;
                        tribe[i].s += tribe[i].ds;
                        tribe[i].n--;
                    }
                }
            }
            next = Long.MAX_VALUE;
            for (int i = 0; i < N; i++) {
                next = Math.min(next, tribe[i].d);
            }
        }
        out.print(breach);
    }

static class Tribe {
    public long d;
    public long n;
    public int w;
    public int e;
    public long s;
    public long dd;
    public int dp;
    public long ds;

    public Tribe(Scanner in) {
        this.d = in.nextLong();
        this.n = in.nextLong();
        this.w = in.nextInt();
        this.e = in.nextInt();
        this.s = in.nextLong();
        this.dd = in.nextLong();
        this.dp = in.nextInt();
        this.ds = in.nextLong();
    }}

}

