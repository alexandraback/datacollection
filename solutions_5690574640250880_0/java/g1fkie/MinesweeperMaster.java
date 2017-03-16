package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MinesweeperMaster {

	public static void main(String[] args) {
		
		File file = new File("C:\\Users\\Marco\\Desktop\\C-small-attempt1.in");
		Scanner sc = null;
		int numCases = 0;
		
		try {
			sc = new Scanner(file);
			numCases = sc.nextInt();
		} catch (FileNotFoundException e) {
			System.out.println("Fehler beim Einlesen!");
			e.printStackTrace();
		}
		
		for (int caseNum = 1; caseNum <= numCases; caseNum++) {
			
			int R = Integer.parseInt(sc.next());
			int C = Integer.parseInt(sc.next());
			int M = Integer.parseInt(sc.next());

			System.out.println("Case #" + caseNum + ":");
			
			char[][] grid = new char[R][C];
			
			int W = (R*C)-M;
			int x = C-1;
			int y = R-1;
			
			grid[y][x] = 'c';
			
			if (W == 1) {
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						grid[i][j] = '*';
					}
				}
				grid[R-1][C-1] = 'c';
				printGrid(grid);
				continue;
			}
			
			if (R == 1) {
				for (int i = 0; i < C; i++) {
					if (i < M)
						grid[0][i] = '*';
					else
						grid[0][i] = '.';
				}
				grid[0][C-1] = 'c';
				printGrid(grid);
				continue;
			}
			
			if (C == 1) {
				for (int i = 0; i < R; i++) {
					if (i < M)
						grid[i][0] = '*';
					else
						grid[i][0] = '.';
				}
				grid[R-1][0] = 'c';
				printGrid(grid);
				continue;
			}
			
			if (W == 2 && M != 0) {
				System.out.println("Impossible");
				continue;
			}
			
			if (W == 3 && M != 0) {
				System.out.println("Impossible");
				continue;
			}
			
			if (R == 2) {
				if (M % 2 == 1) {
					System.out.println("Impossible");
					continue;
				}
				
				x = 0;
				
				while (M > 0) {
					y = R-2;
					grid[y][x] = '*';
					y++;
					grid[y][x] = '*';
					M -= 2;
					
					x++;
					if (x == C-2)
						break;
				}
				for (int i = 0; i < grid.length; i++) {
					for (int j = 0; j < grid[0].length; j++) {
						if (grid[i][j] != '*')
							grid[i][j] = '.'; 
					}
				}
				grid[R-1][C-1] = 'c';
				printGrid(grid);
				continue;
			}
			
			if (C == 2) {
				if (M % 2 == 1) {
					System.out.println("Impossible");
					continue;
				}
			
				y = 0;
				
				while (M > 0) {
					x = C-2;
					grid[y][x] = '*';
					x++;
					grid[y][x] = '*';
					M -= 2;
					
					y++;
					if (y == R-2)
						break;
				}
				for (int i = 0; i < grid.length; i++) {
					for (int j = 0; j < grid[0].length; j++) {
						if (grid[i][j] != '*')
							grid[i][j] = '.'; 
					}
				}
				grid[R-1][C-1] = 'c';
				printGrid(grid);
				continue;
			}
			
			if (M < (R-2)*(C-2)) {
				// Alles cool
				x = 0;
				y = 0;
				
				while (M > 0) {
					
					grid[y][x] = '*';
					x++;
					if (x == C-2) {
						x = 0;
						y++;
					}
					if (y == R-2) {
						break;
					}
					M--;
				}
				for (int i = 0; i < grid.length; i++) {
					for (int j = 0; j < grid[0].length; j++) {
						if (grid[i][j] != '*')
							grid[i][j] = '.'; 
					}
				}
				grid[R-1][C-1] = 'c';
				printGrid(grid);
				
			} else if ((M - ((R-2)*(C-2))) % 2 == 0 && M <= R*C-4) {
				// Alles cool
				
				x = 0;
				y = 0;
				
				while (M > 0) {
					
					grid[y][x] = '*';
					x++;
					if (x == C-2) {
						x = 0;
						y++;
					}
					if (y == R-2) {
						break;
					}
					M--;
				}
				
				x = 0;
				
				while (M > 0) {
					y = R-2;
					grid[y][x] = '*';
					y++;
					grid[y][x] = '*';
					M -= 2;
					
					x++;
					if (x == C-2)
						break;
				}
				
				y = 0;
				
				while (M > 0) {
					x = C-2;
					grid[y][x] = '*';
					x++;
					grid[y][x] = '*';
					M -= 2;
					
					y++;
					if (y == R-2)
						break;
				}
				
				
				for (int i = 0; i < grid.length; i++) {
					for (int j = 0; j < grid[0].length; j++) {
						if (grid[i][j] != '*')
							grid[i][j] = '.'; 
					}
				}
				grid[R-1][C-1] = 'c';
				printGrid(grid);
				
			} else {
				System.out.println("Impossible");
			}
			
		}
	}
	
	public static void printGrid(char[][] grid) {
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				System.out.print(grid[i][j]);
			}
			System.out.println();
		}
	}
}
