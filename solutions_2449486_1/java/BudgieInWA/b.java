import java.util.*;

public class b {
	private static void p(String p) { System.out.print(p);   }
	private static void pln(String p) { System.out.println(p); }

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int P = in.nextInt();

		for (int p = 1; p <= P; p++) {
			int r = in.nextInt();
			int c = in.nextInt();
			int[][] g = new int[r][c];
			boolean[][] can = new boolean[r][c];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					g[i][j] = in.nextInt();
				}
			}

			line(g, can, 0, 1);
			line(g, can, 1, 0);
			boolean ans = true;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (!can[i][j]) ans = false;
				}
			}
			System.out.printf("Case #%d: %s\n", p, ans ? "YES" : "NO");

		}
	}

	static void line(int[][] g, boolean[][] can, int di, int dj) {
		int r = g.length;
		int c = g[0].length;
		for (int i = 0, j = 0; i < r && j < c; i += di, j += dj) {
			int max = 0;
			for (; i < r && j < c; i += dj, j += di) {
				max = Math.max(max, g[i][j]);
			}
			i -= r*dj; j -= c*di;
			for (; i < r && j < c; i += dj, j += di) {
				if (g[i][j] == max) can[i][j] = true;
			}
			i -= r*dj; j -= c*di;
		}
	}
}
