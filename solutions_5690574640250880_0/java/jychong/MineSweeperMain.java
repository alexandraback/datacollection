/*
 * Google Code Jam 2014 - Problem C
 * 
 * Jae Yoon Chong (jychong1@gmail.com)
 * 
 * MineSweeperMain
 */

import java.io.*;
import java.util.*;

public class MineSweeperMain {
	
	final static int MINESWEEPER_CODE_CLICK = -2;
	final static int MINESWEEPER_CODE_MINE  = -1;
	final static int MINESWEEPER_CODE_EMPTY = 0;
	
	final static char MINESWEEPER_SYMBOL_CLICK = 'c';
	final static char MINESWEEPER_SYMBOL_MINE  = '*';
	final static char MINESWEEPER_SYMBOL_EMPTY = '.';
	
	public static class MineSweeperGridCoords {
		public int indexR;
		public int indexC;

		public MineSweeperGridCoords (int indexR, int indexC)
		{
			this.indexR = indexR;
			this.indexC = indexC;
		}
	}
	
	public static void main(String[] args)
	{
		String filename = args[0];

		FileReader fr = null;
		BufferedReader br = null;
		
		try {
			fr = new FileReader (filename);
			br = new BufferedReader(fr);

			int indexTrickCurrTrial = 1;
			
			String line = br.readLine();
            while ((line = br.readLine()) != null)
    		{	
            	// given input values
            	StringTokenizer st = new StringTokenizer(line, " ");
            	int r = Integer.parseInt(st.nextToken());
            	int c = Integer.parseInt(st.nextToken());
            	int m = Integer.parseInt(st.nextToken());
            	int totalGridCount = r * c;
            	int emptyGridCount = totalGridCount - m;
            	
            	// handle base cases
            	System.out.println("Case #" + indexTrickCurrTrial++ + ":");
            	
            	// 1) no mines
            	if (m == 0)
            	{
            		printGridFilledWithSymbol(r, c, MINESWEEPER_SYMBOL_EMPTY);
            	}
            	
            	// 2) either row or col has size 1
            	else if (r == 1 || c == 1)
            	{
            		if (r == 1)
            			printStraightMine(c, m, true);
            		else
            			printStraightMine(r, m, false);
            	}
            	
            	// 3) all except only one cell are mine cells
            	else if (emptyGridCount == 1)
            	{
            		printGridFilledWithSymbol(r, c, MINESWEEPER_SYMBOL_MINE);
            	}
            	
           		// 4) impossible cell count
            	else if ( (emptyGridCount < 4) || emptyGridCount == 5 || emptyGridCount == 7)
        		{
        			System.out.println("Impossible");
        			continue;
        		}
            	
            	// 5) either row or col has size 2
            	else if (r == 2 || c == 2)
            	{
            		if (m % 2 == 1)
        			{
            			System.out.println("Impossible");
            			continue;
            		}
            		if (r == 2)
            			printDoubleStraightMine(c, m, true);
            		else
            			printDoubleStraightMine(r, m, false);
            	}
            	
            	// 6) non-base cases (at lease 3x3, valid empty cell count (not under counted), valid mine count)
            	else
            	{
            		// 6-1) special treatments for smaller problems (4, 6, 8, 9)
            		if (emptyGridCount == 4)
            		{
            			int [][] grid = new int[r][c];
            			fillGridWithMine(grid, r, c);
            			fillGridWithEmpty(grid, 2, 2);
            			grid[0][0] = -2;
            			printGrid(grid, r, c);
            			continue;
            		}
//            		else if (emptyGridCount == 5)
//            		{
//            			int [][] grid = new int[r][c];
//            			fillGridWithMine(grid, r, c);
//            			fillGridWithEmpty(grid, 2, 2);
//            			fillGridWithEmpty(grid, 1, 3);
//            			grid[0][0] = -2;
//            			printGrid(grid, r, c);
//            			continue;
//            		}
            		else if (emptyGridCount == 6)
            		{
            			int [][] grid = new int[r][c];
            			fillGridWithMine(grid, r, c);
            			fillGridWithEmpty(grid, 2, 3);
            			grid[0][0] = -2;
            			printGrid(grid, r, c);
            			continue;
            		}
//            		else if (emptyGridCount == 7)
//            		{
//            			int [][] grid = new int[r][c];
//            			fillGridWithMine(grid, r, c);
//            			fillGridWithEmpty(grid, 2, 3);
//            			fillGridWithEmpty(grid, 3, 1);
//            			grid[0][0] = -2;
//            			printGrid(grid, r, c);
//            			continue;
//            		}
            		else if (emptyGridCount == 8)
            		{
            			int [][] grid = new int[r][c];
            			fillGridWithMine(grid, r, c);
            			fillGridWithEmpty(grid, 2, 3);
            			fillGridWithEmpty(grid, 3, 2);
            			grid[0][0] = -2;
            			printGrid(grid, r, c);
            			continue;
            		}
            		else if (emptyGridCount == 9)
            		{
            			int [][] grid = new int[r][c];
            			fillGridWithMine(grid, r, c);
            			fillGridWithEmpty(grid, 3, 3);
            			grid[0][0] = -2;
            			printGrid(grid, r, c);
            			continue;
            		}

            		else
            		{
                		int [][] grid = new int[r][c];
                		fillGridWithMine(grid, r, c);
                		
                		int emptyCountLeft = emptyGridCount; 
                				
                		int emptyRowCount = emptyGridCount / c;
                		int emptyColCount = emptyGridCount % c;
                		if (emptyColCount == 1)
                		{
                			emptyColCount = c - 1;
                			emptyRowCount--;
                		}
                		
                		if (emptyRowCount < 2)
                		{
                			emptyRowCount = 2;
                			emptyColCount = emptyGridCount / 2;
                			if (emptyGridCount % 2 == 1)
                				emptyColCount--;

                			fillGridWithEmptyRange(grid, 0, 0, 1, emptyColCount - 1);
                			fillGridWithColor(grid, 0, 0, 2, emptyColCount - 1, r, c);
                			
                			emptyCountLeft -= (emptyRowCount * emptyColCount);
                		}
                		else
                		{
                			fillGridWithEmptyRange(grid, 0, 0, emptyRowCount - 1, c - 1);
                			fillGridWithEmptyRange(grid, emptyRowCount, 0, emptyRowCount, emptyColCount - 1);
                			fillGridWithColor(grid, 0, 0, emptyRowCount, c - 1, r, c);
                			
                			emptyCountLeft -= (emptyRowCount * c) + emptyColCount;
                		}

                		boolean loopFailed = false;
                		while (emptyCountLeft > 0)
                		{
                			MineSweeperGridCoords coord = retrieveGridCoordsForEmptyCount(grid, emptyCountLeft, r, c);
                			if (coord == null)
                			{
                    			System.out.println("Impossible");
                    			loopFailed = true;
                    			break;
                    		}
                			int indexR = coord.indexR;
                			int indexC = coord.indexC;
                			int gridValue = grid[indexR][indexC];
                			fillGridWithEmptyCenterCoord(grid, indexR, indexC, r, c);
                			fillGridWithColor(grid, indexR - 2, indexC - 2, indexR + 2, indexC + 2, r, c);
                			
                			emptyCountLeft -= gridValue;
                		}
                		if (loopFailed)
                			continue;
                		
                		grid[0][0] = -2;
                		//_printGridDebug(grid,r,c);
                		printGrid(grid, r, c);
            		}
            	}
    		}

		} catch (FileNotFoundException ex) {
			// exception handling
		} catch (IOException ex) {
			// exception handling
		} finally {
			try {
				br.close();
				fr.close();
			} catch (IOException ex) {
				// exception handling
			}
		}
	}
	
	public static void fillGridWithMine(int [][] grid, int r, int c)
	{
		for (int indexR = 0; indexR < r; indexR++)
		{
			int [] gridCols = grid[indexR];
			for (int indexC = 0; indexC < c; indexC++)
			{
				gridCols[indexC] = MINESWEEPER_CODE_MINE;
			}
		}
	}

	public static void fillGridWithMineRange(int [][] grid, int startIndexR, int startIndexC, int endIndexR, int endIndexC)
	{
		for (int indexR = startIndexR; indexR <= endIndexR; indexR++)
		{
			int [] gridCols = grid[indexR];
			for (int indexC = startIndexC; indexC <= endIndexC; indexC++)
			{
				gridCols[indexC] = MINESWEEPER_CODE_MINE;
			}
		}
	}

	public static void fillGridWithEmpty(int [][] grid, int r, int c)
	{
		for (int indexR = 0; indexR < r; indexR++)
		{
			int [] gridCols = grid[indexR];
			for (int indexC = 0; indexC < c; indexC++)
			{
				gridCols[indexC] = MINESWEEPER_CODE_EMPTY;
			}
		}
	}

	public static void fillGridWithEmptyRange(int [][] grid, int startIndexR, int startIndexC, int endIndexR, int endIndexC)
	{
		for (int indexR = startIndexR; indexR <= endIndexR; indexR++)
		{
			int [] gridCols = grid[indexR];
			for (int indexC = startIndexC; indexC <= endIndexC; indexC++)
			{
				gridCols[indexC] = MINESWEEPER_CODE_EMPTY;
			}
		}
	}
	
	public static void fillGridWithEmptyCenterCoord(int [][] grid, int centerIndexR, int centerIndexC, int r, int c)
	{
		int startIndexR = centerIndexR - 1;
		int startIndexC = centerIndexC - 1;
		int endIndexR = centerIndexR + 1;
		int endIndexC = centerIndexC + 1;
		
		if (startIndexR < 0)
			startIndexR = 0;
		if (startIndexC < 0)
			startIndexC = 0;

		if (endIndexR >= r)
			endIndexR = r - 1;
		if (endIndexC >= c)
			endIndexC = c - 1;
		
		for (int indexR = startIndexR; indexR <= endIndexR; indexR++)
		{
			int [] gridCols = grid[indexR];
			for (int indexC = startIndexC; indexC <= endIndexC; indexC++)
			{
				gridCols[indexC] = MINESWEEPER_CODE_EMPTY;
			}
		}
	}
	
	public static void fillGridWithColor(int [][] grid, int startIndexR, int startIndexC, int endIndexR, int endIndexC, int r, int c)
	{
		if (startIndexR < 0)
			startIndexR = 0;
		if (startIndexC < 0)
			startIndexC = 0;

		if (endIndexR >= r)
			endIndexR = r - 1;
		if (endIndexC >= c)
			endIndexC = c - 1;
		
		for (int indexR = startIndexR; indexR <= endIndexR; indexR++)
		{
			int [] gridCols = grid[indexR];
			for (int indexC = startIndexC; indexC <= endIndexC; indexC++)
			{
				int gridValue = gridCols[indexC];
				if (gridValue == MINESWEEPER_CODE_MINE)
					continue;

				gridCols[indexC] = calculateColor(grid, indexR, indexC, startIndexR, startIndexC, endIndexR, endIndexC, r, c);
			}
		}
	}
	
	public static MineSweeperGridCoords retrieveGridCoordsForEmptyCount(int [][] grid, int emptyCount, int r, int c)
	{
		int resultIndexR = -1;
		int resultIndexC = -1;
		int resultGridValue = -1;
		
		for (int indexR = 0; indexR < r; indexR++)
		{
			int [] gridCols = grid[indexR];
			for (int indexC = 0; indexC < c; indexC++)
			{
				int gridValue = gridCols[indexC];
				if (gridValue == MINESWEEPER_CODE_MINE || gridValue == MINESWEEPER_CODE_EMPTY)
					continue;
				if (gridValue > emptyCount)
					continue;
				
				if (gridValue == emptyCount)
					return new MineSweeperGridCoords(indexR, indexC);
				
				if (gridValue > resultGridValue)
				{
					resultIndexR = indexR;
					resultIndexC = indexC;
					resultGridValue = gridValue;
				}
			}
		}
		if (resultIndexR == -1 || resultIndexC == -1)
			return null;
		return new MineSweeperGridCoords(resultIndexR, resultIndexC);
	}
	
	public static int calculateColor(int [][] grid, int currIndexR, int currIndexC, int startIndexR, int startIndexC, int endIndexR, int endIndexC, int r, int c)
	{
		int colorValue = 0;
		int indexR = 0;
		int indexC = 0;
		
		// top left
		indexR = currIndexR - 1;
		indexC = currIndexC - 1;
		if (indexR >= 0 && indexC >= 0)
		{
			if (grid[indexR][indexC] == MINESWEEPER_CODE_MINE)
				colorValue++;
		}
		
		// top
		indexR = currIndexR - 1;
		indexC = currIndexC;
		if (indexR >= 0)
		{
			if (grid[indexR][indexC] == MINESWEEPER_CODE_MINE)
				colorValue++;
		}
		
		// top right
		indexR = currIndexR - 1;
		indexC = currIndexC + 1;
		if (indexR >= 0 && indexC < c)
		{
			if (grid[indexR][indexC] == MINESWEEPER_CODE_MINE)
				colorValue++;
		}
		
		// bottom left
		indexR = currIndexR + 1;
		indexC = currIndexC - 1;
		if (indexR < r && indexC >= 0)
		{
			if (grid[indexR][indexC] == MINESWEEPER_CODE_MINE)
				colorValue++;
		}
		
		// bottom
		indexR = currIndexR + 1;
		indexC = currIndexC;
		if (indexR < r)
		{
			if (grid[indexR][indexC] == MINESWEEPER_CODE_MINE)
				colorValue++;
		}
		
		// bottom right
		indexR = currIndexR + 1;
		indexC = currIndexC + 1;
		if (indexR < r && indexC < c)
		{
			if (grid[indexR][indexC] == MINESWEEPER_CODE_MINE)
				colorValue++;
		}
		
		// left
		indexR = currIndexR;
		indexC = currIndexC - 1;
		if (indexC >= 0)
		{
			if (grid[indexR][indexC] == MINESWEEPER_CODE_MINE)
				colorValue++;
		}
		
		// right
		indexR = currIndexR;
		indexC = currIndexC + 1;
		if (indexC < c)
		{
			if (grid[indexR][indexC] == MINESWEEPER_CODE_MINE)
				colorValue++;
		}
		
		return colorValue;
	}

	
	/*
	 * Print Functions
	 */
	// print grid with non-base cases and with 2d array and dimension
	public static void printGrid(int [][] grid, int r, int c)
	{
		for (int indexR = 0; indexR < r; indexR++)
		{
			int [] gridCols = grid[indexR];
			for (int indexC = 0; indexC < c; indexC++)
			{
				switch (gridCols[indexC])
				{
				case MINESWEEPER_CODE_CLICK:
					System.out.print(MINESWEEPER_SYMBOL_CLICK);
					break;
					
				case MINESWEEPER_CODE_MINE:
					System.out.print(MINESWEEPER_SYMBOL_MINE);
					break;

				default:
					System.out.print(MINESWEEPER_SYMBOL_EMPTY);
				}
			}
			System.out.print('\n');
		}
	}

	// print grid with either row or col equals size 2
	public static void printDoubleStraightMine(int size, int m, boolean horizontal)
	{
		int mSize = m / 2;
		int mSizeMod = m % 2;
		int index = 1;
		if (horizontal)
		{
			System.out.print(MINESWEEPER_SYMBOL_CLICK);
			for (index = 1; index < size - mSize; index++)
				System.out.print(MINESWEEPER_SYMBOL_EMPTY);
			for (; index < size; index++)
				System.out.print(MINESWEEPER_SYMBOL_MINE);
			System.out.print('\n');
			
			for (index = 0; index < size - mSize - mSizeMod; index++)
				System.out.print(MINESWEEPER_SYMBOL_EMPTY);
			for (; index < size; index++)
				System.out.print(MINESWEEPER_SYMBOL_MINE);
			System.out.print('\n');
		}
		else
		{
			System.out.print(MINESWEEPER_SYMBOL_CLICK);
			System.out.println(MINESWEEPER_SYMBOL_EMPTY);
			for (index = 1; index < size - mSize - mSizeMod; index++)
				System.out.println("..");
			if (mSizeMod == 1)
			{
				System.out.println("*.");
				index++;
			}
			for (; index < size; index++)
				System.out.println("**");
		}
	}
	
	// print grid with either row or col equals size 1
	public static void printStraightMine(int size, int m, boolean horizontal)
	{
		int index = 1;
		if (horizontal)
		{
			System.out.print(MINESWEEPER_SYMBOL_CLICK);
			for (index = 1; index < size - m; index++)
				System.out.print(MINESWEEPER_SYMBOL_EMPTY);
			for (; index < size; index++)
				System.out.print(MINESWEEPER_SYMBOL_MINE);
			System.out.print('\n');
		}
		else
		{
			System.out.println(MINESWEEPER_SYMBOL_CLICK);
			for (index = 1; index < size - m; index++)
				System.out.println(MINESWEEPER_SYMBOL_EMPTY);
			for (; index < size; index++)
				System.out.println(MINESWEEPER_SYMBOL_MINE);
		}
	}
	
	// print grid with no mine or all mine (empty & filled)
	public static void printGridFilledWithSymbol(int r, int c, char symbol)
	{
		// first start with c
		System.out.print(MINESWEEPER_SYMBOL_CLICK);
		for (int indexC = 1; indexC < c; indexC++)
			System.out.print(symbol);
		System.out.print('\n');

		// rest with empty cells
		for (int indexR = 1; indexR < r; indexR++)
		{
			for (int indexC = 0; indexC < c; indexC++)
				System.out.print(symbol);
			System.out.print('\n');
		}
	}
	
	public static void _printGridDebug(int [][] grid, int r, int c)
	{
		for (int indexR = 0; indexR < r; indexR++)
		{
			int [] gridCols = grid[indexR];
			for (int indexC = 0; indexC < c; indexC++)
			{
				switch (gridCols[indexC])
				{
				case MINESWEEPER_CODE_CLICK:
					System.out.print("c");
					break;
					
				case MINESWEEPER_CODE_MINE:
					System.out.print("*");
					break;
					
				default:
					System.out.print(gridCols[indexC]);	
				}
			}
			System.out.print('\n');
		}
	}
}
