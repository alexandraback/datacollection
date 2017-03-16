import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/*
 * Author :	David Tang
 * Date :	Apr 13, 2013
 */

public class TicTacToeTomek {

	private final static String fILE_NAME = "A-small-attempt0";
	
	private static char[][] board = new char[4][4];
	private static boolean notFinish;
	
	public static void main(String[] args) {
		BufferedReader buffRead = null;
		PrintWriter printWrit = null;
		int t;
		try {
			printWrit = new PrintWriter(new BufferedWriter(new FileWriter(fILE_NAME + ".out")));
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			buffRead =new BufferedReader(new InputStreamReader(new FileInputStream(fILE_NAME + ".in")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		try {
			t = Integer.parseInt(buffRead.readLine());
			for (int i = 0; i < t; i++) {
				String s;
				notFinish = false;
				for (int j = 0; j < 4; j++) {
					s = buffRead.readLine();
					for (int k = 0; k < 4; k++) {
						board[k][j] = s.charAt(k);
						if (!notFinish && board[k][j] == '.') {
							notFinish = true;
						}
					}
				}
				buffRead.readLine();
				printWrit.println("Case #" + (i+1) + ": " + solve());
			}
			buffRead.close();
			printWrit.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static String solve() {
		String s;
		for (int i = 0; i < 4; i++) {
			s = checkRow(i);
			if (s != null) {
				return s;
			}
			s = checkCol(i);
			if (s != null) {
				return s;
			}
		}
		s = checkDiag1();
		if (s != null) {
			return s;
		}
		s = checkDiag2();
		if (s != null) {
			return s;
		}
		if (notFinish) {
			return "Game has not completed";
		} else {
			return "Draw";
		}
	}
	
	private static String checkRow(int r) {
		char c;
		if (board[0][r] == 'T') {
			c = board[1][r];
			if (c == '.') {
				return null;
			}
			if (board[2][r] == c && board[3][r] == c) {
				return c + " won";
			}
		} else {
			c = board[0][r];
			if (c == '.') {
				return null;
			}
			for (int i = 1; i < 4; i++) {
				if (board[i][r] != c && board[i][r] != 'T') {
					return null;
				}
			}
			return c + " won";
		}
		return null;
	}
	
	private static String checkCol(int r) {
		char c;
		if (board[r][0] == 'T') {
			c = board[r][1];
			if (c == '.') {
				return null;
			}
			if (board[r][2] == c && board[r][3] == c) {
				return c + " won";
			}
		} else {
			c = board[r][0];
			if (c == '.') {
				return null;
			}
			for (int i = 1; i < 4; i++) {
				if (board[r][i] != c && board[r][i] != 'T') {
					return null;
				}
			}
			return c + " won";
		}
		return null;
	}
	
	private static String checkDiag1() {
		char c;
		if (board[0][0] == 'T') {
			c = board[1][1];
			if (c == '.') {
				return null;
			}
			if (board[2][2] == c && board[3][3] == c) {
				return c + " won";
			}
		} else {
			c = board[0][0];
			if (c == '.') {
				return null;
			}
			for (int i = 1; i < 4; i++) {
				if (board[i][i] != c && board[i][i] != 'T') {
					return null;
				}
			}
			return c + " won";
		}
		return null;
	}
	
	private static String checkDiag2() {
		char c;
		if (board[0][3] == 'T') {
			c = board[1][2];
			if (c == '.') {
				return null;
			}
			if (board[2][1] == c && board[3][0] == c) {
				return c + " won";
			}
		} else {
			c = board[0][3];
			if (c == '.') {
				return null;
			}
			if (board[1][2] != c && board[1][2] != 'T') {
				return null;
			}
			if (board[2][1] != c && board[2][1] != 'T') {
				return null;
			}
			if (board[3][0] != c && board[3][0] != 'T') {
				return null;
			}
			return c + " won";
		}
		return null;
	}
	
}
