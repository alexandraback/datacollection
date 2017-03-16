import java.io.*;
import java.util.*;

public class B {

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = nextInt();
			}
		}
		int[][] res = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = 100;
			}
		}
		boolean[] wasx = new boolean[n];
		boolean[] wasy = new boolean[m];
		for (int k = 100; k >= 1; k--) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if ((!wasx[i] || !wasy[j]) && res[i][j] >= k) {
						res[i][j] = k;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[i][j] == k) {
						wasx[i] = true;
						wasy[j] = true;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (res[i][j] != a[i][j]) {
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader("b.in"));
		out = new PrintWriter("b.out");
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			out.print("Case #" + i + ": ");
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
