import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class A {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #"+test+": ");
			int n = nextInt();
			int[]dp = new int[n+1];
			dp[1] = 1;
			for (int i = 2; i <= n; i++) {
				dp[i] = dp[i-1] + 1;
				int rev = rev(i);
				if (rev < i)
					dp[i] = Math.min(dp[i], dp[rev]+1);
			}
			pw.println(dp[n]);
		}
		pw.close();
	}

	private static int rev(int n) {
		int res = 0;
		if (n % 10==0)
			return 1000000000;
		while (n > 0) {
			res = res * 10 + n % 10;
			n /= 10;
		}
		return res;
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
