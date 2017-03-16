package r0;

import java.util.Scanner;

public class Q3 {
	private static final int[][] valueTable = new int[][] {
			{0, 1, 2, 3, 4, 5, 6, 7},
			{1, 4, 3, 6, 5, 0, 7, 2},
			{2, 7, 4, 1, 6, 3, 0, 5},
			{3, 2, 5, 4, 7, 6, 1, 0},
			{4, 5, 6, 7, 0, 1, 2, 3},
			{5, 0, 7, 2, 1, 4, 3, 6},
			{6, 3, 0, 5, 2, 7, 4, 1},
			{7, 6, 1, 0, 3, 2, 5, 4},
	};
	public static void main(String... args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		int caseCount = in.nextInt();
		int L_MAX = 10000;
		int[] input = new int[L_MAX + 1];
		int L_X_MAX = 10000;
		int[] values = new int[L_X_MAX + 1];
		for (int caseValue = 1; caseValue <= caseCount; caseValue++) {
			int L = in.nextInt();
			int X = in.nextInt();
			char[] inputStr = in.next().toCharArray();
			for (int i = 0; i < L; i++) {
				char c = inputStr[i];
				input[i] = c == 'i' ? 1 :
					(c == 'j' ? 2 : 3);
			}
			for (int x = 0, iTo = 0; x < X; x++) {
				for (int i = 0; i < L; i++) {
					values[iTo++] = input[i];
				}
			}
			String result = got123(values, L * X) ? "YES" : "NO";
			System.out.println("Case #" + caseValue + ": " + result);
		}
	}

	private static boolean got123(int[] values, int LX) {
		final int[][] valueTable = Q3.valueTable;
		int value = 0;
		int at = 0;
		for (;;) {
			if (at == LX) {
				return false;
			}
			int newValue = values[at++];
			value = valueTable[value][newValue];
			if (value == 1) {
				break;
			}
		}
		value = 0;
		for (;;) {
			if (at == LX) {
				return false;
			}
			int newValue = values[at++];
			value = valueTable[value][newValue];
			if (value == 2) {
				break;
			}
		}
		value = 0;
		for (;;) {
			if (at == LX) {
				return value == 3;
			}
			int newValue = values[at++];
			value = valueTable[value][newValue];
		}
	}
}
