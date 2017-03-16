import java.io.*;
import java.util.*;

public class GCJ_B {
	public static void main(String[] args) throws Exception {
		new GCJ_B().solve();
	}
	String iname = "B-large (2).in";
	String oname = "output.txt";
	FastScanner sc;
	PrintStream out;
	void solve() throws IOException {
		sc = new FastScanner(new FileInputStream(iname));
		out = new PrintStream(new FileOutputStream(new File(oname)));

		int T = sc.nextInt();
		for (int _t = 0; _t < T; _t++) {
			long A = sc.nextInt() - 1;
			long B = sc.nextInt() - 1;
			long K = sc.nextInt() - 1;

			int bN = 33;
			long[][][][] dp = new long[bN][2][2][2];
			for (int bi = 0; bi < bN; bi++) {

				for (int kf = 0; kf < 2; kf++) {
					for (int af = 0; af < 2; af++) {
						for (int bf = 0; bf < 2; bf++) {
							for (int aa = 0; aa < 2; aa++) {
								for (int bb = 0; bb < 2; bb++) {

									if (((af & aa & (A >> bi & 1 ^ 1)) | (bf & bb & (B >> bi & 1 ^ 1))) == 1) {
										// ng
										// System.out.println();
									} else if ((kf & aa & bb & (K >> bi & 1 ^ 1)) == 1) {
										// ng
										// System.out.println();
									} else {
										if (bi == 0) {
											dp[bi][kf][af][bf] += 1;
										} else {

											int nkf = (int) (kf & (aa & bb ^ ~(K >> bi & 1)));
											int naf = (int) (af & (aa ^ ~(A >> bi & 1)));
											int nbf = (int) (bf & (bb ^ ~(B >> bi & 1)));

											dp[bi][kf][af][bf] += dp[bi - 1][nkf][naf][nbf];


										}
									}
								}
							}
						}
					}
				}
			}

			gout(_t, "" + dp[bN - 1][1][1][1]);
		}
	}
	void gout(int t, String ans) {
		out.println("Case #" + (t + 1) + ": " + ans);
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
//
//
//
//
//
//
//
