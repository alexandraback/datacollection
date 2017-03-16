import java.util.*;

public class Main {
	public static int[][] grid;
    public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		
		int t = s.nextInt(), c = 1;
		while (c <= t) {
			int n = s.nextInt();
			int m = s.nextInt();
			grid = new int[n][m];
			for (int i = 0; i < grid.length; i++) {
				for (int j = 0; j < grid[0].length; j++) {
					grid[i][j] = s.nextInt();
				}
			}

			boolean able = checkGrid();
			System.out.println("Case #" + (c++) + ": " + (able?"YES":"NO"));
		}
	}
    
    public static boolean checkGrid() {
    	int[][] init = new int[grid.length][grid[0].length];
    	for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				init[i][j] = 100;
			}
		}
    	
    	for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				boolean mr = isMaxInRow(i, j);
				if (mr) { cutInitRow(init, i, grid[i][j]); continue; }
				
				boolean mc = isMaxInCol(i, j);
				if (mc) cutInitCol(init, j, grid[i][j]); else return false;
			}
		}
    	
    	return true;
    }
    
    public static boolean isMaxInRow(int i, int j) {
    	for (int col = 0; col < grid[i].length; col++) {
    		if (grid[i][col] > grid[i][j]) return false;
    	}
    	return true;
    }
    
    public static boolean isMaxInCol(int i, int j) {
    	for (int row = 0; row < grid.length; row++) {
    		if (grid[row][j] > grid[i][j]) return false;
    	}
    	return true;
    }
    
    public static void cutInitRow(int[][] init, int i, int target) {
    	for (int col = 0; col < grid[i].length; col++) {
    		if (init[i][col] > target) init[i][col] = target;
    	}
    }
    
    public static void cutInitCol(int[][] init, int j, int target) {
    	for (int row = 0; row < grid.length; row++) {
    		if (init[row][j] > target) init[row][j] = target;
    	}
    }
}