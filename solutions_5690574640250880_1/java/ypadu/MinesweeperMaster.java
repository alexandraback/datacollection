package googlejam2014.qualification;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class MinesweeperMaster {
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new FileInputStream(args[0]));
		PrintWriter pw = new PrintWriter("output.txt");
		int testCases = scanner.nextInt();
		Outer: for (int test = 1; test <= testCases; test++) {
			pw.println("Case #"+ test + ":");
			int r = scanner.nextInt();
			int c = scanner.nextInt();
			int m = scanner.nextInt();
			char[][] board = new char[r][c];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					board[i][j] = '*';
				}
			}
			board[0][0] = 'c';
			int leftCell = r * c - m;
			if (leftCell == 1) {
				printBoard(pw, board);
				continue;
			}
			if (r == 1) {
				for (int i = 1; i < leftCell; i++) {
					board[0][i] = '.';
				}
				printBoard(pw, board);
				continue;
			}
			if (c == 1) {
				for (int i = 1; i < leftCell; i++) {
					board[i][0] = '.';
				}
				printBoard(pw, board);
				continue;
			}
			if (leftCell == 2 || leftCell == 3 || leftCell == 5 || leftCell == 7 || (c == 2 || r == 2) && leftCell % 2 != 0){
					pw.println("Impossible");
					continue;
			}
			board[0][1] = '.';
			board[1][0] = '.';
			board[1][1] = '.';
			leftCell -= 4;
			int mr = 2;
			int mc = 2;
			while (leftCell >= 4 && mr < r && mc < c) {
				leftCell -= 4;
				board[mr][0] = '.';
				board[mr++][1] = '.';
				board[0][mc] = '.';
				board[1][mc++] = '.';
			}
			while (mr < r && leftCell >= 2) {
				leftCell -= 2;
				board[mr][0] = '.';
				board[mr++][1] = '.';
			}
			while (mc < c && leftCell >= 2) {
				leftCell -= 2;
				board[0][mc] = '.';
				board[1][mc++] = '.';
			}
			for (int i = 2; i < mr; i++) {
				for (int j = 2; j < mc; j++) {
					if (leftCell-- > 0) {
						board[i][j] = '.';
					} else {
						printBoard(pw, board);
						continue Outer;
					}
				}
			}
			printBoard(pw, board);
		}
		pw.close();
		scanner.close();
	}

	private static void printBoard(PrintWriter pw, char[][] board) {
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				pw.print(board[i][j]);
			}
			pw.println();
		}
	}
}
