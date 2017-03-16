package r1a2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int e = in.nextInt();
			E = e;
			r = in.nextInt();
			int n = in.nextInt();
			v = new int[n];
			for (int i = 0; i < n; i++) v[i] = in.nextInt();
			memo = new int[n][e+1];
			for (int[] mm : memo) Arrays.fill(mm, -1);
			out.println(solve(0, e));
			//out.println(e + " " + r + " " + Arrays.toString(v));
		}

		out.flush();
	}

	static int r, E;
	static int[] v;
	static int[][] memo;
	
	static int solve(int p, int e) {
		if (p >= v.length) return 0;
		if (memo[p][e] != -1) return memo[p][e];
		int ans = 0;
		for (int i = 0; i <= e; i++) {
			int cur = i*v[p] + solve(p+1, Math.min(E, e - i + r));
			if (cur > ans) ans = cur;
		}
		return memo[p][e] = ans;
	}
}
