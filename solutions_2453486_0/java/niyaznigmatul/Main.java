import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("tictactoe.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tictactoe.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TicTacToe solver = new TicTacToe();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TicTacToe {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        out.print("Case #" + testNumber + ": ");
        char[][] c = in.readCharacterFieldTokens(4, 4);
        boolean end = true;
        for (char[] e : c) {
            for (char d : e) {
                if (d == '.') {
                    end = false;
                }
            }
        }
        if (win(c, 'O')) {
            out.println("O won");
            return;
        }
        if (win(c, 'X')) {
            out.println("X won");
            return;
        }
        out.println(end ? "Draw" : "Game has not completed");
    }

    static boolean win(char[][] c, char d) {
        for (int i = 0; i < 4; i++) {
            boolean w = true;
            for (int j = 0; j < 4; j++) {
                if (c[i][j] == d || c[i][j] == 'T') {
                    continue;
                }
                w = false;
                break;
            }
            if (w) return true;
        }
        for (int i = 0; i < 4; i++) {
            boolean w = true;
            for (int j = 0; j < 4; j++) {
                if (c[j][i] == d || c[j][i] == 'T') {
                    continue;
                }
                w = false;
                break;
            }
            if (w) return true;
        }
        {
            boolean w = true;
            for (int i = 0; i < 4; i++) {
                if (c[i][i] == d || c[i][i] == 'T') {
                    continue;
                }
                w = false;
                break;
            }
            if (w) return true;
        }
        {
            boolean w = true;
            for (int i = 0; i < 4; i++) {
                if (c[i][3 - i] == d || c[i][3 - i] == 'T') {
                    continue;
                }
                w = false;
                break;
            }
            if (w) return true;
        }
        return false;
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public char[][] readCharacterFieldTokens(int n, int m) {
        char[][] ret = new char[n][];
        for (int i = 0; i < n; i++) {
            ret[i] = next().toCharArray();
            if (ret[i].length != m) {
                throw new AssertionError("length expected " + m + ", found " + ret[i].length);
            }
        }
        return ret;
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

