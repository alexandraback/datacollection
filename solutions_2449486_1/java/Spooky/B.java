package qual2013;

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
	
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int n = in.nextInt(), m = in.nextInt();
			int[] row = new int[n];
			int[] col = new int[m];
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					int x = in.nextInt();
					map[i][j] = x;
					row[i] = Math.max(row[i], x);
					col[j] = Math.max(col[j], x);
				}
			
			int[][] r = new int[n][m];
			for (int[] rr : r) Arrays.fill(rr, 100);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					r[i][j] = Math.min(r[i][j], Math.min(row[i], col[j]));
			boolean ans = true;
			for (int i = 0; i < n && ans; i++)
				for (int j = 0; j < m && ans; j++)
					if (map[i][j] != r[i][j])
						ans = false;
			out.println(ans ? "YES" : "NO");
		}

		out.flush();
	}

}
