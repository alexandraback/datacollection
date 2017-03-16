package solution;

import java.util.Scanner;

public class A {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		int T = scanner.nextInt();
		scanner.nextLine();

		for (int i = 1; i <= T; i++) {

			String[] row = new String[4];
			boolean containsDot = false;
			for (int j = 0; j < 4; j++) {
				row[j] = scanner.nextLine();
				containsDot |= row[j].contains(".");
			}
			scanner.nextLine();

			boolean winnerFound = false;
			for (int j = 0; j < 4; j++) {
				if (winnerFound = winnerFound(row[j], i))
					break;
			}

			if (winnerFound)
				continue;

			for (int j = 0; j < 4; j++) {
				String column = new String(new char[] { row[0].charAt(j),
						row[1].charAt(j), row[2].charAt(j), row[3].charAt(j) });
				if (winnerFound = winnerFound(column, i))
					break;
			}

			if (winnerFound)
				continue;

			String diagonal1 = new String(new char[] { row[0].charAt(0),
					row[1].charAt(1), row[2].charAt(2), row[3].charAt(3) });
			if (winnerFound(diagonal1, i))
				continue;

			String diagonal2 = new String(new char[] { row[0].charAt(3),
					row[1].charAt(2), row[2].charAt(1), row[3].charAt(0) });
			if (winnerFound(diagonal2, i))
				continue;

			if (containsDot) {
				System.out.println("Case #" + i + ": Game has not completed");
			} else {
				System.out.println("Case #" + i + ": Draw");
			}

		}

		scanner.close();

	}

	private static boolean winnerFound(String s, int caseNum) {
		if (s.equals("XXXX") || s.equals("TXXX") || s.equals("XTXX")
				|| s.equals("XXTX") || s.equals("XXXT")) {
			System.out.println("Case #" + caseNum + ": X won");
			return true;
		}

		if (s.equals("OOOO") || s.equals("TOOO") || s.equals("OTOO")
				|| s.equals("OOTO") || s.equals("OOOT")) {
			System.out.println("Case #" + caseNum + ": O won");
			return true;
		}

		return false;
	}

}
