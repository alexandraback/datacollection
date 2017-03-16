package main;

import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt(); in.nextLine();
		
		for (int i = 1; i <= T; i++) {

			char[][] board = new char[4][4];
			
			for (int j = 0; j <= 3; j++) {
				String line = in.nextLine();
				
				for (int k = 0; k <= 3; k++) {
					board[j][k] = line.charAt(k);
				}
			}
			
			if (i < T)
				in.nextLine();
			
			System.out.format("Case #%d: %s\n", i, getStatus(board));
		}
		
		in.close();
	}

	private static String getStatus(char[][] board) {
		
		if (playerHasWon('X', board))
			return "X won";
		
		if (playerHasWon('O', board))
			return "O won";
		
		if (boardHasEmptyCell(board))
			return "Game has not completed";
		
		return "Draw";	
	}

	private static boolean playerHasWon(char player, char[][] board) {

		if (hasHorizontalLine(player, board)
			|| hasVerticalLine(player, board)
			|| hasDiagonal(player, board))
			return true;
		
		return false;
	}

	private static boolean hasDiagonal(char player, char[][] board) {
		
		boolean diagonal1 = true;
		for (int i = 0; i < board.length; i++)
			if (board[i][i] != player && board[i][i] != 'T') {
				diagonal1 = false;
				break;
			}
		
		if (diagonal1)
			return true;
		
		boolean diagonal2 = true;
		for (int i = 0; i < board.length; i++)
			if (board[board.length - 1 - i][i] != player && board[board.length - 1 - i][i] != 'T') {
				diagonal2 = false;
				break;
			}
		
		if (diagonal2)
			return true;		
		
		return false;
	}

	private static boolean hasHorizontalLine(char player, char[][] board) {
		
		for (int i = 0; i < board.length; i++) {
			boolean line = true;
			for (int j = 0; j < board.length; j++) {
				if (board[i][j] != player && board[i][j] != 'T') {
					line = false;
					break;
				}				
			}
			if (line)
				return true;
		}
		return false;
	}
	
	private static boolean hasVerticalLine(char player, char[][] board) {
		
		for (int i = 0; i < board.length; i++) {
			boolean line = true;
			for (int j = 0; j < board.length; j++) {
				if (board[j][i] != player && board[j][i] != 'T') {
					line = false;
					break;
				}				
			}
			if (line)
				return true;
		}
		return false;
	}	

	private static boolean boardHasEmptyCell(char[][] board) {

		for (int i = 0; i < board.length; i++)
			for (int j = 0; j < board[0].length; j++)
				if (board[i][j] == '.')
					return true;
		
		return false;
	}
}
