import java.text.DecimalFormat;
import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.0000000");
		int total = s.nextInt();
		int current = 1;
		while (current <= total) {
			int R = s.nextInt();
			int C = s.nextInt();
			int M = s.nextInt();
			
			System.out.println("Case #" + (current++) +": ");
			
			char grid[][] = new char[R][C];
			if (able(grid, R, C, M)) {
				printGrid(grid);
			}
			else System.out.println("Impossible");
		}
	}
	
	public static void fillGrid(char[][] grid, int fr, int fc, int ar, int ac) {
		// initialize as mine
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				grid[i][j] = '*';
			}
		}
		// set fr*fc as blank
		for (int i = 0; i < fr; i++) {
			for (int j = 0; j < fc; j++) {
				grid[i][j] = '.';
			}
		}
		// additional blank row
		for (int i = 0; i < ar; i++) {
			grid[fr][i] = '.';
		}
		// additional blank column
		for (int i = 0; i < ac; i++) {
			grid[i][fc] = '.';
		}
		// if not full with mines
		if (fr*fc+ar+ac != 0) grid[0][0] = 'c';
	}
	
	public static void printGrid(char[][] grid) {
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				System.out.print(grid[i][j]);
			}
			System.out.println();
		}		
	}
	
	public static boolean able(char[][] grid, int R, int C, int M) {
		if (R == 1) {
			fillGrid(grid, 1, C-M, 0, 0);
			return true;
		}
		if (C == 1) {
			fillGrid(grid, R-M, 1, 0, 0);
			return true;
		}
		
		// count of blank should be: 1 or m*n+x (where m >= 2, n >= 2 and x != 1)
		int blank = R*C - M;
		if (blank == 1) {
			fillGrid(grid, 1, 1, 0, 0);
			return true;
		}
		//if (blank < 4) return false;
		
		// from one edge to the other
		int fr = R;
		int	fc = blank/R;
		int	ar = 0;
		int	ac = blank%R;
		if (fc == 0) {
			fc = 1;
			fr = blank;
			ac = 0;
		}
		//System.out.printf("%d %d %d %d\n", fr, fc, ar, ac);
		// change continuously
		while (ar == 1 || ac == 1 
				|| fc < 2) {
			// cannot move
			if (fr == 2) return false; 
			// move one block from additional row to additional column
			if (ar == 0) {
				fr--;
				ar = fc - 1;
			} else {
				ar--;
			}
			if (++ac >= fr) {
				ac -= fr;
				fc++;
				if ((ac==0 && fc > C) || (ac!=0) && fc>C-1) return false;
			}
			//System.out.printf("%d %d %d %d\n", fr, fc, ar, ac);
		}
		fillGrid(grid, fr, fc, ar, ac);
		return true;
	}
}
