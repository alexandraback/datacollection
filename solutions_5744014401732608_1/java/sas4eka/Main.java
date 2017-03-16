import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader reader;
	static PrintWriter writer;
	static StringTokenizer tokenizer;

	static String task = "B-large";

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	static int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(task + ".in")));
		writer = new PrintWriter(task + ".out");
		solve();
		reader.close();
		writer.close();
	}

	static void solve() throws NumberFormatException, IOException {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			writer.print("Case #" + (i + 1) + ": ");
			banana();
		}
	}

	static void banana() throws NumberFormatException, IOException {
		int b = nextInt();
		long m = nextLong();

		int[][] res = new int[b][b];

		long curr = 1;
		for (int j = b - 2; j >= 0; j--) {
			if (curr == m) {
				res[j][j + 1] = 1;
			} else if (2 * curr <= m) {
				for (int i = j + 1; i < b; i++) {
					res[j][i] = 1;
				}
				if (j != b - 2) {
					curr *= 2;
				}
			} else {
				long tot = 0;
				for (int i = j + 1; i < b; i++) {
					long node = 1;
					for (int k = 0; k < b - 1 - i - 1; k++) {
						node *= 2;
					}
					if (m - tot >= node) {
						tot += node;
						res[j][i] = 1;
					}
				}
				curr = m;
			}
		}

		if (curr == m) {
			writer.println("POSSIBLE");
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < b; j++) {
					writer.print(res[i][j]);
				}
				writer.println();
			}
		} else {
			writer.println("IMPOSSIBLE");
		}
	}
}