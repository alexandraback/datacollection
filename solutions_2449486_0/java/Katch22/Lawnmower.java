import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Scanner;


public class Lawnmower {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new FileReader(new File(args[0])));

		int problems = s.nextInt();
		s.nextLine();

		for (int prob = 0; prob < problems; prob++) {
			int n = s.nextInt();
			int m = s.nextInt();
			
			s.nextLine();
			
			int[][] board = getBoard(s, n, m);
			
			//printBoard(board);
			
			boolean canDo = good(board);
			
			System.out.println("Case #" + (prob + 1) + ": " + (canDo ? "YES" : "NO"));
		}
	}
	
	public static void printBoard(int[][] board){
		for(int i = 0; i < board.length; i++){
			System.out.println(Arrays.toString(board[i]));
		}
	}
	
	public static int[][] getBoard(Scanner s, int n, int m){
		
		int[][] board = new int[n][m];
		
		for(int i = 0; i < n; i++){
			//String line = s.nextLine();
			for(int j = 0; j < m; j++){
				//board[i][j] = line.charAt(j * 2) - '0';
				board[i][j] = s.nextInt();
			}
			s.nextLine();
		}
		
		return board;
	}
	
	public static boolean good(int[][] board){
		for(int i = 0; i < board.length; i++){
			for(int j = 0; j < board[i].length; j++){
				if(!(checkRow(board, i, board[i][j]) || checkCol(board, j, board[i][j]))){
					//System.out.println("Board failed at " + i + ", " + j);
					return false;
				}
			}
		}
		return true;
	}
	
	public static boolean checkRow(int[][] board, int row, int height){
		for(int i = 0; i < board[row].length; i++){
			if(board[row][i] > height){
				//System.out.println("Row check failed: " + row + ", " + i);
				return false;
			}
		}
		return true;
	}
	
	public static boolean checkCol(int[][] board, int col, int height){
		for(int i = 0; i < board.length; i++){
			if(board[i][col] > height){
				//System.out.println("Col check failed: " + i + ", " + col);
				return false;
			}
		}
		return true;
	}
	
}
