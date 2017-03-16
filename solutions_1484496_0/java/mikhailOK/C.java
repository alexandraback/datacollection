import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		int testCases = nextInt();
		for (int test = 1; test <= testCases; test++) {
			out.println("Case #" + test + ":");
			solveOneTest();
		}
	}

	private static void solveOneTest() throws IOException {
		int n = nextInt();
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextInt();
		}
		int answer1 = -1;
		int answer2 = -1;
		all: for (int mask1 = 1; mask1 < 1 << n; mask1++) {
			for (int mask2 = mask1 - 1 & mask1; mask2 > 0; mask2 = mask2 - 1 & mask1) {
				int ok = 0;
				for (int i = 0; i < n; i++) {
					if ((mask1 & (1 << i)) != 0) {
						if ((mask2 & (1 << i)) != 0) {
							ok += s[i];
						} else {
							ok -= s[i];
						}
					}
				}
				if (ok == 0) {
					answer1 = mask2;
					answer2 = mask1 ^ mask2;
					break all;
				}

			}
		}
		if (answer1 < 0) {
			out.println(" Impossible");
		} else {
			boolean first = true;
			for (int i = 0; i < n; i++) {
				if ((answer1 & (1 << i)) != 0) {
					if (!first) {
						out.print(' ');
					} else {
						first = false;
					}
					out.print(s[i]);
				}
			}
			out.println();
			first = true;
			for (int i = 0; i < n; i++) {
				if ((answer2 & (1 << i)) != 0) {
					if (!first) {
						out.print(' ');
					} else {
						first = false;
					}
					out.print(s[i]);
				}
			}
			out.println();
		}
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("c.in"));
			out = new PrintWriter("c.out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null)
				return null;
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}