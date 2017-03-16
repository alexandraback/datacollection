import java.io.*;
import java.util.*;

public class ProblemB {
	static Scanner scan = new Scanner(System.in);
	static PrintStream out = System.out;
	static int E, R, N;
	static int[] V;
	static void test () {
		E = scan.nextInt();
		R = scan.nextInt();
		N = scan.nextInt();
		V = new int[N];
		for (int i = 0; i < N; ++i)
			V[i] = scan.nextInt();
		long[][] dp = new long[E+1][N];
		
		for (int i = 0; i <= E; ++i)
			dp[i][N-1] = i * V[N-1];
		for (int j = N - 2; j >= 0; --j) {
			for (int i = 0; i <= E; ++i) {
				for (int k = 0; k <= i; ++k) {
					int t = i - k + R;
					t = Math.min(t, E);
					if (t < 0)
						continue;
					dp[i][j] = Math.max (dp[i][j], dp[t][j+1] + k * V[j]);
				}
			}
		}

		out.println(dp[E][0]);
		
	}
	
	public static void main (String[] args) {
		int T = scan.nextInt();
		for (int i = 1; i <= T; ++i) {
			out.print("Case #" + i + ": ");
			test();
		}
	}
}
