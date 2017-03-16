package gcj2016.r1a;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoB {
	public static void main(final String[] args) {

		final String base = "/home/jfortin/workspace-gcj/Codejam2016/r1a/ExoB/";
		final String input = base + "s2.in";
		final String output = base + "s2.out";

		try {
			final Scanner sc = new Scanner(new FileReader(input));
			final PrintWriter pw = new PrintWriter(output);

			final int n = sc.nextInt();
			sc.nextLine();
			for (int c = 0; c < n; c++) {
				System.out.println("Test case " + (c + 1) + "...");
				pw.print("Case #" + (c + 1) + ": ");
				test(sc, pw);
				pw.println();
			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (final FileNotFoundException ex) {
			Logger.getLogger(ExoB.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		int N = sc.nextInt();
		int[][] in = new int[2 * N - 1][N];
		for (int i = 0; i < 2 * N - 1; i++) {
			for (int j = 0; j < N; j++) {
				in[i][j] = sc.nextInt();
			}
		}

		int pow = (int) Math.pow(2, N);
		for (int choices = 0; choices < pow; choices++) {
			try {
				boolean[] used = new boolean[2 * N - 1];
				int[][] grid = new int[N][N];
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						grid[i][j] = -1;
					}
				}
				solve(in, used, grid, 0, N, choices, pw);
				break;
			} catch (Exception e) {
				// System.out.println("Invalid");
			}
		}

	}

	private static void solve(final int[][] in, final boolean[] used, final int[][] grid, final int o, final int N,
			final int choices, final PrintWriter pw) {

		// printGrid(grid, N);

		if (o == N) {
			findMissing(in, grid, N, pw);
			return;
		}

		int min = Integer.MAX_VALUE;
		int i1 = -1;
		int i2 = -1;
		for (int i = 0; i < 2 * N - 1; i++) {
			if (!used[i] && in[i][o] <= min) {
				if (in[i][o] < min) {
					i1 = i;
					i2 = -1;
				} else {
					i2 = i;
				}
				min = in[i][o];
			}
		}

		if (i1 != -1) {
			used[i1] = true;
		}

		if (i2 != -1) {
			used[i2] = true;
		}

		// System.out.println("i1: " + i1 + ", i2: " + i2);

		if (((choices >> o) & 1) == 0) {
			if (i1 != -1) {
				copyRow(in, grid, o, N, i1);
			}
			if (i2 != -1) {
				copyColumn(in, grid, o, N, i2);
			}
		} else {
			if (i1 != -1) {
				copyColumn(in, grid, o, N, i1);
			}
			if (i2 != -1) {
				copyRow(in, grid, o, N, i2);
			}
		}

		solve(in, used, grid, o + 1, N, choices, pw);

	}

	private static void findMissing(final int[][] in, final int[][] grid, final int N, final PrintWriter pw) {
		boolean[] used = new boolean[2 * N - 1];

		outer: for (int c = 0; c < N; c++) {
			for (int i = 0; i < 2 * N - 1; i++) {
				if (!used[i]) {
					boolean id = true;
					for (int k = 0; k < N; k++) {
						if (grid[c][k] != in[i][k]) {
							id = false;
						}
					}
					if (id) {
						used[i] = true;
						continue outer;
					}
				}
			}

			for (int k = 0; k < N; k++) {
				pw.print(grid[c][k] + " ");
			}
			return;
		}

		outer: for (int c = 0; c < N; c++) {
			for (int i = 0; i < 2 * N - 1; i++) {
				if (!used[i]) {
					boolean id = true;
					for (int k = 0; k < N; k++) {
						if (grid[k][c] != in[i][k]) {
							id = false;
						}
					}
					if (id) {
						used[i] = true;
						continue outer;
					}
				}
			}

			for (int k = 0; k < N; k++) {
				pw.print(grid[k][c] + " ");
			}
			return;
		}
	}

	private static void copyColumn(final int[][] in, final int[][] grid, final int o, final int N, final int i2) {
		for (int i = 0; i < N; i++) {
			if (grid[i][o] != -1 && grid[i][o] != in[i2][i]) {
				throw new RuntimeException();
			}
			grid[i][o] = in[i2][i];
		}
	}

	private static void copyRow(final int[][] in, final int[][] grid, final int o, final int N, final int i1) {
		for (int i = 0; i < N; i++) {
			if (grid[o][i] != -1 && grid[o][i] != in[i1][i]) {
				throw new RuntimeException();
			}
			grid[o][i] = in[i1][i];
		}
	}

	public static void printGrid(final int[][] grid, final int N) {
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < N; k++) {
				System.out.print(grid[i][k] + " ");
			}
			System.out.println();
		}
	}

	private static boolean rowCompat(final int[][] in, final int[][] grid, final int o, final int si, final int N) {
		for (int i = 0; i < N; i++) { // column
			int found = 0;
			piece: for (int k = 0; k < 2 * N - 1; k++) {
				for (int j = 0; j < o; j++) { // row
					if (grid[i][j] != -1 && grid[i][j] != in[k][j]) {
						continue piece;
					}
				}
				found++;
			}
		}
		return false;
	}

}
