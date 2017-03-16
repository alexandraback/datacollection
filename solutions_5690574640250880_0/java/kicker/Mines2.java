import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Mines2 {

	Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
	static final String FILENAME = "C-small-attempt4";
	static final String IN = FILENAME + ".in";
	static final String OUT = FILENAME + ".out";
	static int t[][];
	PrintStream out;

	// bad solution
	// bad complexity
	private void solve() {

		int r = sc.nextInt();
		int c = sc.nextInt();
		int m = sc.nextInt();
		int points = r * c - m;
		t = new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				t[i][j] = -1;
			}
		}
		boolean possible = false;
		if (points > 1) {

			t[0][0] = getNeighboors(t, 0, 0).size();
			points -= 1;
			int emptyCase = 0;

			if ((emptyCase = forceZero(points, getNeighboors(t, 0, 0))) != -1) {
				t[0][0] = 0;
				points -= emptyCase;
				List<Coord> list = getNeighboors(t, 0, 0);
				Collections.sort(list);
				while (points >= 0 && list.size() != 0) {
					Coord coord = list.remove(0);
					if (points == 3) {
						for (int j = 0; j < list.size(); j++) {
							if (getNumberOfEmptyNeighBoors(getNeighboors(t,
									list.get(j).row, list.get(j).col)) == 3) {
								coord = list.get(j);
								break;
							}

						}

					}
					if ((emptyCase = forceZero(points,
							getNeighboors(t, coord.row, coord.col))) != -1
							&& emptyCase != 0 ) {
						list.addAll(getNeighboors(t, coord.row, coord.col));
						Collections.sort(list);
						points -= emptyCase;
					}
				}
			}

			if (points == 0)
				possible = true;
		} else if (points == 1) {
			possible = true;
		}

		if (possible) {

			for (int i = 0; i < t.length; i++) {
				out.println();
				for (int j = 0; j < t[0].length; j++) {
					if (i == 0 && j == 0)
						out.print("c");
					else if (t[i][j] == -1)
						out.print("*");
					else
						out.print(".");
				}
			}
		} else if (!possible) {
			out.println();
			out.print("Impossible");
		}
	}

	private int getNumberOfEmptyNeighBoors(List<Coord> list) {
		int res = 0;
		for (Coord coord : list) {
			if (coord.value == -1) {
				res++;
			}

		}
		return res;
	}

	private boolean hasZeroNeighBoors(int r, int c) {
		List<Coord> list = getNeighboors(t, r, c);
		for (Coord coord : list) {
			if (coord.value == 0) {
				return true;
			}

		}
		return false;
	}

	private int forceZero(int nonBomb, List<Coord> list) {
		int emptyCase = getNumberOfEmptyNeighBoors(list);

		if (emptyCase <= nonBomb) {
			for (Coord coord : list) {
				if (coord.value == -1) {
					t[coord.row][coord.col] = getNumberOfEmptyNeighBoors(getNeighboors(
							t, coord.row, coord.col));
				}

			}
			return emptyCase;
		}
		return -1;
	}

	private static Coord initCoord(int row, int col, int value) {
		Coord coord = new Coord();
		coord.row = row;
		coord.col = col;
		coord.value = value;
		return coord;
	}

	public static List<Coord> getNeighboors(int[][] t, int r, int c) {
		List<Coord> res = new ArrayList<>();
		if (c < t[0].length - 1) {

			res.add(initCoord(r, c + 1, t[r][c + 1]));

			if (r < t.length - 1)
				res.add(initCoord(r + 1, c + 1, t[r + 1][c + 1]));
			if (0 < r)
				res.add(initCoord(r - 1, c + 1, t[r - 1][c + 1]));
		}
		if (0 < c) {
			res.add(initCoord(r, c - 1, t[r][c - 1]));
			if (r < t.length - 1)
				res.add(initCoord(r + 1, c - 1, t[r + 1][c - 1]));
			if (0 < r)
				res.add(initCoord(r - 1, c - 1, t[r - 1][c - 1]));

		}
		if (r < t.length - 1) {
			res.add(initCoord(r + 1, c, t[r + 1][c]));
		}
		if (0 < r) {
			res.add(initCoord(r - 1, c, t[r - 1][c]));
		}
		return res;
	}

	static class Coord implements Comparable<Coord> {
		int row;
		int col;
		int value;

		@Override
		public int compareTo(Coord o) {
			// TODO Auto-generated method stub
			if (this.value > o.value)
				return 1;
			return -1;
		}

		@Override
		public boolean equals(Object obj) {
			if (obj instanceof Coord) {
				if (((Coord) obj).col == this.col
						&& ((Coord) obj).row == this.row) {
					return true;
				}

			}
			return false;
		}

		@Override
		public int hashCode() {
			return row * 50 + col;
		}

	}

	private void run() throws Exception {
		sc.useLocale(Locale.US);
		out = new PrintStream(new FileOutputStream(OUT));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sc.nextLine();
			out.print("Case #" + i + ": ");
			solve();
			out.println();
		}
		sc.close();
		out.close();
	}

	public static void main(String args[]) throws Exception {
		new Mines2().run();
	}

}