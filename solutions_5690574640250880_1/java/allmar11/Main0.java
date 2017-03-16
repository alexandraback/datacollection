/*
 * This code is meant to run under the Java Runtime Environment, version 1.7 or
 * later.
 */

package qualification.c;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class Main0 {
	
	// This is used to work around the inability of Eclipse to use a file as
	// System.in when running a program.
	private static final String IN_FILE_NAME = "input.txt";

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE_NAME)));
		
		int numCases = in.nextInt();
		
		for (int i = 1; i <= numCases; i++) {
			int r = in.nextInt();
			int c = in.nextInt();
			int m = in.nextInt(); 
			
			String result = solve(r, c, m);
			System.out.println(String.format("Case #%s:\n%s", i, result));
		}
		
		in.close();
	}
	
	private static String solve(int height, int width, int mines) {
		// Handle some simple special cases so other code doesn't have to
		// consider them.
		int freeSpaces = (height*width) - mines;
		if (mines == 0) {
			return boardToString(buildClearBoard(height, width), false);
		}
		assert(freeSpaces > 0);
		if (freeSpaces == 1) {
			return boardToString(buildSingleFreeSpaceBoard(height, width),
				false);
		}
		
		// For simplicity, require width to be no greater than height.
		boolean rotateBoard = false;
		if (width > height) {
			int temp = width;
			width = height;
			height = temp;
			rotateBoard = true;
		}
		
		// Three cases: width = 1, width = 2, width > 2.
		
		// Handle special cases where the board width is 1 or 2.
		if (width == 1) {
			return solveWithWidthOne(height, mines, rotateBoard);
		}
		else if (width == 2) {
			return solveWithWidthTwo(height, mines, rotateBoard);
		}
		else {
			return solveWithWidthAboveTwo(height, width, mines, rotateBoard);
		}
	}
	
	private static String solveWithWidthOne(int height, int mines,
		boolean rotateBoard)
	{
		assert(1 <= height);
		assert(mines > 0);
		
		int numNonMines = height - mines;
		assert(numNonMines > 1);
		
		// With width 1, there is always a solution.  Simply place the non-mines
		// together at the top of the board.
		char[][] board = new char[height][1];
		for (int i = 0; i < numNonMines; i++) {
			board[i][0] = (i == 0) ? 'c' : '.';
		}
		for (int i = numNonMines; i < height; i++) {
			board[i][0] = '*';
		}
		
		return boardToString(board, rotateBoard);
	}
	
	private static String solveWithWidthTwo(int height, int mines,
		boolean rotateBoard)
	{
		assert(2 <= height);
		assert(mines > 0);
		
		int numNonMines = (2*height) - mines;
		assert(numNonMines > 1);
		
		// With width 2, there is a solution if and only if the number of
		// non-mines is even and not 2.  The solution can be obtained by simply
		// placing the non-mines together in the top rows of the board.
		if (numNonMines == 2 || numNonMines % 2 != 0) {
			return "Impossible";
		}
		
		char[][] board = new char[height][2];
		for (int i = 0; i < numNonMines/2; i++) {
			board[i][0] = (i == 0) ? 'c' : '.';
			board[i][1] = '.';
		}
		for (int i = numNonMines/2; i < height; i++) {
			board[i][0] = '*';
			board[i][1] = '*';
		}
		
		return boardToString(board, rotateBoard);
	}
	
	private static String solveWithWidthAboveTwo(int height, int width,
		int mines, boolean rotateBoard)
	{
		assert(width > 2);
		assert(width <= height);
		assert(mines > 0);
		
		int numNonMines = (width*height) - mines;
		assert(numNonMines > 1);
		
		// With width above two, there is no solution if numNonMines is 2, 3, 5,
		// or 7.
		if (numNonMines == 2 || numNonMines == 3 || numNonMines == 5
			|| numNonMines == 7)
		{
			return "Impossible";
		}
		
		// A solution can be constructed by starting with a board full of mines,
		// setting the four spaces in the top-left corner to be non-mines, and
		// then adding non-mines (in groups of 2 or 1) as needed to the
		// boundaries of the non-mine region.
		
		char[][] board = new char[height][width];
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				board[i][j] = '*';
			}
		}
		board[0][0] = 'c';
		board[0][1] = '.';
		board[1][0] = '.';
		board[1][1] = '.';
		
		if (numNonMines == 4) {
			return boardToString(board, rotateBoard);
		}
		if (numNonMines >= 6) {
			board[0][2] = '.';
			board[1][2] = '.';
			if (numNonMines == 6) {
				return boardToString(board, rotateBoard);
			}
		}
		if (numNonMines >= 8) {
			board[2][0] = '.';
			board[2][1] = '.';
			if (numNonMines == 8) {
				return boardToString(board, rotateBoard);
			}
		}
		
		assert(numNonMines > 8);
		
		// At this point, the 8 spaces in the top-left corner have been "filled"
		// with non-mines.  If the required number of non-mines is odd, it will
		// be necessary to add a non-mine at the remaining position in the 3x3
		// square at the top-left, so go ahead and do that now.
		boolean numNonMinesEven = (numNonMines % 2 == 0);
		if (!numNonMinesEven) {
			board[2][2] = '.';
		}
		
		// Add groups of 2 spaces to the non-mine region along the top and left
		// sides of the board, until no more of these groups are available.
		int numNonMinesToAdd = numNonMines - (numNonMinesEven ? 8 : 9);
		assert(numNonMinesToAdd % 2 == 0);
		int nextColOnRight = 3;
		int nextRowDown = 3;
		while (numNonMinesToAdd > 0 && nextColOnRight < width) {
			board[0][nextColOnRight] = '.';
			board[1][nextColOnRight] = '.';
			numNonMinesToAdd -= 2;
			nextColOnRight++;
		}
		while (numNonMinesToAdd > 0 && nextRowDown < height) {
			board[nextRowDown][0] = '.';
			board[nextRowDown][1] = '.';
			numNonMinesToAdd -= 2;
			nextRowDown++;
		}
		
		// If we ran out of pairs to add, that means we have added every
		// position in the first two rows and first two columns to the non-mine
		// region.  In that case, we can just go down the rows and fill in
		// non-mines until we have enough.
		int i = 0;
		while (numNonMinesToAdd > 0) {
			int nextRow = 2 + (i / (width-2));
			int nextCol = 2 + (i % (width-2));
			if (board[nextRow][nextCol] == '*') {
				board[nextRow][nextCol] = '.';
				numNonMinesToAdd--;
			}
			i++;
		}
		
		assert(numNonMinesToAdd == 0);
		return boardToString(board, rotateBoard);
	}
	
	// Builds a board containing no mines.
	private static char[][] buildClearBoard(int height, int width) {
		char[][] result = new char[height][width];
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				result[i][j] = '.';
			}
		}
		result[0][0] = 'c';
		
		return result;
	}
	
	// Builds a board containing only one free space.
	private static char[][] buildSingleFreeSpaceBoard(int height, int width) {
		char[][] result = new char[height][width];
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				result[i][j] = '*';
			}
		}
		result[0][0] = 'c';
		
		return result;
	}
	
	private static String boardToString(char[][] board, boolean rotateBoard) {
		int numRows = rotateBoard ? board[0].length : board.length;
		int numCols = rotateBoard ? board.length : board[0].length;
		
		StringBuilder result = new StringBuilder();
		for (int row = 0; row < numRows; row++) {
			for (int col = 0; col < numCols; col++) {
				result.append(rotateBoard ? board[col][row] : board[row][col]);
			}
			if (row != numRows-1) {
				result.append("\n");
			}
		}
		
		return result.toString();
	}
}