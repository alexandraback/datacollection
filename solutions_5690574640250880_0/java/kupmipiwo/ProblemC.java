import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemC
{

	public static final String IMPOSSIBLE = "Impossible";
	public static final String BOMB = "*";
	public static final String EMPTY = ".";
	public static final String CLICK = "c";
	public final static String fileInput = "Samples/ProblemC/5.in";

	public static void main(String args[]) throws IOException
	{
		Scanner sc;

		final String fileOutput = fileInput.replace("in", "out.gen");

		FileOutputStream fos = new FileOutputStream(fileOutput);
		sc = new Scanner(new FileInputStream(fileInput));
		// sc = new Scanner(System.in);

		int N = sc.nextInt();

		for (int i = 1; i <= N; ++i)
		{
			final int R = sc.nextInt();
			final int C = sc.nextInt();
			final int M = sc.nextInt();

			String solution = null;
			if (R == 1 || C == 1)
			{
				solution = solveForOnes(R, C, M);
			} else if (R == 2 || C == 2)
			{
				solution = solveForTwos(R, C, M);
			} else
			{
				solution = solve(R, C, M);
			}

			StringBuilder sb = new StringBuilder();
			sb.append(String.format("Case #%d:\n%s\n", i, solution));
			String output = sb.toString();
			System.out.print(output);
			fos.write(output.getBytes());
		}
		fos.close();
		sc.close();
	}

	private static String solveForTwos(int r, int c, int m)
	{
		int diff = r * c - m;

		int numLines = m / 2;
		int length = Math.max(r, c);
		boolean[][] bombMatrix = new boolean[2][length];
		boolean doReverse = (c == 2);
		if (m % 2 == 1 || diff < 4)
		{
			if (diff == 1)
			{
				Arrays.fill(bombMatrix[0], true);
				Arrays.fill(bombMatrix[1], true);
				return createStringFromBombMatrix(bombMatrix, doReverse);
			} else
			{
				return IMPOSSIBLE;
			}
		}
		while (numLines-- > 0)
		{
			bombMatrix[0][length - numLines - 1] = true;
			bombMatrix[1][length - numLines - 1] = true;
		}

		String solution = createStringFromBombMatrix(bombMatrix, doReverse);
		return solution;
	}

	private static String createStringFromBombMatrix(boolean[][] bombMatrix,
			boolean doReverse)
	{
		int rows = bombMatrix.length;
		int cols = bombMatrix[0].length;
		StringBuilder sb = new StringBuilder(rows * cols
				+ (doReverse ? cols : rows));

		if (doReverse)
		{
			for (int i = 0; i < cols; ++i)
			{
				for (int j = 0; j < rows; ++j)
				{
					if (i == 0 && j == 0)
					{
						sb.append(CLICK);
					} else
					{
						sb.append(bombMatrix[j][i] == true ? BOMB : EMPTY);
					}
				}
				if (i != cols - 1)
					sb.append("\n");
			}
		} else
		{
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					if (i == 0 && j == 0)
					{
						sb.append(CLICK);
					} else
					{
						sb.append(bombMatrix[i][j] == true ? BOMB : EMPTY);
					}
				}
				if (i != rows - 1)
					sb.append("\n");
			}
		}
		return sb.toString();
	}

	private static String solve(int r, int c, int m)
	{
		int diff = r * c - m;
		if (diff < 8)
		{
			switch (diff)
			{
			case 7: // 2 bomby
			case 5: // 4 bomby
			case 3: // 6 bomb
			case 2: // 7 bomb
			case 0: // 9 bomb
				return IMPOSSIBLE;
			}
		}

		boolean[][] bombMatrix = new boolean[r][c];
		int curR = r - 1;
		int curC = c - 1;

		while (m > 0)
		{
			int min = Math.min(curR + 1, curC + 1);
			boolean isGoingUp;
			int zmienna;
			if (curC + 1 == min)
			{
				isGoingUp = false;
				zmienna = curC;

			} else
			{
				isGoingUp = true;
				zmienna = curR;
			}

			if (m <= min)
			{
				if (m == min - 1)
				{
					if (isGoingUp)
					{
						bombMatrix[curR][curC - 1] = true;
					} else
					{
						bombMatrix[curR - 1][curC] = true;
					}
					--m;
				}
				for (int i = zmienna; m > 0; --i)
				{
					if (isGoingUp)
					{
						bombMatrix[i][curC] = true;
					} else
					{
						bombMatrix[curR][i] = true;
					}
					--m;
				}
			} else
			{

				for (int i = zmienna; i >= 0; --i)
				{
					if (isGoingUp)
					{
						bombMatrix[i][curC] = true;
					} else
					{
						bombMatrix[curR][i] = true;
					}
					--m;
				}
			}
			if (isGoingUp)
			{
				curC--;
			} else
			{
				curR--;
			}
		}

		String result = createStringFromBombMatrix(bombMatrix, false);
		return result;
	}

	private static String solveForOnes(int r, int c, int m)
	{
		if (m == r*c)
		{
			return IMPOSSIBLE;
		}
		int length = Math.max(r, c);
		boolean[] bombSite = new boolean[length];
		Arrays.fill(bombSite, false);

		boolean inRows = r > c;
		StringBuilder result = new StringBuilder(length * 2);
		for (int i = 0; i < m; ++i)
		{
			result.append(BOMB);
			if (inRows)
			{
				result.append("\n");
			}
		}
		for (int i = 0; i < length - m - 1; ++i)
		{
			result.append(EMPTY);
			if (inRows)
			{
				result.append("\n");
			}
		}
		result.append(CLICK);
		return result.toString();
	}
}
