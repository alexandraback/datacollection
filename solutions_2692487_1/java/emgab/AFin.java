import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class AFin {

	static int[] a;
	static int[][] dp;

	static int solve(int i, int s) {
		if (s > a[a.length - 1])
			s = a[a.length - 1] + 2;
		if (i == a.length)
			return 0;
		if (dp[i][s] != -1)
			return dp[i][s];
		if (s > a[i])
			return dp[i][s] = solve(i + 1, s + a[i]);
		int remove = 1 + solve(i + 1, s);
		int ns = s;
		int cc = 0;
		int tmp = Integer.MAX_VALUE;
		if (ns != 1) {
			while (ns <= a[i]) {
				ns += ns - 1;
				cc++;
			}
			tmp = cc + solve(i + 1, ns + a[i]);
		}
		return dp[i][s] = Math.min(remove, tmp);
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter("A.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			int s = nxtInt();
			int n = nxtInt();
			a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nxtInt();
			Arrays.sort(a);
			dp = new int[n][a[n - 1] + 5];
			for (int i = 0; i < n; i++)
				Arrays.fill(dp[i], -1);
			out.println("Case #" + t + ": " + solve(0, s));
			System.out.println("Case #" + t + ": " + solve(0, s));
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