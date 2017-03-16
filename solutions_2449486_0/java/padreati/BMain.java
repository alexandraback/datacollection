package qualif2013;

import java.io.*;
import java.util.Scanner;

public class BMain {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new FileInputStream(new File("in.txt")));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(
				new FileOutputStream(new File("out.txt"))), false);
		solve(in, out);
		out.flush();
		out.close();
	}

	static void solve(Scanner in, PrintWriter out) throws Exception {

		int cases = in.nextInt();
		for (int k = 1; k <= cases; k++) {
			int rows = in.nextInt();
			int cols = in.nextInt();

			int[][] m = new int[rows][cols];
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					m[i][j] = in.nextInt();
				}
			}

			int[] maxrow = new int[rows];
			int[] maxcol = new int[cols];

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					maxrow[i] = Math.max(maxrow[i], m[i][j]);
					maxcol[j] = Math.max(maxcol[j], m[i][j]);
				}
			}
			boolean valid = true;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (m[i][j] < maxrow[i] && m[i][j] < maxcol[j]) {
						valid = false;
					}
				}
			}
			out.println(String.format("Case #%d: %s", k, valid?"YES":"NO"));
		}
	}
}
