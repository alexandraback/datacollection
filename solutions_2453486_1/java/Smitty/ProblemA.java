import java.io.File;
import java.io.PrintWriter;
import java.util.NavigableSet;
import java.util.Scanner;
import java.util.TreeSet;

public class ProblemA {

	public static void main(String[] args) {

		try {

			final String fileIn = ProblemA.class.getSimpleName().toLowerCase() + ".in";
			final String fileOut = ProblemA.class.getSimpleName().toLowerCase() + ".out";

			final Scanner in = new Scanner(new File(fileIn));
			final PrintWriter out = new PrintWriter(new File(fileOut));

			new ProblemA().solve(in, out);

			out.flush();
			out.close();

		} catch (Exception ex) {

			ex.printStackTrace();
		}
	}

	private final void solve(final Scanner in, final PrintWriter out) throws Exception {

		final int testCount = in.nextInt();

		for (int testCase = 1; testCase <= testCount; ++testCase) {

			final char s[][] = new char[4][];

			s[0] = in.next().toCharArray();
			s[1] = in.next().toCharArray();
			s[2] = in.next().toCharArray();
			s[3] = in.next().toCharArray();

			String result = "";

			if (won(s, "XT")) {

				result = "X won";
			} else if (won(s, "OT")) {

				result = "O won";
			} else {

				boolean notFinished = false;

				for (char line[] : s) {

					for (char ch : line) {

						if (ch == '.') {

							notFinished = true;
						}
					}
				}

				if (notFinished) {

					result = "Game has not completed";
				} else {

					result = "Draw";
				}
			}

			out.printf("Case #%d: %s%n", testCase, result);
		}
	}

	private final boolean won(final char[][] board, final String goodChars) {

		for (int i = 0; i < board.length; ++i) {

			boolean wonRow = true;
			for (int j = 0; j < board[i].length; ++j) {

				if (goodChars.indexOf(board[i][j]) == -1) {

					wonRow = false;
					break;
				}
			}
			if (wonRow) {

				return true;
			}
		}

		for (int i = 0; i < board[0].length; ++i) {

			boolean wonCol = true;
			for (int j = 0; j < board.length; ++j) {

				if (goodChars.indexOf(board[j][i]) == -1) {

					wonCol = false;
					break;
				}
			}
			if (wonCol) {

				return true;
			}
		}

		boolean wonDiagonal = true;

		for (int i = 0; i < board.length; ++i) {

			if (goodChars.indexOf(board[i][i]) == -1) {

				wonDiagonal = false;
				break;
			}
		}

		if (wonDiagonal) {

			return true;
		}

		wonDiagonal = true;

		for (int i = 0; i < board.length; ++i) {

			if (goodChars.indexOf(board[i][board.length - i - 1]) == -1) {

				wonDiagonal = false;
				break;
			}
		}

		if (wonDiagonal) {

			return true;
		}

		return false;
	}
}
