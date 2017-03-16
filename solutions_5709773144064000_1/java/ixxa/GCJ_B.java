import java.io.*;
import java.util.*;

public class GCJ_B {
	public static void main(String[] args) throws Exception {
		new GCJ_B().solve();
	}

	void solve() throws IOException {
		FastScanner sc = new FastScanner(new FileInputStream("B-large.in"));
		PrintStream out = new PrintStream(new FileOutputStream(new File("output.txt")));

		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {

			double C = Double.parseDouble(sc.next());
			double F = Double.parseDouble(sc.next());
			double X = Double.parseDouble(sc.next());

			double r = 2;
			double t = 0;
			double min = time(r, X);
			while (true) {
				t += time(r, C);
				r += F;
				double gt = t + time(r, X);

				if (min < gt) {
					break;
				} else {
					min = gt;
				}
			}
			out.println("Case #" + (test + 1) + ": " + min);
		}


	}
	double time(double r, double ck) {
		return ck / r;
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
