import java.io.*;
import java.util.*;

public class B {

	void solve() throws IOException {
		int n = nextInt();
		int x = nextInt();
		int y = nextInt();
		int st = 1;
		while (st * (st + 1) / 2 <= n) {
			st += 2;
		}
		st -= 2;
		n -= st * (st + 1) / 2;
		if (Math.abs(x) + Math.abs(y) <= st) {
			out.println(1);
			return;
		}
		if (Math.abs(x) + Math.abs(y) > st + 1) {
			out.println(0);
			return;
		}
		st += 2;
		double[][] dp = new double[n + 1][st + 10];
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= st - 1; j++) {
				int left = j;
				int right = i - j;
				double p1 = 0.5;
				double p2 = 0.5;
				if (left == st - 1) {
					p1 = 0;
					p2 = 1;
				}
				if (right == st - 1) {
					p1 = 1;
					p2 = 0;
				}
				dp[i + 1][j] += dp[i][j] * p2;
				dp[i + 1][j + 1] += dp[i][j] * p1;
			}
		}
		double res = 0;
		for (int j = y + 1; j <= st - 1; j++) {
			res += dp[n][j];
		}
		out.println(res);

	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader("B.in"));
		out = new PrintWriter("B.out");
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve();
		}
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer str;
	PrintWriter out;

	String next() throws IOException {
		while (str == null || !str.hasMoreTokens()) {
			String s = br.readLine();
			if (s != null) {
				str = new StringTokenizer(s);
			} else {
				return null;
			}
		}
		return str.nextToken();
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

}
