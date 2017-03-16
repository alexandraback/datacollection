import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QC {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	private static int R;
	private static int C;
	private static int M;

	private static char[][] field;
	private static int[] values;
	private static boolean isGood;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		final int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.println("Case #" + qq + ": ");

			R = readInt();
			C = readInt();
			M = readInt();

			prepareValues();
			printValues();

		}

		pw.close();
	}

	private static void printValues() {

		if (!isGood) {
			pw.println("Impossible");
		}
		if (isGood) {
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {

					if (r == R - 1 && c == C - 1) {
						pw.print('c');
					} else {
						if (r >= R - values[c]) {
							pw.print('.');
						} else {
							pw.print('*');
						}
					}
				}
				pw.println();
			}
		}

		// } else {
		// pw.println("Impossible");
		// }
	}

	private static void prepareValues() {
		values = new int[C];
		int m = M;

		isGood = false;

		if (M == R * C - 1) {
			for (int c = 0; c < C; c++) {
				values[c] = 0;
			}

			isGood = true;
			return;
		}

		if (C == 1) {
			values[0] = R - m;
			isGood = true;
			return;
		}

		if (R == 1) {
			for (int c = 0; c < C; c++) {
				if (c < m) {
					values[c] = 0;
				} else {
					values[c] = 1;
				}
			}

			isGood = true;
			return;
		}

		if (C == 2) {
			if (m % 2 == 0) {
				values[0] = R - m / 2;
				values[1] = R - m / 2;
				if (R * C - m >= 4) {

					isGood = true;
				}
				return;
			} else {
				isGood = false;
				return;
			}
		}

		if (R == 2) {
			if (m % 2 == 0) {
				for (int c = 0; c < C; c++) {
					if (2 * c < m) {
						values[c] = 0;
					} else {
						values[c] = 2;
					}
				}

				if (R * C - m >= 4) {
					isGood = true;
				}

				return;
			} else {
				isGood = false;
				return;
			}
		}

		for (int c = 0; c <= C - 2; c++) {
			if (c < C - 2) {
				if (m > 0) {
					if (m >= R) {
						values[c] = 0;
						m = m - R;
						continue;
					}

					if (m < R - 1) {
						values[c] = R - m;
						m = 0;
						values[C - 2] = R;
						values[C - 1] = R;
						isGood = true;
						for (int j = c + 1; j < C; j++) {
							values[j] = R;
						}
						return;
					}

					// m = R-1

					values[c] = R - (m - 1);
					m = 1;
					continue;
				} else {
					values[c] = R;
				}
			} else {
				if (m > 0) {

					if (m % 2 == 0) {
						values[C - 2] = R - m / 2;
						values[C - 1] = R - m / 2;
						if (values[C - 2] > 1) {
							isGood = true;
						} else {
							isGood = false;
						}
					} else {
						if (values[C - 3] > 1) {
							if (values[C - 3] < R - 1) {
								values[C - 3] = values[C - 3] + 1;
								m = m + 1;
								values[C - 2] = R - m / 2;
								values[C - 1] = R - m / 2;

								isGood = true;
							} else {
								// bad
							}
						} else {
							if (R > 3) {
								values[C - 3] = values[C - 3] + 3;
								m = m + 3;
								values[C - 2] = R - m / 2;
								values[C - 1] = R - m / 2;
								if (values[C - 2] >= values[C - 3]) {
									isGood = true;
								}
							}
						}
					}
				} else {
					values[C - 2] = R;
					values[C - 1] = R;
					isGood = true;
				}
			}

		}

	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}
