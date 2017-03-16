package qual2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class D
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("D.out"));
	
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int k = in.nextInt();
			n = in.nextInt();
			int[] keys = new int[K+1];
			for (int i = 0; i < k; i++) keys[in.nextInt()]++;
			g = new int[n];
			v = new int[n][];
			for (int i = 0; i < n; i++) {
				g[i] = in.nextInt();
				v[i] = new int[in.nextInt()];
				for (int j = 0; j < v[i].length; j++) v[i][j] = in.nextInt();
			}
			b = new boolean[1 << n];
			String ans = go(0, keys);
			out.println(ans == null ? "IMPOSSIBLE" : ans);
		}
		
		out.flush();
	}

	static final int K = 200;
	
	static int n;
	static int[] g;
	static int[][] v;
	static boolean[] b;
	
	static String go(int mask, int[] keys) {
		if (Integer.bitCount(mask) == n) return "";
		if (b[mask]) return null;
		
		b[mask] = true;
		
		for (int i = 0; i < n; i++) {
			if ((mask&(1 << i)) == 0 && keys[g[i]] > 0) {
				keys[g[i]]--;
				for (int k : v[i]) keys[k]++;
				String cur = go(mask|(1 << i), keys);
				keys[g[i]]++;
				for (int k : v[i]) keys[k]--;
				if (cur != null) {
					return (i+1) + " " + cur;
				}
			}
		}
		
		return null;
	}
}
