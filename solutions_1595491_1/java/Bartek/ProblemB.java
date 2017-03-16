import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {

	public static void main(String[] args) {
		final Scanner in = new Scanner(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		final int t = in.nextInt();

		for (int tt = 0; tt < t; tt++) {
			final int n = in.nextInt();
			final int s = in.nextInt();
			final int p = in.nextInt();

			int surprisesLeft = s;
			int googlersCount = 0;
			for (int nn = 0; nn < n; nn++) {
				final int totalScore = in.nextInt();
				if (canAchieveScoreIfNormal(totalScore, p)) {
					googlersCount++;
				} else if (surprisesLeft > 0 && canAchieveScoreIfSurprising(totalScore, p)) {
					googlersCount++;
					surprisesLeft--;
				}
			}

			out.write("Case #" + (tt + 1) + ": " + googlersCount + "\n");
		}

		out.flush();
	}

	private static boolean canAchieveScoreIfNormal(int totalScore, int score) {
		return totalScore >= (3 * score - 2);
	}

	private static boolean canAchieveScoreIfSurprising(int totalScore, int score) {
		if (score == 1)
			return totalScore >= 1;
		else
			return totalScore >= (3 * score - 4);
	}

}
