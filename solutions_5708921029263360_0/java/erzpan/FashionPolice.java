import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;

public class FashionPolice {
	public static void main(String[] args) {
		FileScanner sc = new FileScanner("io/input.txt");
		StringBuilder sb = new StringBuilder();
		
		int T = sc.nextInt();
		
		for (int t = 1; t <= T; t++) {
			int[] W = sc.nextIntArray(3);
			int K = sc.nextInt();
			int[] C = new int[3];
			int[][] x01 = new int[W[0]][W[1]];
			int[][] x02 = new int[W[0]][W[2]];
			int[][] x12 = new int[W[1]][W[2]];
			StringBuilder str = new StringBuilder();
			int cnt = 0;
			do {
				if (x01[C[0]][C[1]] < K && x02[C[0]][C[2]] < K && x12[C[1]][C[2]] < K) {
					x01[C[0]][C[1]]++;
					x02[C[0]][C[2]]++;
					x12[C[1]][C[2]]++;
					str.append(String.format("%d %d %d\n", C[0] + 1, C[1] + 1, C[2] + 1));
					cnt++;
				}
			} while(incr(C, W));
			sb.append(String.format("Case #%d: %d\n", t, cnt));
			sb.append(str.toString());
		}
		
		try (PrintWriter pw = new PrintWriter("io/output.txt")) {
			pw.append(sb.toString());
		} catch (FileNotFoundException e) {
			System.out.println("Error with output file!");
		}
	}
	
	private static boolean incr(int[] C, int[] W) {
		C[2]++;
		C[1] += C[2] / W[2];
		C[2] %= W[2];
		C[0] += C[1] / W[1];
		C[1] %= W[1];
		return C[0] < W[0];
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