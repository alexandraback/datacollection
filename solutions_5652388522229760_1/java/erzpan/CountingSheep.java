import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class CountingSheep {
	public static void main(String[] args) {
		FasterScanner sc = new FasterScanner("io/input.txt");
		StringBuilder sb = new StringBuilder();

		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			String ans = compute(N);
			sb.append(String.format("Case #%d: %s\n", t, ans));
			System.out.println(ans);
		}
		
		try (PrintWriter pw = new PrintWriter("io/output.txt")) {
			pw.append(sb.toString());
		} catch (FileNotFoundException e) {
			System.out.println("Error with output file!");
		}
	}
	
	private static String compute(int N) {
		if (N == 0) {
			return "INSOMNIA";
		}
		boolean[] seen = new boolean[10];
		int cnt = 0;
		for (long i = 0; ; i += N) {
			long tmp = i;
			while (tmp > 0) {
				int d = (int)(tmp % 10);
				if (!seen[d]) {
					seen[d] = true;
					cnt++;
				}
				tmp /= 10;
			}
			if (cnt == 10) {
				return Long.toString(i);
			}
		}
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