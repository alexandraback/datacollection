import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/*
 * Author :	David Tang
 * Date :	Apr 13, 2013
 */

public class Lawnmower {

	private final static String fILE_NAME = "B-small-attempt0";

	private static int[][] field;

	public static void main(String[] args) {
		BufferedReader buffRead = null;
		PrintWriter printWrit = null;
		int t;
		try {
			printWrit = new PrintWriter(new BufferedWriter(new FileWriter(fILE_NAME + ".out")));
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			buffRead =new BufferedReader(new InputStreamReader(new FileInputStream(fILE_NAME + ".in")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		try {
			t = Integer.parseInt(buffRead.readLine());
			for (int i = 0; i < t; i++) {
				int[] dim = tabStringToInt(buffRead.readLine().split(" "));
				field = new int[dim[0]][dim[1]];
				int[] tabInt;
				for (int j = 0; j < dim[0]; j++) {
					tabInt = tabStringToInt(buffRead.readLine().split(" "));
					for (int k = 0; k < dim[1]; k++) {
						field[j][k] = tabInt[k];
					}
				}
				printWrit.println("Case #" + (i+1) + ": " + solve());
			}
			buffRead.close();
			printWrit.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static int[] tabStringToInt(String[] s) {
		int[] i = new int[s.length];
		for (int j = 0; j < i.length; j++) {
			i[j] = Integer.parseInt(s[j]);
		}
		return i;
	}

	//	private static void drawTab(int[][] tab) {
	//		for (int i = 0; i < tab.length; i++) {
	//			for (int j = 0; j < tab[i].length; j++) {
	//				System.out.print(tab[i][j] + " ");
	//			}
	//			System.out.println();
	//		}
	//		System.out.println();
	//	}

	private static String solve() {
		Point p;
		int min;
		boolean row;
		boolean col;
		do {
			p = getMin(field);
			min = field[p.x][p.y];
			row = checkRow(p.x, min);
			col = checkCol(p.y, min);
			if (!row && !col) {
				return "NO";
			}
			if (row) {
				for (int i = 0; i < field[0].length; i++) {
					field[p.x][i] = 0;
				}
			}
			if (col) {
				for (int i = 0; i < field.length; i++) {
					field[i][p.y] = 0;
				}
			}
		} while(!isClear(field));
		return "YES";
	}

	private static boolean checkRow(int r, int min) {
		for (int i = 0; i < field[0].length; i++) {
			if (field[r][i] > min) {
				return false;
			}
		}
		return true;
	}

	private static boolean checkCol(int c, int min) {
		for (int i = 0; i < field.length; i++) {
			if (field[i][c] > min) {
				return false;
			}
		}
		return true;
	}

	private static Point getMin(int[][] tab) {
		Point p = null;
		int min = 1291;
		for (int i = 0; i < tab.length; i++) {
			for (int j = 0; j < tab[i].length; j++) {
				if (tab[i][j] < min && tab[i][j] != 0) {
					min = tab[i][j];
					p = new Point(i, j);
				}
			}
		}
		return p;
	}

	private static boolean isClear(int[][] tab) {
		for (int i = 0; i < tab.length; i++) {
			for (int j = 0; j < tab[i].length; j++) {
				if (tab[i][j] != 0) {
					return false;
				}
			}
		}
		return true;
	}

}
