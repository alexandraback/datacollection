import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class CoinJam {
	public static void main(String[] args) {
		FasterScanner sc = new FasterScanner("io/input.txt");
		StringBuilder sb = new StringBuilder();
		
		sb.append("Case #1:\n");
		sc.nextInt();
		
		int N = sc.nextInt();
		int J = sc.nextInt();
		
		int cnt = 0;
		int[] primes = { 2, 3, 5, 7 };
		long start = 1 + (1L << (N - 1));
		long end = 1L << N;
		for (long mask = start; mask < end; mask += 2) {
			boolean pass = true;
			int[] which = new int[11];
			for (int b = 2; b <= 10; b++) {
				boolean div = false;
				for (int p : primes) {
					if (divisible(mask, N, b, p)) {
						which[b] = p;
						div = true;
						break;
					}
				}
				if (!div) {
					pass = false;
					break;
				}
			}
			if (pass) {
				sb.append(toBinary(mask, N));
				for (int b = 2; b <= 10; b++) {
					sb.append(" " + which[b]);
				}
				sb.append("\n");
				cnt++;
				if (cnt >= J) {
					break;
				}
			}
		}
		
		try (PrintWriter pw = new PrintWriter("io/output.txt")) {
			pw.append(sb.toString());
		} catch (FileNotFoundException e) {
			System.out.println("Error with output file!");
		}
	}
	
	private static boolean divisible(long mask, int bits, int base, int p) {
		long sum = 0;
		long mod = 1;
		for (int i = 0; i < bits; i++) {
			long d = mask & 1;
			sum = (sum + d * mod) % p;
			mod = (mod * base) % p;
			mask >>= 1;
		}
		return (sum == 0);
	}
	
	private static String toBinary(long mask, int bits) {
		char[] arr = new char[bits];
		for (int i = bits - 1; i >= 0; i--) {
			arr[i] = (char)((mask & 1) + '0');
			mask >>= 1;
		}
		return new String(arr);
	}

	public static class FasterScanner {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private InputStream stream;
		
		public FasterScanner(String file) {
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