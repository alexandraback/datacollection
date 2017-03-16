import java.util.Arrays;
import java.util.Scanner;


public class MinesweeperMaster {
	
	public static char[][] grid;
	public static int mine;
	public static int avail;

	public static boolean c2() {
		if (avail % 2 > 0 || avail == 2) {
			return false;
		} else {
			fillAvail(avail);
			return true;
		}
	}
	
	public static boolean r2() {
		if (avail % 2 > 0 || avail == 2) {
			return false;
		} else {
			int count = avail;
			for (int c = 0; c < grid[0].length; c++) {
				for (int r = 0; r < 2; r++) {
					grid[r][c] = '.';
					count--;
					if (count == 0) {
						grid[0][0] = 'c';
						return true;
					}
				}
			}
			grid[0][0] = 'c';
			return true;
		}
	}
	
	public static void fillAvail(int count) {
		for (int r = 0; r < grid.length; r++) {
			for (int c = 0; c < grid[0].length; c++) {
				grid[r][c] = '.';
				count--;
				if (count == 0) {
					grid[0][0] = 'c';
					return;
				}
			}
		}
		grid[0][0] = 'c';
	}
	
	public static void printResult(int test, boolean valid) {
		System.out.println("Case #" + test + ":");
		if (!valid) {
			System.out.println("Impossible");
			return;
		}
		for (int i = 0; i < grid.length; i++) {
			System.out.println(grid[i]);
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for (int test = 1; test <= testNum; test++) {
			scan.nextLine();
			int row = scan.nextInt();
			int col = scan.nextInt();
			grid = new char[row][col];
			for (int i = 0; i < row; i++) {
				Arrays.fill(grid[i], '*');
			}
			mine = scan.nextInt();
			avail = row * col - mine;
			if (avail == 0) {
				printResult(test, true);
				continue;
			}
			if (avail == 1 || row == 1 || col == 1) {
				fillAvail(avail);
				printResult(test, true);
				continue;
			}
			if (col == 2) {
				printResult(test, c2());
				continue;
			}
			if (avail <= 2 * col) {
				if (r2()) {
					printResult(test, true);
				} else if (row == 2 || avail == 2) {
					printResult(test, false);
				} else if (avail > col && mine % col == 1 && col > 4) {
					fillAvail(avail);
					grid[2][0] = '.';
					grid[2][1] = '.';
					grid[2][2] = '.';
					grid[0][col - 1] = '*';
					grid[0][col - 2] = '*';
					grid[1][col - 2] = '*';
					printResult(test, true);
				} else if (avail > col && mine % col > 1 && mine % col <= col / 2) {
					fillAvail(avail);
					for (int i = 0; i < mine % col; i++) {
						grid[2][i] = '.';
						grid[0][col - 1 - i] = '*';
					}
					printResult(test, true);
				} else {
					printResult(test, false);
				}
				continue;
			}
			if (avail == 2 * col + 1) {
				if (col == 3) {
					printResult(test, false);
					continue;
				}
				fillAvail(avail);
				grid[2][1] = '.';
				grid[2][2] = '.';
				grid[0][col - 1] = '*';
				grid[1][col - 1] = '*';
				printResult(test, true);
				continue;
			}
			fillAvail(avail);
			if (avail % col == 1) {
				grid[avail/col][1] = '.';
				grid[avail/col-1][col-1] = '*';
			}
			printResult(test, true);
			continue;
		}
		scan.close();
	}

}
