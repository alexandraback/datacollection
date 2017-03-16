import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "B";
	static final String INPUT = "small";
	static final String ID = "0";
	static final String PATH = "C:\\software installation\\codejam-commandline-1.2-beta1\\source\\";

	static int board[][];

	public static void main(String args[]) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int row = in.nextInt();
			int column = in.nextInt();
			board = new int[row][column];
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					board[i][j] = in.nextInt();
				}
			}

			int rowMax[] = new int[row];
			for (int i = 0; i < row; i++) {
				rowMax[i] = maxOfLine(i, 0, 0, 1, column);
			}
			int columnMax[] = new int[column];
			for (int j = 0; j < column; j++) {
				columnMax[j] = maxOfLine(0, j, 1, 0, row);
			}

			boolean possible = true;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					if (board[i][j] != rowMax[i] && board[i][j] != columnMax[j]) {
						possible = false;
						break;
					}
				}
				if (!possible) {
					break;
				}
			}

			out.println(possible ? "YES" : "NO");
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static int maxOfLine(int x0, int y0, int offsetX, int offsetY, int length) {
		int max = -1;
		for (int i = 0; i < length; i++) {
			max = Math.max(max, board[x0 + i * offsetX][y0 + i * offsetY]);
		}
		return max;
	}
}
