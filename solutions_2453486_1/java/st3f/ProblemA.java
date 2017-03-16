import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemA {
	static Scanner sc;
	static PrintStream ps;
	static char[][] board = new char[4][4];
	static String status;

	static void nextCase() {
		int i, j;
		for (i = 0; i < 4; i++) {
			String line = sc.next();
			for (j = 0; j < 4; j++)
				board[i][j] = line.charAt(j);
		}

		int xs, os, ts;
		for (i = 0; i < 4; i++) {
			xs = os = ts = 0;
			for (j = 0; j < 4; j++) {
				if (board[i][j] == 'X')
					xs++;
				else if (board[i][j] == 'O')
					os++;
				else if (board[i][j] == 'T')
					ts++;
			}
			if (xs + ts == 4) {
				status = "X won";
				return;
			}
			if (os + ts == 4) {
				status = "O won";
				return;
			}
		}

		for (j = 0; j < 4; j++) {
			xs = os = ts = 0;
			for (i = 0; i < 4; i++) {
				if (board[i][j] == 'X')
					xs++;
				else if (board[i][j] == 'O')
					os++;
				else if (board[i][j] == 'T')
					ts++;
			}
			if (xs + ts == 4) {
				status = "X won";
				return;
			}
			if (os + ts == 4) {
				status = "O won";
				return;
			}
		}

		xs = os = ts = 0;
		for (i = 0; i < 4; i++) {
			if (board[i][i] == 'X')
				xs++;
			else if (board[i][i] == 'O')
				os++;
			else if (board[i][i] == 'T')
				ts++;
		}
		if (xs + ts == 4) {
			status = "X won";
			return;
		}
		if (os + ts == 4) {
			status = "O won";
			return;
		}

		xs = os = ts = 0;
		for (i = 0; i < 4; i++) {
			if (board[3 - i][i] == 'X')
				xs++;
			else if (board[3 - i][i] == 'O')
				os++;
			else if (board[3 - i][i] == 'T')
				ts++;
		}
		if (xs + ts == 4) {
			status = "X won";
			return;
		}
		if (os + ts == 4) {
			status = "O won";
			return;
		}
		
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				if (board[i][j] == '.') {
					status = "Game has not completed";
					return;
				}
		status = "Draw";
	}

	static void printSol() {
		ps.println(status);
	}

	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(new File(args[0] + ".in"));
		ps = new PrintStream(args[0] + ".out");
		int t = sc.nextInt();
		sc.nextLine();

		for (int c = 1; c <= t; c++) {
			nextCase();
			ps.printf("Case #%d: ", c);
			printSol();
		}
	}
}
