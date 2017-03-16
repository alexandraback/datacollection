import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class Problem {

	int num;

	boolean[] blankRow = new boolean[4];
	boolean[] blankColumn = new boolean[4];
	int[][] field = new int[4][4];

	Problem(String file) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File("./"
				+ file + ".in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("./"
				+ file + ".out"), false));

		try {
			num = Integer.parseInt(reader.readLine());

			for (int n = 1; n <= num; ++n) {
				for (int i = 0; i < 4; ++i) {
					blankRow[i] = blankColumn[i] = false;
				}

				boolean blank = false;

				for (int i = 0; i < 4; ++i) {
					String cols = reader.readLine();
					for (int j = 0; j < 4; ++j) {
						switch (cols.charAt(j)) {
						case '.':
							field[i][j] = 0;
							blankRow[i] = true;
							blankColumn[j] = true;
							blank = true;
							break;
						case 'X':
							field[i][j] = 1;
							break;
						case 'O':
							field[i][j] = 2;
							break;
						case 'T':
							field[i][j] = 3;
							break;
						}
					}
				}

				boolean win1 = check(1);
				boolean win2 = check(2);

				if (win1) {
					if (win2) {
						writer.write("Case #" + n + ": Draw");
					} else {
						writer.write("Case #" + n + ": X won");
					}
				} else {
					if (win2) {
						writer.write("Case #" + n + ": O won");
					} else {
						if (blank) {
							writer.write("Case #" + n
									+ ": Game has not completed");
						} else {
							writer.write("Case #" + n + ": Draw");
						}
					}
				}
				writer.newLine();

				reader.readLine();

			}
		} finally {
			writer.close();
			reader.close();
		}
	}

	boolean check(int p) {
		boolean winner = false;

		for (int i = 0; i < 4 && !winner; ++i) {
			if (!blankColumn[i])
				winner = checkColumn(i, p);
		}
		if (winner) {
			return true;
		}

		for (int i = 0; i < 4 && !winner; ++i) {
			if (!blankRow[i])
				winner = checkRow(i, p);
		}
		if (winner) {
			return true;
		}

		winner = checkDiag1(p);
		if (winner) {
			return true;
		}

		winner = checkDiag2(p);
		if (winner) {
			return true;
		}

		return false;
	}

	boolean checkRow(int i, int p) {
		for (int j = 0; j < 4; ++j) {
			if ((field[i][j] & p) != p) {
				return false;
			}
		}
		return true;
	}

	boolean checkColumn(int i, int p) {
		for (int j = 0; j < 4; ++j) {
			if ((field[j][i] & p) != p) {
				return false;
			}
		}
		return true;
	}

	boolean checkDiag1(int p) {
		for (int j = 0; j < 4; ++j) {
			if ((field[j][j] & p) != p) {
				return false;
			}
		}
		return true;
	}

	boolean checkDiag2(int p) {
		for (int j = 0; j < 4; ++j) {
			if ((field[3 - j][j] & p) != p) {
				return false;
			}
		}
		return true;
	}

	/**
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception {
		new Problem("small");
	}

}
