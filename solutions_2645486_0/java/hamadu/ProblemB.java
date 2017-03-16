import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemB {

	static final String YES = "YES";
	static final String NO = "NO";
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			int E = in.nextInt();
			int R = in.nextInt();
			int N = in.nextInt();
			int[] a = new int[N];
			for (int i = 0 ; i < N ; i++) {
				a[i] = in.nextInt();
			}
			out.println(String.format("Case #%d: %s", cn, solve(E, R, a)));
		}
		out.flush();
	}
	
	private static int solve(int E, int R, int[] a) {
		int n = a.length;
		int[][] dp = new int[n+1][E+1];
		for (int i = 0 ; i <= n ; i++) {
			Arrays.fill(dp[i], -1);
		}
		dp[0][E] = 0;
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j <= E ; j++) {
				if (dp[i][j] == -1) {
					continue;
				}
				for (int use = 0 ; use <= j ; use++) {
					int tj = Math.min(E, j-use+R);
					dp[i+1][tj] = Math.max(dp[i+1][tj], dp[i][j]+a[i]*use);
				}
			}
		}
		
		int ret = 0;
		for (int i = 0 ; i <= E ; i++) {
			ret = Math.max(ret, dp[n][i]);
		}
		return ret;
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
