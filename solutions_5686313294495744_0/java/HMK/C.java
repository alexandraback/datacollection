package feb_long_2016;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.InputMismatchException;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		FasterScanner in = new FasterScanner();
		PrintWriter out = new PrintWriter(new File("output.txt"));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int n = in.nextInt();
			int[] leftNodes = new int[n];
			int[] rightNodes = new int[n];
			int countLeft = 0;
			int countRight = 0;
			HashMap<String, Integer> mapLeft = new HashMap<>();
			HashMap<String, Integer> mapRight = new HashMap<>();
			for (int i = 0; i < n; i++) {
				String left = in.nextString();
				String right = in.nextString();
				if (!mapLeft.containsKey(left)) {
					mapLeft.put(left, countLeft++);
				}
				leftNodes[i] = mapLeft.get(left);
				if (!mapRight.containsKey(right)) {
					mapRight.put(right, countRight++);
				}
				rightNodes[i] = mapRight.get(right);
			}
			int totalNodes = countLeft + countRight;
			int min = (int) 1e9;
			outer: for (int val = 0; val < (1 << n); val++) {
				boolean[] doneLeft = new boolean[countLeft];
				boolean[] doneRight = new boolean[countRight];
				int count = 0;
				for (int i = 0; i < n; i++) {
					if ((val & (1 << i)) != 0) {
						doneLeft[leftNodes[i]] = true;
						doneRight[rightNodes[i]] = true;
						count++;
					}
				}
				for (int i = 0; i < countLeft; i++) {
					if (!doneLeft[i])
						continue outer;
				}
				for (int i = 0; i < countRight; i++) {
					if (!doneRight[i])
						continue outer;
				}
				min = Math.min(min, count);
			}
			int ans = n-min;
			System.out.println("Case #" + t + ": " + ans);
		}
		out.close();
	}
	static class FasterScanner {

		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public int read() {
			if (numChars == -1) {
				throw new InputMismatchException();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = System.in.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0) {
					return -1;
				}
			}
			return buf[curChar++];
		}

		public String nextLine() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9') {
					throw new InputMismatchException();
				}
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9') {
					throw new InputMismatchException();
				}
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
			}
			return arr;
		}

		public long[] nextLongArray(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextLong();
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

