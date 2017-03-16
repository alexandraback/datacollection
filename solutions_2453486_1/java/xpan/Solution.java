
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Solution {
	public static Scanner in;
	public static PrintWriter out;
	public static final String IN_FILE = "A-large.in";
	public static final String OUT_FILE = "A-large.out";
	
	public static void main(String[] args) throws IOException {
		in = new Scanner(new FileReader(IN_FILE));
		out = new PrintWriter(new FileWriter(OUT_FILE));
		
		int cases = in.nextInt();
		in.nextLine();
		
		for (int i = 1; i <= cases; i++) {
			int[][] board = new int[4][4];
			for (int j = 0; j < 4; j++) {
				String tmp = in.next();
				for (int k = 0; k < 4; k++) {
					if (tmp.charAt(k) == '.') {
						board[j][k] = -1000;
					} else if (tmp.charAt(k) == 'T') {
						board[j][k] = 100;
					} else if (tmp.charAt(k) == 'O') {
						board[j][k] = 10;
					} else {
						board[j][k] = 1;
					}
					//System.out.print(board[j][k] + "|");
				}
			}
			//System.out.println();
			out.print(String.format("Case #%d: %s%n", i, whowins(board)));
		}
		out.flush();
		out.close();
		in.close();
	}

	private static String whowins(int[][] board) {
		int[] arr = new int[10];
		arr[0] = board[0][0] + board[0][1] + board[0][2] + board[0][3];
		arr[1] = board[1][0] + board[1][1] + board[1][2] + board[1][3];
		arr[2] = board[2][0] + board[2][1] + board[2][2] + board[2][3];
		arr[3] = board[3][0] + board[3][1] + board[3][2] + board[3][3];
		
		arr[4] = board[0][0] + board[1][0] + board[2][0] + board[3][0];
		arr[5] = board[0][1] + board[1][1] + board[2][1] + board[3][1];
		arr[6] = board[0][2] + board[1][2] + board[2][2] + board[3][2];
		arr[7] = board[0][3] + board[1][3] + board[2][3] + board[3][3];
		
		arr[8] = board[0][0] + board[1][1] + board[2][2] + board[3][3];
		arr[9] = board[0][3] + board[1][2] + board[2][1] + board[3][0];
		boolean find = true;
		for (int i = 0; i < 10; i++) {
			if (arr[i] == 103 || arr[i] == 4) {
				return "X won";
			} else if (arr[i] == 130 || arr[i] == 40) {
				return "O won";
			} else if (arr[i] < 0) {
				find = false;
			}
		}
		if (find)
			return "Draw";
		return "Game has not completed";
	}
}
