import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		new B();
	}
	B() {
		Scanner sc = null;
		PrintWriter pw = null;
		try {
			sc = new Scanner(new File("B.in"));
			pw = new PrintWriter(new File("B.out"));
		}
		catch (Exception e) {
		
		}
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int E = sc.nextInt(),
					R = sc.nextInt();
			long dp[] = new long[E + 1];
			int N = sc.nextInt();
			for (int j = 0; j < N; j++) {
				int v = sc.nextInt();
				for (int i = 1; i <= Math.min(R, E); i++) {
					dp[E] = Math.max(dp[E], dp[E - i]);
				}
				for (int i = E - 1; i >= 0; i--) {
					dp[i] = Math.max(dp[i], dp[i + 1] + v);
					if (i >= R)
						dp[i] = Math.max(dp[i], dp[i - R]);
				}
			}
			long max = 0;
			for (int i = 0; i < E + 1; i++) {
				max = Math.max(max, dp[i]);
			}
			pw.println("Case #" + t + ": " + max);
		}
		pw.close();
	}
}
