import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class TicTacToeTomek {

	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("tictomek.out"));
		
		int T = Integer.parseInt(in.nextLine());
		
		for (int t = 1; t <= T; t++) {
			if(t > 1) in.nextLine();
			
			char board[][] = new char[4][];
			
			int empty = 0;
			
			for (int i = 0; i < board.length; i++) {
				board[i] = in.nextLine().toCharArray();
				for (int j = 0; j < 4; j++) {
					if(board[i][j] == '.') 
						empty++;
				}
			}
			
			if(win('X', board)){
				out.println("Case #" + t + ": X won");
			}
			else if(win('O', board)){
				out.println("Case #" + t + ": O won");
			}
			else if(empty == 0){
				out.println("Case #" + t + ": Draw");
			}
			else {
				out.println("Case #" + t + ": Game has not completed");
			}
		}
		
		out.close();
		
	}

	private static boolean win(char c, char[][] board) {
		
		for (int i = 0; i < 4; i++) {
			int count = 0;
			for (int j = 0; j < 4; j++) {
				if(board[i][j] == c || board[i][j] == 'T') count++;
			}
			if(count == 4) return true;
			
			count = 0;
			for (int j = 0; j < 4; j++) {
				if(board[j][i] == c || board[j][i] == 'T') count++;
			}
			if(count == 4) return true;
			
		}
		
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < 4; i++) {
			if(board[i][i] == c || board[i][i] == 'T') count1++;
			if(board[i][3-i] == c || board[i][3-i] == 'T') count2++;
		}
		if(count1 == 4 || count2 == 4) return true;
		return false;
	}

}
