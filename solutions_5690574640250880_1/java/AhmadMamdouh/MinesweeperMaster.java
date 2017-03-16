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
	static String problem = "CLarge";
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

	static boolean hasSolution(int c) {
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

						if (check(k / m, k % m)) {
							// for (char[] a : arr)
							// System.out.println(new String(a));
							return true;
						}
						arr[k / m][k % m] = '.';
					}
				}
			}
		}
		return false;
	}

	static boolean check(int row, int col) {
		vis = new boolean[n][m];
		go(row, col);
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				if (arr[i][j] == '.' && !vis[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	static boolean tryStart() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '.') {
					arr[i][j] = 'c';
					if (check(i, j)) {
						return true;
					}
					arr[i][j] = '.';
				}
			}
		}
		return false;
	}

	static boolean placeHorizontal(int c) {
		int completeRows = c / m;
		if (tryRow(completeRows, c))
			return true;
		for (int k = 1; k <= 5; k++)
			if (completeRows - k >= 0 && tryRow(completeRows - k, c))
				return true;
		return false;
	}

	static boolean tryRow(int completeRows, int c) {
		arr = new char[n][m];
		for (char[] a : arr)
			Arrays.fill(a, '.');
		for (int i = 0; i < completeRows; i++) {
			for (int j = 0; j < m; j++)
				arr[i][j] = '*';
		}
		int extra = c - completeRows * m;
		for (int j = 0; j < m; j++) {
			if (extra == 0)
				break;
			arr[completeRows][j] = '*';
			extra--;
		}
		if (extra == 0 && tryStart())
			return true;
		extra = c - completeRows * m;
		for (int j = 0; j < m; j++) {
			if (extra == 0)
				break;
			arr[completeRows][j] = '.';
			extra--;
		}
		extra = c - completeRows * m;
		for (int j = 0; j < m; j++) {
			for (int i = completeRows; i < n; i++) {
				if (extra == 0)
					break;
				arr[i][j] = '*';
				extra--;
			}
		}
		if (extra == 0 && tryStart())
			return true;
		return false;
	}

	static boolean tryCol(int completeCols, int c) {
		arr = new char[n][m];
		for (char[] a : arr)
			Arrays.fill(a, '.');
		for (int i = 0; i < completeCols; i++) {
			for (int j = 0; j < n; j++)
				arr[j][i] = '*';
		}
		int extra = c - completeCols * n;
		for (int i = 0; i < n; i++) {
			if (extra == 0)
				break;
			arr[i][completeCols] = '*';
			extra--;
		}
		if (extra == 0 && tryStart())
			return true;
		extra = c - completeCols * n;
		for (int i = 0; i < n; i++) {
			if (extra == 0)
				break;
			arr[i][completeCols] = '.';
			extra--;
		}
		extra = c - completeCols * n;
		for (int j = 0; j < n; j++) {
			for (int i = completeCols; i < m; i++) {
				if (extra == 0)
					break;
				arr[j][i] = '*';
				extra--;
			}
		}
		if (extra == 0 && tryStart())
			return true;
		return false;
	}

	static boolean placeVertical(int c) {
		int completeCols = c / n;
		if (tryCol(completeCols, c))
			return true;
		for (int k = 1; k <= 5; k++)
			if (completeCols - k >= 0 && tryCol(completeCols - k, c))
				return true;
		return false;
	}

	static boolean tryL(int c) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr = new char[n][m];
				for (char[] a : arr)
					Arrays.fill(a, '.');
				for (int k = 0; k <= i; k++)
					arr[k][0] = '*';
				for (int k = 0; k <= j; k++)
					arr[0][k] = '*';
				int mines = 0;
				for (int k = 0; k < n; k++)
					for (int k2 = 0; k2 < m; k2++)
						if (arr[k][k2] == '*')
							mines++;
				if (mines == c) {
					if (tryStart())
						return true;
				}
			}
		}
		return false;
	}

	public static void main(String[] args) throws Exception {
		// InputReader r = new InputReader(System.in);
		// PrintWriter out = new PrintWriter(System.out);
		InputReader r = new InputReader(new FileReader(problem + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(problem
				+ "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			n = r.nextInt();
			m = r.nextInt();
			int c = r.nextInt();
//			boolean hasSolution = hasSolution(c);
			if (placeHorizontal(c)) {
//				if (!hasSolution)
//					System.out.println(n + " " + m + " " + c + " H");
				out.printf("Case #%d:\n", test++);
				for (char[] a : arr)
					out.println(new String(a));
			} else if (placeVertical(c)) {
//				if (!hasSolution)
//					System.out.println(n + " " + m + " " + c + " V");
				out.printf("Case #%d:\n", test++);
				for (char[] a : arr)
					out.println(new String(a));
			} else if (tryL(c)) {
//				if (!hasSolution)
//					System.out.println(n + " " + m + " " + c + " L");
				out.printf("Case #%d:\n", test++);
				for (char[] a : arr)
					out.println(new String(a));
			} else {
//				if (hasSolution)
//					System.out.println(n + " " + m + " " + c + " NN");
				out.printf("Case #%d:\n%s\n", test++, "Impossible");
			}
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
