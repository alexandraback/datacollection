import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class A implements Runnable {

	public boolean X_Won(String row) {
		if (row.equals("TXXX") || row.equals("XTXX") || row.equals("XXTX")
				|| row.equals("XXXT") || row.equals("XXXX")) {
			return true;
		}
		return false;
	}

	public boolean O_Won(String row) {
		if (row.equals("TOOO") || row.equals("OTOO") || row.equals("OOTO")
				|| row.equals("OOOT") || row.equals("OOOO")) {
			return true;
		}
		return false;
	}

	private void solve() throws IOException {
		int t = nextInt();

		while (t-- > 0) {
			char[][] g = new char[4][4];

			boolean dot = false;
			for (int i = 0; i < 4; i++) {
				g[i] = nextToken().toCharArray();
				if (new String(g[i]).contains(".")) {
					dot = true;
				}
			}

			boolean X = false, O = false;
			for (int i = 0; i < 4; i++) {
				String row = new String(g[i]);
				if (X_Won(row)) {
					X = true;
				}
				if (O_Won(row)) {
					O = true;
				}
			}

			for (int j = 0; j < 4; j++) {
				String col = "";
				for (int i = 0; i < 4; i++) {
					col += g[i][j];
				}
				if (X_Won(col)) {
					X = true;
				}
				if (O_Won(col)) {
					O = true;
				}
			}

			String diagonal = "";
			for (int i = 0; i < 4; i++) {
				diagonal += g[i][i];
			}
			if (X_Won(diagonal)) {
				X = true;
			}
			if (O_Won(diagonal)) {
				O = true;
			}

			String right_diagonal = "";
			for (int i = 0; i < 4; i++) {
				right_diagonal += g[i][4 - (i + 1)];
			}
			if (X_Won(right_diagonal)) {
				X = true;
			}
			if (O_Won(right_diagonal)) {
				O = true;
			}

			pf();
			if (X && O) {
				pl("Draw");
			} else if (X) {
				pl("X won");
			} else if (O) {
				pl("O won");
			} else {
				if (!dot) {
					pl("Draw");
				} else {
					pl("Game has not completed");
				}
			}

		}
	}

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new FileReader("A-large.in"));
			writer = new PrintWriter("A.out");
			tokenizer = null;
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	void p(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.println();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
	}

}