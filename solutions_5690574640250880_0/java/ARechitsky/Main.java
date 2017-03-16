import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter("OUTPUT.TXT");
		int t = in.nextInt();
		for (int t0 = 0; t0 < t; ++t0) {
			int r = in.nextInt();
			int c = in.nextInt();
			int m = in.nextInt();
			char[][] res = solve(r, c, m);
			out.println(String.format("Case #%d:", t0+1));
			if (res!=null)
			{
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						out.print(res[i][j]);
					}
					out.println();
				}
			}
			else
			{
				out.println("Impossible");
			}
		}
		in.close();
		out.close();
	}

	private static char[][] solve(int r, int c, int m) {
		int f = r * c - m;
		if (m == 0)
			return empty(r, c);
		if (f == 0)
			return null;
		if (f == 1)
			return withOne(r, c);
		if (r == 1)
			return row(c, f);
		if (c == 1)
			return column(r, f);
		if (f == 2)
			return null;
		if (f < 8 && f % 2 == 1)
			return null;
		if ((r == 2 || c == 2) && f % 2 == 1)
			return null;
		if (f <= 2 * c && f % 2 == 0)
			return evenTwoRows(r, c, f);
		if (f <= 2 * c + 1 && f % 2 == 1)
			return oddTwoRows(r, c, f);
		return fill(r, c, f);
	}

	private static char[][] withOne(int r, int c) {
		char[][] res = new char[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				res[i][j] = '*';
			}
		}
		res[0][0] = 'c';
		return res;
	}

	private static char[][] empty(int r, int c) {
		char[][] res = new char[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				res[i][j] = '.';
			}
		}
		res[0][0] = 'c';
		return res;
	}

	private static char[][] row(int c, int f) {
		char[][] res = new char[1][c];
		for (int j = 0; j < c; j++) {
			res[0][j] = j < f ? '.' : '*';
		}
		res[0][0] = 'c';
		return res;
	}

	private static char[][] column(int r, int f) {
		char[][] res = new char[r][1];
		for (int j = 0; j < r; j++) {
			res[j][0] = j < f ? '.' : '*';
		}
		res[0][0] = 'c';
		return res;
	}

	private static char[][] evenTwoRows(int r, int c, int f) {
		char[][] res = new char[r][c];
		for (int j = 0; j < f / 2; j++) {
			res[0][j] = '.';
			res[1][j] = '.';
		}
		for (int j = f / 2; j < c; j++) {
			res[0][j] = '*';
			res[1][j] = '*';
		}
		for (int i = 2; i < r; i++) {
			for (int j = 0; j < c; j++) {
				res[i][j] = '*';
			}
		}
		res[0][0] = 'c';
		return res;
	}

	private static char[][] oddTwoRows(int r, int c, int f) {
		char[][] res = new char[r][c];
		for (int j = 0; j < (f / 2) - 1; j++) {
			res[0][j] = '.';
			res[1][j] = '.';
		}
		for (int j = (f / 2) - 1; j < c; j++) {
			res[0][j] = '*';
			res[1][j] = '*';
		}
		for (int j = 0; j < 3; j++) {
			res[2][j] = '.';
		}
		for (int j = 3; j < c; j++) {
			res[2][j] = '*';
		}
		for (int i = 3; i < r; i++) {
			for (int j = 0; j < c; j++) {
				res[i][j] = '*';
			}
		}
		res[0][0] = 'c';
		return res;
	}

	private static char[][] fill(int r, int c, int f) {
		char[][] res = new char[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				res[i][j] = i * c + j < f ? '.' : '*';
			}
		}
		if (f % c == 1) {
			res[(f / c) - 1][c - 1] = '*';
			res[f / c][1] = '.';
		}
		res[0][0] = 'c';
		return res;
	}
}
