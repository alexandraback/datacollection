package com.example;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class HelloWorld {
    static PrintWriter out = null;
    static FileInputStream in = null;
    static Scanner inp;
    static int ROW, COL;

    public static void main(String[] args) throws IOException {

        try {
            in = new FileInputStream("src/com/resources/smallInput.txt");
            out = new PrintWriter("src/com/resources/output.txt");
            inp = new Scanner(in);

            int tc = inp.nextInt();
            for (int i = 0; i < tc; i++) {
                solveTest(i + 1, inp.nextInt(), inp.nextInt(), inp.nextInt());
            }
        } finally {
            if (in != null) {
                in.close();
            }
            if (out != null) {
                out.close();
            }
        }
    }

    private static void solveTest(int tc, int R, int C, int M) throws IOException {
        boolean debug = false;
        String output = null;
        int[][] board = new int[R][C];
        int rnum = 0, cnum = 0, mnum = 0;

        int min = (R < C) ? R : C, temp = 0, left = M;
        while (M > mnum) {
            mnum += min;
            if (mnum > M) {
                left = min - (mnum - M);
            }
            if (min == C - cnum) {
                for (int i = 0; (i < C) && (i < cnum + left); i++) {
                    if ((mnum > M) && (C - cnum - left == 1) && (i == cnum + left - 1)) {
                        board[rnum + 1][cnum] = 1;
                    } else {
                        board[rnum][i] = 1;
                    }
                }
                rnum++;
            } else {
                for (int i = 0; (i < R) && (i < rnum + left); i++) {
                    if ((mnum > M) && (R - rnum - left == 1) && (i == rnum + left - 1)) {
                        board[rnum][cnum + 1] = 1;
                    } else {
                        board[i][cnum] = 1;
                    }
                }
                cnum++;
            }
            min = ((R - rnum) < (C - cnum)) ? R - rnum : C - cnum;
        }

        /**
         for (int i = 0; i < R; i++) {
         for (int j = 0; j < C; j++) {
         System.out.print(board[i][j] + " ");
         }
         System.out.println();
         }
         */

        if (debug) {
            System.out.println(R + " " + C + " " + M);
        }
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (board[i][j] != 1) {
                    board[i][j] = 2;
                }
        ROW = R;
        COL = C;
        if (board[R - 1][C - 1] != 1) {
            board[R - 1][C - 1] = 0;
            modify(board, R - 1, C - 1);
        }

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                temp += board[i][j];

        output = "Case #" + tc + ":\n";
        if (temp > M) {
            output += "Impossible";
        } else {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (board[i][j] == 1) {
                        output += '*';
                    } else if(i==(R-1) && (j==(C-1))){
                        output += 'c';
                    } else {
                        output += '.';
                    }
                }
                if(i != R-1) output += "\n";
            }
        }
        System.out.println(output);
        out.println(output);
    }

    private static void modify(int[][] board, int rows, int cols) {
        /**
         for (int i = 0; i < ROW; i++) {
         for (int j = 0; j < COL; j++) {
         System.out.print(board[i][j] + " ");
         }
         System.out.println();
         }
         */

        boolean flag1 = false, flag2 = false;
        if (rows < 1) {
            flag1 = true;
        }

        if (cols < 1) {
            flag2 = true;
        }

        if ((flag1 || (board[rows - 1][cols] != 1)) && (flag2 || (board[rows][cols - 1] != 1)) && (flag1 || flag2 || (board[rows - 1][cols - 1] != 1))) {
            if ((flag1 || (board[rows - 1][cols] == 0)) && (flag2 || (board[rows][cols - 1] == 0)) && (flag1 || flag2 || (board[rows - 1][cols - 1] == 0))) {
                return;
            }
            int temp1 = 0, temp2 = 0, temp3 = 0;
            if (!flag1) {
                temp1 = board[rows - 1][cols];
            }
            if (!flag2) {
                temp2 = board[rows][cols - 1];
            }
            if (!flag1 && !flag2) {
                temp3 = board[rows - 1][cols - 1];
            }
            if (!flag1) {
                board[rows - 1][cols] = 0;
            }
            if (!flag2) {
                board[rows][cols - 1] = 0;
            }
            if (!flag1 && !flag2) {
                board[rows - 1][cols - 1] = 0;
            }
            if (!flag1) {
                modify(board, rows - 1, cols);
            }
            if (!flag2) {
                modify(board, rows, cols - 1);
            }
            if (!flag1 && !flag2) {
                modify(board, rows - 1, cols - 1);
            }
        }
    }
}
