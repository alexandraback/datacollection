import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;

public class Kingdom {
	final BufferedReader reader;
	final PrintStream writer;

	@SuppressWarnings({ "unchecked", "rawtypes" })
	Object nLevels(int[][] stars) {
		int n = stars.length;

		// first, sort levels in decreasing order of two-star difficulty
		Arrays.sort(stars, new Comparator() {
			@Override
			public int compare(Object arg0, Object arg1) {
				int[] a = (int[]) arg0;
				int[] b = (int[]) arg1;
				return -Integer.compare(a[1], b[1]);
			}
		});

		// do a greedy algorithm, count how many levels it takes
		int nlevels = 0;
		boolean[][] done = new boolean[n][2];
		int nstars = 0;
		while (nstars < n * 2) {
			// do all available twostars
			int cheapestTwostar;
			while (true) {
				cheapestTwostar = 1 << 30;
				int oldNstars = nstars;
				for (int i = 0; i < n; i++) {
					if (stars[i][1] <= nstars && !done[i][1]) {
						done[i][1] = true;
						if (done[i][0]) {
							nstars += 1;
							nlevels++;
						} else {
							done[i][0] = true;
							nstars += 2;
							nlevels++;
						}
					} else if (stars[i][1] > nstars && stars[i][1] < cheapestTwostar) {
						cheapestTwostar = stars[i][1];
					}
				}
				if (oldNstars == nstars) {
					break;
				}
			}
			if (nstars == n * 2) {
				break;
			}

			// can't get two stars on any levels.... do as few onestar levels as possible to get to cheapestTwostar
			while (nstars < cheapestTwostar) {
				int oldNstars = nstars;
				for (int i = 0; i < n && nstars < cheapestTwostar; i++) {
					if (!done[i][0] && stars[i][0] <= nstars) {
						done[i][0] = true;
						nstars++;
						nlevels++;
					}
				}
				if (oldNstars == nstars && nstars < cheapestTwostar) {
					return "Too Bad";
				}
			}
		}
		return nlevels;
	}

	/**
	 * Just IO
	 */
	void run() {
		int ncases = readInt();
		for (int ncase = 1; ncase <= ncases; ncase++) {
			int n = readInt();
			int[][] stars = new int[n][];
			for (int i = 0; i < n; i++) {
				stars[i] = readInts();
			}
			String line = "Case #" + ncase + ": " + nLevels(stars);
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

	Kingdom(String input, String output) {
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
			new Kingdom("B-small-attempt0.in", "C:/workspace/codejam/src/B-small-attempt0.out").run();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
