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

	private static class Solution {

		public int a;
		public int b;
		public int c;

		public static Solution decode(int code) {

			Solution s = new Solution();

			s.a = code & 7;
			code = code >> 3;
			s.b = code & 7;
			code = code >> 3;
			s.c = code & 7;

			return s;
		}

		public static int encode(int a, int b, int c) {
			return a + b * 8 + c * 64;
		}

	}

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
			int X = readInt();

			String s = nextToken();
			String t = "";
			for (int i = 0; i < X; i++) {
				t += s;
			}

			BitSet solutions = new BitSet(512);

			solutions.set(Solution.encode(q(t.charAt(0)), 0, 0));

			for (int i = 1; i < t.length(); i++) {
				BitSet newSolutions = new BitSet(512);

				int m = q(t.charAt(i));

				for (int v = 0; v < 512; v++) {
					if (solutions.get(v)) {
						Solution c = Solution.decode(v);

						if (c.c != 0) {
							newSolutions.set(Solution.encode(c.a, c.b,
									product[c.c][m]));
						} else {
							if (c.b != 0) {
								newSolutions.set(Solution.encode(c.a,
										product[c.b][m], 0));
								newSolutions.set(Solution.encode(c.a, c.b, m));
							} else {
								newSolutions.set(Solution.encode(
										product[c.a][m], 0, 0));
								newSolutions.set(Solution.encode(c.a, m, 0));
							}
						}

					}
				}

				solutions = newSolutions;
			}

			if (solutions.get(Solution.encode(2, 4, 6))) {
				pw.println("YES");
			} else {
				pw.println("NO");
			}

		}

		pw.close();
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
