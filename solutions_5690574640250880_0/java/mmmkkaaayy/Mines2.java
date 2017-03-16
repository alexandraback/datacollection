package codejams;

import java.io.BufferedReader;
import java.io.PrintWriter;

public class Mines2 {
	
	String[][] grid;
	int r;
	int c;
	int mines;
	
	public Mines2() {
		
	}
	
	public void testCase(BufferedReader br, PrintWriter pw) {
		try {
			String[] read = br.readLine().split(" ");
			r = Integer.parseInt(read[0]);
			c = Integer.parseInt(read[1]);
			mines = Integer.parseInt(read[2]);
			grid = new String[r][c];

			int cr = r;
			int cc = c;
			while (mines > 0) {
				if (cr == cc && mines == cr - 1 && cr > 3) {
					fillCol(r-cr,c-cc,mines-1);
					cc--;
					continue;
				}
				if (mines == cr-1 && cr < cc) {
					fillRow(r-cr,c-cc,mines);
				}
				else if (mines == cc - 1 && cc < cr) {
					fillCol(r-cr,c-cc,mines);
				}
				else if (cr <= cc) {
					fillCol(r-cr,c-cc,cr);
					cc--;
				}
				else if (cr > cc) {
					fillRow(r-cr,c-cc,cc);
					cr--;
				}
			}
			
			pw.print("\n");
			if (!validateGrid()) {
				pw.print("Impossible");
				return;
			}
			printGrid(pw);
			
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private void fillCol(int row,int col,int num) {
		for (int i = row;i < r && num > 0 && mines > 0;i++) {
			grid[i][col] = "*";
			num--;
			mines--;
		}
	}
	
	private void fillRow(int row,int col,int num) {
		for (int i = col;i < c && num > 0 && mines > 0;i++) {
			grid[row][i] = "*";
			num--;
			mines--;
		}
	}
	
	private boolean validateGrid() {
		reveal(r-1,c-1);
		grid[r-1][c-1] = "c";
		for (int i = 0;i < r;i++) {
			for (int j = 0;j < c;j++) {
				if (grid[i][j] == null) return false;
			}
		}
		return true;
	}
	
	private void reveal(int row, int col) {
		if (grid[row][col] != ".") {
			grid[row][col] = ".";
			if (noBombsAround(row,col)) {
				if (row > 0) reveal(row-1,col); // top
				if (row < r-1) reveal(row+1,col); // down
				if (col > 0) reveal(row,col-1); // left
				if (col < c-1) reveal(row,col+1); // right
				if (row > 0 && col < c-1) reveal(row-1,col+1); // top-right
				if (row > 0 && col > 0) reveal(row-1,col-1); // top-left
				if (row < r-1 && col < c-1) reveal(row+1,col+1); // bottom-right
				if (row < r-1 && col > 0) reveal(row+1,col-1); // bottom-left
			}
		}
	}
	
	private boolean noBombsAround(int row, int col) {
		if (row > 0 && grid[row-1][col] == "*") return false; // top
		if (row < r-1 && grid[row+1][col] == "*") return false; // down
		if (col > 0 && grid[row][col-1] == "*") return false; // left
		if (col < c-1 && grid[row][col+1] == "*") return false; // right
		if (row > 0 && col < c-1 && grid[row-1][col+1] == "*") return false; // top-right
		if (row > 0 && col > 0 && grid[row-1][col-1] == "*") return false; // top-left
		if (row < r-1 && col < c-1 && grid[row+1][col+1] == "*") return false; // bottom-right
		if (row < r-1 && col > 0 && grid[row+1][col-1] == "*") return false; // bottom-left
		return true;
	}
	
	private void printGrid(PrintWriter pw) {
		for (int i = 0;i < r;i++) {
			for (int j = 0;j < c;j++) {
				pw.print(grid[i][j]);
			}
			if (i != r-1) pw.print("\n");
		}
	}
	
}