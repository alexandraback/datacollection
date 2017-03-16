package qualification2013;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class TicTacToeTomek {
    static int T;
    static int t;
    static char[][] board = new char[4][4];
    static PrintWriter pw;

    public static void main(String[] args) throws IOException {
        File output = new File("output.txt");
        pw = new PrintWriter(output);
        read();
        pw.close();
    }

    static void read() throws IOException {
        File input = new File("input.txt");
        Scanner scanner = new Scanner(input);
        T = Integer.parseInt(scanner.nextLine());
        for (t=0; t<T; t++) {
            if (t != 0) {
                scanner.nextLine();
            }
            for (int i=0; i<4; i++) {
                String s = scanner.nextLine();
                for (int j=0; j<4; j++) {
                    board[i][j] = s.charAt(j);
                }
            }
            process();
        }
    }

    static void process() throws IOException {
        boolean full = true;
        for (int i=0; i<4; i++) {
            boolean Owon = true;
            boolean Xwon = true;
            for (int j=0; j<4; j++) {
                char c = board[i][j];
                if (c == '.') {
                    full = false;
                    Xwon = false;
                    Owon = false;
                }
                if (c == 'O') {
                    Xwon = false;
                }
                if (c == 'X') {
                    Owon = false;
                }
            }
            if (Owon) {
                write("O won");
                return;
            }
            if (Xwon) {
                write("X won");
                return;
            }
        }
        for (int i=0; i<4; i++) {
            boolean Owon = true;
            boolean Xwon = true;
            for (int j=0; j<4; j++) {
                char c = board[j][i];
                if (c == '.') {
                    Xwon = false;
                    Owon = false;
                }
                if (c == 'O') {
                    Xwon = false;
                }
                if (c == 'X') {
                    Owon = false;
                }
            }
            if (Owon) {
                write("O won");
                return;
            }
            if (Xwon) {
                write("X won");
                return;
            }
        }
        boolean Owon = true;
        boolean Xwon = true;
        for (int j=0; j<4; j++) {
            char c = board[j][j];
            if (c == '.') {
                Xwon = false;
                Owon = false;
            }
            if (c == 'O') {
                Xwon = false;
            }
            if (c == 'X') {
                Owon = false;
            }
        }
        if (Owon) {
            write("O won");
            return;
        }
        if (Xwon) {
            write("X won");
            return;
        }
        Owon = true;
        Xwon = true;
        for (int j=0; j<4; j++) {
            char c = board[j][3-j];
            if (c == '.') {
                Xwon = false;
                Owon = false;
            }
            if (c == 'O') {
                Xwon = false;
            }
            if (c == 'X') {
                Owon = false;
            }
        }
        if (Owon) {
            write("O won");
            return;
        }
        if (Xwon) {
            write("X won");
            return;
        }
        if (full) {
            write("Draw");
        } else {
            write("Game has not completed");
        }
    }

    static void write(String result) throws IOException {
        pw.println("Case #"+(t+1)+": "+result);
    }

}
