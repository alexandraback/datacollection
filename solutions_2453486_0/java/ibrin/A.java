import java.io.*;
import java.util.*;

public class A
{
/*
	private static void print(char[][] array) {
		for(int i = 0; i < array.length; i++) {
			for(int j = 0; j < array[i].length; j++) {
				System.out.print(array[i][j] + ", ");
			}
			System.out.println();
		}
	}
*/
	private static boolean anyDots(char[][] board) {
		for(int i = 0; i < board.length; i++) {
			for(int j = 0; j < board[i].length; j++) {
				if (board[i][j] == '.') {
					return true;
				}
			}
		}
		return false;
	}
	
	private static boolean checkFour(char player, char a, char b, char c, char d) {
		if ( ! (a==player || a=='T')) {
			return false;
		}
		if ( ! (b==player || b=='T')) {
			return false;
		}
		if ( ! (c==player || c=='T')) {
			return false;
		}
		if ( ! (d==player || d=='T')) {
			return false;
		}
		return true;
	}
	
	private static boolean checkIfWon(char player, char[][] board) {
		for(int i = 0; i < board.length; i++) {
			boolean won = true;
			for(int j = 0; j < board[i].length; j++) {
				if (! (board[i][j] == player || board[i][j] == 'T')) {
					won = false;
					break;
				}
			}
			if(won) {
				return true;
			}
		}

		for(int i = 0; i < board.length; i++) {
			boolean won = true;
			for(int j = 0; j < board[i].length; j++) {
				if (! (board[j][i] == player || board[j][i] == 'T')) {
					won = false;
					break;
				}
			}
			if(won) {
				return true;
			}
		}
		
		if( checkFour(player, board[0][0], board[1][1], board[2][2], board[3][3])) {
			return true;
		}
		if( checkFour(player, board[3][0], board[2][1], board[1][2], board[0][3])) {
			return true;
		}
		return false;
	}
	
	private static void solve(int num, char[][] board) {
		System.out.print("Case #" + num + ": ");
		if (checkIfWon('X', board)) {
			System.out.println("X won");
			return;
		}
		if (checkIfWon('O', board)) {
			System.out.println("O won");
			return;
		}
		if (anyDots(board)) {
			System.out.println("Game has not completed");
			return;
		}
		System.out.println("Draw");
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int numCases = Integer.parseInt(br.readLine());
		for(int i = 0; i < numCases; i++)
		{
			char[][] board = new char[4][4];
			for(int r = 0; r < 4; r++) {
				String line = br.readLine();
				for(int c = 0; c < 4; c++) {
					board[r][c] = line.charAt(c);
				}
			}
			solve(i+1, board);
			br.readLine();
		}
	}


}