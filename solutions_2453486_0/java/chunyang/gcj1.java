import java.util.*;
import java.io.*;

public class gcj1 {
	
	public static int rowwin(char player, int row, char [][] board)
	{
		boolean playerwin = true;
		for (int i = 0; i < 4; i ++) {
			if (!(board[row][i] == 'T') && !(board[row][i] == player)) {
				playerwin = false;
				break;
			}
		}
		if (playerwin)return 1; else return 0;
	}
	
	public static boolean crosswin(char player, char [][] board) {
		for (int i = 0; i < 4; i ++) if (board[i][i] != 'T' && board[i][i] != player) return false;
		return true;
	}
	
	public static boolean crossinvertwin(char player, char [][] board) {
		for (int i = 0; i < 4; i ++) if (board[i][3 - i] != 'T' && board[i][3 - i] != player) return false;
		return true;
	}
	
	public static int colwin(char player, int col, char [][] board)
	{
		boolean playerwin = true;
		for (int i = 0; i < 4; i ++) {
			if (!(board[i][col] == 'T') && !(board[i][col] == player)) {
				playerwin = false;
				break;
			}
		}
		if (playerwin) return 1; else return 0;
	}
	
	public static void main(String [] args) throws Exception {
		String file = "A-small-attempt0.in";
		Scanner scanner = new Scanner(new FileInputStream(file));
		PrintStream ps = new PrintStream(file + ".out");
		
		int tot = scanner.nextInt();
		char [][] board = new char[4][4];
		
		for (int tt = 0; tt < tot; tt ++) {
			boolean conempty = false;
			for (int j = 0; j < 4; j ++) {
				String tmp = scanner.next();
				for (int i = 0; i < 4; i ++) {
					board[j][i] = tmp.charAt(i);
					if (board[j][i] == '.') conempty = true;
				}
			}
			boolean finished = false;
			for (int i = 0; i < 4; i ++) {
				if (colwin('X', i, board) > 0 || rowwin('X', i, board) > 0 || crosswin('X', board) || crossinvertwin('X', board)) {
					ps.println("Case #" + (tt + 1) + ": X won");
					finished = true; break;
				}
			}
			if (finished) continue;
			for (int i = 0; i < 4; i ++) {
				if (colwin('O', i, board) > 0 || rowwin('O', i, board) > 0 || crosswin('O', board) || crossinvertwin('O', board)) {
					ps.println("Case #" + (tt + 1) + ": O won");
					finished = true; break;
				}
			}
			if (finished) continue;
			if (conempty) {
				ps.println("Case #" + (tt + 1) + ": Game has not completed");
				finished = true;
			}
			if (finished) continue;
			ps.println("Case #" + (tt + 1) + ": Draw");
		}
	}

}
