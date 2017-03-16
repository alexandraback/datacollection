/*
 * CONFIDENTIAL
 * Copyright 2013 Webalo, Inc.  All rights reserved.
 */

package mahfouz.google.codejam.y2014.qual;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Solution of "Minesweeper Master" problem (Qualification 2014).
 */
public final class MinesweeperMaster {

    public static void main(String[] args) throws Exception{
        Scanner s = new Scanner(new File("C:\\Users\\amahfouz\\Downloads\\cj.in"));
        PrintStream out = new PrintStream(new File("C:\\Users\\amahfouz\\Desktop\\solution.txt"));

        int numCases = s.nextInt();

        for (int i = 0; i < numCases; i++) {
            solveCase(i + 1, s, out);
        }
    }

    private static void solveCase(int caseNum, Scanner in, PrintStream out) {
        final int rows = in.nextInt();
        final int cols = in.nextInt();
        final int numMines = in.nextInt();
        final int blank = rows * cols - numMines;

        final char[][] board = new char[rows][cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                board[i][j] = '*';

        boolean possible = false;

        if (rows == 1 && cols == 1) {
            possible = (numMines == 0);
        }
        else if (rows == 1) {
            possible = (cols > numMines);
            if (possible)
                for (int j = 0; j < blank; j++)
                    board[0][j] = '.';
        }
        else if (cols == 1) {
            possible = (rows > numMines);
            if (possible)
                for (int i = 0; i < blank; i++)
                    board[i][0] = '.';
        }
        else if (blank == 1) {
            possible = true;
        }
        else if (blank < 4) {
            possible = false;
        }
        else {
            int squareSide = (int)Math.floor(Math.sqrt(blank));
            int partSquareSide = blank - squareSide * squareSide;

            if (squareSide > 1
                && squareSide <= rows
                && squareSide <= cols
                && partSquareSide != 1
                && partSquareSide <= squareSide) {

                possible = true;

                // fill a square
                for (int i = 0; i < squareSide; i++)
                    for (int j = 0; j < squareSide; j++)
                        board[i][j] = '.';

                // fill part row/col along the shorter dimension
                if (rows > cols) {
                    for (int j = 0; j < partSquareSide; j++)
                        board[squareSide][j] = '.';
                }
                else {
                    for (int i = 0; i < partSquareSide; i++)
                        board[i][squareSide] = '.';
                }
            }
            else {
                // try laying out filling full rows or full columns

                int numFullRows = blank / cols;
                int partRow = blank % cols;
                int numFullCols = blank / rows;
                int partCol = blank % rows;

                if (partRow != 1 && numFullRows > 1){
                    possible = true;
                    for (int i = 0; i < numFullRows; i++)
                        for (int j = 0; j < cols; j++)
                            board[i][j] = '.';

                    for (int j = 0; j < partRow; j++)
                        board[numFullRows][j] = '.';
                }
                else if (partCol != 1 && numFullCols > 1){
                    possible = true;
                    for (int j = 0; j < numFullCols; j++)
                        for (int i = 0; i < rows; i++)
                            board[i][j] = '.';

                    for (int i = 0; i < partCol; i++)
                        board[i][numFullCols] = '.';
                }
                else {
                    // try laying out part rows or cols

                    int remain;

                    done:
                    for (int i = squareSide - 1; i <= rows - 1; i++) {
                        for (int j = squareSide - 1; j <= cols - 1; j++) {
                            remain = blank - i * j;
                            if (remain == 1)
                                continue;

                            if (remain < 0)
                                continue;

                            if (remain <= j) {
                                possible = true;

                                for (int x = 0; x < i; x++)
                                    for (int y = 0; y < j; y++)
                                        board[x][y] = '.';

                                for (int y = 0; y < remain; y++)
                                    board[i][y] = '.';

                                break done;
                            }
                            else if (remain <= i) {
                                possible = true;

                                for (int x = 0; x < i; x++)
                                    for (int y = 0; y < j; y++)
                                        board[x][y] = '.';

                                for (int x = 0; x < remain; x++)
                                    board[x][j] = '.';

                                break done;
                            }
                        }
                    }
                }
            }
        }
        if (! possible) {

            System.out.println("New case " + caseNum);
            // try laying out the mines in a rectangle instead

            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    board[i][j] = '.';

            board[rows - 1][cols - 1] = 'c';

            int mineSquareSide = (int)Math.floor(Math.sqrt(numMines));
//            int minePartSquareSide = numMines - mineSquareSide * mineSquareSide;

            int remain;

            done:
            for (int i = mineSquareSide; i <= rows - 2; i++) {
                nexti:
                for (int j = mineSquareSide; j <= cols - 2; j++) {
                    remain = numMines - i * j;

                    if (remain < 0)
                        continue nexti;

                    if (remain < j + j) {

                        for (int x = 0; x < i; x++)
                            for (int y = 0; y < j; y++)
                                board[x][y] = '*';

                        if (i < rows - 2)
                            for (int y = 0; (y < j && remain > 0); y++, remain--)
                                board[i][y] = '*';

                        if (j < cols - 2)
                            for (int x = 0; x < i && remain > 0; x++, remain--) {
                                board[x][j] = '*';
                            }

                        if (remain == 0)
                            possible = true;

                        break done;
                    }
                }
            }
        }
        else
            board[0][0] = 'c';

        out.println("Case #" + caseNum + ":");

        if (possible) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++)
                    out.print(board[i][j]);
                out.println();
            }
        }
        else {
            out.println("Impossible");
        }
    }
}

