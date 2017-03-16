import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Main Class
 * Solves all Google Code Jam Tasks.
 * @author Jones
 */
public class Main {

	private static boolean isBoardFound = false;
	private static String[][] finalBoard = null;
	private static int cols = 0;
	private static int rows = 0;

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// read input file and prepare buffered writer
		Scanner sc = new Scanner(new File("C-small-attempt0.in"));
		BufferedWriter wr = new BufferedWriter(new FileWriter("C-small-attempt0.out"));
		
		// get the number of test cases
		int noCases = sc.nextInt();

		for(int i=0; i<noCases; i++) {
			// reset previous results
			isBoardFound = false;
			finalBoard = null;
			
			// input
			rows = sc.nextInt();	// rows
			cols = sc.nextInt(); // cols
			int mines = sc.nextInt(); // mines
			int nLen = rows * cols; // length of the board string

			// generate board string array
			String[] boardArr = new String[nLen];
			for(int m = 0; m < nLen; m++){
				boardArr[m] = (m < mines) ? "*" : ".";
			}
			
			// calculate possible boards
			generateBoard(boardArr, 0);
			
			// print out result
			wr.write("Case #" + (i+1) + ":");
			wr.newLine();
			if(isBoardFound && finalBoard != null){
				for(int m = 0; m < finalBoard.length; m++){
					for(int n = 0; n < finalBoard[m].length; n++){
						wr.write(finalBoard[m][n]);
					}
					wr.newLine();
				}
			}else{
				wr.write("Impossible");
				wr.newLine();
			}
		}
		wr.close();
	}
	
	/**
	 * Processes the click on a board cell (recursively)
	 * @param board
	 * @param row
	 * @param col
	 * @return
	 */
	private static String[][] processClick(String[][] board, int row, int col){
		// process first click
		int initScore = getScore(board, row, col);
		if(initScore != 0){
			board[row][col] = initScore + "";
			return board;
		}
		
		for(int colt = col-1; colt <= col+1; colt++){
			for(int rowt = row-1; rowt <= row+1; rowt++){
				// validate field
				if(colt < 0 || colt >= board[0].length || rowt < 0 || rowt >= board.length){
					// field is not valid
					continue;
				}
				
				//ignore already filled fields
				if(!board[rowt][colt].equalsIgnoreCase(".")){
					continue;
				}
				
				int score = getScore(board, rowt, colt);
				board[rowt][colt] = score + "";
				
				if(score == 0){
					processClick(board, rowt, colt);
				}
			}
		}
		
		return board;
	}
	
	/**
	 * calculate the score of a cell
	 * @param board
	 * @param row
	 * @param col
	 * @return
	 */
	private static int getScore(String[][] board, int row, int col){
		int result = 0;
		for(int colt = col-1; colt <= col+1; colt++){
			for(int rowt = row-1; rowt <= row+1; rowt++){
				// validate field
				if(colt < 0 || colt >= board[0].length || rowt < 0 || rowt >= board.length){
					// field is not valid
					continue;
				}
				if(board[rowt][colt].equalsIgnoreCase("*")){
					result++;
				}
			}
		}
		
		return result;
	}
	
	/**
	 * Check whether the given board is won or not
	 * @param board
	 * @return
	 */
	private static boolean isGameWon(String[][] board){
		for(int m = 0; m < board.length; m++){
			for(int n = 0; n < board[m].length; n++){
				if(board[m][n].equalsIgnoreCase(".")){
					return false;
				}
			}
		}
		
		return true;
	}
	
	/**
	 * Checks if the new board is the solution (one click that wins the game)
	 * @param genBoard
	 */
	private static void checkNewBoard(ArrayList<String> genBoard){
		if(isBoardFound) return;
		
		// generate array board
		String[][] board = new String[rows][cols];
		int rCount = 0;
		int cCount = 0;

		for(int m = 1; m <= genBoard.size(); m++){
			board[rCount][cCount] = genBoard.get(m-1);
			if((m % cols) == 0){
				rCount++;
				cCount = -1;
			}
			cCount++;
		}
		
		// check every possible clickable cell
		for(int m = 0; m < rows; m++){
			for(int n = 0; n < cols; n++){
				if(board[m][n].equalsIgnoreCase(".")){
					String[][] nB = cloneArr(board, cols, rows);
					nB = processClick(nB, m, n);
					
					if(isGameWon(nB)){
						isBoardFound = true;
						board[m][n] = "c";
						finalBoard = board;
						return;
					}
				}
			}
		}	
	}
	
	private static String[][] cloneArr(String[][] arr, int c, int r){
		String[][] result = new String[r][c];
		for(int m = 0; m < r; m++){
			for(int n = 0; n < c; n++){
				result[m][n] = arr[m][n];
			}
		}
		
		return result;
	}
	
	private static void generateBoard(String[] brd, int start) {
	 
		if (start >= brd.length ) {
			ArrayList<String> item = arrToList(brd);
			checkNewBoard(item);
		}
	 
		if(isBoardFound){
			return;
		}
		
		for (int j = start; j <= brd.length-1; j++) {
			if (isDuplicateAv(brd, start, j)) {
				swap(brd, start, j);
				generateBoard(brd, start + 1);
				swap(brd, start, j);
			}
		}
	}
	 
	private static ArrayList<String> arrToList(String[] brd) {
		ArrayList<String> item = new ArrayList<String>();
		for (int h = 0; h < brd.length; h++) {
			item.add(brd[h]);
		}
		return item;
	}
	 
	private static boolean isDuplicateAv(String[] arr, int start, int end) {
		for (int i = start; i <= end-1; i++) {
			if (arr[i] == arr[end]) {
				return false;
			}
		}
		return true;
	}
	 
	private static void swap(String[] arr, int i, int j) {
		String tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}
