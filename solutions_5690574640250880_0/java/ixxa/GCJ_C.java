import java.io.*;
import java.math.*;
import java.util.*;

public class GCJ_C {

	public static void main(String[] args) throws Exception {
		new GCJ_C().solve();
	}

	void solve() throws IOException {
		FastScanner sc = new FastScanner(new FileInputStream("C-small-attempt1.in"));
		PrintStream out = new PrintStream(new FileOutputStream(new File("output.txt")));

		int T = sc.nextInt();
		L:
		for (int test = 0; test < T; test++) {
			out.println("Case #" + (test + 1) + ":");

			int R = sc.nextInt();
			int C = sc.nextInt();
			int M = sc.nextInt();
			int S = R * C - M;

			char[][] ch = new char[R][C];
			for (int r = 0; r < R; r++) {
				Arrays.fill(ch[r], '*');
			}

			// S==1
			if (S == 1) {
				chout(out, ch);
				check(ch, M);
				continue L;
			}
			if (R == 1) {
				for (int cc = 0; cc < S; cc++) {
					ch[0][cc] = '.';
				}
				chout(out, ch);
				check(ch, M);
				continue L;
			}
			if (C == 1) {
				for (int rr = 0; rr < S; rr++) {
					ch[rr][0] = '.';
				}
				chout(out, ch);
				check(ch, M);
				continue L;
			}

			// r*c
			for (int r = 2; r <= R; r++) {
				for (int c = 2; c <= C; c++) {
					if (r * c == S) {
						// ok
						for (int rr = 0; rr < r; rr++) {
							for (int cc = 0; cc < c; cc++) {
								ch[rr][cc] = '.';
							}
						}
						chout(out, ch);

						check(ch, M);
						continue L;
					}
				}
			}

			// r1, r2, c1, c2
			for (int r1 = 2; r1 <= R; r1++) {
				for (int r2 = 2; r2 <= r1 - 1; r2++) {
					for (int c1 = 2; c1 <= C; c1++) {
						for (int c2 = 2; c2 <= c1 - 1; c2++) {
							if ((r1 - 1) * (c1 - 1) + r2 + c2 == S) {
								// ok

								for (int rr = 0; rr < r1 - 1; rr++) {
									for (int cc = 0; cc < c1 - 1; cc++) {
										ch[rr][cc] = '.';
									}
								}
								for (int rr = 0; rr < r2; rr++) {
									ch[rr][c1 - 1] = '.';
								}
								for (int cc = 0; cc < c2; cc++) {
									ch[r1 - 1][cc] = '.';
								}

								chout(out, ch);

								check(ch, M);

								continue L;
							}
						}
					}
				}
			}
			out.println("Impossible");

		}
	}
	void chout(PrintStream out, char[][] ch) {
		ch[0][0] = 'c';
		for (int i = 0; i < ch.length; i++) {
			out.println(String.valueOf(ch[i]));
		}
	}
	void check(char[][] ch, int m) {
		int count = 0;
		for (int r = 0; r < ch.length; r++) {
			for (int c = 0; c < ch[0].length; c++) {
				if (ch[r][c] == '*') {
					count++;
				}
			}
		}
		if (m != count) {
			System.out.println("NG!!!!");
		}
	}


	class FastScanner {

		private InputStream _stream;
		private byte[] _buf = new byte[1024];
		private int _curChar;
		private int _numChars;
		private StringBuilder _sb = new StringBuilder();

		FastScanner(InputStream stream) {
			this._stream = stream;
		}

		public int read() {
			if (_numChars == -1) throw new InputMismatchException();
			if (_curChar >= _numChars) {
				_curChar = 0;
				try {
					_numChars = _stream.read(_buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (_numChars <= 0) return -1;
			}
			return _buf[_curChar++];
		}

		public String next() {
			int c = read();
			while (isWhitespace(c)) {
				c = read();
			}
			_sb.setLength(0);
			do {
				_sb.appendCodePoint(c);
				c = read();
			} while (!isWhitespace(c));
			return _sb.toString();
		}

		public int nextInt() {
			return (int) nextLong();
		}
		public long nextLong() {
			int c = read();
			while (isWhitespace(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9') throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isWhitespace(c));
			return res * sgn;
		}

		public boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	}
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
