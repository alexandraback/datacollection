import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class B_ManageYourEnergy {
	
//	static final int INF = 1 << 28, MAX = 10000001, MAXN = 10001;
	static final int INF = 1 << 28, MAX = 11, MAXN = 11;
	static final double EPS = 1E-9;
	
	static long[][] dp = new long[MAXN][MAX];
	static long[] v = new long[MAXN];
	
	static void solve() {
		Scanner scan = new Scanner(in);
		int T = scan.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			long E = scan.nextLong();
			int R = scan.nextInt();
			int N = scan.nextInt();
			for (int i = 0; i < N; i++)
				v[i] = scan.nextLong();
			
			for (int i = 0; i <= E; i++)
				dp[0][i] = v[0] * (E - i);
			for (int n = 1; n < N; n++)
				for (int e = 0; e <= E; e++) {
					dp[n][e] = 0;
					for (int i = Math.max(0, e - R); i <= E; i++) {
						long w = Math.min(E, i + R);
						dp[n][e] = Math.max(dp[n][e], dp[n-1][i] + (w - e) * v[n]);
					}
				}
			
			long max = 0;
			for (int i = 0; i <= E; i++)
				max = Math.max(max, dp[N-1][i]);
			out.println(max);
		}
	}
	
	static String read() {
		try { return in.readLine(); } catch (IOException e) { return null; }
	}
	public static void main(String[] args) throws IOException {
//		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(new BufferedOutputStream(System.out));
		String file = "B-small";
		in = new BufferedReader( new FileReader(file + ".in") );
		out = new PrintWriter( new FileOutputStream(file + "_" + System.currentTimeMillis() + ".out") );
		solve(); out.flush();
	}
	static BufferedReader in; static PrintWriter out;
}
