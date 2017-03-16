import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    static private int field[][];
    static private char board[][];
    static private int R, C, M, N;
    static private PrintWriter writer;
    static boolean failed;
    static boolean debug = false;
    static int nt;

    public static void click2() {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (board[i][j] == '*')
                    continue;
                int sum = 0;
                sum += (board[i-1][j-1] == '*' && (i-1 >= 1 && i-1 <= R && j-1 >= 1 && j-1 <= C)) ? 1 : 0;
                sum += (board[i-1][j] == '*' && (i-1 >= 1 && i-1 <= R && j >= 1 && j <= C)) ? 1 : 0;
                sum += (board[i-1][j+1] == '*' && (i-1 >= 1 && i-1 <= R && j+1 >= 1 && j+1 <= C)) ? 1 : 0;
                sum += (board[i][j-1] == '*' && (i >= 1 && i <= R && j-1 >= 1 && j-1 <= C)) ? 1 : 0;
                sum += (board[i][j+1] == '*' && (i >= 1 && i <= R && j+1 >= 1 && j+1 <= C)) ? 1 : 0;
                sum += (board[i+1][j-1] == '*' && (i+1 >= 1 && i+1 <= R && j-1 >= 1 && j-1 <= C)) ? 1 : 0;
                sum += (board[i+1][j] == '*' && (i+1 >= 1 && i+1 <= R && j >= 1 && j <= C)) ? 1 : 0;
                sum += (board[i+1][j+1] == '*' && (i+1 >= 1 && i+1 <= R && j+1 >= 1 && j+1 <= C)) ? 1 : 0;

                if (sum == 2) {
                    click(i, j);
                    N -= 2;
                    return;
                }
            }
        }

        failed = true;
        System.out.println("fuck! " + nt + " " + R + " " + C + " " + M);
    }

    public static void click(int i, int j) {
        board[i][j] = '.';
        if (board[i-1][j-1] != '0')
            board[i-1][j-1] = '.';
        if (board[i-1][j] != '0')
            board[i-1][j] = '.';
        if (board[i-1][j+1] != '0')
            board[i-1][j+1] = '.';
        if (board[i+1][j-1] != '0')
            board[i+1][j-1] = '.';
        if (board[i+1][j] != '0')
            board[i+1][j] = '.';
        if (board[i][j-1] != '0')
            board[i][j-1] = '.';
        if (board[i][j+1] != '0')
            board[i][j+1] = '.';
        if (board[i+1][j+1] != '0')
            board[i+1][j+1] = '.';
    }

    public static void printBoard() {
        board[1][1] = 'c';
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                writer.print(board[i][j]);
            }
            writer.println();
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        writer = new PrintWriter(new FileWriter("answer.txt"));

        for (nt = 1; nt <= T; nt++) {

            R = in.nextInt();
            C = in.nextInt();
            M = in.nextInt();
            N = R*C-M;
            // System.out.println("hehe");
            failed = false;

            board = new char[55][55];
            for (int i = 0; i <= R+1; i++) {
                for (int j = 0; j <= C+1; j++) {
                    board[i][j] = '*';
                }
            }

            writer.println("Case #" + nt + ":");

            if (N == 0) {
                writer.println("Impossible");
                continue;
            }

            if (N == 1) {
                printBoard();
                continue;
            }

            if (R == 1) {
                for (int i = 1; i <= N-1; i++)
                    click(1, i);
                printBoard();
                continue;
            }

            if (C == 1) {
                for (int i = 1; i <= N-1; i++)
                    click(i, 1);
                printBoard();
                continue;
            }

            if (C == 4 && R == 4 && M == 1) {
                writer.println("c...");
                writer.println("....");
                writer.println("....");
                writer.println("...*");
                continue;
            }

            // odd
            if (N % 2 == 1) {
                if (C < 3 || R < 3 || N < 9) {
                    writer.println("Impossible");
                    continue;
                }

                click(2,2);
                N -= 9;

                while (N != 0 && !failed)
                    click2();

                if (failed) {
                    writer.println("Impossible");
                    if (debug) {}
                        // printBoard();
                } else {
                    printBoard();
                }

                continue;
            }

            // even
            if (N < 4) {
                writer.println("Impossible");
                continue;
            }

            click(1, 1);
            N -= 4;
            while (N != 0 && !failed)
                click2();

            if (failed) {
                writer.println("Impossible");
                if (debug) {}
                    // printBoard();
            } else {
                printBoard();
            }
        }

        writer.close();
    }
}
