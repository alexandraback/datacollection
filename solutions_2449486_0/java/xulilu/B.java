package qr;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("b.in"));
		PrintWriter out = new PrintWriter(new File("b-small.out"));
		int n = in.nextInt();
		for (int cn = 1; cn <= n; cn++) {
			boolean check = true;
			int row = in.nextInt();
			int col = in.nextInt();
			int[][] lawn = new int[row][col];
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					lawn[i][j] = in.nextInt();
			for (int r = 0; r < row; r++)
				for (int c = 0; c < col; c++) {
					boolean rowCheck = true;
					for (int i = 0; i < row; i++)
						if (i != r && lawn[i][c] > lawn[r][c])
							rowCheck = false;

					boolean colCheck = true;
					for (int j = 0; j < col; j++)
						if (j != c && lawn[r][j] > lawn[r][c])
							colCheck = false;
					if (!colCheck && !rowCheck)
						check = false;
				}
			out.printf("Case #%d: %s\n", cn, check ? "YES" : "NO");
		}
		in.close();
		out.close();
	}
}
