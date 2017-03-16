import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Scanner;


public class TicTacToe {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new FileReader(new File(args[0])));
		
		int problems = s.nextInt();
		s.nextLine();
		
		for(int prob = 0; prob < problems; prob++){
			
			char[][] board = getBoard(s);
		
			s.nextLine();
			
			//printBoard(board);
			
			boolean xwins = getGameOutcome('X', board);
			boolean owins = getGameOutcome('O', board);
			boolean gameover = gameOver(board);
			
			String winString = "";
			
			if(xwins){
				winString = "X won";
			}
			else if(owins){
				winString = "O won";
			}
			else if(!gameover){
				winString = "Game has not completed";
			}
			else
			{
				winString = "Draw";
			}
			
			System.out.println("Case #" + (prob + 1) + ": " + winString);
		}
	}
	
	public static void printBoard(char[][] board){
		for(int i = 0; i < 4; i++){
			System.out.println(Arrays.toString(board[i]));
		}
	}
	
	public static char[][] getBoard(Scanner s){
		final char[][] board = new char[4][4];
		
		for(int i = 0; i < 4; i++){
			String line = s.nextLine();
			
			//System.out.println(line);
			
			for(int j = 0; j < 4; j++){
				board[i][j] = (char)line.charAt(j);
			}
		}
		
		return board; 
	}
	
	public static boolean gameOver(char[][] board){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(board[i][j] == '.'){
					return false;
				}
			}
		}
		return true;
	}
	
	public static boolean getGameOutcome(char piece, char[][] board){
		
		//Check rows for a winner
		
		for(int i = 0; i < 4; i++){
			int rowTotal = 0;
			for(int j = 0; j < 4; j++){
				if(board[i][j] == piece || board[i][j] == 'T'){
					rowTotal++; 
				}
			}
			if(rowTotal >= 4){
//				System.out.println(piece + " is a winner on row " + i);
//				System.out.println("Row: " + Arrays.toString(board[i]));
				return true;
			}
		}
		
		//Check columns for a winner
		for(int i = 0; i < 4; i++){
			int colTotal = 0;
			for(int j = 0; j < 4; j++){
				if(board[j][i] == piece || board[j][i] == 'T'){
					colTotal++; 
				}
			}
			if(colTotal >= 4){
//				System.out.println(piece + " is a winner on col " + i);
//				System.out.println("Col: " + Arrays.toString(board[i]));
				return true;
			}
		}
		
		//Check diagonal right-to-left
		int diag = 0;
		for(int i = 0; i < 4; i++){
			if(board[i][i] == piece || board[i][i] == 'T'){
				diag++; 
			}
		}
		if(diag >= 4){
			return true;
		}
		
		//Check diagonal left-to-right
		diag = 0;
		for(int i = 0; i < 4; i++){
			if(board[i][3-i] == piece || board[i][3-i] == 'T'){
				diag++; 
			}
		}
		if(diag >= 4){
			return true;
		}
		
		return false;
	}

}
