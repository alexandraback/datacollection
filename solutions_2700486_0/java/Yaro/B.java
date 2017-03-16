import static java.lang.Math.abs;
import static java.util.Arrays.deepToString;

import java.io.*;
import java.math.*;
import java.util.*;

public class B {

	static void solve(int test) {
		int n = nextInt(), x = nextInt(), y = nextInt();
		int h = 0;
		while (n >= 4 * h + 1) {
			n -= 4 * h + 1;
			h++;
		}
		int len = 2 * h;
		if (abs(x) + y < 2 * h) {
			writer.printf("Case #%d: %f\n", test, 1.0);
			return;
		}
		if (abs(x) + y > 2 * h) {
			writer.printf("Case #%d: %f\n", test, 0.0);
			return;
		}
		int where = abs(x);
		if (where == 0) {
			writer.printf("Case #%d: %f\n", test, 0.0);
			return;
		}
		double[] pLeft = new double[len + 2];
		pLeft[0] = 1;
		for (int step = 0; step < n; step++) {
			for (int size = len; size >= 0; size--) {
				if (step - size == len) {
					pLeft[size + 1] += pLeft[size];
					pLeft[size] = 0;
				} else if (size == len) {
					// nothing
				} else {
					pLeft[size + 1] += pLeft[size] / 2;
					pLeft[size] /= 2;
				}
			}
		}
		double ans = 0;
		for (int have = len - where + 1; have <= len; have++) {
			ans += pLeft[have];
		}
		writer.printf("Case #%d: %f\n", test, ans);
	}

	public static void main(String[] args) throws Exception {
		reader = new BufferedReader(new FileReader("b.in"));
		writer = new PrintWriter("b.out");
		Locale.setDefault(Locale.US);

		setTime();
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			solve(i + 1);
		}
		printTime();
		printMemory();
		writer.close();
	}

	static BufferedReader reader;
	static PrintWriter writer;
	static StringTokenizer tok = new StringTokenizer("");
	static long systemTime;

	static void debug(Object... o) {
		System.err.println(deepToString(o));
	}

	static void setTime() {
		systemTime = System.currentTimeMillis();
	}

	static void printTime() {
		System.err.println("Time consumed: " + (System.currentTimeMillis() - systemTime));
	}

	static void printMemory() {
		System.err.println("Memory consumed: "
				+ (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1000 + "kb");
	}

	static String next() {
		while (!tok.hasMoreTokens()) {
			String w = null;
			try {
				w = reader.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (w == null)
				return null;
			tok = new StringTokenizer(w);
		}
		return tok.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static long nextLong() {
		return Long.parseLong(next());
	}

	static double nextDouble() {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() {
		return new BigInteger(next());
	}
}