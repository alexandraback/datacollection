package shb.test.codejam.k14;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

import shb.test.codejam.JamInputReader;

public class MineSweeper {
	private JamInputReader jam;
	private StringBuffer out;
	
	char[][] solution;
	boolean found = false;
	int rows, cols, mines;

	public static void main(String[] args) throws IOException {
//		MineSweeper problem = new MineSweeper("mines.in");
//		MineSweeper problem = new MineSweeper("C-small-attempt1.in");
		MineSweeper problem = new MineSweeper("C-large.in");

		int tests = problem.jam.readInt();

		for (int t = 1; t <= tests; t++) {
			problem.solve(t);
		}

		problem.printResults("mines.out");

	}
	
	private void solve(int t) throws IOException {
		int[] row = jam.readIntArray(3);
		rows = row[0];
		cols = row[1];
		mines = row[2];
		
		char[][] game;
		boolean[][] vis;
		
		game = new char[rows][cols];
		solution = new char[rows][cols];
		vis = new boolean[rows][cols];
		for (int ro = 0; ro < rows; ro++) {
			for (int co = 0; co < cols; co++) {
				game[ro][co] = '*';
				vis[ro][co] = false;
			}
		}
	
		found = false;
		
		if (t > 1) {
			out.append("\n");
		}
		out.append("Case #" + t + ":");
		// possible?
		boolean possible = isPossible(rows, cols, mines);
		if (!possible) {
//			out.append("\nImpossible");
		} else {
			game[0][0] = '.';
			solve(0,0,1, game, vis);
			solution[0][0] = 'c';
		}
		
		if (found) {
			for (int i = 0; i < rows; i++) {
				out.append("\n");
				for (int j = 0; j < cols; j++) {
					out.append(solution[i][j] + "");
				}
			}
		} else {
			out.append("\nImpossible");
		}
	}
	
	char[][] copyMat(char[][] mat) {
		char[][] result = new char[mat.length][mat[0].length];
		
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[0].length; j++) {
				result[i][j] = mat[i][j];
			}
		}
		return result;
	}
	
	
	boolean[][] copyMat(boolean[][] mat) {
		boolean[][] result = new boolean[mat.length][mat[0].length];
		
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[0].length; j++) {
				result[i][j] = mat[i][j];
			}
		}
		return result;
	}
	

	private void solve(int x, int y, int spaces, char[][] game, boolean[][] vis) {
		if (found) {
			return;
		}

		if (spaces > rows * cols - mines) {
			return;
		}
		if (spaces == rows * cols - mines) {
			System.out.println("YAY");
			found = true;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					solution[i][j] = game[i][j];
				}
			}
		}
		
		vis[x][y]= true;
		// update empty spaces
		spaces += checkSpaces(x, y, game);

		// move right if necessary,
		if (isInbound(x, y+1) && !vis[x][y + 1]) {
			solve(x, y + 1, spaces, copyMat(game), copyMat(vis));
		}
		
		// move down if necessary
		if (isInbound(x+1, y) && !vis[x + 1][y]) {
			solve(x + 1, y, spaces, copyMat(game), copyMat(vis));
		}

		// move left if necessary
		if (isInbound(x, y-1) && !vis[x][y - 1]) {
			solve(x, y - 1, spaces, copyMat(game), copyMat(vis));
		}
		
		//move up
		if (isInbound(x-1, y) && !vis[x-1][y]) {
			solve(x-1, y, spaces, copyMat(game), copyMat(vis));
		}
		
/*		//move down-right
		if (isInbound(x+1, y+1) && !vis[x+1][y+1]) {
			solve(x+1, y+1, spaces);
		}*/
	}

	private int checkSpaces(int x, int y, char[][] game) {
		int spaces = 0;
		spaces += checkSpace(x, y, game);
		spaces += checkSpace(x, y + 1, game);
		spaces += checkSpace(x + 1, y + 1, game);
		spaces += checkSpace(x + 1, y, game);
		spaces += checkSpace(x + 1, y - 1, game);
		spaces += checkSpace(x, y - 1, game);
		spaces += checkSpace(x - 1, y - 1, game);
		spaces += checkSpace(x - 1, y, game);
		spaces += checkSpace(x - 1, y + 1, game);
		return spaces;
	}

	private int checkSpace(int x, int y, char[][] game) {
		if (isInbound(x,y) && game[x][y] != '.') {
			game[x][y] = '.';
			return 1;
		}
		return 0;
	}
	
	private boolean isInbound(int x, int y) {
		return x >= 0 && x < rows && y >= 0 && y < cols; 
	}

	private boolean isPossible(int r, int c, int m) {
		if (m == r * c - 1 || m == 0) {
			// no mines or (all but one mines)
			return true;
		}

		if (r == 1 || c == 1) {
			return true;
		}

		if (r == 2 && c == 2) {
			// in a 2x2 you can solve it in one click with no mines or with 3
			// mines, both cases covered above
			return false;
		}

		if (r == 2 || c == 2) {
			//
			return m % 2 == 0;
		}

		if (r * c >= m + 9) {
			// any combination is possible w/ at least 9 empty spaces
			return true;
		}

		// remaining solve 3x3
		int empty = r * c - m;//9 - m % 9;
		if (empty == 2 || empty == 3 || empty == 5 || empty == 7) {
			return false;
		}
		return true;

	}
	
	
	public MineSweeper(String filename) throws FileNotFoundException {
		jam = new JamInputReader(filename);
		out = new StringBuffer();
	}

	private void printResults(String filename) throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
		writer.append(out.toString());
		writer.close();
	}

}
