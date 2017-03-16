import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class MinesweeperMaster {

	private void work() throws Exception {
		Scanner sc = new Scanner(new BufferedReader(new FileReader(
				"C-small-attempt1.in")));
		PrintWriter pw = new PrintWriter(new FileWriter("C-small-attempt1.out"));

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			pw.printf("Case #%d:\n", tc);

			int m = sc.nextInt();
			int n = sc.nextInt();
			int k = sc.nextInt();
			int empty = m * n - k;

			if (empty == 1) {
				char[] s = new char[n];
				Arrays.fill(s, '*');
				for (int i = 0; i < m; i++) {
					if (i == 0)
						s[0] = 'c';
					pw.println(new String(s, 0, n));
					if (i == 0)
						s[0] = '*';
				}
				continue;
			}

			if (k == 0) {
				char[] s = new char[n];
				Arrays.fill(s, '.');
				for (int i = 0; i < m; i++) {
					if (i == 0)
						s[0] = 'c';
					pw.println(new String(s, 0, n));
					if (i == 0)
						s[0] = '.';
				}
				continue;

			}

			if (m == 1 || n == 1) {
				char[][] g = new char[m][n];
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						if (empty-- > 0) {
							g[i][j] = '.';
						} else {
							g[i][j] = '*';
						}
					}
				}
				g[0][0] = 'c';
				for (int i = 0; i < m; i++) {
					pw.println(new String(g[i], 0, n));
				}
			} else {
				char[][] g = getValid(m, n, k);
				if (g == null) {
					pw.println("Impossible");
				} else {
					for (int i = 0; i < m; i++) {
						pw.println(new String(g[i], 0, n));
					}
				}
			}
		}
		sc.close();
		pw.close();
	}

	private char[][] getValid(int m, int n, int k) {
		int lim = 1 << (m * n);
		int mask = (1 << k) - 1;
		char[][] g = new char[m][n];
		while (mask < lim) {
			int t = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (((1 << t) & mask) != 0) {
						g[i][j] = '*';
					} else {
						g[i][j] = '.';
					}
					t++;
				}
			}
			if (check(g, m, n, k))
				return g;
			mask = snoob(mask);
		}
		return null;
	}

	private int snoob(int x) {
		int smallest, ripple, ones;
		smallest = x & -x;
		ripple = x + smallest;
		ones = x ^ ripple;
		ones = (ones >>> 2) / smallest;
		x = ripple | ones;
		return x;
	}

	int[] q = new int[1 << 16];
	int qs, qe;
	int[] dr = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int[] dc = { 0, 1, 1, 1, 0, -1, -1, -1 };

	private boolean check(char[][] g, int m, int n, int k) {
		int[][] blah = new int[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] == '*') {
					for (int ii = 0; ii < 8; ii++) {
						int tr = i + dr[ii];
						if (tr < 0 || tr >= m)
							continue;
						int tc = j + dc[ii];
						if (tc < 0 || tc >= n)
							continue;
						blah[tr][tc]++;
					}
				}
			}
		}
		int rr = -1;
		int cc = -1;
		for (int i = 0; i < m && rr < 0; i++) {
			for (int j = 0; j < n; j++) {
				if (blah[i][j] == 0 && g[i][j] == '.') {
					rr = i;
					cc = j;
					break;
				}
			}
		}
		if (rr < 0)
			return false;

		qs = qe = 0;
		q[qe++] = rr;
		q[qe++] = cc;
		boolean[][] used = new boolean[m][n];
		used[rr][cc] = true;
		while (qs < qe) {
			int r = q[qs++];
			int c = q[qs++];
			if (blah[r][c] == 0) {
				for (int i = 0; i < 8; i++) {
					int tr = r + dr[i];
					if (tr < 0 || tr >= m)
						continue;
					int tc = c + dc[i];
					if (tc < 0 || tc >= n)
						continue;
					if (g[tr][tc] == '.' && !used[tr][tc]) {
						used[tr][tc] = true;
						q[qe++] = tr;
						q[qe++] = tc;
					}
				}
			}
		}
		if (qe / 2 == m * n - k) {
			g[rr][cc] = 'c';
			return true;
		} else {
			return false;
		}
	}

	public static void main(String[] args) throws Exception {
		new MinesweeperMaster().work();
	}

}
