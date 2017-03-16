import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Jacob Jiang
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        char[][] s = in.next2DCharArray(4, 4);
        out.print("Case #" + testNumber + ": ");
        if (isWon(s, 'X')) {
            out.println("X won");
        } else if (isWon(s, 'O')) {
            out.println("O won");
        } else {
            boolean hasEmpty = false;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (s[i][j] == '.')
                        hasEmpty = true;
                }
            }
            if (hasEmpty)
                out.println("Game has not completed");
            else
                out.println("Draw");
        }
    }

    private boolean isWon(char[][] s, char x) {
        for (int i = 0; i < 4; i++) {
            boolean can = true;
            for (int j = 0; j < 4; j++) {
                if (s[i][j] != x && s[i][j] != 'T')
                    can = false;
            }
            if (can)
                return true;
        }
        for (int j = 0; j < 4; j++) {
            boolean can = true;
            for (int i = 0; i < 4; i++) {
                if (s[i][j] != x && s[i][j] != 'T')
                    can = false;
            }
            if (can)
                return true;
        }
        boolean can = true;
        for (int i = 0; i < 4; i++) {
            if (s[i][i] != x && s[i][i] != 'T')
                can = false;
        }
        if (can)
            return true;
        can = true;
        for (int i = 0; i < 4; i++) {
            if (s[i][3 - i] != x && s[i][3 - i] != 'T')
                can = false;
        }
        return can;
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public String next() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public char nextChar() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        return (char) c;
    }

    public char[] nextCharArray(int count) {
        char[] result = new char[count];
        for (int i = 0; i < count; i++) {
            result[i] = nextChar();
        }
        return result;
    }

    public char[][] next2DCharArray(int n, int m) {
        char[][] result = new char[n][];
        for (int i = 0; i < n; i++) {
            result[i] = nextCharArray(m);
        }
        return result;
    }

    }

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(OutputStream stream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void println(String x) {
        writer.println(x);
    }

    public void close() {
        writer.close();
    }

    public void print(String s) {
        writer.print(s);
    }

    }

