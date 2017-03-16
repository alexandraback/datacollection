
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

/**
 * @author Adrian Buturuga
 */
public class MinesweeperMagic
{

	private static void solveTestCase(int testCase, Scanner input, FileOutputStream output) throws IOException
	{
		int R = input.nextInt();
		int C = input.nextInt();
		int M = input.nextInt();

		output.write(("Case #" + testCase + ":\n").getBytes());
		if (M == 0)
		{
			writeNoMinesSolution(R, C, output);
		}
		else if (C == 1)
		{
			writeColumnLiniarSolution(R, M, output);
		}
		else if (R == 1)
		{
			writeRowLiniarSolution(C, M, output);
		}
		else if (M == R * C - 1)
		{
			writeFullSolution(R, C, output);
		}
		else if ((R * C - 1 > M && M > R * C - 4) || ((R == 2 || C == 2) && (M % 2 == 1)))
		{
			writeImpossible(output);
		}
		else
		{
			writePartialSolution(R, C, M, output);
		}
	}

	private static void writeNoMinesSolution(int R, int C, FileOutputStream output) throws IOException
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (i == 0 && j == 0)
				{
					output.write("c".getBytes());
				}
				else
				{
					output.write(".".getBytes());
				}
			}
			output.write("\n".getBytes());
		}
	}

	private static void writeColumnLiniarSolution(int R, int M, FileOutputStream output) throws IOException
	{
		output.write("c\n".getBytes());
		for (int i = 1; i < R - M; i++)
		{
			output.write(".\n".getBytes());
		}
		for (int i = 0; i < M; i++)
		{
			output.write("*\n".getBytes());
		}
	}

	private static void writeRowLiniarSolution(int C, int M, FileOutputStream output) throws IOException
	{
		output.write("c".getBytes());
		for (int i = 1; i < C - M; i++)
		{
			output.write(".".getBytes());
		}
		for (int i = 0; i < M; i++)
		{
			output.write("*".getBytes());
		}
		output.write("\n".getBytes());
	}

	private static void writeImpossible(FileOutputStream output) throws IOException
	{
		output.write("Impossible\n".getBytes());
	}

	private static void writeFullSolution(int R, int C, FileOutputStream output) throws IOException
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (i == 0 && j == 0)
				{
					output.write("c".getBytes());
				}
				else
				{
					output.write("*".getBytes());
				}
			}
			output.write("\n".getBytes());
		}
	}

	private static void writePartialSolution(int R, int C, int M, FileOutputStream output) throws IOException
	{
		// Prepare
		boolean matrix[][] = new boolean[R][];
		for (int i = 0; i < R; i++)
		{
			matrix[i] = new boolean[C];
			for (int j = 0; j < C; j++)
			{
				matrix[i][j] = true;
			}
		}
		int spaces = R * C - M;
		// Build
		matrix[0][0] = false;
		matrix[0][1] = false;
		matrix[1][0] = false;
		matrix[1][1] = false;
		spaces -= 4;
		boolean marked = true;
		while (spaces > 0 && marked)
		{
			marked = false;
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if (matrix[i][j]==false) {
						int count = getObtainableSquares(matrix, R, C, i, j);
						if (count > 0 && (count == spaces || count < spaces -1))
						{
							spaces -= count;
							mark(matrix, R, C, i, j);
							marked = true;
						}
					}
				}
			}
		}
		if (!marked) {
			writeImpossible(output);
			return;
		}

		// Display
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (i == 0 && j == 0)
				{
					output.write("c".getBytes());
				}
				else if (matrix[i][j])
				{
					output.write("*".getBytes());
				}
				else
				{
					output.write(".".getBytes());
				}
			}
			output.write("\n".getBytes());
		}
	}

	private static int getObtainableSquares(boolean matrix[][], int R, int C, int r, int c)
	{
		int count = 0;
		for (int i = r > 0 ? r - 1 : 0; i <= r + 1 && i < R; i++)
		{
			for (int j = c > 0 ? c - 1 : 0; j <= c + 1 && j < C; j++)
			{
				if (matrix[i][j])
				{
					count++;
				}
			}
		}
		return count;
	}

	private static void mark(boolean matrix[][], int R, int C, int r, int c)
	{
		for (int i = r > 0 ? r - 1 : 0; i <= r + 1 && i < R; i++)
		{
			for (int j = c > 0 ? c - 1 : 0; j <= c + 1 && c < C; j++)
			{
				matrix[i][j] = false;
			}
		}
	}

	public static void main(String args[]) throws Exception
	{
		File inputFile = new File("C-large.in");
		Scanner input = new Scanner(inputFile);

		File outputFile = new File("C-large.out");
		FileOutputStream fos = new FileOutputStream(outputFile);

		int testCases = input.nextInt();

		for (int i = 1; i <= testCases; i++)
		{
			solveTestCase(i, input, fos);
		}

		input.close();
		fos.close();
	}
}
