import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * @author Mikeldi Latorre (mikeldi10@gmail.com)
 */
public class Kingdom implements Runnable {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		new Thread(new Kingdom()).start();
	}

	public Kingdom() {
		try {
			System.setIn(new FileInputStream("kingdom.in"));
			System.setOut(new PrintStream(new FileOutputStream("kingdom.out")));
		} catch (FileNotFoundException e) {
			throw new RuntimeException();
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	public void run() {
		int numTests = in.readInt();
		for (int testNumber = 0; testNumber < numTests; testNumber++) {
			out.println("Case #" + (testNumber + 1) + ": " + algorithm());
		}
		out.close();
	}

	private String algorithm() {
		int n = in.readInt();
		int[][] need = new int[n][2];
		boolean[][] stars = new boolean[n][2];
		int plays = 0;
		int totalStars = 0;
		for (int i = 0; i < n; i++) {
			need[i][0] = in.readInt();
			need[i][1] = in.readInt();
			stars[i][0] = false;
			stars[i][1] = false;
		}
		int newStars=0;
		do {
			newStars = 0;
			for (int i = 0; i < n; i++) {
				if ((!stars[i][1]) && (totalStars >= need[i][1])) {
					plays++;
					newStars++;
					if (!stars[i][0])
						newStars++;
					stars[i][1] = true;
					stars[i][0] = true;
				}
			}
			if(newStars==0){
				for (int i = 0; i < n; i++) {
					if ((!stars[i][0]) && (totalStars >= need[i][0])) {
						plays++;
						newStars++;
						stars[i][0] = true;
						break;
					}
				}
			}
			totalStars += newStars;
		} while ((totalStars < 2*n) && (newStars!=0));

		if(totalStars == 2*n)
			return ""+plays;
		return "Too Bad";
		
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
