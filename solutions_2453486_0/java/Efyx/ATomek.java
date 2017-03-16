import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class ATomek {
	
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(args[0]));
		
		int T = scanner.nextInt();
		for(int t=0; t<T; t++) {
			System.out.print("Case #" + (t+1) + ": ");
			char [][] board = buildBoard(scanner);
			char s = getStatus(board);
			
			switch(s) {
			case 'X':
			case 'O':
				System.out.println(s + " won");
				break;
			case '.':
				System.out.println("Game has not completed");
				break;
			case'T':
				System.out.println("Draw");
				break;
			}
			
		}
	}
	
	private static char getStatus(char[][] board) {
		// Horizontal
		for(int i=0; i<4; i++) {
			char c = getStatus(board[i]);
			if(c != '\0') return c;
		}
		
		// Vertical
		for(int j=0; j<4; j++) {
			char c = getStatus(board[0][j], board[1][j], board[2][j], board[3][j]);
			if(c != '\0') return c;
		}
		
		// Diagonal
		char c = getStatus(board[0][0], board[1][1], board[2][2], board[3][3]);
		if(c != '\0') return c;
		
		c = getStatus(board[0][3], board[1][2], board[2][1], board[3][0]);
		if(c != '\0') return c;
		
		// not completed
		for(int i=0; i<4; i++) for(int j=0; j<4; j++) {
			if(board[i][j] == '.') {
				return '.';
			}
		}
		
		// Draw
		return 'T';
	}
	
	private static char getStatus(char ... array) {
		char c = array[0] != 'T' ? array[0] : array[1];
		if(c != '.') {
			int i;
			for(i=0; i<array.length; i++) {
				if(array[i] != c && array[i] != 'T') {
					return '\0';
				}
			}
			if(i == array.length) {
				return c;
			}
		}
		
		return '\0';
	}
	
	private static char[][] buildBoard(Scanner scanner) {
		char[][] board = new char[4][];
		
		scanner.nextLine();// skip new line
		for(int i=0; i<board.length; i++) {
			board[i] = scanner.nextLine().toCharArray();
		}
		
		return board;
	}
}
