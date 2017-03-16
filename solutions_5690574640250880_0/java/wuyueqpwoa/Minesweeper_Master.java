import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Scanner;

public class Minesweeper_Master {

	private Scanner sc = new Scanner(System.in);
	private PrintStream ps = new PrintStream(System.out);

	public void setIO(InputStream is, OutputStream os) {
		sc = new Scanner(is);
		ps = new PrintStream(os);
	}

	private int r, c;
	private char[][] map = new char[50][50];
	private LinkedList<Integer> status;

	private boolean check(int x, int y) {
		if (x < 0 || x >= r) {
			return false;
		}

		if (y < 0 || y >= c) {
			return false;
		}

		return true;
	}

	private int save(int x, int y) {
		if (check(x, y) && map[x][y] == '*') {
			status.push(y);
			status.push(x);
			map[x][y] = '0';
			return 1;
		}

		return 0;
	}

	private int statusSave(int x, int y) {
		int count = 0;
		count += save(x + 1, y);
		count += save(x + 1, y + 1);
		count += save(x, y + 1);
		count += save(x - 1, y + 1);
		count += save(x - 1, y);
		count += save(x - 1, y - 1);
		count += save(x, y - 1);
		count += save(x + 1, y - 1);
		status.push(count);
		return count;
	}

	private int statusLoad() {
		if (status.size() == 0) {
			return 0;
		}

		int count = status.pop();

		for (int i = 0; i < count; ++i) {
			map[status.pop()][status.pop()] = '*';
		}

		return count;
	}

	private boolean dfs(int needCells, int x, int y) {
		if (needCells == 0) {
			return false;
		}

		needCells -= statusSave(x, y);
		map[x][y] = '.';

		if (needCells < 0) {
			needCells += statusLoad();
			map[x][y] = '0';
			return true;
		}

		int newX = x, newY = y + 1;

		if (check(newX, newY) && map[newX][newY] == '0') {
			if (!dfs(needCells, newX, newY)) {
				return false;
			}
		}

		newX = x + 1;
		newY = y;

		if (check(newX, newY) && map[newX][newY] == '0') {
			if (!dfs(needCells, newX, newY)) {
				return false;
			}
		}

		newX = x;
		newY = y - 1;

		if (check(newX, newY) && map[newX][newY] == '0') {
			if (!dfs(needCells, newX, newY)) {
				return false;
			}
		}

		newX = x - 1;
		newY = y;

		if (check(newX, newY) && map[newX][newY] == '0') {
			if (!dfs(needCells, newX, newY)) {
				return false;
			}
		}

		needCells += statusLoad();
		map[x][y] = '0';
		return true;
	}

	public void solve() throws FileNotFoundException {
		int cases = sc.nextInt();

		for (int tCases = 1; tCases <= cases; ++tCases) {
			r = sc.nextInt();
			c = sc.nextInt();
			int m = sc.nextInt();

			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					map[i][j] = '*';
				}
			}

			status = new LinkedList<>();
			ps.println("Case #" + tCases + ":");

			if (dfs(r * c - m - 1, 0, 0)) {
				ps.println("Impossible");
			} else {
				map[0][0] = 'c';

				for (int i = 0; i < r; ++i) {
					for (int j = 0; j < c; ++j) {
						char c = map[i][j];

						if (c == '0') {
							ps.print(".");
						} else {
							ps.print(c);
						}
					}

					ps.println();
				}
			}
		}

		sc.close();
	}

	public static void main(String[] args) throws FileNotFoundException {
		Minesweeper_Master solver = new Minesweeper_Master();

		InputStream is = new FileInputStream(
				"Problems\\Minesweeper_Master\\C-small-attempt4.in");
		OutputStream os = new FileOutputStream(
				"Problems\\Minesweeper_Master\\C-small-attempt4.out");
		solver.setIO(is, os);

		solver.solve();
	}
}
