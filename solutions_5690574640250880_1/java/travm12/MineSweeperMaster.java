import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class MineSweeperMaster {
	public static void main(String[] Args) throws FileNotFoundException {
		 Scanner sc = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter(new File("things.out"));
//		Scanner sc = new Scanner(System.in);
		boolean[] things = new boolean[16];
		int t = sc.nextInt(), cc = 0;
		while (t-- > 0) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int m = sc.nextInt();
			out.printf("Case #%d:%n", ++cc);
			if (r == 1) {
				out.printf("c");
				for (int k = 1; k < c - m; k++)
					out.print(".");
				for (int k = 0; k < m; k++)
					out.print("*");
				out.println();
			} else if (c == 1) {
				out.printf("c%n");
				for (int k = 1; k < r - m; k++)
					out.println(".");
				for (int k = 0; k < m; k++)
					out.println("*");
			} else if (m == r * c - 1)
				for (int k = 0; k < r; k++) {
					for (int j = 0; j < c; j++)
						if (k == 0 && j == 0)
							out.print("c");
						else
							out.print("*");
					out.println();
				}
			else if ((r * c - m<= 3) || (r * c - m == 5) || (r * c - m == 7)
					|| ((r * c - m) % 2 == 1 && (r == 2 || c == 2)))
				out.println("Impossible");
			else {
				boolean[][] thing = new boolean[r][c];
				for(int k = 0; k <r;k++)
					Arrays.fill(thing[k],true);
				int curRow = 0;
				int curCol = 0;
				while (m != 0) {
					if (r - curRow >= c - curCol) {
						if (c - curCol > m + 1) {
							for (int j = 0; j < m; j++)
								thing[curRow][curCol + j] = false;
							m = 0;
						} else if (c - curCol < m + 1) {
							for (int j = 0; j + curCol < c; j++)
								thing[curRow][curCol + j] = false;
							m -= c - curCol;
						} else {
							for (int j = 0; j + curCol < c - 2; j++)
								thing[curRow][curCol + j] = false;
							thing[curRow + 1][curCol] = false;
							m = 0;
						}
						curRow++;
					} else {
						if (r - curRow > m + 1) {
							for (int k = 0; k < m; k++)
								thing[curRow + k][curCol] = false;
							m = 0;
						} else if (r - curRow < m + 1) {
							for (int k = 0; k + curRow < r; k++)
								thing[curRow + k][curCol] = false;
							m -= r - curRow;
						} else {
							for (int k = 0; k + curRow < r - 2; k++)
								thing[curRow + k][curCol] = false;
							thing[curRow][curCol + 1] = false;
							m = 0;
						}
						curCol++;
					}
				}
				for (int k = 0; k < r; k++) {
					for (int j = 0; j < c; j++)
						if (j == c - 1 && k == r - 1)
							out.print("c");
						else if (thing[k][j])
							out.print(".");
						else
							out.print("*");
					out.println();
				}
			}
		}
		out.close();
	}
}
