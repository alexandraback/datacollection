import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class MinesweeperMaster {
	static String problem = "C";
	static boolean[][] vis;
	static int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int[] dy = { 1, 0, -1, 1, -1, 1, 0, -1 };
	static int n, m;
	static char[][] arr;

	static void go(int row, int col) {
		vis[row][col] = true;
		if (count(row, col) > 0)
			return;
		for (int k = 0; k < 8; k++) {
			int nr = row + dx[k];
			int nc = col + dy[k];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
				go(nr, nc);
			}
		}
	}

	private static int count(int row, int col) {
		int mines = 0;
		for (int k = 0; k < 8; k++) {
			int nr = row + dx[k];
			int nc = col + dy[k];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m)
				if (arr[nr][nc] == '*')
					mines++;
		}
		return mines;
	}

	public static void main(String[] args) throws Exception {
		// InputReader r = new InputReader(System.in);
		// PrintWriter out = new PrintWriter(System.out);
		InputReader r = new InputReader(new FileReader(problem + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(problem
				+ "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		loop: while (T-- > 0) {
			n = r.nextInt();
			m = r.nextInt();
			int c = r.nextInt();
			for (int mask = 0; mask < (1 << (n * m)); mask++) {
				if (Integer.bitCount(mask) == c) {
					arr = new char[n][m];
					for (char[] x : arr)
						Arrays.fill(x, '.');
					int bit = 0;
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							if ((mask & (1 << bit)) > 0)
								arr[i][j] = '*';
							bit++;
						}
					}
					for (int k = 0; k < n * m; k++) {
						if ((mask & (1 << k)) == 0) {
							arr[k / m][k % m] = 'c';
							vis = new boolean[n][m];
							go(k / m, k % m);
							boolean can = true;
							for (int i = 0; i < arr.length; i++) {
								for (int j = 0; j < arr[i].length; j++) {
									if (arr[i][j] == '.' && !vis[i][j]) {
										can = false;
									}
								}
							}
							if (can) {
								out.printf("Case #%d:\n", test++);
								for (char[] a : arr)
									out.println(new String(a));
								continue loop;
							}
							arr[k / m][k % m] = '.';
						}
					}

				}
			}
			out.printf("Case #%d:\n%s\n", test++, "Impossible");
		}
		out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
