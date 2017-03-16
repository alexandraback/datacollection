import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

	static int e, r, n;
	static int[] val;
	static long[][] dp;

	static long solve(int i, int en) {
		if (en > e) {
			en = e;
			System.out.println("OBA");
		}
		if (i == n)
			return 0;
		if (dp[i][en] != -1)
			return dp[i][en];
		long ans = 0;
		for (int j = 0; j <= en; j++)
			ans = Math.max(ans, (val[i] * j) + solve(i + 1, en + r - j));
		return dp[i][en] = ans;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter("B.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			e = nxtInt();
			r = nxtInt();
			n = nxtInt();
			dp = new long[n][e + 1];
			val = new int[n];
			for (int i = 0; i < n; i++) {
				Arrays.fill(dp[i], -1);
				val[i] = nxtInt();
			}
			long ans = solve(0, e);
			out.println("Case #" + t + ": " + ans);
		}
		br.close();
		out.close();
	}

	static BufferedReader br;

	static StringTokenizer sc;

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
}