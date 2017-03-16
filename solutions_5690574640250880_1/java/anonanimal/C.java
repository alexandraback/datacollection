import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();
			System.out.printf("Case #%d:\n", t);
			solve(R, C, M);
		}
	}

	public static void solve(int R, int C, int M) {
		int startX = 0;
		int startY = 0;
		boolean[][] board = new boolean[R][C];

		int n = R;
		int m = C;

		int safe = R * C - M;

		while (true) {
			// Fill out a row
			if (R > C) {
				if (M < C)
					break;

				M -= C;
				startX++;
				R--;

			}
			// Fill out a column
			else {
				if (M < R)
					break;

				M -= R;
				startY++;
				C--;

			}
		}

		// True indicates mine
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i >= startX && j >= startY)
					break;

				board[i][j] = true;
			}
		}

		for (int i = startX; i < n - 2; i++) {
			if (M == 0)
				break;
			board[i][startY] = true;
			M--;
		}

		for (int j = startY + 1; j < m; j++) {
			if (M == 0)
				break;
			board[startX][j] = true;
			M--;
		}

		if (valid(board, safe)) {
			print(board);
		} else {
			System.out.println("Impossible");
		}

	}

	public static boolean valid(boolean[][] board, int total) {
		int n = board.length;
		int m = board[0].length;
		return dfs(board, new boolean[n][m], n - 1, m - 1) == total;
	}

	public static int dfs(boolean[][] mine, boolean[][] seen, int i, int j) {

		int n = mine.length;
		int m = mine[0].length;

		if (!inBounds(i, j, n, m))
			return 0;
		if (seen[i][j] || mine[i][j])
			return 0;

		seen[i][j] = true;

		int ans = 1;

		// Make sure it's a '0'
		for (int x = -1; x <= 1; x++) {
			for (int y = -1; y <= 1; y++) {
				if (x == 0 && y == 0)
					continue;

				int newx = i + x;
				int newy = j + y;

				if (inBounds(newx, newy, n, m) && mine[newx][newy])
					return ans;
			}
		}

		// Recurse on neighbors
		for (int x = -1; x <= 1; x++) {
			for (int y = -1; y <= 1; y++) {
				if (x == 0 && y == 0)
					continue;

				int newx = i + x;
				int newy = j + y;
				ans += dfs(mine, seen, newx, newy);
			}
		}

		return ans;
	}

	public static boolean inBounds(int x, int y, int n, int m) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}

	public static void print(boolean[][] b) {
		for (int i = 0; i < b.length; i++) {
			for (int j = 0; j < b[0].length; j++) {
				if (i == b.length - 1 && j == b[0].length - 1) {
					System.out.print("c");
					continue;
				}

				if (b[i][j])
					System.out.print("*");
				else
					System.out.print(".");
			}
			System.out.println();
		}
	}
}
