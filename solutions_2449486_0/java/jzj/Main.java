import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.RandomAccess;
import java.util.AbstractList;
import java.io.Writer;
import java.util.HashSet;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.math.BigDecimal;
import java.util.InputMismatchException;
import java.util.Set;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Collections;
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
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    private boolean valid(boolean[][] map) {
        int height = map.length;
        int width = map[0].length;
        boolean[] isOccupied = new boolean[width];
        for (boolean[] row : map) {
            if (ArrayUtils.getTrueCount(row) < width) {
                for (int j = 0; j < width; j++) {
                    if (row[j])
                        isOccupied[j] = true;
                }
            }
        }
        for (int j = 0; j < width; j++) {
            if (isOccupied[j]) {
                //noinspection ForLoopReplaceableByForEach
                for (int i = 0; i < height; i++) {
                    if (!map[i][j])
                        return false;
                }
            }
        }
        return true;
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int height = in.nextInt();
        int width = in.nextInt();
        int[][] a = in.next2DIntArray(height, width);
        out.print("Case #" + testNumber + ": ");
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                set.add(a[i][j]);
            }
        }
        for (int item : set) {
            boolean[][] map = new boolean[height][width];
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (a[i][j] <= item)
                        map[i][j] = true;
                }
            }
            if (!valid(map)) {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
    }
}

class ArrayUtils {



    public static int getTrueCount(boolean[] array) {
        int result = 0;
        for (boolean b : array) {
            if (b) result++;
        }
        return result;
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

    public int nextInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
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

    public int[] nextIntArray(int count) {
        int[] result = new int[count];
        for (int i = 0; i < count; i++) {
            result[i] = nextInt();
        }
        return result;
    }

    public int[][] next2DIntArray(int n, int m) {
        int[][] result = new int[n][];
        for (int i = 0; i < n; i++) {
            result[i] = nextIntArray(m);
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

