import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;


public class Main {

	
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new FileInputStream(new File("small.txt")));
		int T = scanner.nextInt();
		scanner.nextLine();
		
		for (int t = 0; t < T; t++) {
			char[][] board = new char[4][4];
			for (int i = 0; i < 4; i++) {
				String line = scanner.nextLine();
				board[i] = line.toCharArray();
			}
			
			boolean end = true;
			String winner = null;
			
			for (int row = 0; row < 4; row++) {
				boolean rx = true;
				boolean ro = true;
				boolean cx = true;
				boolean co = true;
				for (int col = 0; col < 4; col++) {
					if (board[row][col] == 'X') {
						ro = false;
					} else if (board[row][col] == 'O') {
						rx = false;
					} else if (board[row][col] == '.') {
						ro = false;
						rx = false;
						end = false;
					}
					if (board[col][row] == 'X') {
						co = false;
					} else if (board[col][row] == 'O') {
						cx = false;
					} else if (board[col][row] == '.') {
						co = false;
						cx = false;
						end = false;
					}
				}
				if (rx || cx) {
					winner = "X won";
					break;
				}
				if (ro || co) {
					winner = "O won";
					break;
				}
				
			}
			if (winner == null) {
				boolean d1x = true;
				boolean d1O = true;
				boolean d2x = true;
				boolean d2O = true;
				for (int i = 0; i < 4; i++) {
					if (board[i][i] == 'X') {
						d1O = false;
					} else if (board[i][i] == 'O') {
						d1x = false;
					} else if (board[i][i] == '.') {
						d1O = false;
						d1x = false;
					}
					if (board[i][3 - i] == 'X') {
						d2O = false;
					} else if (board[i][3 - i] == 'O') {
						d2x = false;
					} else if (board[i][3 - i] == '.') {
						d2O = false;
						d2x = false;
					}
					
				}
				if (d1x || d2x) {
					winner = "X won";
				}
				if (d1O || d2O) {
					winner = "O won";
				}
			}
			if (winner == null && end) {
				winner = "Draw";
			} else if (winner == null && !end) {
				winner = "Game has not completed";
			}
			System.out.print("Case #" + (t + 1) + ": " + winner + "\n");
			if (scanner.hasNextLine()) scanner.nextLine();
		}
		
		

	}

}
