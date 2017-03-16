package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("A-local.in"));
        PrintWriter w = new PrintWriter(new File("A-small.out"));
//        PrintWriter w = new PrintWriter(System.out);
        int n = s.nextInt();
        for (int i = 0; i < n; i++) {
            int num = s.nextInt();
            w.print("Case #" + (i+1) + ": ");
            w.println(solve(num));
        }
        w.close();
        s.close();
    }

    static class Step implements Comparable<Step> {
        int num;
        int step;

        public Step(int num, int step) {
            this.num = num;
            this.step = step;
        }

        public Step branchLeft() {
            int diff = num % 10 - 1;
            if (diff <= 0) {
                diff = 1;
            }
            Step s = new Step(num - diff, step + diff);
            Step ss = null;
            return s.num % 10 == 1 ? (ss = s.branchRight()) == null ? s : ss : s;
        }

        public Step branchRight() {
            if (num % 10 == 0) {
                return null;
            }
            int reverse = reverse(num);
            if (reverse >= num) {
                return null;
            }
            return new Step(reverse, step + 1);
        }

        private int reverse(int num) {
            int prefix = num % 10;
            int postfix = num / 10;
            return Integer.valueOf(String.valueOf(prefix) + new StringBuilder(String.valueOf(postfix)).reverse());
        }

        @Override
        public int compareTo(Step o) {
            int result = Integer.valueOf(num).compareTo(o.num);
            if (result == 0) {
                return Integer.valueOf(num).compareTo(o.num);
            } else {
                return result;
            }
        }
    }

    static Queue<Step> q = new PriorityQueue<Step>();

    private static int solve(int problem) {
        q.clear();
        q.add(new Step(problem, 1));
        Step s;
        while ((s = q.poll()).num != 1) {
            q.add(s.branchLeft());
            Step e = s.branchRight();
            if (e != null) {
                q.add(e);
            }}
        return s.step;
    }
}
