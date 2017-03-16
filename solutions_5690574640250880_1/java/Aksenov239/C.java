import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	int[] dx = { 1, 1, 0, -1, -1, -1, 0, 1 };
	int[] dy = { 0, 1, 1, 1, 0, -1, -1, -1 };

	public boolean zero(int x, int y, boolean[][] mine) {
		for (int k = 0; k < dx.length; k++) {
			if (x + dx[k] >= 0 && x + dx[k] < mine.length)
				if (y + dy[k] >= 0 && y + dy[k] < mine[0].length)
					if (mine[x + dx[k]][y + dy[k]])
						return false;
		}
		return true;
	}

	boolean[][] was;

	public int cnt(int x, int y, boolean[][] mine) {
		if (was[x][y])
			return 0;
		was[x][y] = true;
		int sum = 1;
		if (zero(x, y, mine)) {
			for (int k = 0; k < dx.length; k++) {
				if (x + dx[k] >= 0 && x + dx[k] < mine.length)
					if (y + dy[k] >= 0 && y + dy[k] < mine[0].length)
						sum += cnt(x + dx[k], y + dy[k], mine);
			}
		}
		return sum;
	}

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int M = nextInt();

		out.println();

		if (n == 1) {
			for (int i = 0; i < m - 1; i++) {
				if (i < M)
					out.print("*");
				else
					out.print(".");
			}
			out.println("c");
			return;
		}

		if (m == 1) {
			for (int i = 0; i < n - 1; i++) {
				if (i < M)
					out.println("*");
				else
					out.println(".");
			}
			out.println("c");
			return;
		}

		if (n * m - 1 == M) {
			out.print("c");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i + j != 0)
						out.print("*");
				}
				out.println();
			}
			return;
		}

		int d = M % 2 == (n * m) % 2 ? 0 : 1;

		int totalS = (n - 2) * (m - 2) - d;
		if (totalS < 0) {
			out.println("Impossible");
			return;
		}

		boolean[][] mine = new boolean[n][m];
		int add = Math.min(M, totalS);
		M = M - totalS;

		for (int i = 0; i < n - 2; i++) {
			for (int j = 0; j < m - 2; j++) {
				if (add > 0)
					mine[i][j] = true;
				add--;
			}
		}
		int ln = n - 2 - d;
		int lm = m - 2 - d;

		if (M > 2 * ln + 2 * lm) {
			out.println("Impossible");
			return;
		}

		for (int i = 0; i < ln; i++)
			if (M > 0) {
				mine[i][m - 1] = true;
				mine[i][m - 2] = true;
				M -= 2;
			}

		for (int i = 0; i < lm; i++)
			if (M > 0) {
				mine[n - 1][i] = true;
				mine[n - 2][i] = true;
				M -= 2;
			}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + j != n + m - 2) {
					out.print(mine[i][j] ? "*" : ".");
				}
			}
			if (i != n - 1)
				out.println();
			else
				out.print("c\n");
		}
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print(String.format("Case #%d: ", i + 1));
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
