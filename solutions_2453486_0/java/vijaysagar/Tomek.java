package in.codejam;

import java.util.Scanner;

public class Tomek {
	public static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);
		in.useDelimiter("\\s+");
		int testCases = readTestCases();
		String[] results = new String[testCases];
		for (int i = 1; i <= testCases; i++) {
			char[][] input = readInput();
			if (hasWon(input, 'X')) {
				results[i - 1] = ("Case #" + i + ": X won");
			} else if (hasWon(input, 'O')) {
				results[i - 1] = ("Case #" + i + ": O won");
			} else if (isContestIncomplete(input)) {
				results[i - 1] = "Case #" + i + ": Game has not completed";
			} else {
				results[i - 1] = ("Case #" + i + ": Draw");
			}
		}
		for (int i = 0; i < testCases; i++)
			System.out.println(results[i]);
		in.close();
	}

	public static int readTestCases() {
		int i = in.nextInt();
		return i;
	}

	public static char[][] readInput() {
		char array[][] = new char[4][4];
		for (int row = 0; row < 4; row++) {
			String s = in.next();
			for (int col = 0; col < 4; col++) {
				array[row][col] = s.charAt(col);
			}
		}
		return array;
	}

	public static boolean isContestIncomplete(char[][] array) {
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				if (array[row][col] == '.')
					return true;
			}
		}
		return false;
	}

	public static boolean hasWon(char[][] array, char contestant) {
		for (int row = 0; row < 4; row++) {
			boolean won = true;
			for (int col = 0; col < 4; col++) {
				if (!isMyCol(array[row][col], contestant))
					won = false;
			}
			if (won)
				return true;
		}
		for (int col = 0; col < 4; col++) {
			boolean won = true;
			for (int row = 0; row < 4; row++) {
				if (!isMyCol(array[row][col], contestant))
					won = false;
			}
			if (won)
				return true;
		}
		if (isMyCol(array[0][0], contestant)
				&& isMyCol(array[1][1], contestant)
				&& isMyCol(array[2][2], contestant)
				&& isMyCol(array[3][3], contestant))
			return true;
		if (isMyCol(array[0][3], contestant)
				&& isMyCol(array[1][2], contestant)
				&& isMyCol(array[2][1], contestant)
				&& isMyCol(array[3][0], contestant))
			return true;
		return false;
	}

	public static boolean isMyCol(char arrayEl, char contestant) {
		return arrayEl == contestant || arrayEl == 'T';
	}

}
