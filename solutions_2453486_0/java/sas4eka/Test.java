import java.io.*;
import java.util.*;

public class Test {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				"A-small-attempt0.in")));
		tokenizer = null;
		writer = new PrintWriter("A-small-attempt0.out");

		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			writer.print("Case #" + i + ": ");
			banana();
		}

		reader.close();
		writer.close();
	}

	private static void banana() throws IOException {
		char[][] mas = new char[4][4];
		for (int i = 0; i < 4; i++) {
			String s = nextToken();
			for (int j = 0; j < 4; j++) {
				mas[i][j] = s.charAt(j);
			}
		}
		boolean dx1 = true;
		boolean do1 = true;
		boolean dx2 = true;
		boolean do2 = true;
		boolean ended = true;
		for (int i = 0; i < 4; i++) {
			if (mas[i][i] != 'T') {
				if (mas[i][i] != 'X')
					dx1 = false;
				if (mas[i][i] != 'O')
					do1 = false;
			}
			if (mas[i][3 - i] != 'T') {
				if (mas[i][3 - i] != 'X')
					dx2 = false;
				if (mas[i][3 - i] != 'O')
					do2 = false;
			}
			boolean vx = true;
			boolean vo = true;
			boolean hx = true;
			boolean ho = true;
			for (int j = 0; j < 4; j++) {
				if (mas[i][j] == '.')
					ended = false;
				if (mas[i][j] != 'T') {
					if (mas[i][j] != 'X')
						vx = false;
					if (mas[i][j] != 'O')
						vo = false;
				}

				if (mas[j][i] != 'T') {
					if (mas[j][i] != 'X')
						hx = false;
					if (mas[j][i] != 'O')
						ho = false;
				}
			}
			if (vx || hx) {
				writer.println("X won");
				return;
			}
			if (vo || ho) {
				writer.println("O won");
				return;
			}
		}
		if (dx1 || dx2) {
			writer.println("X won");
			return;
		}
		if (do1 || do2) {
			writer.println("O won");
			return;
		}
		if (ended)
			writer.println("Draw");
		else
			writer.println("Game has not completed");
	}
}