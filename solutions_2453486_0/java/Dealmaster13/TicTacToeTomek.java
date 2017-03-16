import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class TicTacToeTomek {

	private static BufferedReader br;
	private static BufferedWriter bw;
	
	private static final int numCols = 4;
	private static final int numRows = 4;

	private static final char playerXSymbol = 'X';
	private static final char playerOSymbol = 'O';
	private static final char wildcardSymbol = 'T';
	private static final char emptyCellSymbol = '.';
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// Open input file.

		try {
			br = new BufferedReader(new FileReader("input.in"));
			bw = new BufferedWriter(new FileWriter("output.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			// Initialise input and read number of cases.
			int testCases = Integer.parseInt(br.readLine());

			// For each test case.
			analyseTestCases(testCases);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		finally {
			try {
				br.close();
				bw.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private static void analyseTestCases(int testCases) throws IOException {
		for (int i = 1; i <= testCases; i++) {
			char[][] cells = getCells(readRows());
			
			if (checkPlayerWon(cells, playerXSymbol)) {
				// Player X won.
				write("Case #" + i + ": X won\n");
			}
			else if (checkPlayerWon(cells, playerOSymbol)) {
				// Player O won.
				write("Case #" + i + ": O won\n");
			}
			else if (checkGameFinished(cells)) {
				// Draw.
				write("Case #" + i + ": Draw\n");
			}
			else {
				// Game has not completed.
				write("Case #" + i + ": Game has not completed\n");
			}
			
			// Read empty line.
			br.readLine();
		}
	}

	private static String[] readRows() throws IOException {
		// Initialise game rows.
		String rows[] = new String[numRows];

		for (int i = 0; i < numRows; i++) {
			rows[i] = br.readLine();
		}
		
		return rows;
	}
	
	private static char[][] getCells(String[] rows) {
		char[][] cells = new char[numRows][numCols];
		
		for (int i = 0; i < numRows; i++) {
			cells[i] = rows[i].toCharArray();
		}
		
		return cells;
	}
	
	private static boolean checkPlayerWon(char[][] cells, char playerSymbol) {
		return checkRows(cells, playerSymbol) || checkColumns(cells, playerSymbol) || checkLeadingDiagonal(cells, playerSymbol) || checkCounterDiagonal(cells, playerSymbol);
	}
	
	private static boolean checkRows(char[][] cells, char playerSymbol) {
		boolean playerWon = false;

		int row = 0;
		
		while (!playerWon && (row < numRows)) {
			playerWon = true;
			
			for (int col = 0; col < cells[row].length; col++) {
				if ((cells[row][col] != playerSymbol) && (cells[row][col] != wildcardSymbol)) {
					playerWon = false;
				}
			}
			
			if (playerWon) {
				return playerWon;
			}
			
			row ++;
		}
		
		return false;
	}
	
	private static boolean checkColumns(char[][] cells, char playerSymbol) {
		boolean playerWon = false;

		int col = 0;
		
		while (!playerWon && (col < numCols)) {
			playerWon = true;
			
			for (int row = 0; row < cells[col].length; row++) {
				if ((cells[row][col] != playerSymbol) && (cells[row][col] != wildcardSymbol)) {
					playerWon = false;
				}
			}
			
			if (playerWon) {
				return playerWon;
			}
			
			col ++;
		}
		
		return false;
	}
	
	private static boolean checkLeadingDiagonal(char[][] cells, char playerSymbol) {
		boolean playerWon = true;
		
		for (int i = 0; i < numRows; i++) {
			if ((cells[i][i] != playerSymbol) && (cells[i][i] != wildcardSymbol)) {
				playerWon = false;
			}
		}
		
		return playerWon;
	}
	
	private static boolean checkCounterDiagonal(char[][] cells, char playerSymbol) {
		boolean playerWon = true;
		
		for (int i = 0; i < numRows; i++) {
			if ((cells[i][numRows - i - 1] != playerSymbol) && (cells[i][numRows - i - 1] != wildcardSymbol)) {
				playerWon = false;
			}
		}
		
		return playerWon;
	}
	
	private static boolean checkGameFinished(char[][] cells) {
		for (int row = 0; row < cells.length; row++) {
			for (int col = 0; col < cells[row].length; col++) {
				if (cells[row][col] == emptyCellSymbol) {
					return false;
				}
			}
		}
		
		return true;
	}
	
	private static void write(String s) {
		try {
			bw.write(s);
			System.out.print(s);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	@SuppressWarnings("unused")
	private static void printCells(char[][] cells) {
		for (int row = 0; row < cells.length; row++) {
			for (int col = 0; col < cells[row].length; col++) {
				System.out.print(cells[row][col]);
			}
			
			System.out.println();
		}
	}

}
