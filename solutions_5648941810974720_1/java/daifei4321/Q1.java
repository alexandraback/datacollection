package r1B;

import java.util.Arrays;
import java.util.Scanner;

public class Q1 {
	public static void main(String... args) {
		try (Scanner in = new Scanner(System.in)) {
			int T = in.nextInt();
			for (int caseI = 0; caseI < T; caseI++) {
				char[] str = in.next().toCharArray();
				int[] counts = new int[255];
				for (char c : str) {
					counts[c]++;
				}
				int[] valCounts = new int[10];
				valCounts[0] = counts['Z'];
				valCounts[2] = counts['W'];
				valCounts[4] = counts['U'];
				valCounts[6] = counts['X'];
				valCounts[8] = counts['G'];
				valCounts[3] = counts['H'] - valCounts[8];
				valCounts[5] = counts['F'] - valCounts[4];
				valCounts[7] = counts['S'] - valCounts[6];
				valCounts[9] = counts['I'] - valCounts[6] - valCounts[5] - valCounts[8];
				valCounts[1] = counts['N'] - valCounts[7] - valCounts[9] - valCounts[9];
				StringBuilder result = new StringBuilder();
				for (int i = 0; i <= 9; i++) {
					for (int j = 0; j < valCounts[i]; j++) {
						result.append(Integer.toString(i));
					}
				}
				System.out.println("Case #" + (caseI + 1) + ": " + result);
			}
		}
	}
}
