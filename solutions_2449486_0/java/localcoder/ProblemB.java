package y2013.qualification.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ProblemB {

	public static void main(final String[] args) throws FileNotFoundException {
		new ProblemB().start();
	}

	private void start() throws FileNotFoundException {
		final Scanner s = new Scanner(new File("src/y2013/qualification/b/B-small-attempt0.in"));
		final int numTests = s.nextInt();
		for (int i = 0; i < numTests; i++) {
			final int rows = s.nextInt();
			final int cols = s.nextInt();
			final int[][] grid = new int[rows][cols];
			for (int row = 0; row < rows; row++) {
				for (int col = 0; col < cols; col++) {
					final int height = s.nextInt();
					grid[row][col] = height;
				}
			}

			final String answer = solve(rows, cols, grid);

			System.out.println("Case #" + (i + 1) + ": " + answer);
		}
	}

	private String solve(final int rows, final int cols, final int[][] grid) {
		//OK. The height at each location was either set by a horizontal pass, or a vertical pass.
		//(100 is a special case - no pass at all - but we don't need to handle that.)
		//We can calulate which it was - its height must be the highest in its row or column for it to be valid.
		//I believe there are no special cases, no need to remember previous results - this just works.

		//runtime - 100 x 100 (check each cell) * 100 * 100 (check each row)
		//Hmm, doesn't sound so good. Let's optimise by calucating the min of each row and column first.
		//100 + 100 (get min of each row and column)+ 100 * 100 much better.

		final int[] maxOfEachColumn = getMaxOfEachColumn(rows, cols, grid);
		final int[] maxOfEachRow = getMaxOfEachRow(rows, cols, grid);

		//ok. check every row:
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				final int height = grid[row][col];
				if (height < maxOfEachColumn[col] && height < maxOfEachRow[row]) {
					return "NO";
				}
			}
		}
		return "YES";
	}

	private int[] getMaxOfEachRow(final int rows, final int cols, final int[][] grid) {
		final int[] maxOfEachRow = new int[rows];
		for (int myRow = 0; myRow < rows; myRow++) {
			int max = 0;
			for (int myCol = 0; myCol < cols; myCol++) {
				final int val = grid[myRow][myCol];
				if (val > max) {
					max = val;
				}
			}
			maxOfEachRow[myRow] = max;
		}
		return maxOfEachRow;
	}

	private int[] getMaxOfEachColumn(final int rows, final int cols, final int[][] grid) {
		final int[] maxOfEachColumn = new int[cols];
		for (int myCol = 0; myCol < cols; myCol++) {
			int max = 0;
			for (int myRow = 0; myRow < rows; myRow++) {
				final int val = grid[myRow][myCol];
				if (val > max) {
					max = val;
				}
			}
			maxOfEachColumn[myCol] = max;
		}
		return maxOfEachColumn;
	}

}
