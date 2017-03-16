import java.io.*;
import java.util.*;
import java.math.*;


public class Main implements Runnable {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int N = (int)1e6;
	static int[] dp;
	
	static void solve() throws Exception {
		dp = new int[N + 1];
		for (int i = 1; i <= N; ++i) {
			dp[i] = Integer.MAX_VALUE;
		}
		dp[1] = 1;
		int t = nextInt();
		for (int tt = 1; tt <= t; ++tt) {
			out.println("Case #" + tt + ": " + f(nextInt()));
		}
	}
	
	static int f(int n) {
		if (dp[n] == Integer.MAX_VALUE) {			
			dp[n] = f(n - 1) + 1;
			if (n % 10 != 0) {
				int rev = reverse(n);
				if (rev < n) {
					dp[n] = Math.min(f(rev) + 1, dp[n]);
				}
			}
		}
		return dp[n];
	}
	
	static int reverse(int n) {
		int res = 0;
		while (n > 0) {
			res = res * 10 + (n % 10);
			n /= 10;
		}
		return res;
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() throws IOException {
		return new BigInteger(next());
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static String nextLine() throws IOException {
		tok = new StringTokenizer("");
		return in.readLine();
	}

	static boolean hasNext() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null) {
				return false;
			}
			tok = new StringTokenizer(s);
		}
		return true;
	}
	
	public static void main(String args[]) {
		new Thread(null, new Main(), "Main", 1 << 28).start();
	}
	
	public void run() {
		try {
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("input.in"));
			out = new PrintWriter(new FileWriter("output.out"));
			Locale.setDefault(Locale.US);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			java.lang.System.exit(1);
		}
	}
}