import java.util.Arrays;
import java.util.Scanner;

public class Small {
	int E, R, N;
	int[] v;

	void go() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tt = 0; tt < T; tt++) {
			E = sc.nextInt();
			R = sc.nextInt();
			N = sc.nextInt();
			v = new int[N];
			for (int i = 0; i < N; i++) {
				v[i] = sc.nextInt();
			}
			solve(tt);
		}
		sc.close();
	}

	void solve(int tt) {
		long[][] dp = new long[N + 1][E + 2];
		for (int i = 1; i <= N; i++) {
			for (int j = E; j >= 0; j--) {
				if (j == E) {
					dp[i][j] = dp[i - 1][j - R];
				} else if (j >= R) {
					dp[i][j] = Math.max(dp[i - 1][j - R], dp[i][j + 1]
							+ v[i - 1]);
				} else {
					dp[i][j] = dp[i][j + 1] + v[i - 1];
				}
			}
		}
		System.out.println("Case #" + (tt + 1) + ": " + dp[N][0]);
	}

	public static void main(String[] args) throws Exception {
		new Small().go();
	}

}
