import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
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
 * @author @Ziklon
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("bullseye.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("bullseye.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		Bullseye solver = new Bullseye();
		solver.solve(1, in, out);
		out.close();
	}
}

class Bullseye {
    BigInteger sumPares(long n) {
        n = (n >> 1);
        BigInteger a = BigInteger.valueOf(n);
        BigInteger b = BigInteger.valueOf((2 * n) + 1);
        return a.multiply(b);
    }

    BigInteger sum(long n) {
        BigInteger a = BigInteger.valueOf(n);
        return a.pow(2);
    }

    BigInteger sumImPares(long n) {
        BigInteger a = sum(n);
        BigInteger b = sumPares(n);
        return a.subtract(b);
    }


    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int T = in.nextInt();
        for (int c = 1; c <= T; c++) {
            long r = in.nextLong();
            BigInteger t = in.nextBigInteger();
            long low = 1;
            long hih = 1L << 62;

            while (hih - low > 1) {
                long mid = (low + hih) >> 1;
                BigInteger a = sum(mid).subtract(sum(r));
                if ((r % 2) == 1) {
                    a = a.subtract(sumImPares(mid));
                    a = a.add(sumImPares(r));
                } else {
                    a = a.subtract(sumPares(mid));
                    a = a.add(sumPares(r));
                }
                if (a.compareTo(t) <= 0)
                    low = mid;
                else hih = mid;
            }
            low = (low - r)/2;
            out.printFormat("Case #%d: %d\n", c, low);
        }
    }
}

class InputReader {
    InputStream stream;
    byte[] buf = new byte[1024];
    int curChar, numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    private int read() {
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
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
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
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String nextString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    private boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public BigInteger nextBigInteger() {
        try {
            return new BigInteger(nextString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    }

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void printFormat(String format, Object...objects) {
        writer.printf(format, objects);
    }

    public void close() {
        writer.close();
    }

    }

