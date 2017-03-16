package gcj.c2016.r1c;


import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class B implements Runnable {

	public void run() {
		int tests = nextInt();
		for (int iter = 1; iter <= tests; ++iter) {
			int b = nextInt();
			long m = nextInt();

			boolean[][] f = new boolean[b][b];
			int pow = 0;
			int cb = b;
			while (cb - 1 > 0) {
				pow += cb - 1;
				--cb;
			}
			boolean found = false;
			for (int i = 0; i < (1<<(pow)); ++i) {
				for (int j = 0; j < pow; ++j) {
					int src = 0;
					int dest = 0;
					int cur = -1;
					for (src = 0; src < b; ++src) {
						for (dest = src+1; dest < b; ++dest) {
							++cur;
							if (cur == j) {
								break;
							}

						}
						if (cur == j) {
							break;
						}
					}
					if ((i & (1<<j)) != 0) {
						f[src][dest] = true;
					} else {
						f[src][dest] = false;
					}

				}

				long[] dp = new long[b];
				dp[0] = 1;
				for (int pos = 0; pos < b; ++pos) {
					for (int next = 0; next < b; ++next) {
						if (f[pos][next]) {
							dp[next] += dp[pos];
						}
					}
				}

				if (dp[b-1] == m) {
					found = true;
					break;
				}
			}
			if (found) {
				out.println("Case #" + iter +": POSSIBLE");
				for (int i = 0; i < b; ++i) {
					for (int j = 0; j < b; ++j) {
						out.print(f[i][j] ? "1" : "0");
					}
					out.println();
				}
			} else {
				out.println("Case #" + iter +": IMPOSSIBLE");
			}

		}
		out.flush();
	}

	private static BufferedReader br = null;
	private static PrintWriter out = null;
	private static StringTokenizer stk = null;
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("B.txt")));
		out = new PrintWriter("BB.txt");
		(new B()).run();
	}

	private void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

	private String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	private int nextInt() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}

	private long nextLong() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Long.parseLong(stk.nextToken());
	}

	private double nextDouble() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}

	private String nextWord() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return (stk.nextToken());
	}
}
