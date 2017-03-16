import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.StringTokenizer;

public class Q2C {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static int q(char c) {
		if (c == 'i') {
			return 2;
		} else if (c == 'j') {
			return 4;
		} else {
			return 6;
		}
	}

	public static int encode(int a, int b, int c, int type) {
		return a + b * 8 + c * 64 + type * 8 * 8 * 8;
	}

	public static int[][] product = new int[][] { { 0, 1, 2, 3, 4, 5, 6, 7 },
			{ 1, 0, 3, 2, 5, 4, 7, 6 }, { 2, 3, 1, 0, 6, 7, 5, 4 },
			{ 3, 2, 0, 1, 7, 6, 4, 5 }, { 4, 5, 7, 6, 1, 0, 2, 3 },
			{ 5, 4, 6, 7, 0, 1, 3, 2 }, { 6, 7, 4, 5, 3, 2, 1, 0 },
			{ 7, 6, 5, 4, 2, 3, 0, 1 } };

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.print("Case #" + qq + ": ");

			int L = readInt();
			long X = readLong();

			String s = nextToken();
			char[] chars = s.toCharArray();

			BitSet solutions = new BitSet(512 * 8);

			solutions.set(encode(q(chars[0]), 0, 0, 1)); // x**
			solutions.set(encode(0, q(chars[0]), 0, 2)); // *x*
			solutions.set(encode(0, 0, q(chars[0]), 4)); // **x

			for (int i = 1; i < chars.length; i++) {
				BitSet newSolutions = new BitSet(512 * 8);

				int m = q(chars[i]);

				for (int v = 0; v < 512 * 8; v++) {
					if (solutions.get(v)) {
						int code = v;
						int a = code & 7;
						int b = (code >> 3) & 7;
						int c = (code >> 6) & 7;
						int type = (code >> 9) & 7;

						if ((type & 4) > 0) {
							// **x - >**xm
							newSolutions.set(encode(a, b, product[c][m], type));
						} else {
							if ((type & 2) > 0) {
								newSolutions.set(encode(a, product[b][m], 0,
										type));
								newSolutions.set(encode(a, b, m, type | 4));
							} else {
								newSolutions.set(encode(product[a][m], 0, 0,
										type));
								newSolutions.set(encode(a, m, 0, type | 2));
							}
						}

					}
				}

				solutions = newSolutions;
			}

			BitSet square = copySet(solutions);
			BitSet result = null;

			while (X > 0) {

				if ((X & 1L) > 0) {
					if (result == null) {
						result = copySet(square);
					} else {
						result = multyply(result, square);

					}
				}

				square = multyply(square, square);
				X = X >> 1;
			}

			if (result.get(encode(2, 4, 6, 7))) {
				pw.println("YES");
			} else {
				pw.println("NO");
			}

		}

		pw.close();
	}

	private static BitSet multyply(BitSet a, BitSet b) {
		BitSet result = new BitSet(512 * 8);

		for (int v1 = 0; v1 < 512 * 8; v1++) {
			if (a.get(v1)) {
				for (int v2 = 0; v2 < 512 * 8; v2++) {
					if (b.get(v2)) {

						int[] w1 = new int[3];
						w1[0] = v1 & 7;
						w1[1] = (v1 >> 3) & 7;
						w1[2] = (v1 >> 6) & 7;
						int type1 = (v1 >> 9) & 7;

						int[] w2 = new int[3];
						w2[0] = v2 & 7;
						w2[1] = (v2 >> 3) & 7;
						w2[2] = (v2 >> 6) & 7;
						int type2 = (v2 >> 9) & 7;

						int[] r = new int[3];

						int last1 = -1;
						int first2 = -1;

						for (int i = 0; i < 3; i++) {
							if ((type1 & (1 << i)) > 0) {
								last1 = i;

								if ((type2 & (1 << i)) > 0) {
									if (first2 == -1) {
										first2 = i;
									}
									r[i] = product[w1[i]][w2[i]];
								} else {
									r[i] = w1[i];
								}
							} else {
								if ((type2 & (1 << i)) > 0 && first2 == -1) {
									first2 = i;
								}
								r[i] = w2[i];
							}
						}

						if (last1 != -1 && first2 != -1
								&& (last1 == first2 || last1 + 1 == first2)) {
							result.set(encode(r[0], r[1], r[2], type1 | type2));
						}

					}
				}
			}
		}

		return result;
	}

	private static BitSet copySet(BitSet source) {
		BitSet result = new BitSet(source.size());
		result.or(source);
		return result;
	}

	private static void skip(int n) throws IOException {
		int i = 1;
		while (i <= n) {
			br.readLine();
			i++;
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
