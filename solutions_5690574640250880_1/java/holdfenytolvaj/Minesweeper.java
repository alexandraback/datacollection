package gcjpractice.qualification2014;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Minesweeper {

	private static final String IMPOSSIBLE = "Impossible\n";

	public static void main(String[] args) throws Exception {
		String base = "/home/radicsge/gcj2014/qualification/";
		String input = base + "c5.in";
		String output = base + "c5.out";

		try {
			Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

			int n = sc.nextInt();
			sc.nextLine();
			for (int i = 0; i < n; i++) {

				int r = sc.nextInt();
				int c = sc.nextInt();
				int m = sc.nextInt();
				sc.nextLine();

				System.out.println("Case #" + (i + 1) + ": " + r + " " + c + " " + m);
				pw.println("Case #" + (i + 1) + ": ");

				String solution = solve(r, c, m);

				System.out.print(solution);
				pw.print(solution);

			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
		}
	}

	private static String solve(int r, int c, int m) throws Exception {
		if (m >= r * c) {
			return IMPOSSIBLE;
		}

		boolean transpose = false;
		if (r > c) {
			transpose = true;
			int tmp = r;
			r = c;
			c = tmp;
		}

		char[][] board = getFull(r, c, '.');
		placeBombsKeepingInvariant(board, r, c, m);

		if (board[0][0] == 'i') {
			return IMPOSSIBLE;
		} else {
			return printMatrix(board, transpose);
		}
	}

	private static void placeBombsKeepingInvariant(char[][] board, int r, int c, int m) {
		if (m == 0) {
			board[0][0] = 'c';
			return;
		}
		int numberOfFields = r * c;
		if (r != 1 && (numberOfFields - m == 3 || numberOfFields - m == 7)) {
			board[0][0] = 'i';
			return;
		}

		if (r < c) {
			if (r <= 2) {
				solveSmallProblem(board, r, c, m);
			} else if (m >= r) {
				fillColumn(board, c, '*');
				placeBombsKeepingInvariant(board, r, c - 1, m - r);
			} else {
				placeBombsInCorner(board, r, c, m);
			}
		} else {
			if (c <= 2) {
				solveSmallProblem(board, r, c, m);
			} else if (m >= c) {
				fillRow(board, r, '*');
				placeBombsKeepingInvariant(board, r - 1, c, m - c);
			} else {
				placeBombsInCorner(board, r, c, m);
			}
		}
	}

	/** r<=2  */
	private static void solveSmallProblem(char[][] board, int r, int c, int m) {
		int numberOfFields = r * c;
		if (r == 1) {
			if (c == 1) {
				board[0][0] = 'c';
			} else {
				for (int i = 0; i < m; i++) {
					board[r - 1][c - 1 - i] = '*';
				}
				board[0][0] = 'c';
			}
		} else if (r == 2) {
			if (m % 2 != 0) {
				if (m == numberOfFields - 1) {
					fillRow(board, 1, '*');
					fillRow(board, 2, '*');
					board[0][0] = 'c';
				} else {
					board[0][0] = 'i';
				}
			} else if (m == numberOfFields - 2) {
				board[0][0] = 'i';
			} else {
				fillRow(board, 1, '*');
				fillRow(board, 2, '*');
				for (int i = 0; i < (numberOfFields - m) / 2; i++) {
					board[0][i] = '.';
					board[1][i] = '.';
				}
				board[0][0] = 'c';
			}
		} else {
			throw new IllegalStateException();
		}
	}

	private static void fillRow(char[][] board, int r, char f) {
		for (int i = 0; i < board[r - 1].length; i++) {
			board[r - 1][i] = f;
		}
	}

	private static void fillColumn(char[][] board, int c, char f) {
		for (int i = 0; i < board.length; i++) {
			board[i][c - 1] = f;
		}
	}

	private static void placeBombsInCorner(char[][] board, int r, int c, int m) {
		for (int i = 0; m > 0; i++) {
			for (int j = 0; i >= j && m > 0; j++) {
				board[r - 1 - j][c - 1 - (i - j)] = '*';
				m--;
			}
		}
		board[0][0] = 'c';
	}

	private static char[][] getFull(int r, int c, char f) {
		char[][] board = new char[r][c];
		for (int i = 0; i < r; i++) {
			board[i] = new char[c];
			Arrays.fill(board[i], f);
		}
		return board;
	}

	private static String printMatrix(char[][] board, boolean transpose) {
		String r = "";
		if (transpose) {
			for (int j = 0; j < board[0].length; j++) {
				for (int i = 0; i < board.length; i++) {
					r += board[i][j];
				}
				r += "\n";
			}
		} else {
			for (int i = 0; i < board.length; i++) {
				for (int j = 0; j < board[0].length; j++) {
					r += board[i][j];
				}
				r += "\n";
			}
		}
		return r;
	}

}
