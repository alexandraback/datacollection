import java.io.*;
import java.util.Scanner;

public class C
{
	static char[][] grid;

	static void displayGrid()
	{
		for (int row = 0; row < grid.length; row++)
		{
			for (int col = 0; col < grid[0].length; col++)
				System.out.print(grid[row][col]);
			System.out.println();
		}
	}

	static void displayGrid(PrintWriter out)
	{
		for (int row = 0; row < grid.length; row++)
		{
			for (int col = 0; col < grid[0].length; col++)
				out.print(grid[row][col]);
			out.println();
		}
	}

	static int countEmpty()
	{
		int emptyCount = 0;
		for (int row = 0; row < grid.length; row++)
		{
			for (int col = 0; col < grid[0].length; col++)
				if (grid[row][col] == '.')
					emptyCount++;
		}
		return emptyCount;
	}

	static int charCount(int row, int col, char ch)
	{
		int mineCount = 0;
		if (row + 1 < grid.length && grid[row + 1][col] == ch)
			mineCount++;
		if (row + 1 < grid.length && col + 1 < grid[0].length
				&& grid[row + 1][col + 1] == ch)
			mineCount++;
		if (row + 1 < grid.length && col - 1 >= 0
				&& grid[row + 1][col - 1] == ch)
			mineCount++;
		if (col - 1 >= 0 && grid[row][col - 1] == ch)
			mineCount++;
		if (col + 1 < grid[0].length && grid[row][col + 1] == '*')
			mineCount++;
		if (row - 1 >= 0 && grid[row - 1][col] == ch)
			mineCount++;
		if (row - 1 >= 0 && col + 1 < grid[0].length
				&& grid[row - 1][col + 1] == ch)
			mineCount++;
		if (row - 1 >= 0 && col - 1 >= 0 && grid[row - 1][col - 1] == ch)
			mineCount++;
		return mineCount;
	}

	static void floodFill(int row, int col)
	{
		// Check if on the grid
		if (row < 0 || row >= grid.length || col < 0 || col >= grid[0].length)
			return;
		// Check if a .
		if (grid[row][col] == '*')
			return;
		if (grid[row][col] == '.' || grid[row][col] == 'c')
		{
			int mineCount = charCount(row, col, '*');
			grid[row][col] = (char) ('0' + mineCount);

			if (mineCount == 0)
			{
				floodFill(row, col + 1);
				floodFill(row - 1, col + 1);
				floodFill(row + 1, col + 1);

				floodFill(row + 1, col);
				floodFill(row - 1, col);
				floodFill(row, col - 1);
				floodFill(row + 1, col - 1);
				floodFill(row - 1, col - 1);
			}

		}

	}

	static int countEmpty(char[][] gridNew)
	{
		int emptyCount = 0;
		for (int row = 0; row < gridNew.length; row++)
		{
			for (int col = 0; col < gridNew[0].length; col++)
				if (gridNew[row][col] == '.')
					emptyCount++;
		}
		return emptyCount;
	}

	static int charCount(char[][] gridNew, int row, int col, char ch)
	{
		int mineCount = 0;
		if (row + 1 < gridNew.length && gridNew[row + 1][col] == ch)
			mineCount++;
		if (row + 1 < gridNew.length && col + 1 < gridNew[0].length
				&& gridNew[row + 1][col + 1] == ch)
			mineCount++;
		if (row + 1 < gridNew.length && col - 1 >= 0
				&& gridNew[row + 1][col - 1] == ch)
			mineCount++;
		if (col - 1 >= 0 && gridNew[row][col - 1] == ch)
			mineCount++;
		if (col + 1 < gridNew[0].length && gridNew[row][col + 1] == '*')
			mineCount++;
		if (row - 1 >= 0 && gridNew[row - 1][col] == ch)
			mineCount++;
		if (row - 1 >= 0 && col + 1 < gridNew[0].length
				&& gridNew[row - 1][col + 1] == ch)
			mineCount++;
		if (row - 1 >= 0 && col - 1 >= 0 && gridNew[row - 1][col - 1] == ch)
			mineCount++;
		return mineCount;
	}

	static void floodFill(char[][] gridNew, int row, int col)
	{
		// Check if on the grid
		if (row < 0 || row >= gridNew.length || col < 0
				|| col >= gridNew[0].length)
			return;
		// Check if a .
		if (gridNew[row][col] == '*')
			return;
		if (gridNew[row][col] == '.' || gridNew[row][col] == 'c')
		{
			int mineCount = charCount(gridNew, row, col, '*');
			gridNew[row][col] = (char) ('0' + mineCount);

			if (mineCount == 0)
			{
				floodFill(gridNew, row, col + 1);
				floodFill(gridNew, row - 1, col + 1);
				floodFill(gridNew, row + 1, col + 1);

				floodFill(gridNew, row + 1, col);
				floodFill(gridNew, row - 1, col);
				floodFill(gridNew, row, col - 1);
				floodFill(gridNew, row + 1, col - 1);
				floodFill(gridNew, row - 1, col - 1);
			}

		}

	}

	public static boolean isValid(char[][] gridNew)
	{
		char[][] copy = new char[gridNew.length][gridNew[0].length];
		for (int row = 0; row < gridNew.length; row++)
			for (int col = 0; col < gridNew[0].length; col++)
				copy[row][col] = gridNew[row][col];

		floodFill(copy, 0, 0);
		return countEmpty(copy) == 0;
	}

	public static boolean placeMines(int minesToPlace)
	{
		if (minesToPlace > 0)
		{
			for (int row = grid.length - 1; row >= 0; row--)
				for (int col = grid[0].length -1; col >= 0; col--)
					if (grid[row][col] == '.')
					{
						grid[row][col] = '*';
						if (placeMines(minesToPlace - 1))
							return true;
						grid[row][col] = '.';
					}
			return false;
		}
		return isValid(grid);

	}

	public static void main(String[] args) throws IOException
	{
		String fileName = "C-large";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			out.printf("Case #%d:%n", caseNo);
			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();
			System.out.printf("Case #%d: %d %d %d %n", caseNo, R, C, M);
			grid = new char[R][C];
			boolean possible = true;

			// Click in corner
			int emptySquares = R * C - M;

			// Fill in as big a square as possible
			int squareSize = (int) Math.round(Math.sqrt(emptySquares));
		//	System.out.println("SS" + squareSize );
			for (int row = 0; row < Math.min(squareSize, grid.length); row++)
				for (int col = 0; col < Math.min(squareSize, grid[0].length); col++)
					if (grid[row][col] == 0)
					{
						grid[row][col] = '.';
						emptySquares--;
					}

			if (grid[0][0] == 0)
				emptySquares--;
			grid[0][0] = 'c';

			// Need to fill in the rest of empty
			// Deal with special cases single row or col first
			if (R == 1)
			{
				int col = squareSize;
				while (emptySquares > 0)
				{
					grid[0][col++] = '.';
					emptySquares--;
				}
			}
			else if (C == 1)
			{
				int row = squareSize;
				while (emptySquares > 0)
				{
					grid[row++][0] = '.';
					emptySquares--;
				}
			}
			else
			{
				//displayGrid();
				// Fill in by complete row or column
				if (R >= C)
				{
					int row = squareSize;
					while (row < grid.length && emptySquares > 0)
					{
						for (int col = 0; col < grid[0].length; col++)
						{
							if (grid[row][col] ==  0 && emptySquares >= -4 )
							{
							grid[row][col] = '.';
							emptySquares--;
							}
						}

						row++;
					}
				}
				else
				{
					int col = squareSize;
					while (col < grid[0].length && emptySquares > 0)
					{
						for (int row = 0; row < grid.length; row++)
						{
							if (grid[row][col] ==  0 && emptySquares >= -4)
							{
							grid[row][col] = '.';
							emptySquares--;
							}
						}

						col++;
					}
				}

			}

			// Everything else is a mine
			for (int row = 0; row < grid.length; row++)
				for (int col = 0; col < grid[0].length; col++)
					if (grid[row][col] != '.' && grid[row][col] != 'c')
						grid[row][col] = '*';

			int minesLeft = -emptySquares;
			System.out.println(minesLeft);
		  //  displayGrid();
			if (minesLeft > 0)
			{
				//System.out.println("Before fill: ");
			//	displayGrid();
				if (!placeMines(minesLeft))
					possible = false;
				//System.out.println("After placing: ");
			//	displayGrid();
			}
			if (possible)
			{
				// System.out.println("Before fill: ");
				// displayGrid();
				floodFill(0, 0);
				// displayGrid();

				int emptyCount = countEmpty();
				if (emptyCount > 0)
				{
					possible = false;
					// System.out.println("This happened");
				}
				else
				{
					grid[0][0] = 'c';
					for (int row = 0; row < grid.length; row++)
						for (int col = 0; col < grid[0].length; col++)
							if (grid[row][col] >= '0' && grid[row][col] <= '8')
								grid[row][col] = '.';

				}
			}
			// }
			// else
			// possible = false;
			if (!possible)
			{
				System.out.println("Impossible");
				out.println("Impossible");
			}
			else
			{
				displayGrid();
				displayGrid(out);
			}

		}
		in.close();
		out.close();

	}
}
