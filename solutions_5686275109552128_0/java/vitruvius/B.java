import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int t = scan.nextInt();
		for (int tc = 1; tc <= t; tc++) {
			int d = scan.nextInt();
			int[] p = new int[d];
			int maxP = 0;
			for (int i = 0; i < d; i++) {
				p[i] = scan.nextInt();
				maxP = Math.max(maxP, p[i]);
			}

			int minTurns = Integer.MAX_VALUE;
			for (int turnsSpentEating = 1; turnsSpentEating <= maxP; turnsSpentEating++) {
				// System.out.println("attempting to spend at most "
				// + turnsSpentEating + " turns eating.");
				int totalSplitsNeeded = 0;
				for (int i = 0; i < d; i++) {
					int splitsNeeded = (int) Math.ceil((double) p[i]
							/ turnsSpentEating) - 1;
					// System.out.println("p[" + i + "] = " + p[i] + ": needs "
					// + splitsNeeded + " splits");
					totalSplitsNeeded += splitsNeeded;
				}

				minTurns = Math.min(minTurns, totalSplitsNeeded
						+ turnsSpentEating);
			}

			System.out.println("Case #" + tc + ": " + minTurns);
		}
		scan.close();

	}
}
