import java.util.*;
import java.io.*;

public class BoxFactory {

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	
	public static void main(String[] args) throws IOException {
		new BoxFactory().run();
	}
	
	void run() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		int T = nextInt();
		for (int tt = 1; tt <= T; ++tt) {
			int n = nextInt();
			int m = nextInt();
			
			long[][] l1 = new long[n][2];
			long[][] l2 = new long[m][2];
			for (int i = 0; i < n; i++) {
				l1[i][0] = nextLong();
				l1[i][1] = nextLong();
			}
			for (int i = 0; i < m; i++) {
				l2[i][0] = nextLong();
				l2[i][1] = nextLong();
			}
			
			long[][] dp = new long[n + 1][m + 1];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					dp[i][j] = Math.max(dp[i][j - 1], Math.max(dp[i - 1][j], dp[i - 1][j - 1]));
					if (l1[i - 1][1] == l2[j - 1][1]) {
						// dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + Math.min(l1[i - 1][0], l2[j - 1][0]));
						long c = Math.min(l1[i - 1][0], l2[j - 1][0]);
						if (c > 0) {
							l1[i - 1][0] -= c;
							l2[j - 1][0] -= c;
							dp[i][j] += c;
						}
					}
				}
			}
			
			/* for (int[] d : dp) {
				out.println(Arrays.toString(d));
			} */
			
			out.printf("Case #%d: %d\n", tt, dp[n][m]);
		}
		
		out.close();
	}
	
	String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
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
