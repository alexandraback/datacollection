package codejam.sums;

import java.util.Arrays;

public class Sums {

	public String solve(String line) {

		String[] flds = line.split(" ");
		int n = Integer.parseInt(flds[0]);

		int[] numbers = new int[n];
		int totalSum = 0;
		int[] partialSums = new int[n];
		for (int i = 0; i < n; i++) {
			numbers[i] = Integer.parseInt(flds[1 + i]);
			totalSum += numbers[i];
			partialSums[i] = totalSum;
		}

		for (int offset = 0; offset < n; offset++) {
			boolean[][] Q = new boolean[n][totalSum + 1];
			boolean[][] ans = new boolean[totalSum + 1][];
			for (int i = 0; i < n; i++) {
				int partialSum = 0;
				for (int k = 0; k <= i; k++) {
					partialSum += numbers[(k + offset) % n];
				}

				for (int j = 0; j <= totalSum; j++) {
					if (i == 0) {
						if (numbers[(i + offset) % n] == j) {
							Q[i][j] = true;
							ans[j] = new boolean[] { true };
						}
						else {
							ans[j] = new boolean[] { false };
						}
					}
					else if (Q[i - 1][j]) {
						Q[i][j] = true;
						ans[j] = Arrays.copyOf(ans[j], i + 1);
					}
					else if (numbers[(i + offset) % n] == j) {
						Q[i][j] = true;
						ans[j] = new boolean[i + 1];
						ans[j][i] = true;
					}
					else if ((j - numbers[(i + offset) % n] > 0 && Q[i - 1][j - numbers[(i + offset) % n]])) {
						Q[i][j] = true;
						ans[j] = Arrays.copyOf(ans[j - numbers[(i + offset) % n]], i + 1);
						ans[j][i] = true;
					}

					if (Q[i][j] && j == partialSum / 2d) {
						String returnString = "\n";
						int sum = 0;
						for (int k = 0; k < ans[j].length; k++) {
							if (ans[j][k]) {
								sum += numbers[(k + offset) % n];
								returnString += numbers[(k + offset) % n] + " ";
							}
						}
						returnString += "\n";
						for (int k = 0; k < ans[j].length; k++) {
							if (!ans[j][k]) {
								sum -= numbers[(k + offset) % n];
								returnString += numbers[(k + offset) % n] + " ";
							}
						}
						System.out.println(offset);
						return returnString;
					}
				}
			}
		}

		return "\nImpossible";
	}
}
