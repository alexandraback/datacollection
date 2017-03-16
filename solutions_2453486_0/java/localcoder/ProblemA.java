package y2013.qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ProblemA {

	public static void main(final String[] args) throws FileNotFoundException {
		new ProblemA().start();
	}

	private void start() throws FileNotFoundException {
		final Scanner s = new Scanner(new File("src/y2013/qualification/A-small-attempt0.in"));
		final int numTests = s.nextInt();
		s.nextLine(); //finish the line
		for (int i = 0; i < numTests; i++) {
			final char[][] grid = new char[4][4];
			for (int row = 0; row < 4; row++) {
				final String line = s.nextLine();
				for (int col = 0; col < 4; col++) {
					grid[row][col] = line.charAt(col);
				}
			}

			final String answer = solve(grid);
			System.out.println("Case #" + (i+1) + ": " + answer);
			s.nextLine(); //skip blank line
		}
	}

	private String solve(final char[][] grid) {
		//find answers:
		//someone wins, or it's a draw, or it's a game not yet over
		final String rows = checkRows(grid, false);
		if (rows != null) {
			return rows;
		}

		final String cols = checkRows(grid, true);
		if (cols != null) {
			return cols;
		}

		//diagonals
		final String diag1 = checkDiags(grid, true);
		if (diag1 != null) {
			return diag1;
		}

		final String diag2 = checkDiags(grid, false);
		if (diag2 != null) {
			return diag2;
		}

		//OK, that's all possible ways to win.
		//now, is it a draw, or an incomplete game?
		//it's incomplete if there is any empty space.
		if (isAnyEmptySpace(grid)) {
			return "Game has not completed";
		} else {
			return "Draw";
		}
	}

	private String checkDiags(final char[][] grid, final boolean swap) {
		int pOScore = 0;
		int pXScore = 0;
		for (int x = 0; x < 4; x++) {
			int y;
			if (swap) {
				y = 3 -x;
			} else {
				y = x;
			}
			switch (getPos(grid, x, y, swap)) {
				case 'O': pOScore++; break;
				case 'X': pXScore++; break;
				case 'T': pXScore++; pOScore++; break;
				case '.': break;
				default: throw new IllegalStateException("Illegal char " + getPos(grid, x, y, false));
			}
		}
		if (pOScore == 4) {
			return "O won";
		} else if (pXScore == 4) {
			return "X won";
		}
		return null;
	}

	private String checkRows(final char[][] grid, final boolean swap) {
		//check all rows for a winner
		for (int row = 0; row < 4; row++) {
			int pOScore = 0;
			int pXScore = 0;
			for (int col = 0; col < 4; col++) {
				final char value = getPos(grid, row, col, swap);
				switch (value) {
					case 'O': pOScore++; break;
					case 'X': pXScore++; break;
					case 'T': pXScore++; pOScore++; break;
					case '.': break;
					default: throw new IllegalStateException("Illegal char " + value);
				}
			}
			if (pOScore == 4) {
				return "O won";
			} else if (pXScore == 4) {
				return "X won";
			}
		}
		return null;
	}

	private char getPos(final char[][] grid, final int row, final int col, final boolean swap) {
		if (swap) {
			return grid[col][row];
		} else {
			return grid[row][col];
		}
	}

	private boolean isAnyEmptySpace(final char[][] grid) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (grid[i][j]=='.') {
					return true;
				}
			}
		}
		return false;
	}

}
