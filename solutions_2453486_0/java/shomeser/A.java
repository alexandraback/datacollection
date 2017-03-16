public class A {
	public static final java.util.Scanner in = new java.util.Scanner(System.in);
	public static final java.io.PrintStream out = System.out;

	public static boolean boardFull;

	public static void main(String[] args) {
		final int n = in.nextInt();
		final char[][] test = new char[6][4];

		for (int i = 0; i < n; ++i) {
			boolean resolved = false;
			boardFull = true;

			for (int j = 0; j < 4; ++j) {
				String input = in.next();

				if (resolved) {
					continue;
				} else {
					char[] line = input.toCharArray();

					if (hasWinner(line, i)) {
						resolved = true;
					} else {
						test[0][j] = line[0];
						test[1][j] = line[1];
						test[2][j] = line[2];
						test[3][j] = line[3];

						test[4][j] = line[j];
						test[5][j] = line[3 - j];
					}
				}
			}

			if (!resolved) {
				for (char[] line : test) {
					if (hasWinner(line, i)) {
						resolved = true;
						break;
					}
				}
			}

			if (!resolved) {
				if (boardFull) {
					printDraw(i);
				} else {
					printNotComplete(i);
				}
			}
		}
	}

	private static boolean hasWinner(char[] line, int caseNumber) {
		char first = line[0];
		int i = 0;

		boolean result = true;

		if (first == 'T') {
			first = line[1];

			if (first == '.') {
				boardFull = false;
				result = false;
			}

			i = 2;
		} else if (first != '.') {
			i = 1;
		} else {
			boardFull = false;
			result = false;
		}

		for (; i < 4; ++i) {
			char next = line[i];

			if (next == '.') {
				boardFull = false;
				result = false;
			} else if (next != 'T' && next != first) {
				result = false;
			}
		}

		if (result) {
			out.print("Case #");
			out.print(caseNumber + 1);
			out.print(": ");
			out.print(first);
			out.println(" won");
		}

		return result;
	}

	private static void printNotComplete(int caseNumber) {
		out.print("Case #");
		out.print(caseNumber + 1);
		out.println(": Game has not completed");
	}

	private static void printDraw(int caseNumber) {
		out.print("Case #");
		out.print(caseNumber + 1);
		out.println(": Draw");
	}
}
