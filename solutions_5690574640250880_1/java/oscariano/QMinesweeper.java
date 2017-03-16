/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.podervisual.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 *
 * @author osdroid
 */
public class QMinesweeper {

    private static void printResult(boolean[][] result, PrintStream writer) throws Exception {
        for (int i = 0; i < result.length; i++) {
            StringBuffer builder = new StringBuffer();
            for (int j = 0; j < result[i].length; j++) {
                if (i == 0 && j == 0) {
                    builder.append("c");
                    continue;
                }
                if (result[i][j]) {
                    builder.append(".");
                } else {
                    builder.append("*");
                }
            }
            writer.println(builder.toString());
        }
    }
    private static void set(boolean[][] result, boolean value, int x, int y, int rows, int cols) {
        if (rows < cols) {
            result[y][x] = value;
        } else {
            result[x][y] = value;
        }
    }
    private static boolean get(boolean[][] result, int x, int y, int rows, int cols) {
        if (rows < cols) {
            if (y >= rows || x >= cols)
                return true;
            return result[y][x];
        } else {
            if (x >= rows || y >= cols)
                return true;
            return result[x][y];
        }
    }
    private static void solve(int rows, int cols, int mines, PrintStream writer) throws Exception {
        int free = rows * cols - mines;
        int minRC = Math.min(rows, cols);
        boolean[][] result = new boolean[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = false;
            }
        }
        result[0][0] = true;
        if (mines == 0) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = true;
                }
            }
            printResult(result, writer);
            return;
        }
        if (free == 1) {
            printResult(result, writer);
            return;
        }
        if (minRC == 2) {
            if (free % 2 == 1 || free == 2) {
                writer.println("Impossible");
                return;
            }
            for (int i = 0; i < free / 2; i++) {
                if (rows == 2) {
                    result[0][i] = true;
                    result[1][i] = true;
                } else {
                    result[i][0] = true;
                    result[i][1] = true;
                }
            }
            printResult(result, writer);
            return;
        }
        if (minRC == 1) {
            for (int i = 0; i < free; i++) {
                if (rows == 1) {
                    result[0][i] = true;
                } else {
                    result[i][0] = true;
                }
            }
            printResult(result, writer);
            return;
        }
        if (free < 4 || free == 5 || free == 7) {
            writer.println("Impossible");
            return;
        }
        result[0][0] = true;
        result[0][1] = true;
        result[1][0] = true;
        result[1][1] = true;
        if (free == 4) {
            printResult(result, writer);
            return;
        }
        result[2][0] = true;
        result[2][1] = true;
        if (free == 6) {
            printResult(result, writer);
            return;
        }
        result[0][2] = true;
        result[1][2] = true;
        if (free == 8) {
            printResult(result, writer);
            return;
        }
        free -= 8;
        int currX = 3;
        int maxX = Math.max(rows, cols);
        int currY = 0;
        int maxY = Math.min(rows, cols);
        while (free > 0) {
            if (free > 1) {
                free -= 2;
                if (!get(result, 0, currY + 2, rows, cols)) {
                    set(result, true, 0, currY + 2, rows, cols);
                    set(result, true, 1, currY + 2, rows, cols);
                    continue;
                }
                if (currX < maxX) {
                    set(result, true, currX, currY, rows, cols);
                    if (currY + 1 < maxY) {
                        set(result, true, currX, currY + 1, rows, cols);
                    } else {
                        currX++;
                        set(result, true, currX, currY, rows, cols);
                    }
                    
                    currX++;
                } else {
                    currY += 2;
                    currX = 2;
                    if (currY + 1 < maxY) {
                        set(result, true, 0, currY + 1, rows, cols);
                        set(result, true, 1, currY + 1, rows, cols);
                    }
                }
            } else {
                free--;
                if (currY == 0) {
                    set(result, true, 2, 2, rows, cols);
                } else {
                    if (currX < maxX) {
                        set(result, true, currX, currY, rows, cols);
                    } else {
                        set(result, true, 2, currY + 2, rows, cols);
                    }
                }
            }
        }
        
        printResult(result, writer);
    }
    private static void solve(BufferedReader reader, PrintStream writer) throws Exception {
        String line = reader.readLine();
        String[] pieces = line.split(" ");
        int rows = Integer.parseInt(pieces[0]);
        int cols = Integer.parseInt(pieces[1]);
        int mines = Integer.parseInt(pieces[2]);
        solve(rows, cols, mines, writer);
    }
    private static void solve(String filename) throws Exception {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(new FileInputStream(filename + ".in")));
        PrintStream writer = new PrintStream(new File(filename + ".out"));
        int numCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numCases; i++) {
            writer.println(String.format("Case #%d:", i + 1));
            solve(reader, writer);
        }
        writer.close();
    }
    
    public static void main(String[] args) throws Exception {
        solve(5, 3, 4, new PrintStream(System.out));
        System.out.println("File?: ");
        BufferedReader lector = new BufferedReader(
                new InputStreamReader(System.in));
        String filename = lector.readLine();
        solve(filename);
    }
    
}
