
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class TicTacToeTomek implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new TicTacToeTomek(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();

            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/input.txt"));
             out = new PrintWriter("src/tomekoutput.txt");

            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    // solution
    void solve() throws IOException {
        int ct = readInt();
        int n = 0;
        while (ct-- > 0) {
            solveTestCase(++n);
        }
    }
    static final char EMPTY = '.';

    public TicTacToeTomek() {
    }

    void solveTestCase(int number) throws IOException {
        out.print("Case #" + number + ": ");
        char[][] board = new char[4][4];
        for (int i = 0; i < 4; i++) {
            board[i] = readString().toCharArray();
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (!equals(board[i][j], board[i][0]) || !equals(board[i][j], board[i][1])) {
                    break;
                } else if (j == 3) {
                    print(board[i][j], board[i][j - 1]);
                    return;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (!equals(board[j][i], board[0][i]) || !equals(board[j][i], board[1][i])) {
                    break;
                } else if (j == 3) {
                    print(board[j][i], board[j - 1][i]);
                    return;
                }
            }
        }
        if (equals(board[0][0], board[1][1]) && equals(board[1][1], board[2][2]) && equals(board[2][2], board[3][3]) && equals(board[1][1], board[3][3]) && equals(board[0][0], board[2][2])) {
            print(board[0][0], board[1][1]);
            return;
        }
        if (equals(board[3][0], board[2][1]) && equals(board[2][1], board[1][2]) && equals(board[1][2], board[0][3]) && equals(board[3][0], board[1][2]) && equals(board[2][1], board[0][3])) {
            print(board[3][0], board[2][1]);
            return;
        }
        boolean hasEmpty = false;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                hasEmpty |= (board[i][j] == EMPTY);
            }
        }
        if (hasEmpty) {
            out.println("Game has not completed");
        } else {
            out.println("Draw");
        }
    }

    boolean equals(char ch1, char ch2) {
        if (ch1 == EMPTY || ch2 == EMPTY) {
            return false;
        }
        if (ch1 == 'T' || ch2 == 'T') {
            return true;
        }
        return (ch1 == ch2);
    }

    void print(char ch1, char ch2) {
        out.println((ch1 == 'T' ? ch2 : ch1) + " won");
    }
}