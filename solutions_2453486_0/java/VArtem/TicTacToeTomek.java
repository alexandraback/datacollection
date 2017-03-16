import java.io.*;
import java.util.*;

public class TicTacToeTomek {

	FastScanner in;
	PrintWriter out;

	void solve() {
		char[][] field = new char[4][];
		for (int i = 0; i < 4; i++) {
			field[i] = in.nextToken().toCharArray();
		}

		boolean xWon = false, oWon = false;

		for (int i = 0; i < 4; i++) {
			{
				boolean allO = true, allX = true;
				for (int j = 0; j < 4; j++) {
					if (field[i][j] == '.' || field[i][j] == 'X') {
						allO = false;
					}
					if (field[i][j] == '.' || field[i][j] == 'O') {
						allX = false;
					}
				}
				xWon |= allX;
				oWon |= allO;
			}
			{
				boolean allO = true, allX = true;
				for (int j = 0; j < 4; j++) {
					if (field[j][i] == '.' || field[j][i] == 'X') {
						allO = false;
					}
					if (field[j][i] == '.' || field[j][i] == 'O') {
						allX = false;
					}
				}
				xWon |= allX;
				oWon |= allO;
			}
		}
		
		{
			boolean allO = true, allX = true;
			for (int j = 0; j < 4; j++) {
				if (field[j][j] == '.' || field[j][j] == 'X') {
					allO = false;
				}
				if (field[j][j] == '.' || field[j][j] == 'O') {
					allX = false;
				}
			}
			xWon |= allX;
			oWon |= allO;
		}
		
		{
			boolean allO = true, allX = true;
			for (int j = 0; j < 4; j++) {
				if (field[3 - j][j] == '.' || field[3 - j][j] == 'X') {
					allO = false;
				}
				if (field[3 - j][j] == '.' || field[3 - j][j] == 'O') {
					allX = false;
				}
			}
			xWon |= allX;
			oWon |= allO;
		}
		
		boolean hasDot = false;
		for (char[] c : field) {
			for (char ch : c) {
				if (ch == '.') {
					hasDot = true;
				}
			}
		}
		
		if (oWon) {
			out.println("O won");
		} else if (xWon) {
			out.println("X won");
		} else {
			if (hasDot) {
				out.println("Game has not completed");
			} else {
				out.println("Draw");
			}
		}
	}

	void run() throws FileNotFoundException {
		in = new FastScanner("input.txt");
		out = new PrintWriter("output.txt");
		int tests = in.nextInt();
		for (int i = 0; i < tests; i++) {
			out.printf("Case #%d: ", i + 1);
			solve();
		}
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String name) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(name)));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		new TicTacToeTomek().run();
	}
}
