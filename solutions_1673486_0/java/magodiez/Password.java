import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.InputMismatchException;

/**
 * @author Mikeldi Latorre (mikeldi10@gmail.com)
 */
public class Password implements Runnable {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		new Thread(new Password()).start();
	}

	public Password() {
		try {
			System.setIn(new FileInputStream("password.in"));
			System.setOut(new PrintStream(new FileOutputStream("password.out")));
		} catch (FileNotFoundException e) {
			throw new RuntimeException();
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	public void run() {
		int numTests = in.readInt();
		for (int testNumber = 0; testNumber < numTests; testNumber++) {
			double x = solveError(algorithm());
			out.println("Case #" + (testNumber + 1) + ": "+(int)x+"."+(""+((int)((x-(int)x+1)*1000000))).substring(1));
		}
		out.close();
	}

	private double algorithm() {

		int a = in.readInt();
		int b = in.readInt();
		double[] p = new double[a];
		for (int i = 0; i < a; i++) {
//			p[i] = solveError(in.readDouble());
			p[i] = in.readDouble();

		}
		double ok = probOk(a, b, p);
//		double ok = 0;
		double min = ok + (1 - ok) * (b + 2); // result if hit enter and retype
		// out.println(min);
		double prob = 1;// probability of everyting ok
		for (int i = 0; i < a; i++) {// not deleting i+1 letters
			prob *= p[i];
			int hits = b - a + 1 + (2 * (a - (i + 1)));
			double x = (prob * hits) + ((1 - prob) * (hits + b + 1));
			// out.println(x);
			min = Math.min(min, x);
		}

		return min;
	}

	private double probOk(int a, int b, double[] p) {
		if (a == b) {
			double prob = 1;
			for (int i = 0; i < p.length; i++) {
				prob *= p[i];
			}
			return solveError(prob);
		} else {
			return 0;
		}
	}

	private double solveError(double x) {
//		x += 0.000000000000001;
		long y = (long) (x * 1000000);
		double z = ((double) y) / 1000000;
		return z;
	}

	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1000];
		private int curChar, numChars;

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

		public int readInt() {
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

		public long readLong() {
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

		public String readString() {
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

		private String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		public String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		public BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
	}
}
