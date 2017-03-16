import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

	static class chest {
		int x;
		ArrayList<Integer> al = new ArrayList<Integer>();
	}

	static int n;
	static int[] key = new int[205];
	static chest[] a = new chest[25];
	static int[] dp = new int[1 << 20];
	static int[] p = new int[1 << 20];

	static int solve(int mask) {
		if (mask == (1 << n) - 1)
			return 1;
		if (dp[mask] != -1)
			return dp[mask];
		int[] tmp = Arrays.copyOf(key, 205);
		for (int i = 0; i < n; i++)
			if ((mask & (1 << i)) != 0) {
				tmp[a[i].x]--;
				for (int j = 0; j < a[i].al.size(); j++)
					tmp[a[i].al.get(j)]++;
			}
		for (int i = 0; i < n; i++)
			if ((mask & (1 << i)) == 0 && tmp[a[i].x] > 0) {
				int nans = solve(mask | (1 << i));
				if (nans == 1) {
					p[mask] = i;
					return dp[mask] = 1;
				}
			}
		return dp[mask] = 0;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("D.in"));
		PrintWriter out = new PrintWriter("D.out");
		sc = new StringTokenizer(br.readLine());
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			int k = nxtInt();
			n = nxtInt();
			Arrays.fill(key, 0);
			for (int i = 0; i < k; i++)
				key[nxtInt()]++;
			for (int i = 0; i < n; i++) {
				a[i] = new chest();
				a[i].x = nxtInt();
				int tmp = nxtInt();
				while (tmp-- > 0)
					a[i].al.add(nxtInt());
			}
			Arrays.fill(dp, -1);
			int ans = solve(0);
			if (ans == 0)
				out.println("Case #" + t + ": IMPOSSIBLE");
			else {
				int mask = 0;
				out.print("Case #" + t + ":");
				while (mask != (1 << n) - 1) {
					out.print(" " + (p[mask] + 1));
					mask |= (1 << p[mask]);
				}
				out.println();
			}
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