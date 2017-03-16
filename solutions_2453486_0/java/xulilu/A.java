package qr;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("a.in"));
		PrintWriter out = new PrintWriter(new File("a-small.out"));
		int n = in.nextInt();
		char[][] xb = new char[4][4];
		char[][] ob = new char[4][4];
		for (int c = 1; c <= n; c++) {
			in.nextLine();
			boolean completed = true;
			int row = 0;
			while (row < 4) {
				String line = in.nextLine();
				for (int col = 0; col < 4; col++) {
					xb[row][col] = line.charAt(col);
					ob[row][col] = line.charAt(col);
					if (xb[row][col] == 'T') {
						xb[row][col] = 'X';
						ob[row][col] = 'O';
					}
					if (xb[row][col] == '.')
						completed = false;
				}
				row++;
			}
			boolean xWin = check(xb, 'X');
			boolean oWin = check(ob, 'O');
			String status;
			if (xWin)
				status = "X won";
			else if (oWin)
				status = "O won";
			else if (completed)
				status = "Draw";
			else
				status = "Game has not completed";
			out.printf("Case #%d: %s\n", c, status);
		}
		in.close();
		out.close();
	}

	private static boolean check(char[][] b, char ch) {
		// check row
		for (int row = 0; row < 4; row++)
			if (b[row][0] == ch && b[row][1] == ch && b[row][2] == ch
					&& b[row][3] == ch)
				return true;
		// check col
		for (int col = 0; col < 4; col++)
			if (b[0][col] == ch && b[1][col] == ch && b[2][col] == ch
					&& b[3][col] == ch)
				return true;
		if (b[0][0] == ch && b[1][1] == ch && b[2][2] == ch && b[3][3] == ch)
			return true;
		if (b[0][3] == ch && b[1][2] == ch && b[2][1] == ch && b[3][0] == ch)
			return true;
		return false;
	}
}
