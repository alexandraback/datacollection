package org.soonk.codejam.round1B2013;

import java.util.Scanner;

public class B {

	public void compute() {
		Scanner scanner = new Scanner(System.in);

		int testCases = scanner.nextInt();

		for (int t = 1; t <= testCases; t++) {

			double result = handleTestCase(scanner);

			System.out.format("Case #%d: %f%n", t, result);
		}

		scanner.close();
	}

	private double handleTestCase(Scanner scanner) {
		int diamonds = scanner.nextInt();
		int x = scanner.nextInt();
		int y = scanner.nextInt();

		if ((x + y) % 2 == 1) {
			return 0.0;
		}

		int fullRanks = 0;
		int n = 1;

		int rankSize = (n * 2 - 1) + (n * 2 - 2);

		while (rankSize <= diamonds) {
			// System.out.format("Diamonds=%d, rankSize=%d%n", diamonds,
			// rankSize);
			diamonds -= rankSize;
			fullRanks++;
			n++;
			rankSize = (n * 2 - 1) + (n * 2 - 2);
		}

		//System.out.format("Diamonds=%d, fullRanks=%d%n", diamonds, fullRanks);

		// Check if x,y is within full ranks.
		int fullXY = (fullRanks - 1) * 2;
		if (Math.abs(x) + Math.abs(y) <= fullXY) {
			return 1.0;
		}

		int openXY = fullRanks * 2;
		if (Math.abs(x) > openXY || Math.abs(y) > openXY) {
			return 0.0;
		}

		// Compute probability
		int openRankSize = (fullRanks + 1) * 2 - 1;
		int min = 0;

		// Max diamonds on side is min of total diamonds and open rank size -1
		int max = openRankSize - 1;
		if (diamonds < max) {
			max = diamonds;
		}

		// Min = overflow
		min = diamonds - max;

		// Total open rank diamond configurations. Min have no choice. Rest do,
		// can go either way.
		double choices = Math.pow(2, max - min);

//		System.out
//				.format("Open rank size=%d, yRank=%d, diamonds left=%d, min=%d, max=%d, choices=%f%n",
//						openRankSize, y, diamonds, min, max, choices);

		if (y < min) {
			return 1.0;
		} else if (y == max) {
			return 0.0;
		} else {
			double yChoices = choices;
			int testy = y;
			while (testy >= min) {
				yChoices -= choose(max - min, testy);
				testy--;
			}
			return yChoices / choices;
		}
	}

	private int choose(int n, int k) {
		if (k == 0)
			return 1;
		return (n * choose(n - 1, k - 1)) / k;
	}

	public static void main(String[] args) {
		B b = new B();
		b.compute();
	}
}
