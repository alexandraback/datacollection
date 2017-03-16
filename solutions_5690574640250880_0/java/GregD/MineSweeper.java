/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: April 12, 2013
 * 
 * Copyright 2013 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2014.Quals.ProbC;

import java.io.*;

/**
 * @author Greg Dougherty
 *
 */
public class MineSweeper
{
	
	private static final String		kInSuffix = ".in";
	private static final String		kOutSuffix = ".out";
	private static final char[][]	kFailed = {{'I', 'm', 'p', 'o', 's', 's', 'i', 'b', 'l', 'e'}};
	
	
	/**
	 * @param args
	 */
	public static void main (String[] args)
	{
		String	inName = args[0];
		int		nameLen = inName.indexOf (kInSuffix);
		String	outName = inName.substring (0, nameLen) + kOutSuffix;
		File	dataFile = new File (args[0]);
		File	resultFile = new File (outName);
		
		try
		{
			BufferedReader	dataReader = new BufferedReader (new FileReader (dataFile));
			BufferedWriter	dataWriter = new BufferedWriter (new FileWriter (resultFile));
			String			line = dataReader.readLine ();	// Get first line
			int				numCases = Integer.parseInt (line);
			
			// Run each test case
			for (int i = 0; i < numCases; ++i)
			{
				line = dataReader.readLine ();
				
				String[]	values = line.split (" ");
				int			rows = Integer.parseInt (values[0]);
				int			cols = Integer.parseInt (values[1]);
				int			mines = Integer.parseInt (values[2]);
				boolean		swapped = false;
				
				if (rows > cols)
				{
					int	hold = rows;
					rows = cols;
					cols = hold;
					swapped = true;
				}
				
				
				dataWriter.write ("Case #" + (i + 1) + ":");
				dataWriter.newLine ();
//				dataWriter.write (line);
//				dataWriter.newLine ();
				char[][]	solution = solveMine (rows, cols, mines, swapped);
				for (char[] row : solution)
				{
					for (char cell : row)
						dataWriter.write (cell);
					dataWriter.newLine ();
				}
				
				dataWriter.flush ();
			}
			
			dataReader.close ();
			dataWriter.close ();
		}
		catch (IOException ioE)
		{
			ioE.printStackTrace ();
		}
	}
	
	
	/**
	 * 
	 * @param rows		Number of rows, will always be <= cols
	 * @param cols		Number of cols
	 * @param mines		Number of mines to put in the minefield
	 * @param swapped	True if output needs to swap the rows and columns
	 * @return	The results to print out
	 */
	private static char[][] solveMine (int rows, int cols, int mines, boolean swapped)
	{
		if (rows == 1)
			return makeRowResult (cols, mines, swapped);
		
		if (rows == 2)
			return makeTwoRowResult (cols, mines, swapped);
		
		switch (cols)
		{
			case 3:
				return solveThree (mines);
				
			case 4:
				return solveFour (rows, mines, swapped);
				
			case 5:
				return solveFive (rows, mines, swapped);
				
		}
		
		return solveXByY (rows, cols, mines, swapped);
	}
	
	
	/**
	 * Solve the 1 by X cases
	 * 
	 * @param cols		Number of cols
	 * @param mines		Number of mines
	 * @param swapped	True if rows and columns should be swapped for output
	 * @return	The results to print out
	 */
	private static char[][] makeRowResult (int cols, int mines, boolean swapped)
	{
		if (mines >= cols)
			return kFailed;
		
		int	numBlank = cols - mines;
		if (swapped)
		{
			char[][]	result = new char[cols][];
			
			result[0] = new char[1];
			result[0][0] = 'c';
			
			int i = 1;
			for (; i < numBlank; ++i)
			{
				result[i] = new char[1];
				result[i][0] = '.';
			}
			
			for (; i < cols; ++i)
			{
				result[i] = new char[1];
				result[i][0] = '*';
			}
			
			return result;
		}
		
		char[][]	result = new char[1][];
		result[0] = new char[cols];
		result[0][0] = 'c';
		
		int i = 1;
		for (; i < numBlank; ++i)
			result[0][i] = '.';
		
		for (; i < cols; ++i)
			result[0][i] = '*';
		
		return result;
	}

	
	/**
	 * Solve the 2 by X cases
	 * 
	 * @param cols		Number of cols
	 * @param mines		Number of mines
	 * @param swapped	True if rows and columns should be swapped for output
	 * @return	The results to print out
	 */
	private static char[][] makeTwoRowResult (int cols, int mines, boolean swapped)
	{
		char[][]	result = noneAllOrFourEmpty (2, cols, mines, swapped);
		if (result != null)
			return result;
		
		int	open = (cols * 2) - mines;
		// If odd or only 2, can't be done
		if (((open & 1) == 1) || (open < 4))
			return kFailed;
		
		result = makeArray (2, cols, swapped);
		
		fillArray (result, '.');
		
		int	mineRows = mines / 2;
		fillLastCols (result, '*', mineRows, swapped);
		
		return result;
	}
	
	
	/**
	 * Solve the X x 3 case.  Called after looked at the empty and "all but one" cases
	 * 
	 * @param cols		Number of columns
	 * @param mines		Number of mines
	 * @param swapped	True if rows and columns should be swapped for output
	 * @return	The results to print out
	 */
	private static char[][] makeThreeRowResult (int cols, int mines, boolean swapped)
	{
		int	squares = cols * 3;
		if ((mines == (squares - 7)) || (mines == (squares - 5)) || (mines > (squares - 4)))
			return kFailed;
		
		char[][]	result = makeArray (3, cols, swapped);
		
		if (mines == (squares - 4))
		{
			fillArray (result, '*');
			result[1][0] = result[0][1] = result[1][1] = '.';
		}
		else
		{
			fillArray (result, '.');
			
			if ((mines % 3) == 0)
				fillLastCols (result, '*', mines / 3, swapped);
			else 
			{
				int	maxSide = cols - 2;
				int	fillRows = mines / 3;
				int	side = (mines % 3) + fillRows;
				if ((fillRows > 0) && ((side <= maxSide)))
				{
					fillLastCols (result, '*', fillRows, swapped);
					fillLastRow (result, side, swapped);
				}
				else if (fillRows == 0)
					fillLastRow (result, mines, swapped);
				else
					return kFailed;
			}
		}
		
		return result;
	}
	
	
	/**
	 * Solve the X x Y case.  Called after looked at the empty, "all but one", and four empty cases
	 * 
	 * @param rows		Number of rows
	 * @param mines		Number of mines
	 * @param swapped	True if rows and columns should be swapped for output
	 * @return	The results to print out
	 */
	private static char[][] solveXByY (int rows, int cols, int mines, boolean swapped)
	{
		int	squares = rows * cols;
		if ((mines == (squares - 7)) || (mines == (squares - 5)) || (mines > (squares - 4)))
			return kFailed;
		
		char[][]	result = makeArray (rows, cols, swapped);
		int			toFill;
		int			maxRows = rows - 2;
		int			maxCols = cols - 2;
		
		fillArray (result, '.');
		
		if (((mines % cols) == 0) && ((toFill = (mines / cols)) <= maxRows))
			fillLastRows (result, '*', toFill, swapped);
		else if (((mines % rows) == 0) && ((toFill = (mines / rows)) <= maxCols))
			fillLastCols (result, '*', toFill, swapped);
		else 
		{
			int	maxSide = cols - 2;
			int	fillCols = mines / rows;
			int	side = (mines % rows) + fillCols;
			if ((side <= maxSide) && (fillCols <= maxCols))
			{
				if (fillCols > 0)
				{
					fillLastCols (result, '*', fillCols, swapped);
					fillLastRow (result, side, swapped);
				}
				else
					fillLastRow (result, mines, swapped);
			}
			else if ((fillCols < maxCols) && ((side - fillCols) <= maxRows))
			{
				side = (mines % rows);
				fillLastCols (result, '*', fillCols, swapped);
				fillCol (result, (cols - fillCols) - 1, side, swapped);
			}
			else
			{
				maxSide = rows - 2;
				int	fillRows = mines / cols;
				side = (mines % cols) + fillRows;
				
				if ((side <= maxSide) && (fillRows <= maxRows))
				{
					if (fillRows > 0)
					{
						fillLastRows (result, '*', fillRows, swapped);
						fillLastRow (result, side, !swapped);
					}
					else
						fillLastRow (result, mines, !swapped);
				}
				else if ((fillRows < maxRows) && ((side - fillRows) <= maxCols))
				{
					side = (mines % cols);
					fillLastRows (result, '*', fillRows, swapped);
					fillRow (result, (rows - fillRows) - 1, side, swapped);
				}
				else if (!checkRectangle (result, rows, cols, mines, swapped) && 
						!checkL (result, rows, cols, mines, swapped))
				{
					return kFailed;
				}
			}
		}
		
		return result;
	}
	
	
	/**
	 * Solve the case if trying to fit a rectangle that is at least 2 on each side
	 * 
	 * @param target	Array to use, must be filled in with c and '.'
	 * @param rows		Number of rows
	 * @param cols		Number of columns
	 * @param mines		Number of mines
	 * @param swapped	True if rows and columns should be swapped for output
	 * @return	True if solved with a rectangle, false if didn't and made no changes
	 */
	private static boolean checkRectangle (char[][] target, int rows, int cols, int mines, boolean swapped)
	{
		int	nonMines = (rows * cols) - mines;
		
		if (nonMines < 4)
			return false;
		
		for (int width = 2; width < rows; ++width)
		{
			int	length = nonMines / width;
			if ((length <= cols) && ((nonMines % width) == 0))
			{
				makeRectangle (target, width, length, swapped);
				return true;
			}
		}
		
		for (int width = 2; width < cols; ++width)
		{
			int	length = nonMines / width;
			if ((length <= rows) && ((nonMines % width) == 0))
			{
				makeRectangle (target, width, length, !swapped);
				return true;
			}
		}
		
		return false;
	}
	
	
	/**
	 * 
	 * @param target	Array to use, must be filled in with c and '.'
	 * @param clearRows	Number of rows that don't have mines in them
	 * @param clearCols	Number of rows that don't have mines in them
	 * @param swapped	True if rows and columns of the rectangle should be swapped for output
	 */
	private static void makeRectangle (char[][] target, int clearRows, int clearCols, boolean swapped)
	{
		if (swapped)
		{
			int	hold = clearRows;
			clearRows = clearCols;
			clearCols = hold;
		}
		
		int	rows = target.length;
		int	cols = target[0].length;
		
		for (int i = 0; i < rows; ++i)
		{
			char[]	row = target[i];
			for (int j = 0; j < cols; ++j)
			{
				if ((i >= clearRows) || (j >= clearCols))
					row[j] = '*';
			}
		}
	}
	
	
	/**
	 * Solve the case if trying to fit a line on bottom 2 less than length of bottom, plus line up side 
	 * at least two less than length of side
	 * 
	 * @param target	Array to use, must be filled in with c and '.'
	 * @param rows		Number of rows
	 * @param cols		Number of columns
	 * @param mines		Number of mines
	 * @param swapped	True if rows and columns should be swapped for output
	 * @return	True if solved with a rectangle, false if didn't and made no changes
	 */
	private static boolean checkL (char[][] target, int rows, int cols, int mines, boolean swapped)
	{
		// Skip two from each side, overlap at corner
		if ((rows + cols - 5) < mines)
			return false;
		
		cols -= 2;
		fillLastRow (target, cols, swapped);
		mines = (mines - cols) + 1;	// Add one for corner
		fillLastRow (target, mines, !swapped);
		
		return true;
	}
	
	
	/**
	 * Solve the 3 x 3 case
	 * 
	 * @param mines	Number of mines
	 * @return	The results to print out
	 */
	private static char[][] solveThree (int mines)
	{
		char[][]	result = noneAllOrFourEmpty (3, 3, mines, false);
		if (result != null)
			return result;
		
		if ((mines == 2) || (mines == 4) || (mines > 5))
			return kFailed;
		
		result = makeArray (3, 3, false);
		fillArray (result, '.');
		
		char[]	row = result[2];	// Get the last row
		for (int i = 0; i < mines; ++i)
			row[i] = '*';
		
		return result;
	}
	
	
	/**
	 * Solve the 4 x 3 and 4 x 4 cases
	 * 
	 * @param rows		Number of rows
	 * @param mines		Number of mines
	 * @param swapped	True if rows and columns should be swapped for output
	 * @return	The results to print out
	 */
	private static char[][] solveFour (int rows, int mines, boolean swapped)
	{
		char[][]	result = noneAllOrFourEmpty (rows, 4, mines, swapped);
		if (result != null)
			return result;
		
		if (rows == 3)
			return makeThreeRowResult (4, mines, swapped);
		
		if ((mines == 9) || (mines == 11) || (mines > 12))
			return kFailed;
		
		result = makeArray (4, 4, false);
		
		fillArray (result, '.');
		
		if ((mines % 4) == 0)
			fillLastCols (result, '*', mines / 4, swapped);
		else if (mines < 3)
			fillLastRow (result, mines, swapped);
		else if (mines > 6)	// 7, 10
		{
			int	fillRows = mines / 4;
			fillLastCols (result, '*', fillRows, swapped);
			fillLastRow (result, (mines % 4) + fillRows, swapped);
		}
		else if (mines >= 5)
		{
			fillLastCols (result, '*', 1, swapped);
			result[3][2] = '*';
			if (mines > 5)
				result[2][2] = '*';
		}
		else if (mines == 3)
		{
			result[3][2] = result[2][3] = result[3][3] = '*';
		}
		
		return result;
	}
	
	
	/**
	 * Solve the 5 x 3, 5 x 4 and 5 x 5 cases
	 * 
	 * @param rows		Number of rows
	 * @param mines		Number of mines
	 * @param swapped	True if rows and columns should be swapped for output
	 * @return	The results to print out
	 */
	private static char[][] solveFive (int rows, int mines, boolean swapped)
	{
		char[][]	result = noneAllOrFourEmpty (rows, 5, mines, swapped);
		if (result != null)
			return result;
		
		if (rows == 3)
			return makeThreeRowResult (5, mines, swapped);
		
		return solveXByY (rows, 5, mines, swapped);
	}
	
	
	/**
	 * Solve the cases where there are no mines, or all mines but one
	 * 
	 * @param rows		Number of rows
	 * @param cols		Number of columns
	 * @param mines		Number of mines
	 * @param swapped	True if rows and columns should be swapped for output
	 * @return	A filled in array, or null if not the special cases
	 */
	private static char[][] noneAllOrFourEmpty (int rows, int cols, int mines, boolean swapped)
	{
		int	squares = cols * rows;
		if ((mines == 0) || (mines == (squares - 1)))
		{
			char[][]	result = makeArray (rows, cols, swapped);
			char		fill;
			
			if (mines == 0)
				fill = '.';
			else
				fill = '*';
			
			fillArray (result, fill);
			
			return result;
		}
		
		if (mines == (squares - 4))
		{
			char[][]	result = makeArray (rows, cols, swapped);
			
			fillArray (result, '*');
			result[1][0] = result[0][1] = result[1][1] = '.';
			
			return result;
		}
		
		return null;
	}
	
	
	/**
	 * Make an empty array
	 * 
	 * @param rows	Number of rows
	 * @param cols	Number of columns
	 * @return	An array
	 */
	private static char[][] makeArray (int rows, int cols, boolean swapped)
	{
		if (swapped)
		{
			int	hold = rows;
			rows = cols;
			cols = hold;
		}
		
		char[][]	result = new char[rows][];
		for (int i = 0; i < rows; ++i)
			result[i] = new char[cols];
		
		return result;
	}

	
	/**
	 * Fill an array with "fill", putting a 'c' at 0, 0
	 * 
	 * @param target	Array to fill
	 * @param fill		What to fill it with
	 */
	private static void fillArray (char[][] target, char fill)
	{
		int	cols = target[0].length;
		
		for (char[] row : target)
		{
			for (int i = 0; i < cols; ++i)
				row[i] = fill;
		}
		
		target[0][0] = 'c';
	}
	
	
	/**
	 * Fill the last mineRows cols or rows (depending on if swapped) with fill
	 * 
	 * @param target	Array to fill
	 * @param fill		What to fill it with
	 * @param mineRows	Number of columns or rows (if swapped) to fill with "fill"
	 * @param swapped	If true fill rows, false fill cols
	 */
	private static void fillLastCols (char[][] target, char fill, int mineRows, boolean swapped)
	{
		fillLastRows (target, fill, mineRows, !swapped);
	}
	
	
	/**
	 * Fill the last mineRows rows or cols (depending on if swapped) with fill
	 * 
	 * @param target	Array to fill
	 * @param fill		What to fill it with
	 * @param mineRows	Number of columns or rows (if swapped) to fill with "fill"
	 * @param swapped	If true fill rows, false fill cols
	 */
	private static void fillLastRows (char[][] target, char fill, int mineRows, boolean swapped)
	{
		int	cols = target[0].length;
		
		if (swapped)
		{
			int	start = cols - mineRows;
			
			for (char[] row : target)
			{
				for (int i = start; i < cols; ++i)
					row[i] = fill;
			}
		}
		else
		{
			int	rows = target.length;
			int	start = rows - mineRows;
			
			for (int i = start; i < rows; ++i)
			{
				char[]	row = target[i];
				for (int j = 0; j < cols; ++j)
					row[j] = fill;
			}
		}
	}
	
	
	/**
	 * Fill last row / col of an array with count mines
	 * 
	 * @param target	Array to fill
	 * @param mines		Number of cells to fill
	 * @param swapped	If true fill col, false fill row
	 */
	private static void fillLastRow (char[][] target, int mines, boolean swapped)
	{
		if (swapped)
		{
			int	col = target[0].length - 1;
			int	lastRow = target.length - 1;
			
			for (int i = 0; i < mines; ++i)
				target[lastRow - i][col] = '*';
		}
		else
		{
			char[]	row = target[target.length - 1];	// Get the last row
			int		lastCol = row.length - 1;
			for (int i = 0; i < mines; ++i)
				row[lastCol - i] = '*';
		}
	}
	
	
	/**
	 * Fill last row / col of an array with count mines
	 * 
	 * @param target	Array to fill
	 * @param mines		Number of cells to fill
	 * @param swapped	If true fill col, false fill row
	 */
	private static void fillCol (char[][] target, int theRow, int mines, boolean swapped)
	{
		fillRow (target, theRow, mines, !swapped);
	}
	
	
	/**
	 * Fill last row / col of an array with count mines
	 * 
	 * @param target	Array to fill
	 * @param mines		Number of cells to fill
	 * @param swapped	If true fill col, false fill row
	 */
	private static void fillRow (char[][] target, int theRow, int mines, boolean swapped)
	{
		if (swapped)
		{
			int	col = theRow;
			int	lastRow = target.length - 1;
			
			for (int i = 0; i < mines; ++i)
				target[lastRow - i][col] = '*';
		}
		else
		{
			char[]	row = target[theRow];	// Get the row to fill
			int		lastCol = row.length - 1;
			for (int i = 0; i < mines; ++i)
				row[lastCol - i] = '*';
		}
	}
	
}
