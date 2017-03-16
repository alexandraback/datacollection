package googlecodejam2014.round1c.enclosure;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;

public class Enclosure {
	private static final long MOD = 1_000_000_007l;
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(final String[] args) throws IOException {
		final String lineSep = System.getProperty("line.separator");
		final BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
		try {
			final Writer out = new BufferedWriter(args.length > 1 ? new FileWriter(args[1]): new OutputStreamWriter(System.out));
			try {
				final int numCases = Integer.parseInt(br.readLine().trim());
				for (int i = 1; i <= numCases;++i) {
					final String[] parts = br.readLine().split(" ");
					final int n = Integer.parseInt(parts[0]), m = Integer
							.parseInt(parts[1]), k = Integer.parseInt(parts[2]);
					out.write("Case #" + i + ": "
 + minStones(n, m, k)
							+ lineSep);
				}
			} finally {
				out.close();
			}
		} finally {
			br.close();
		}
	}


	private static int minStones(final int n, final int m, final int k) {
		if (k < 5) {
			return k;
		}
		if (n == 1) {
			return k;
		}
		if (m == 1) {
			return k;
		}
		if (k >= n * m - 4) {
			final int diff = k - (n * m - 4);
			final int ret = 2 * n + 2 * m - 8 + diff;
			return ret;
		}
		int min = k;
		// int[][] cache;
		// cache = new int[n][m];
		// for (int i = n; i-- > 0;) {
		// for (int j = m; j-- > 0;) {
		// cache[i][j] = Integer.MAX_VALUE;
		// }
		// }
		for (int i = 1; i <= n; ++i) {
			for (int j = (k + i - 1) / i; j <= m; ++j) {
				if (i * j > k) {
					if (k >= i * j - 4) {
						min = Math.min(min, minStones(i, j, k));
					} else {
						min = Math.min(min, 2 * i + 2 * j - 4);
					}
				}
			}
		}
		for (int v = min; v-- > 5;) {
			if (found(n, m, k, v)) {
				min = v;
			} else {
				break;
			}
		}
		int i = Arrays.binarySearch(circleAreas, k);
		if (i < 0) {
			i = -i + 1;
		}
		if (n >= 2 * i && m >= 2 * i) {
			return circlePerimeters[i];
		}
		// int min = Integer.MAX_VALUE;
		// for (final int[] arr : cache) {
		// for (final int i : arr) {
		// min = Math.min(min, i);
		// }
		// }
		return min;
	}

	private static boolean found(final int n, final int m, final int k,
			final int v) {
		final boolean[][] table = new boolean[n][m];
		final int x = n / 2, y = m / 2;
		for (int i = 0; i < k; ++i) {
			table[x][y] = true;
		}
		final boolean valid = isValid(table, k);
		return false;
	}

	private static boolean isValid(final boolean[][] table, final int k) {
		int covered = 0;
		for (int i = 0; i < table.length; ++i) {
			boolean in = false;
			for (int j = 0; j < table[i].length; ++j) {
				if (table[i][j]) {
					++covered;
					in ^= j > 0 ? !table[i][j - 1] : true;
				} else if (in) {
					++covered;
				}
			}
		}
		return covered >= k;
	}

	private static final int[] circlePerimeters = new int[501];
	private static final int[] circleAreas = new int[501];
	static {
		for (int i = circlePerimeters.length; i-- > 0;) {
			circlePerimeters[i] = i * 4;
		}
		for (int i = 1; i < circlePerimeters.length; ++i) {
			circleAreas[i] = circleAreas[i - 1] + circlePerimeters[i];
		}
	}
}
