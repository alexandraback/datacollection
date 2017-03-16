import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class Minesweeper {

	private static void fillMines(char[][] field) {
		for (int i = 0; i < field.length; i++) {
			for (int j = 0; j < field[i].length; j++)
				if (field[i][j] == 0) {
					field[i][j] = '*';
				}
		}
	}

	private static int open(int r, int c, char[][] field) {
		if (field[r][c] == 0) {
			field[r][c] = '.';
			return 1;
		}
		return 0;
	}

	private static int putZero(int r, int c, char[][] field) {
		int opened = 0;
		if (r < field.length - 1) {
			opened += open(r + 1, c, field);
		}
		if (c < field[r].length - 1) {
			opened += open(r, c + 1, field);
		}
		if (r < field.length - 1 && c < field[r].length - 1) {
			opened += open(r + 1, c + 1, field);
		}

		return opened;
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(new Locale("en", "US"));

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int m = in.nextInt();

			char[][] field = new char[R][C];
			field[0][0] = 'c';
			int r = 0, c = 0, free = R * C - 1;

			while (free > m) {
				if (r < R - 1) {
					int j = 0;
					while (j < c && free > m) {
						free -= putZero(r, j, field);
						j++;
						if (free - m == 2) {
							if (c < C - 1) {
								free -= putZero(0, c, field);
							} else if (r < R - 2) {
								free -= putZero(r + 1, 0, field);
							}
						}
					}
				}
				if (free <= m) {
					break;
				}
				if (c < C - 1) {
					int i = 0;
					while (i < r && free > m) {
						free -= putZero(i, c, field);
						i++;
						if (free - m == 2 && c < C - 2) {
							free -= putZero(0, c + 1, field);
						}
					}
				}
				if (free - m == 2) {
					if (r < R - 2) {
						free -= putZero(r + 1, 0, field);
					} else {
						free -= putZero(0, c + 1, field);
					}
				} else if (free > m) {
					free -= putZero(r, c, field);
					if (r < R - 1)
						r++;
					if (c < C - 1)
						c++;
				}

			}

			boolean possible = (free == m);

			out.println("Case #" + test + ":");
			if (possible) {
				fillMines(field);
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						out.print(field[i][j]);
					}
					out.println();
				}
			} else {
				out.println("Impossible");
			}
		}
	}
}
