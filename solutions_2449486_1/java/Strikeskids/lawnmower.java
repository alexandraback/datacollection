import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class lawnmower {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("lawnmower.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("lawnmower.out")));

		int cases = in(br.readLine());

		for (int rep = 1; rep <= cases; ++rep) {
			int[][] goal = loadGoal(br);
			int[][] cur = new int[goal.length][goal[0].length];
			for (int[] row : cur) {
				for (int i = 0; i < row.length; i++) {
					row[i] = 100;
				}
			}
			for (int r = 0; r < cur.length; r++) {
				sweepRow(goal, cur, r);
			}
			for (int c = 0; c < cur[0].length; c++) {
				sweepCol(goal, cur, c);
			}
			boolean failed = false;
			outer: for (int r = 0; r < cur.length; r++) {
				for (int c = 0; c < cur[r].length; c++) {
					if (goal[r][c] != cur[r][c]) {
						failed = true;
						break outer;
					}
				}
			}
			pw.print("Case #");
			pw.print(rep);
			pw.print(": ");
			if (failed) {
				pw.println("NO");
			} else {
				pw.println("YES");
			}
		}

		br.close();
		pw.close();
	}

	public static void sweepRow(int[][] source, int[][] dest, int r) {
		int max = 0;
		for (int c = 0; c < source[r].length; ++c) {
			if (source[r][c] > max)
				max = source[r][c];
		}
		for (int c = 0; c < dest[r].length; ++c) {
			if (max < dest[r][c])
				dest[r][c] = max;
		}
	}

	public static void sweepCol(int[][] source, int[][] dest, int c) {
		int max = 0;
		for (int r = 0; r < source.length; ++r) {
			if (source[r][c] > max)
				max = source[r][c];
		}
		for (int r = 0; r < dest.length; ++r) {
			if (max < dest[r][c])
				dest[r][c] = max;
		}
	}

	public static int[][] loadGoal(BufferedReader br) throws IOException {
		StringTokenizer tk = new StringTokenizer(br.readLine());
		int n = in(tk), m = in(tk);
		int[][] ret = new int[n][m];
		for (int i = 0; i < n; i++) {
			tk = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				ret[i][j] = in(tk);
			}
		}
		return ret;
	}

	private static final int in(StringTokenizer tk) {
		return in(tk.nextToken());
	}

	private static final int in(String s) {
		return Integer.parseInt(s);
	}
}
