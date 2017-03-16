import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;


public class Lawnmower {
	
	private Scanner cin;
	private PrintStream cout;
	
	private int[][] lawn;

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		new Lawnmower().solve();
	}

	public void solve() throws Exception {
		cin = new Scanner(System.in);
		cout = System.out;
		int no = cin.nextInt();
		for (int i = 1; i <= no; ++i) {
			cout.printf("Case #%d: %s\n", i, solveCase(i));
		}
	}
	
	private String solveCase(int no) throws Exception {
		int row = cin.nextInt();
		int col = cin.nextInt();
		lawn = new int[row][col];
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				lawn[i][j] = cin.nextInt();
			}
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (!testRow(i, j) && !testCol(i, j)) {
					return "NO";
				}
			}
		}
		return "YES";
	}
	
	private boolean testRow(int row, int col) {
		for (int i = 0; i < lawn[0].length; ++i) {
			if (lawn[row][i] > lawn[row][col]) {
				return false;
			}
		}
		return true;
	}
	
	private boolean testCol(int row, int col) {
		for (int i = 0; i < lawn.length; ++i) {
			if (lawn[i][col] > lawn[row][col]) {
				return false;
			}
		}
		return true;
	}
}
