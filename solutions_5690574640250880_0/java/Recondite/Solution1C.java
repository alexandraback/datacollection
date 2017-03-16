package practice;

import genericSolver.ISolver;
import genericSolver.Reader;

import java.io.IOException;

public class Solution1C implements ISolver {

	public static void main(String[] args) {
		ISolver Solution = new Solution1C();
		Reader s;
		try {
			s = new Reader(Solution, "C-small-attempt4", "out");
//			 s = new Reader(Solution, "in", "out");

			s.solveCases(true);
			s.finish();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	static String impString = "\nImpossible";

	/**
	 * @param args
	 */
	@Override
	public String solve(Reader reader) {
		int i = reader.returnInt();
		int j = reader.returnInt();
		int mines = reader.returnInt();
		char[][] grid = new char[i][j];

		for (int m = 0; m < i; m++)
			for (int k = 0; k < j; k++)
				grid[m][k] = '*';

		mines -= j * i;
		if (mines >= 0)
			return impString;
		grid[0][0] = 'c';
		mines++;
		if (mines == 0)
			return printout(grid, i, j);

		mines += zeroPoint(grid, 0, 0, true);

		if (mines == 0)
			return printout(grid, i, j);
		else if (mines > 0)
			return impString;
		
		if(i==1 || i==2){
			int q=1;
			while(mines<0){
				mines+= zeroPoint(grid,0,q,true);
				q++;
			}
			if(mines==1)
				return impString;
			return printout(grid,i,j);
		}
		
		if(j==1 || j==2){
			int q=1;
			while(mines<0){
				mines+= zeroPoint(grid,q,0,true);
				q++;
			}
			if(mines==1)
				return impString;
			return printout(grid,i,j);
		}
		
		int x = 1;
		int y = 0;
		
		mines += zeroPoint(grid, x, y, true);
		x=2;
		
		if (mines == 0)
			return printout(grid, i, j);
		else if (mines > -2)
			return impString;

		while (mines <= 0 && x < i) {
//			System.out.println("Mines left " + mines);
//			System.out.println(printout(grid, i, j));
			if (mines == 0)
				return printout(grid, i, j);
			if (mines == -3) {
				if (j == 2)
					return impString;
				else if (x > 1 && j > 1)
					mines += zeroPoint(grid, 1, 1, true);
			} else {
				mines += zeroPoint(grid, x, y, true);
				x++;
			}
		}

		for (y = 1; y < j; y++) {
			// System.out.println("Mines left " + mines);
			// System.out.println(printout(grid, i, j));
			if (mines == -3) {
				mines += zeroPoint(grid, 1, y, true);
			}
			for (x = 0; x < i; x++) {
				// System.out.println("Mines left " + mines);
				// System.out.println(printout(grid, i, j));
				if ((x == i - 2) && mines == -2) {
					mines += zeroPoint(grid, 0, y + 1, true);
				} else {
					if (mines == 0)
						return printout(grid, i, j);
					mines += zeroPoint(grid, x, y, true);
				}
			}
		}

		System.out.println("Unsure");
		return printout(grid, i, j);
	}

	public static int zeroPoint(char[][] grid, int x, int y, boolean Zero) {
		int i = grid.length;
		int j = grid[0].length;

		int mines = 0;
//		System.out.println("x" + x + " y" + y);

		if (y + 1 < j) {
			if (grid[x][y + 1] == '*') {
				mines++;
				grid[x][y + 1] = '.';
			}
			if (x + 1 < i) {
				if (grid[x + 1][y + 1] == '*') {
					mines++;
					grid[x + 1][y + 1] = '.';
				}
			}
			if (x - 1 >= 0) {
				if (grid[x - 1][y + 1] == '*') {
					mines++;
					grid[x - 1][y + 1] = '.';
				}
			}
		}

		if (x + 1 < i) {
			if (grid[x + 1][y] == '*') {
				grid[x + 1][y] = '.';
				mines++;
			}
		}
		return mines;

	}

	public static String printout(char[][] grid, int i, int j) {

		String result = "\n";
		for (int m = 0; m < i; m++) {
			for (int k = 0; k < j; k++)
				result += grid[m][k];
			if (m != i - 1)
				result += "\n";
		}
		return result;
	}
}
