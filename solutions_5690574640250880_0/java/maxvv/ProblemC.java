
import java.io.File;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author massimo
 */
public class ProblemC {

    public static void main(String[] args) throws Exception {

        //String inFile = "sampleC.in";
        //String outFile = "sampleC.out";
        String inFile = "C-small-attempt5.in";
        String outFile = "C-small-attempt5.out";
        //String inFile = "B-large-practice.in";
        //String outFile = "B-large-practice.out";

        Scanner sc = new Scanner(new File(inFile));
        PrintWriter writer = new PrintWriter(outFile);
        int numTest = sc.nextInt();
        for (int test = 1; test <= numTest; test++) {
            int r = sc.nextInt();
            int c = sc.nextInt();
            int m = sc.nextInt();
            writer.print("Case #" + test + ":" + solution(r, c, m));
        }
        writer.close();
    }

    private static String solution(int r, int c, int m0) {
        boolean debug = false;
        boolean impossible = false;
        String res = debug ? (r + " " + c + " " + m0 + "\n") : "\n";
        int m = m0;
        if (r * c <= m) {
            if (debug) {
                return "\n" + r + " " + c + " " + m + "\nImpossible\n";
            } else {
                return "\nImpossible\n";
            }
        }
        char[][] board = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i][j] = '.';
            }
        }
        board[r - 1][c - 1] = 'c';

        int r0 = 0;
        int c0 = 0;

        while (m >= Math.min(r - r0, c - c0)) {
            if (r - r0 < c - c0) { //landscape
                if (r - r0 <= 2) { //fill a column
                    for (int i = r0; i < r; i++) {
                        board[i][c0] = '*';
                    }
                    c0++;
                    m -= r - r0;
                } else { //fill a row
                    for (int j = c0; j < c; j++) {
                        board[r0][j] = '*';
                    }
                    r0++;
                    m -= c - c0;
                }
            } else { //portrait
                if (c - c0 <= 2) { //fill a row
                    for (int j = c0; j < c; j++) {
                        board[r0][j] = '*';
                    }
                    r0++;
                    m -= c - c0;
                } else {//fill a column
                    for (int i = r0; i < r; i++) {
                        board[i][c0] = '*';
                    }
                    c0++;
                    m -= r - r0;
                }
            }
        }

        if (m > 0) {
            if (r - r0 <= c - c0) {
                for (int i = r0; i <= Math.min(r - 2, r0 + m); i++) {
                    board[i][c0] = '*';
                    m--;
                }
                r0++;
            } else {
                for (int j = c0; j <= Math.min(c - 2, c0 + m); j++) {
                    board[r0][j] = '*';
                    m--;
                }
                c0++;
            }
            if (m > 0) {
                board[r0][c0] = '*';
            }
        }

        if (r * c != m0 + 1 && c != 1 && r != 1) {
            for (int i = r - 2; i >= 0; i--) {
                if (board[i][c - 1] == '.') {
                    if (board[i][c - 2] == '*') {
                        if (debug) {
                            res += "\nImpossible\n";
                            impossible = true;
                        } else {
                            return "\nImpossible\n";
                        }
                    }
                } else {
                    break;
                }
            }
            for (int j = c - 2; j >= 0; j--) {
                if (board[r - 1][j] == '.') {
                    if (board[r - 2][j] == '*') {
                        if (debug) {
                            res += "\nImpossible\n";
                            impossible = true;
                        } else {
                            return "\nImpossible\n";
                        }
                    }
                } else {
                    break;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res += board[i][j];
            }
            res += "\n";
        }
        if (debug) {
            boolean ok = test(board);
            if (ok == impossible) {
                System.out.println("ERROR!");
            }
            System.out.println(ok + "\n\n");
        }
        return res;
    }

    public static boolean test(char[][] originalBoard) {
        char[][] board = new char[originalBoard.length][originalBoard[0].length];
        int[] start = new int[2];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                board[i][j] = originalBoard[i][j];
                if (board[i][j] == 'c') {
                    start[0] = i;
                    start[1] = j;
                }
            }
        }
        LinkedList<int[]> q = new LinkedList<int[]>();
        q.addLast(start);
        while (!q.isEmpty()) {
            int[] p = q.removeFirst();
            int m = 0;
            for (int i = Math.max(p[0] - 1, 0); i <= Math.min(board.length - 1, p[0] + 1); i++) {
                for (int j = Math.max(p[1] - 1, 0); j <= Math.min(board[0].length - 1, p[1] + 1); j++) {
                    if (board[i][j] == '*') {
                        m++;
                    }
                }
            }
            board[p[0]][p[1]] = (char) (m + '0');
            if (m == 0) {
                for (int i = Math.max(p[0] - 1, 0); i <= Math.min(board.length - 1, p[0] + 1); i++) {
                    for (int j = Math.max(p[1] - 1, 0); j <= Math.min(board[0].length - 1, p[1] + 1); j++) {
                        if (board[i][j] == '.') {
                            q.addLast(new int[]{i, j});
                        }
                    }
                }
            }
        }
        boolean ok = true;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                System.out.print(board[i][j]);
                if (board[i][j] == '.') {
                    ok = false;
                }
            }
            System.out.println();
        }
        return ok;
    }
}
