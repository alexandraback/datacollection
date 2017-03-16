import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader in;
        try {
            in = new InputReader(new FileInputStream("A-large.in"));
        } catch (FileNotFoundException e) {
            in = new InputReader(System.in);
        }
        PrintWriter out;
        try {
            out = new PrintWriter(new FileOutputStream("Output.out"));
        } catch (FileNotFoundException e) {
            out = new PrintWriter(System.out);
        }
        Task solver = new Task();
        int testCount = in.readInt();
        for (int i = 1; i <= testCount; ++i)
            solver.solve(i, in, out);
        out.close();
    }
}

class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        char[][] board = new char[4][4];
        for (int i = 0; i < board.length; ++i)
            board[i] = in.readString().toCharArray();
        out.print("Case #" + testNumber + ": ");
        if (isWinning('X', board)) out.println("X won");
        else if (isWinning('O', board)) out.println("O won");
        else if (hasGameCompleted(board)) out.println("Draw");
        else out.println("Game has not completed");
    }

    public boolean isWinning(char t, char[][] board) {
        char s = t == 'X' ? 'O' : 'X';
        for (int i = 0; i < board.length; ++i) {
            boolean win = true;
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == '.' || board[i][j] == s) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
        for (int j = 0; j < board[0].length; ++j) {
            boolean win = true;
            for (int i = 0; i < board.length; ++i) {
                if (board[i][j] == '.' || board[i][j] == s) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
        boolean mainDiagonalWin = true;
        for (int i = 0; i < board.length; ++i) {
            if (board[i][i] == '.' || board[i][i] == s) {
                mainDiagonalWin = false;
                break;
            }
        }
        if (mainDiagonalWin) return true;
        boolean minorDiagonalWin = true;
        for (int i = 0; i < board.length; ++i) {
            if (board[i][board[0].length - 1 - i] == '.' || board[i][board[0].length - 1 - i] == s) {
                minorDiagonalWin = false;
                break;
            }
        }
        if (minorDiagonalWin) return true;
        return false;
    }

    public boolean hasGameCompleted(char[][] board) {
        for (int i = 0; i < board.length; ++i)
            for (int j = 0; j < board[0].length; ++j)
                if (board[i][j] == '.')
                    return false;
        return true;
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        this.reader = new BufferedReader(new InputStreamReader(stream));
        this.tokenizer = null;
    }

    public String readLine() {
        String res;
        try {
            do {
                res = reader.readLine();
            } while (res == null);
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return res;
    }

    public String readString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(readLine());
        return tokenizer.nextToken();
    }

    public int readInt() {
        return Integer.parseInt(readString());
    }

    public long readLong() {
        return Long.parseLong(readString());
    }

    public double readDouble() {
        return Double.parseDouble(readString());
    }
}
