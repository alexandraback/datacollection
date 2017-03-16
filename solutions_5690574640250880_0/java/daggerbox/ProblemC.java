package com.forthgo.contest.g2014r0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;


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
//                out.println();
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private static void solve(Scanner in, PrintWriter out) {
        int R = in.nextInt();
        int C = in.nextInt();
        int M = in.nextInt();
        int rc = R * C;
        int n = rc - M;
        boolean swapped = false;
        if (R > C) {
            swapped = true;
            int t = R;
            R = C;
            C = t;
        }
        boolean impossible = false;
        char[][] grid = new char[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = '*';
            }
        }
        if (n > 1) {
            if (M == 0) {
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        grid[i][j] = '.';
                    }
                }
            }
            else if (R == 1) {
                // one row
                for (int j = 0; j < n; j++) {
                    grid[0][j] = '.';
                }
            }
            else if (R == 2) {
                if (n > 2 && n % 2 == 0) {
                    for (int j = 0; j < n / 2; j++) {
                        grid[0][j] = '.';
                        grid[1][j] = '.';
                    }
                }
                else
                    impossible = true;
            }
            else {
                if (n < 4 || n == 5 || n == 7) {
                    impossible = true;
                }
                else {
                    int rFull = n / C;
                    if (rFull > 1) {
                        for (int i = 0; i < rFull; i++) {
                            for (int j = 0; j < C; j++) {
                                grid[i][j] = '.';
                            }
                        }
                        n -= rFull * C;
                        if (n == 1) {
                            if (rFull > 2) {
                                grid[rFull - 1][C - 1] = '*';
                                grid[rFull][0] = '.';
                                grid[rFull][1] = '.';
                            }
                            else {
                                grid[rFull - 1][C - 1] = '*';
                                grid[rFull - 2][C - 1] = '*';
                                grid[rFull][0] = '.';
                                grid[rFull][1] = '.';
                                grid[rFull][2] = '.';
                            }
                        }
                        else {
                            for (int j = 0; j < n; j++) {
                                grid[rFull][j] = '.';
                            }
                        }
                    }
                    else {
                        // less than 2 full rows
                        if (n % 2 == 0) {
                            for (int j = 0; j < n / 2; j++) {
                                grid[0][j] = '.';
                                grid[1][j] = '.';
                            }
                        }
                        else {
                            for (int i = 0; i < 3; i++) {
                                for (int j = 0; j < 3; j++) {
                                    grid[i][j] = '.';
                                }
                            }
                            for (int j = 0; j < (n - 9) / 2; j++) {
                                grid[0][j + 3] = '.';
                                grid[1][j + 3] = '.';
                            }
                        }
                    }
                }
            }
        }
        grid[0][0] = 'c';
        out.println();
        if (impossible) {
            out.println("Impossible");
        }
        else if (swapped) {
            for (int j = 0; j < C; j++) {
                for (int i = 0; i < R; i++) {
                    out.print(grid[i][j]);
                }
                out.println();
            }
        }
        else {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    out.print(grid[i][j]);
                }
                out.println();
            }
        }
    }

}

