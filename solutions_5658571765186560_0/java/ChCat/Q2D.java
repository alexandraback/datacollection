import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Q2D {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.print("Case #" + qq + ": ");

			boolean blockable = false;

			int X = readInt();
			int R = readInt();
			int C = readInt();

			if (X >= 7 || (R * C) % X > 0 || (X > R && X > C)) {
				blockable = true;
			} else {

				int min = R > C ? C : R;
				int max = R < C ? C : R;

				if (min < (X + 1) / 2) {
					blockable = true;
				} else if (min == 2) {
					if (X >= 4) {
						blockable = true;
					}
				} else if (min == 3) {
					if (X >= 6) {
						blockable = true;
					}
				} else if (min == 4) {
					if (X == 5) {
						if (max == 4) {
							blockable = true;
						}
					} else if (X >= 6) {
						blockable = true;
					}
				}

			}

			if (blockable) {
				pw.println("RICHARD");
			} else {
				pw.println("GABRIEL");
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
