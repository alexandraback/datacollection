import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static int n;
	static int[] dp;

	static int reverse(int x) {
		int res = 0;
		while (x > 0) {
			res = (res * 10) + (x % 10);
			x /= 10;
		}
		return res;
	}

	static int solve(int x) {
		if (x == 1)
			return 1;
		if (dp[x] != -1)
			return dp[x];
		int rev = reverse(x);
		int ans = 1 + solve(x - 1);
		if (rev < x && x % 10 != 0)
			ans = Math.min(ans, 1 + solve(rev));
		return dp[x] = ans;
	}

	// static int naive(int x) {
	// int cnt = 0;
	// while (x > 0) {
	// if (x % 10 != 0) {
	// int y = reverse(x);
	// if (y < x) {
	// x = y;
	// cnt++;
	// } else {
	// x--;
	// cnt++;
	// }
	// } else {
	// cnt++;
	// x--;
	// }
	//
	// }
	// return cnt;
	// }

	public static void main(String[] args) throws IOException {
		dp = new int[1000001];
		dp[1] = 1;
		for (int i = 2; i <= 1000000; i++) {
			dp[i] = 1 + dp[i - 1];
			int rev = reverse(i);
			if (rev < i && i % 10 != 0)
				dp[i] = Math.min(dp[i], 1 + dp[rev]);
		}
		br = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter("A.out");
		sc = new StringTokenizer("");
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			int n = nxtInt();
			System.out.println("Case #" + t + ": " + dp[n]);
			out.println("Case #" + t + ": " + dp[n]);
		}
		br.close();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer sc;
	static PrintWriter out;

	static String nxtTok() throws IOException {
		while (!sc.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null)
				return null;
			sc = new StringTokenizer(s.trim());
		}
		return sc.nextToken();
	}

	static int nxtInt() throws IOException {
		return Integer.parseInt(nxtTok());
	}

	static long nxtLng() throws IOException {
		return Long.parseLong(nxtTok());
	}

	static double nxtDbl() throws IOException {
		return Double.parseDouble(nxtTok());
	}

	static int[] nxtIntArr(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nxtInt();
		return a;
	}

	static long[] nxtLngArr(int n) throws IOException {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nxtLng();
		return a;
	}

	static char[] nxtCharArr() throws IOException {
		return nxtTok().toCharArray();
	}
}