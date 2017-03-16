import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Mines {

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner (new File("m3.in"));
		//Scanner in = new Scanner(System.in);
		int cases = in.nextInt();

		for (int caseNo = 1; caseNo <= cases; caseNo++) {
			System.out.println("Case #" + caseNo + ": ");
			solve2(in);
		}

	}

	// Sleep is good. I think this is the slightly more elegant solution.

	private static void solve2(Scanner in) {
		int rows = in.nextInt();
		int cols = in.nextInt();
		int mines = in.nextInt();

		// But with some inelegant parts...
		// Silly, easy degenerate cases.
		if (mines == 0) {
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++)
					if (r == 0 && c == 0)
						System.out.print('c');
					else
						System.out.print('.');
				System.out.println();
			}
			return;
		}

		if (rows == 1) {
			System.out.print('c');
			for (int c = 1; c < cols - mines; c++)
				System.out.print('.');
			for (int c = 0; c < mines; c++)
				System.out.print('*');
			System.out.println();
			return;
		}

		if (cols == 1) {
			System.out.println('c');
			for (int c = 1; c < rows - mines; c++)
				System.out.println('.');
			for (int c = 0; c < mines; c++)
				System.out.println('*');
			return;
		}

		// All mines?
		if (mines == rows * cols - 1) {
			System.out.print('c');
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols ; c++)
					if (r + c > 0)
						System.out.print('*');
				System.out.println();
			}
			return;
		}
		
		
		
		//  Those impossible cases
		//  Should I upload a photo of the scratch paper?  8-)
		int blanks = rows * cols - mines;
		if (blanks < 4  || blanks == 5 || blanks == 7) {
			System.out.println ("Impossible");
			return;
		}
		
		//  Okay, so here's an extra case dammit.  What if you have 9 blanks?  
		//  And another...which is needed before the 9 case.
		
		if ((rows == 2 || cols == 2) && ( mines % 2 == 1)) {
			System.out.println ("Impossible");
			return;
		}
		
		//  Now, the 9 case...we know rows > 2 and col > 2
		if (blanks == 9) {
			//  Damn...is this really the only special case?  Can 10 take care of itself?
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++)
					if (r == 1 && c == 1)
						System.out.print('c');
					else if (r < 3 && c < 3)
						System.out.print('.');
					else
						System.out.print('*');
				System.out.println();
			}
			return;
				
		}
			
		char[][] board = new char[rows][cols];
		
		for (int r = 0; r < rows; r++)
			for (int c = 0; c < cols; c++)
				board[r][c] = '.';
		board[0][0] = 'c';
		
		//  Yeah, the following was too easy.
		int filledRows = mines/cols;
		
		//  Make sure you always leave the top 3 rows empty.
		
		int highestRowToFill = rows - filledRows;
		if (highestRowToFill < 2)
			highestRowToFill = 2;
		
		for (int r = highestRowToFill; r < rows; r++)
			for (int c = 0; c < cols; c++)
				board[r][c] = '*';
			
		int extraMines = mines - cols * (rows - highestRowToFill);
		
		int currCol = cols - 1;
		int currRow = highestRowToFill - 1;
		
		while (extraMines > 1)
		{
			extraMines--;
			board[currRow][currCol] = '*';
			currRow--;
			if (currRow < 0) {
				currCol--;
				currRow = highestRowToFill - 1;
			}
		}
		
		//  That ugly last mine...
		if (extraMines > 0 && currRow != 1)
			board[currRow][currCol] = '*';
		else if (extraMines > 0)
			board[highestRowToFill - 1][currCol - 1] = '*';
			
		printBoard(board);
		//System.out.println ("Maybe impossible???");
		
	}

	private static void printBoard(char[][] board) {
		for (int r = 0; r < board.length; r++) {
			for (int c = 0; c < board[0].length; c++)
				System.out.print(board[r][c]);
			System.out.println();
		}
		
	}

	private static void solve(Scanner in) {
		int rows = in.nextInt();
		int cols = in.nextInt();
		int mines = in.nextInt();

		// Silly, easy degenerate cases.
		if (mines == 0) {
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++)
					if (r == 0 && c == 0)
						System.out.print('c');
					else
						System.out.print('.');
				System.out.println();
			}
			return;
		}

		if (rows == 1) {
			System.out.print('c');
			for (int c = 1; c < cols - mines; c++)
				System.out.print('.');
			for (int c = 0; c < mines; c++)
				System.out.print('*');
			System.out.println();
			return;
		}

		if (cols == 1) {
			System.out.println('c');
			for (int c = 1; c < rows - mines; c++)
				System.out.println('.');
			for (int c = 0; c < mines; c++)
				System.out.println('*');
			return;
		}

		// Okey dokey. So, it's not an easy case. Let's try doing the initial
		// click in a
		// position and seeing what happens.
	}

}
