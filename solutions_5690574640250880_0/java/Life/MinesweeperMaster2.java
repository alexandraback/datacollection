package codejam2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class MinesweeperMaster2 {
    public static void main(String[] args) throws IOException {

        String fileName;

        //fileName = "C-large.in";
        //fileName = "test.in";
        fileName = "C-small-attempt1.in";

        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")));) {
            Scanner s = new Scanner(r);
            int T = s.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int R = s.nextInt();
                int C = s.nextInt();
                int M = s.nextInt();
                w.write("Case #" + (i + 1) + ":\n" + calc(R, C, M));
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }
    }

    // should be possible to use binary search
    private static String calc(int R, int C, int M) {
        char[][] board = new char[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j] = '.';
            }
        }

        int i = 0;
        int j = 0;
        int mines = M;
        while (mines > 0 && i < R && j < C) {
            boolean row = (R - i) < (C - j);
            if (row && mines == R - i - 1) {
                row = false;
            } else if (!row && mines == C - j - 1) {
                row = true;
            }
            if (row) {
                int k = i;
                int delta = mines == R - i - 1 ? 2 : 0;
                while (mines > 0 && k < R - delta) {
                    board[k][j] = '*';
                    k++;
                    mines--;
                }
                j++;
            } else {
                int k = j;
                int delta = mines == C - j - 1 ? 2 : 0;
                while (mines > 0 && k < C - delta) {
                    board[i][k] = '*';
                    k++;
                    mines--;
                }
                i++;
            }
        }

        putStart(R, C, board);
        if (mines != 0 || !validate(board, R, C, M)) {
            return "Impossible\n";
        } else {
            return getBoard(R, board);
        }
    }

    private static boolean validate(char[][] board, int R, int C, int M) {
        if(R==1 || C==1) {
            return true;
        }
        if(R*C-M==1) {
            return true;
        }
        for (int i = 0; i < R; i++) {
            int mines = 0;
            for (int j = 0; j < C; j++) {
                if (board[i][j] == '*' ) {
                    mines++;
                }
            }
            if (C - mines == 1) {
                return false;
            }
        }
        for (int j = 0; j < C; j++) {
            int mines = 0;
            for (int i = 0; i < R; i++) {
                if (board[i][j] == '*') {
                    mines++;
                }
            }
            if (R - mines == 1) {
                return false;
            }
        }
        return true;
    }

    private static String getBoard(int R, char[][] board) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < R; i++) {
            sb.append(new String(board[i]));
            sb.append("\n");
        }
        return sb.toString();
    }

    private static void putStart(int R, int C, char[][] board) {
        board[R - 1][C - 1] = 'c';
//        out:
//        for (int i = 0; i < R; i++) {
//            for (int j = 0; j < C; j++) {
//                if (board[i][j] == '.') {
//                    board[i][j] = 'c';
//                    break out;
//                }
//            }
//        }
    }


}

