import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Treasure {

	private static int k;
	private static int n;
	private static int[] start;
	private static int[] type;
	private static int[][] keys;
	private static int[] dp;
	private static int[] parent;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("D-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new File("D.out"));
		int t = Integer.parseInt(buf.readLine());
		for (int i = 1; i <= t; i++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			k = Integer.parseInt(str.nextToken());
			n = Integer.parseInt(str.nextToken());
			start = new int[201];
			str = new StringTokenizer(buf.readLine());
			for (int j = 0; j < k; j++) {
				int x = Integer.parseInt(str.nextToken());
				start[x]++;
			}
			type = new int[n];
			keys = new int[n][];
			for (int j = 0; j < n; j++) {
				str = new StringTokenizer(buf.readLine());
				int x = Integer.parseInt(str.nextToken());
				int y = Integer.parseInt(str.nextToken());
				type[j] = x;
				keys[j] = new int[y];
				for (int l = 0; l < y; l++) {
					keys[j][l] = Integer.parseInt(str.nextToken());
				}
			}
			dp = new int[1 << n+1];
			parent = new int[1 << n+1];
			Arrays.fill(dp, -1);
			int ans = go(0);
			if (ans == 0)
				writer.printf("Case #%d: IMPOSSIBLE\n", i);
			else {
				String s = "";
				int msk = 0;
				while (msk != (1 << n) - 1) {
					int j = parent[msk];
					s += " " + (j + 1);
					msk |= (1 << j);
				}
				writer.printf("Case #%d:%s\n", i, s);
			}

		}
		writer.close();
	}

	private static int go(int i) {
		if (i == (1 << n) - 1)
			return 1;
		if (dp[i] != -1)
			return dp[i];
		else {
			int ans = 0;
			int[] available = new int[201];
			for (int j = 0; j < start.length; j++)
				available[j] = start[j];
			for (int j = 0; j < n; j++)
				if (((1 << j) & i) != 0) {
					available[type[j]]--;
					for (int l = 0; l < keys[j].length; l++)
						available[keys[j][l]]++;
				}
			for (int j = 0; j < n; j++)
				if (((1 << j) & i) == 0) {
					if (available[type[j]] > 0) {
						int x = go(i | (1 << j));
						if (x == 1) {
							ans = 1;
							parent[i] = j;
							break;
						}
					}
				}
			return dp[i] = ans;
		}
	}
}
