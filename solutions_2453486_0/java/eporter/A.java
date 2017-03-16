

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

// Using the Google Collections library.
public class A {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/A-small-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			char [][] board = new char [4][];
			int dots = 0;
			for (int i = 0; i < 4; i++) {
				board[i] = in.next().toCharArray();
				for (char c : board[i]) {
					dots += (c == '.') ? 1 : 0;
				}
			}
			String ans = "Game has not completed";
			if (checkForWin(board, 'X')) {
				ans = "X won";
			} else if (checkForWin(board, 'O')) {
				ans = "O won";
			} else if (dots == 0) {
				ans = "Draw";
			}
			out.print("Case #"+cs+": " + ans);
			out.println();
		}
		out.close();
	}
	
	private static boolean checkForWin(char [][] board, char c) {
		for (int x = 0; x < 4; x++) {
			boolean win = true;
			for (int y = 0; y < 4; y++) {
				win &= board[x][y] == c || board[x][y] == 'T';
			}
			if (win) {
				return true;
			}
		}
		for (int y = 0; y < 4; y++) {
			boolean win = true;
			for (int x = 0; x < 4; x++) {
				win &= board[x][y] == c || board[x][y] == 'T';
			}
			if (win) {
				return true;
			}
		}
		boolean d1 = true, d2 = true;
		for (int i = 0; i < 4; i++) {
			d1 &= board[i][i] == c || board[i][i] == 'T';
			d2 &= board[i][3-i] == c || board[i][3-i] == 'T';
		}
		return d1 || d2;
	}
}
