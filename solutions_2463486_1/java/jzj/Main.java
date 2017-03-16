import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.math.BigDecimal;
import java.util.InputMismatchException;
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
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    private long[] possible;

    private static boolean isPalin(long x) {
        String s = String.valueOf(x);
        return s.equals(StringUtils.reverse(s));
    }

    public TaskC() {
        LongArrayBuilder builder = new LongArrayBuilder();
        long bound = (long) 1e7;
        for (long i = 1; i <= bound; i++) {
            if (isPalin(i) && isPalin(i * i)) {
                builder.append(i * i);
            }
        }
        possible = builder.toLongArray();
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        long a = in.nextLong();
        long b = in.nextLong();
        int answer = 0;
        for (long l : possible) {
            if (a <= l && l <= b)
                answer++;
        }
        out.println("Case #" + testNumber + ": " + answer);
    }
}

class StringUtils {
    public static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    }

class LongArrayBuilder {
    long[] data;
    int length;
    int capacity;

    public LongArrayBuilder() {
        this(16);
    }
    
    public LongArrayBuilder(int initialCapacity) {
        this.capacity = initialCapacity;
        length = 0;
        data = new long[initialCapacity];
    }

    private void ensureCapacity(int neededCapacity) {
        while (neededCapacity > capacity) {
            capacity = (capacity << 1) + 1;
        }
        if (data.length < capacity) {
            data = Arrays.copyOf(data, capacity);
        }
    }

    public LongArrayBuilder append(long item) {
        ensureCapacity(length + 1);
        data[length++] = item;
        return this;
    }

    public long[] toLongArray() {
        return ArrayUtils.copyOf(data, length);
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

    public long nextLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
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

    }

class ArrayUtils {



    public static long[] copyOf(long[] original, int newLength) {
        long[] copy = new long[newLength];
        System.arraycopy(original, 0, copy, 0,
                Math.min(original.length, newLength));
        return copy;
    }


    }

