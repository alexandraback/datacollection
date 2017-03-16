import static java.lang.Math.min;
import static java.util.Arrays.deepToString;

import java.io.*;
import java.math.*;
import java.util.*;

public class A {

	static void solve(int test) {
		int us = nextInt(), n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		int ans = n;
		outer: for (int need = 0; need <= n; need++) {
			int mistakes = n - need, have = us;

			for (int pos = 0; pos < need;) {
				if (have > a[pos]) {
					have += a[pos];
					pos++;
				} else if (pos < need) {
					if (have == 1)
						continue outer;
					have = 2 * have - 1;
					mistakes++;
				}
			}
			ans = min(ans, mistakes);
		}
		writer.printf("Case #%d: %d\n", test, ans);
	}

	public static void main(String[] args) throws Exception {
		reader = new BufferedReader(new FileReader("a.in"));
		writer = new PrintWriter("a.out");

		int t = nextInt();
		for (int i = 0; i < t; i++) {
			solve(i + 1);
		}

		setTime();
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