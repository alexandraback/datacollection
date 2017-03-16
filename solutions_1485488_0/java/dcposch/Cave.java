package r1b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class Cave {
	final BufferedReader reader;
	final PrintStream writer;

	void fill(int h, int n, int m, int[][] floor, int[][] ceil, int[][] minTimes, boolean clock) {

		while (true) {
			boolean changed = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {

					// can we move into this square?
					if (!clock && h > ceil[i][j] - 50)
						continue;
					if (floor[i][j] > ceil[i][j] - 50)
						continue;

					int[][] fuu = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
					for (int k = 0; k < 4; k++) {
						int i1 = fuu[k][0] + i, j1 = fuu[k][1] + j;
						if (i1 < 0 || i1 >= n)
							continue;
						if (j1 < 0 || j1 >= m)
							continue;
						if (floor[i1][j1] > ceil[i][j] - 50)
							continue;
						if (floor[i][j] > ceil[i1][j1] - 50)
							continue;

						// yay, (i,j) is accessible from (i1,j1)

						if (!clock) {
							if (minTimes[i1][j1] == 0 && minTimes[i][j] != 0) {
								changed = true;
								minTimes[i][j] = 0;
							}
							continue;
						}

						// clock time.
						int minTStart = minTimes[i1][j1];
						if (h - minTStart > ceil[i][j] - 50) {
							minTStart = h - ceil[i][j] + 50;
						}

						int dtStart = (h - minTStart >= floor[i1][j1] + 20) ? 10 : 100;
						int minTArrive = minTStart + dtStart;
						// if (h - minTArrive > ceil[i][j] - 50) {
						// minTArrive = h - ceil[i][j] + 50;
						// minTStart = minTArrive - dtStart;
						// dtStart = (h - minTStart >= floor[i1][j1] + 20) ? 10 : 100;
						// minTArrive = minTStart + dtStart;
						// }

						if (minTArrive < minTimes[i][j]) {
							minTimes[i][j] = minTArrive;
							changed = true;
						}
					}
				}
			}
			if (!changed)
				break;
		}
	}

	double solve(int h, int n, int m, int[][] floor, int[][] ceil) {
		int[][] minTimes = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				minTimes[i][j] = 1 << 30;
			}
		}
		minTimes[0][0] = 0;

		fill(h, n, m, floor, ceil, minTimes, false);

		// System.out.println("*********");
		// for (int i = 0; i < n; i++) {
		// for (int j = 0; j < m; j++) {
		// String s = new Integer(minTimes[i][j]).toString();
		// System.out.print(s);
		// for (int k = 0; k < 6 - s.length(); k++)
		// System.out.print(' ');
		// }
		// System.out.println();
		// }

		fill(h, n, m, floor, ceil, minTimes, true);

		// System.out.println("*********");
		// for (int i = 0; i < n; i++) {
		// for (int j = 0; j < m; j++) {
		// String s = new Integer(minTimes[i][j]).toString();
		// System.out.print(s);
		// for (int k = 0; k < 6 - s.length(); k++)
		// System.out.print(' ');
		// }
		// System.out.println();
		// }
		// System.out.println("*********");

		return minTimes[n - 1][m - 1];
	}

	/**
	 * Just IO
	 */
	void run() {
		int ncases = readInt();
		for (int ncase = 1; ncase <= ncases; ncase++) {
			int[] hnm = readInts();
			int h = hnm[0], n = hnm[1], m = hnm[2];
			int[][] floor = new int[n][m], ceil = new int[n][m];
			for (int i = 0; i < n; i++) {
				int[] row = readInts();
				for (int j = 0; j < m; j++) {
					ceil[i][j] = row[j];
				}
			}
			for (int i = 0; i < n; i++) {
				int[] row = readInts();
				for (int j = 0; j < m; j++) {
					floor[i][j] = row[j];
				}
			}
			String line = "Case #" + ncase + ": " + solve(h, n, m, floor, ceil) / 10.0;
			if (writer != null) {
				writer.println(line);
			}
			System.out.println(line);
		}
	}

	int readInt() {
		try {
			return Integer.parseInt(reader.readLine());
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	int[] readInts() {
		try {
			String[] parts = reader.readLine().split(" ");
			int[] ret = new int[parts.length];
			for (int i = 0; i < parts.length; i++) {
				ret[i] = Integer.parseInt(parts[i]);
			}
			return ret;
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	Cave(String input, String output) {
		InputStream inputStream = this.getClass().getResourceAsStream(input);
		reader = new BufferedReader(new InputStreamReader(inputStream));
		if (output == null) {
			writer = null;
		} else {
			try {
				writer = new PrintStream(output);
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
	}

	public static void main(String[] args) {
		try {
			new Cave("B-small-attempt0.in", "C:/workspace/codejam/src/r1b/B-small-attempt0.out").run();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
