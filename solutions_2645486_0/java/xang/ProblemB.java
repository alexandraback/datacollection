package com.forthgo.contest.g2013r1a;

import com.forthgo.collection.LongTuple;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
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
        long E = in.nextLong();
        long R = in.nextLong();
        int N = in.nextInt();
        long sum = 0;
        long[] value = new long[N];
        for (int i = 0; i < value.length; i++) {
            value[i] = in.nextLong();
        }
        Stack<Work> work = new Stack<Work>();
        work.push(new Work(E, 0, 0, N));
        while (!work.empty()) {
            Work w = work.pop();
            long v = value[w.begin];
            int k = w.begin;
            for (int i = w.begin + 1; i < w.end; i++) {
                if (value[i] > v) {
                    v = value[i];
                    k = i;
                }
            }
            long free = (k - w.begin) * R - w.reserved;
            long ee = Math.min(E, w.energy + free);
            sum += ee * value[k];
            if (k == w.begin) {
                if (k != w.end - 1)
                    work.push(new Work(R, Math.min(w.reserved, R * (w.end - (w.begin + 1))), w.begin + 1, w.end));
            }
            else {
                long using = Math.min(E, free);
                long f = w.energy + using - ee;
                work.push(new Work(f, Math.min(w.reserved + using, R * (w.end - (k))), w.begin, k));
                if (k != w.end - 1) {
                    work.push(new Work(R, Math.min(w.reserved, R * (w.end - (k + 1))), k + 1, w.end));
                }
            }
        }
        out.print(sum);
    }

    static class Work {
        public long energy;
        public long reserved;
        public int begin;
        public int end;

        Work(long energy, long reserved, int begin, int end) {
            this.energy = energy;
            this.reserved = reserved;
            this.begin = begin;
            this.end = end;
        }
    }

}

