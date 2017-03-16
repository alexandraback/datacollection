package com.forthgo.contest.g2013r0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


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
        int n = in.nextInt();
        int m = in.nextInt();
        int [][]lawn = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                lawn[i][j] = in.nextInt();
            }
        }
        int prev = 0;
        for (;;) {
            int next = findMin(lawn);
            if (next == prev) {
                out.print("NO");
                return;
            }
            if (next == Integer.MAX_VALUE) {
                out.print("YES");
                return;
            }
            mow(lawn, next);
            prev = next;
        }
    }

    private static void mow(int[][] lawn, int h) {
        for (int i = 0; i < lawn.length; i++) {
            if (rowMax(lawn, i) == h)
                mowRow(lawn, i);
        }
        for (int i = 0; i < lawn[0].length; i++) {
            if (colMax(lawn, i) == h)
                mowCol(lawn, i);
        }
    }

    private static int rowMax(int[][] lawn, int r) {
        int max = 0;
        for (int i = 0; i < lawn[0].length; i++) {
            max = Math.max(lawn[r][i], max);
        }
        return max;
    }

    private static void mowRow(int[][] lawn, int r) {
        for (int i = 0; i < lawn[0].length; i++) {
            lawn[r][i] = 0;
        }
    }

    private static int colMax(int[][] lawn, int c) {
        int max = 0;
        for (int i = 0; i < lawn.length; i++) {
            max = Math.max(lawn[i][c], max);
        }
        return max;
    }

    private static void mowCol(int[][] lawn, int c) {
        for (int i = 0; i < lawn.length; i++) {
            lawn[i][c] = 0;
        }
    }


    private static int findMin(int[][] lawn) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < lawn.length; i++) {
            int[] row = lawn[i];
            for (int j = 0; j < row.length; j++) {
                int cell = row[j];
                if (cell > 0 && cell < min)
                    min = cell;
            }
        }
        return min;
    }

}

