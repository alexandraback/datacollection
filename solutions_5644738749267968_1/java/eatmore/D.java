import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static int solve(double a[], double b[]) {
		int n = a.length;
		int ans = 0;
		boolean used[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			double key = a[i];
			int cur = -1;
			double curVal = key;
			for (int j = 0; j < n; j++) {
				if (used[j]) {
					continue;
				}
				if ((b[j] > key && !(curVal > key)) || ((b[j] > key) == (curVal > key) && b[j] < curVal)) {
					cur = j;
					curVal = b[j];
				}
			}
			if (curVal > key) {
				++ans;
			}
			used[cur] = true;
		}
		return ans;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		double a[] = new double[n];
		double b[] = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextDouble();
		}
		for (int i = 0; i < n; i++) {
			b[i] = nextDouble();
		}
		printCase();
		out.println(solve(b, a) + " " + (n - solve(a, b)));
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