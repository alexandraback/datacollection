import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;


public class MinesweeperMaster {
	
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedReader(new FileReader(new File("C-small-attempt3.in")), 256 << 10));
			PrintStream out = new PrintStream(new File("output.txt"));

			int testsNumber = in.nextInt();
			test:
			for (int testId = 1; testId <= testsNumber; testId++) {
				out.println("Case #" + testId + ": ");
				int rows = in.nextInt();
				int cols = in.nextInt();
				int bombs = in.nextInt();
				int free = rows * cols - bombs;
				char[][] grid = new char[rows][cols];
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++) grid[i][j] = '*';
				// - edge cases
				// -- single bomb-free position
				if (free == 1) {
					grid[0][0] = 'c';
					for (int q = 0; q < rows; q++) out.println(grid[q]);					
					continue test;
				}
				// -- line-grid
				if (rows == 1 | cols == 1) {
					main:
					for (int i = 0; i < rows; i++) {
						for (int j = 0; j < cols; j++) {
							grid[i][j] = '.';
							free--;
							if (free == 0) break main;
						}
					}
					grid[0][0] = 'c';
					for (int q = 0; q < rows; q++) out.println(grid[q]);
					continue test;
				}
				// - general solution
				for (int i = 2; i <= rows; i++) {
					for (int j = 2; j <= cols; j++) {
						if (i * j >= free) {
							int possibleBombs = (i-2) * (j-2);
							int requiredBombs = i * j - free;
							if (requiredBombs <= possibleBombs) {
								for (int ii = 0; ii < i; ii++)
									for (int jj = 0; jj < j; jj++)
										grid[ii][jj] = '.';
								for (int ii = i-1; ii >= 2 & requiredBombs > 0; ii--)
									for (int jj = j-1; jj >= 2 & requiredBombs > 0; jj--) {
										grid[ii][jj] = '*';
										requiredBombs--;
									}
								grid[0][0] = 'c';
								for (int q = 0; q < rows; q++) out.println(grid[q]);
								continue test;
							}
							else break;
						}
					}
				}
				out.println("Impossible");
			}
			in.close();
			out.close();
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}

}
