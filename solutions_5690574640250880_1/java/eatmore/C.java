import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int r = nextInt();
		int c = nextInt();
		int f = r * c - nextInt();
		boolean flip = r > c;
		if (flip) {
			int t = r;
			r = c;
			c = t;
		}
		boolean map[][] = new boolean[r][c];
		if (r == 1 || f == 1) {
			fill(map[0], 0, f, true);
		} else if (f < 4 || (r == 2 && f % 2 != 0)) {
			map = null;
		} else if (f % 2 == 0 && f <= 2 * c) {
			fill(map[0], 0, f / 2, true);
			fill(map[1], 0, f / 2, true);
		} else if (f < 9 && f % 2 != 0) {
			map = null;
		} else if (f % 2 == 1 && f <= 2 * c + 3) {
			fill(map[0], 0, (f - 3) / 2, true);
			fill(map[1], 0, (f - 3) / 2, true);
			fill(map[2], 0, 3, true);
		} else {
			int i;
			for (i = 0; f >= c + 2; i++, f -= c) {
				fill(map[i], true);
			}
			if (f <= c) {
				fill(map[i], 0, f, true);
			} else {
				fill(map[i], 0, c - 1, true);
				fill(map[i + 1], 0, 2, true);
			}
		}
		if (flip) {
			int t = r;
			r = c;
			c = t;
		}
		printlnCase();
		if (map == null) {
			out.println("Impossible");
		} else {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					out.print(i == 0 && j == 0 ? 'c' : (flip ? map[j][i] : map[i][j]) ? '.' : '*');
				}
				out.println();
			}
		}
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}