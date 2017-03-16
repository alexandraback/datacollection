import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class Main_A {

	/**
	 * @param args
	 */
	static Scanner scan = new Scanner(System.in);
	static PrintWriter pw = new PrintWriter(System.out);

	static class Pair<F, S> {
		public F first;
		public S second;

		public Pair(F first, S second) {
			this.first = first;
			this.second = second;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int tc = scan.nextInt();
		for (int tt = 0; tt < tc; tt++) {
			int row = scan.nextInt(), column = scan.nextInt();
			int[][] mat = new int[row][column];
			for (int rr = 0; rr < row; rr++) {
				for (int cc = 0; cc < column; cc++) {
					mat[rr][cc] = scan.nextInt();
				}
			}
			boolean valid = true;
			OUT: for (int rr = 0; rr < row; rr++) {
				for (int cc = 0; cc < column; cc++) {
					// check //
					boolean validcol = true;
					for (int zz = 0; zz < row; zz++) {
						if (mat[zz][cc] > mat[rr][cc]) {
							validcol = false;
							break;
						}
					}

					boolean validrow = true;
					for (int zz = 0; zz < column; zz++) {
						if (mat[rr][zz] > mat[rr][cc]) {
							validrow = false;
							break;
						}
					}

					valid = validcol || validrow;
					if (!valid) {
						break OUT;
					}
				}
			}
			pw.printf("Case #%d: %s\n", tt + 1, (valid ? "YES" : "NO"));
		}
		pw.close();
	}

}
