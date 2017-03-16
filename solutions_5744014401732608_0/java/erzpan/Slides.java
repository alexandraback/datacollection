import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class Slides {
	public static void main(String[] args) {
		FileScanner sc = new FileScanner("io/input.txt");
		StringBuilder sb = new StringBuilder();

		int T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			int B = sc.nextInt();
			long M = sc.nextLong();
			long maxSlides = (1L << (B - 2));
			if (M > maxSlides) {
				sb.append(String.format("Case #%d: IMPOSSIBLE\n", t));
			} else {
				int[][] slide = new int[B][B];
				for (int i = 1; i < B; i++) {
					for (int j = i + 1; j < B; j++) {
						slide[i][j] = 1;
					}
				}
				if (M == maxSlides) {
					for (int i = 1; i < B; i++) {
						slide[0][i] = 1;
					}
				} else {
					long rem = M;
					for (int i = B - 2; i >= 1; i--) {
						int d = (int)(rem % 2);
						slide[0][i] = d;
						rem /= 2;
					}
				}
				sb.append(String.format("Case #%d: POSSIBLE\n", t));
				for (int i = 0; i < B; i++) {
					for (int j = 0; j < B; j++) {
						sb.append(slide[i][j]);
					}
					sb.append("\n");
				}
			}
		}

		try (PrintWriter pw = new PrintWriter("io/output.txt")) {
			pw.append(sb.toString());
		} catch (FileNotFoundException e) {
			System.out.println("Error with output file!");
		}
	}

	public static class Party implements Comparable<Party> {
		public char type;
		public int count;

		public Party(char t, int c) {
			this.type = t;
			this.count = c;
		}

		public int compareTo(Party p) {
			return -Integer.compare(this.count, p.count);
		}
	}

	public static class FileScanner {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private InputStream stream;

		public FileScanner(String file) {
			try {
				stream = new FileInputStream(file);
			} catch (FileNotFoundException e) {
				System.out.println("Error with input file!");
			}
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

		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public String nextString() {
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

		public int[] nextIntArray(int n) {
			return nextIntArray(n, 0);
		}

		public int[] nextIntArray(int n, int off) {
			int[] arr = new int[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextInt();
			}
			return arr;
		}

		public long[] nextLongArray(int n) {
			return nextLongArray(n, 0);
		}

		public long[] nextLongArray(int n, int off) {
			long[] arr = new long[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextLong();
			}
			return arr;
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}
}