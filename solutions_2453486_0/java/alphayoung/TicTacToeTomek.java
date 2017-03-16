package codejam13;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class TicTacToeTomek {
	private static final String WON = " won";
	private static final String DRAW = "Draw";
	private static final String INCOMPLETE = "Game has not completed";
	private static final int BOARD_SIZE = 4;

	public void solve(String input, String output) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader(input));
		BufferedWriter out = new BufferedWriter(new FileWriter(output));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		char[][] board = new char[BOARD_SIZE][BOARD_SIZE];
		int index = 1;
		
		while (T > 0) {
			for (int i = 0; i < BOARD_SIZE; ++i) {
				board[i] = in.readLine().toCharArray();
			}
			
			String gameState = getGameState(board);
			out.write("Case #" + index + ": ");
			out.write(gameState);
			out.newLine();
			
			--T;
			++index;
			in.readLine();
		}
		
		in.close();
		out.close();
	}
	
	public String getGameState(char[][] board) {
		char lastChar1, lastChar2;
		boolean incomplete = false;
		
		// Row & Column
		for (int i = 0; i < BOARD_SIZE; ++i) {
			lastChar1 = '\0';
			lastChar2 = '\0';
			for (int j = 0; j < BOARD_SIZE; ++j) {
				if (board[i][j] == '.' || board[j][i] == '.') {
					incomplete = true;
				}
				
				lastChar1 = check(lastChar1, board[i][j]);
				lastChar2 = check(lastChar2, board[j][i]);
			}
			if (lastChar1 != '!') {
				return lastChar1 + WON;
			}
			if (lastChar2 != '!') {
				return lastChar2 + WON;
			}
		}
		
		// Diagonal
		lastChar1 = '\0';
		lastChar2 = '\0';
		for (int i = 0; i < BOARD_SIZE; ++i) {
			lastChar1 = check(lastChar1, board[i][i]);
			lastChar2 = check(lastChar2, board[i][BOARD_SIZE - i - 1]);
		}
		if (lastChar1 != '!') {
			return lastChar1 + WON;
		}
		if (lastChar2 != '!') {
			return lastChar2 + WON;
		}
		
		return incomplete ? INCOMPLETE : DRAW;
	}
	
	private char check(char lastChar, char currentChar) {
		if (currentChar == 'T') {
			return lastChar;
		}
		if (lastChar == '\0') {
			return currentChar;
		}
		if (lastChar != currentChar || lastChar == '.') {
			return '!';
		}
		return lastChar;
	}
}
