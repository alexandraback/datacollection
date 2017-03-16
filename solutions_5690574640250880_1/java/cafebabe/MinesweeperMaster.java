import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class MinesweeperMaster {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter(new File("output_c_large.out"));
		int numOfTests = in.nextInt();

		for (int test = 1; test <= numOfTests; test++) {
			int r = in.nextInt();
			int c = in.nextInt();
			int m = in.nextInt();
			int[][] board = new int[r][c];
			int countOfMines = m;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					board[i][j] = -1;
				}
			}
			int li = 0;
			int lj = 0;
			int ri = r - 1;
			int rj = c - 1;
			while (countOfMines >= Math.min(ri - li + 1, rj - lj + 1)) {

				boolean fillRow = ri - li + 1 >= rj - lj + 1;
				if (fillRow) {
					for (int i = lj; i <= rj; i++) {
						board[li][i] = 9;
						countOfMines--;
					}
					li++;
				} else {
					for (int i = li; i <= ri; i++) {
						board[i][lj] = 9;
						countOfMines--;
					}
					lj++;
				}
			}
			while (countOfMines > 0) {
				if (countOfMines == ri - li && countOfMines == rj - lj) {
					for (int i = lj; i <= (rj + lj) / 2; i++) {
						board[li][i] = 9;
						countOfMines--;
						if (countOfMines == 0) {
							break;
						}
					}
					if (li + 1 < r)
						for (int i = lj; i <= (rj + lj) / 2; i++) {
							board[li + 1][i] = 9;
							countOfMines--;
							if (countOfMines == 0) {
								break;
							}
						}
				} else {
					boolean fillRow = ri - li + 1 <= rj - lj + 1;
					if (fillRow) {
						for (int i = lj; i <= (rj + lj) / 2; i++) {
							board[li][i] = 9;
							countOfMines--;
							if (countOfMines == 0) {
								break;
							}
						}
						if (countOfMines != 0)
							for (int i = rj; i > (rj + lj) / 2; i--) {
								board[ri][i] = 9;
								countOfMines--;
								if (countOfMines == 0) {
									break;
								}
							}
					} else {
						for (int i = li; i <= (ri + li) / 2; i++) {
							board[i][lj] = 9;
							countOfMines--;
							if (countOfMines == 0) {
								break;
							}
						}
						if (countOfMines != 0)
							for (int i = ri; i > (ri + li) / 2; i--) {
								board[i][rj] = 9;
								countOfMines--;
								if (countOfMines == 0) {
									break;
								}
							}
					}
				}
			}
			int fi = (ri + li) / 2;
			int fj = (lj + rj) / 2;
			int n = calculateNeiborMines(board, r, c, fi, fj);
			if (n != 0)
				for (int i = li; i <= ri; i++) {
					for (int j = lj; j <= rj; j++) {
						n = calculateNeiborMines(board, r, c, i, j);
						if (n == 0) {
							fi = i;
							fj = j;
							break;
						}
					}
				}
			calculate(board, r, c, fi, fj);
			out.println(String.format("Case #%d:", test));
			if (isIncomplete(board, r, c)) {
				out.println("Impossible");
			} else {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (i == fi && j == fj) {
							out.print('c');
						} else if (board[i][j] == 9) {
							out.print('*');
						} else {
							out.print('.');
						}
					}
					out.println();
				}
			}
		}
		out.close();
		in.close();
	}

	private static void calculate(int[][] board, int rows, int columns, int i,
			int j) {
		// System.out.println(String.format("calculate for board[%d][%d]", i,
		// j));
		// System.out.println(String.format("current value board[%d][%d]=%d", i,
		// j, board[i][j]));
		if (board[i][j] != -1)
			return;
		int numOfMines = calculateNeiborMines(board, rows, columns, i, j);

		board[i][j] = numOfMines;
		if (numOfMines == 0) {
			if (j - 1 >= 0)
				calculate(board, rows, columns, i, j - 1);
			if (j + 1 < columns)
				calculate(board, rows, columns, i, j + 1);
			if (i - 1 >= 0 && j - 1 >= 0)
				calculate(board, rows, columns, i - 1, j - 1);
			if (i - 1 >= 0)
				calculate(board, rows, columns, i - 1, j);
			if (i - 1 >= 0 && j + 1 < columns)
				calculate(board, rows, columns, i - 1, j + 1);
			if (i + 1 < rows && j - 1 >= 0)
				calculate(board, rows, columns, i + 1, j - 1);
			if (i + 1 < rows)
				calculate(board, rows, columns, i + 1, j);
			if (i + 1 < rows && j + 1 < columns)
				calculate(board, rows, columns, i + 1, j + 1);
		}

	}

	private static int calculateNeiborMines(int[][] board, int rows,
			int columns, int i, int j) {
		int numOfMines = 0;
		if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 9)
			numOfMines++;
		if (i - 1 >= 0 && board[i - 1][j] == 9)
			numOfMines++;
		if (i - 1 >= 0 && j + 1 < columns && board[i - 1][j + 1] == 9)
			numOfMines++;
		if (j - 1 >= 0 && board[i][j - 1] == 9)
			numOfMines++;
		if (j + 1 < columns && board[i][j + 1] == 9)
			numOfMines++;
		if (i + 1 < rows && j - 1 >= 0 && board[i + 1][j - 1] == 9)
			numOfMines++;
		if (i + 1 < rows && board[i + 1][j] == 9)
			numOfMines++;
		if (i + 1 < rows && j + 1 < columns && board[i + 1][j + 1] == 9)
			numOfMines++;
		return numOfMines;
	}

	private static boolean isIncomplete(int[][] board, int r, int c) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] == -1) {
					return true;
				}
			}
		}
		return false;
	}

}
