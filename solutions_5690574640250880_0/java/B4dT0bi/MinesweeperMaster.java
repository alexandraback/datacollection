import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;
import java.util.HashSet;

public class MinesweeperMaster
{

	public static void main(String[] args)
	{
//		solve(0, 5, 5, 21);
		// solve(1, 5, 5, 19);
		// solve(1, 5, 5, 0);
		// solve(2, 3, 1, 1);
		// solve(3, 2, 2, 1);
		// solve(19, 4, 5, 13);
		// solve(4, 4, 7, 3);
		// solve(5, 10, 10, 82);
		// solve(6, 50, 50, 82);
		// solve(7, 50, 50, 2410);
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			int anzTC = Integer.parseInt(br.readLine());
			for (int tc = 0; tc < anzTC; tc++)
			{
				String[] tmp = br.readLine().split(" ");
				solve(tc + 1, Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]), Integer.parseInt(tmp[2]));
			}
			br.close();
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}

	}

	private static void solve(int tc, int row, int col, int mines)
	{
		int field[][] = new int[row][col];
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
			{
				field[r][c] = EMPTY;
			}
		}
		int cornerField[][] = fromCorner(row, col, mines);
		if (cornerField != null)
		{
			field = cornerField;
		}
		else
		{
			int tmpMines = mines - fillEdges(field, 0, row - 1, 0, col - 1, mines);
			// printField(-1, field);
			field = getRecField(field, row, col, tmpMines, new HashSet<String>());
		}
		if (field == null)
		{
			System.out.println("Case #" + tc + ":\nImpossible");
		}
		else
		{
			printField(tc, field);
		}
	}

	private static int[][] fromCorner(int row, int col, int mines)
	{
		if (((row * col) - mines) % 2 != 0) return null;
		int tmpField[][] = new int[row][col];
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
			{
				tmpField[r][c] = EMPTY;
			}
		}
		int tmpMines = mines;
		int crrRow = 0;
		int crrCol = 0;
		while (tmpMines > 0)
		{
			if (tmpMines >= countRow(tmpField, crrRow, false))
			{
				int tmpField2[][] = new int[row][col];
				for (int r = 0; r < row; r++)
				{
					for (int c = 0; c < col; c++)
					{
						tmpField2[r][c] = tmpField[r][c];
					}
				}
				countRow(tmpField2, crrRow, true);
				if (!isSolveable(tmpField2, false))
				{
					if (tmpMines >= countCol(tmpField, crrCol, false))
					{
						tmpMines -= countCol(tmpField, crrCol, true);
						crrCol++;
					}
				}
				else
				{
					tmpMines -= countRow(tmpField, crrRow, true);
					crrRow++;
				}
			}
			else if (tmpMines >= countCol(tmpField, crrCol, false))
			{
				tmpMines -= countCol(tmpField, crrCol, true);
				crrCol++;
			}
			else
				return null;
		}
		return isSolveable(tmpField, true) ? tmpField : null;
	}

	private static int countRow(int[][] field, int row, boolean setMine)
	{
		int result = 0;
		for (int i = 0; i < field[row].length; i++)
		{
			if (field[row][i] == EMPTY)
			{
				result++;
				if (setMine) field[row][i] = MINE;
			}
		}
		return result;
	}

	private static int countCol(int[][] field, int col, boolean setMine)
	{
		int result = 0;
		for (int i = 0; i < field.length; i++)
		{
			if (field[i][col] == EMPTY)
			{
				result++;
				if (setMine) field[i][col] = MINE;
			}
		}
		return result;
	}

	private static int fillEdges(int[][] field, int boundRL, int boundRH, int boundCL, int boundCH, int mines)
	{
		if (boundRH <= boundRL || boundCH <= boundCL) return 0;
		int outerRect = ((boundRH + 1) - (boundRL)) * ((boundCH + 1) - (boundCL));
		int innerRect = ((boundRH) - (boundRL + 1)) * ((boundCH) - (boundCL + 1));
		if (innerRect <= 0) return 0;
		if (outerRect - innerRect < mines)
		{
			for (int iC = boundCL; iC <= boundCH; iC++)
			{
				field[boundRL][iC] = MINE;
				field[boundRH][iC] = MINE;
			}
			for (int iR = boundRL; iR <= boundRH; iR++)
			{
				field[iR][boundCL] = MINE;
				field[iR][boundCH] = MINE;
			}
			// printField(-1, field);
			return (outerRect - innerRect) + fillEdges(field, boundRL + 1, boundRH - 1, boundCL + 1, boundCH - 1, mines - (outerRect - innerRect));
		}
		return 0;
	}

	private static final int CLICKED = -3;
	private static final int MINE = -2;
	private static final int EMPTY = -1;

	private static void printField(int tc, int[][] field)
	{
		System.out.println("Case #" + tc + ":");
		for (int iR = 0; iR < field.length; iR++)
		{
			String output = "";
			for (int iC = 0; iC < field[iR].length; iC++)
			{
				switch (field[iR][iC])
				{
					case EMPTY:
						output += '.';
						break;
					case MINE:
						output += '*';
						break;
					case CLICKED:
						output += 'c';
						break;
				}
			}
			System.out.println(output);
		}
	}

	private static boolean testField(int field[][], int posR, int posC)
	{
		int playField[][] = new int[field.length][field[0].length];
		int anzFree = field.length * field[0].length;
		for (int r = 0; r < field.length; r++)
		{
			for (int c = 0; c < field[0].length; c++)
			{
				if (field[r][c] == MINE)
				{
					playField[r][c] = MINE;
					anzFree--;
				}
				else
				{
					playField[r][c] = anzNeighbour(field, r, c, MINE);
				}
			}
		}
		if (anzNeighbour(field, posR, posC, MINE) != 0 && anzFree > 1) return false;
		visitNeighbours(playField, posR, posC);
		for (int r = 0; r < playField.length; r++)
		{
			for (int c = 0; c < playField[0].length; c++)
			{
				if (playField[r][c] != MINE && playField[r][c] != VISITED) return false;
			}
		}
		return true;
	}

	private static final int VISITED = -4;

	private static void visitNeighbours(int field[][], int posR, int posC)
	{
		int myValue = field[posR][posC];
		field[posR][posC] = VISITED;
		if (myValue != 0) return;
		int startRow = posR - 1;
		int startCol = posC - 1;
		int endRow = posR + 1;
		int endCol = posC + 1;
		if (startRow < 0) startRow = 0;
		if (startCol < 0) startCol = 0;
		if (endRow >= field.length) endRow = field.length - 1;
		if (endCol >= field[0].length) endCol = field[0].length - 1;
		for (int iR = startRow; iR <= endRow; iR++)
		{
			for (int iC = startCol; iC <= endCol; iC++)
			{
				if (field[iR][iC] == 0 || (myValue == 0 && field[iR][iC] != MINE && field[iR][iC] != VISITED)) visitNeighbours(field, iR, iC);
				;
			}
		}
	}

	private static int anzNeighbour(int field[][], int posR, int posC, int type)
	{
		int startRow = posR - 1;
		int startCol = posC - 1;
		int endRow = posR + 1;
		int endCol = posC + 1;
		if (startRow < 0) startRow = 0;
		if (startCol < 0) startCol = 0;
		if (endRow >= field.length) endRow = field.length - 1;
		if (endCol >= field[0].length) endCol = field[0].length - 1;
		int anz = 0;
		for (int iR = startRow; iR <= endRow; iR++)
		{
			for (int iC = startCol; iC <= endCol; iC++)
			{
				if (field[iR][iC] == type) anz++;
			}
		}
		return anz;
	}

	private static String fieldToString(int field[][])
	{
		String result = "";
		for (int i = 0; i < field.length; i++)
		{
			result += Arrays.toString(field[i]);
		}
		return result;
	}

	private static int[][] getRecField(int field[][], int row, int col, int mines, HashSet<String> fieldsTested)
	{
		int minesLeft = mines;
		for (int iR = 0; iR < row; iR++)
		{
			for (int iC = 0; iC < col; iC++)
			{
				if (field[iR][iC] == EMPTY)
				{
					int[][] tmpField = new int[row][col];
					for (int iR2 = 0; iR2 < row; iR2++)
					{
						for (int iC2 = 0; iC2 < col; iC2++)
						{
							tmpField[iR2][iC2] = field[iR2][iC2];
						}
					}
					if (minesLeft >= 1) tmpField[iR][iC] = MINE;
					if (minesLeft <= 1)
					{
						// printField(-1, tmpField);
						if (isSolveable(tmpField, true)) return tmpField;
						fieldsTested.add(fieldToString(tmpField));
					}
					else
					{
						if (!fieldsTested.contains(fieldToString(tmpField)))
						{
							int tmpResField[][] = getRecField(tmpField, row, col, minesLeft - 1, fieldsTested);
							if (tmpResField != null) return tmpResField;
							fieldsTested.add(fieldToString(tmpField));
						}
					}
				}
			}
		}
		return null;
	}

	private static boolean isSolveable(int[][] field, boolean setClicked)
	{
		for (int row = 0; row < field.length; row++)
		{
			for (int col = 0; col < field[0].length; col++)
			{
				if (field[row][col] != MINE)
				{
					if (testField(field, row, col))
					{
						if (setClicked) field[row][col] = CLICKED;
						return true;
					}
				}
			}
		}
		return false;
	}
}
