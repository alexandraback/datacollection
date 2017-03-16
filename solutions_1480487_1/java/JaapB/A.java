import java.util.Arrays;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;

public class A {
	static {
		Locale.setDefault(Locale.US);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			System.out.println("Case #" + caseNr + ":" + solveCase(scanner));
		}
	}

	// String
	static String solveCase(Scanner scanner) {
		int contestantsN = scanner.nextInt();
		int[] scoresS = new int[contestantsN];
		for (int i = 0; i < contestantsN; i++)
			scoresS[i] = scanner.nextInt();
		long total = 0;
		for (int score : scoresS)
			total += score;
		int[] sortedScores = Arrays.copyOf(scoresS, contestantsN);
		Arrays.sort(sortedScores);
		int worstScore = sortedScores[0];
		int worstIndex = indexOf(scoresS, worstScore, 0);
		int sndWorstScore = sortedScores[1];
		int sndWorstIndex = worstScore == sndWorstScore ? indexOf(scoresS, sndWorstScore,
				worstIndex) : indexOf(scoresS, sndWorstScore, 0);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < scoresS.length; i++) {
			sb.append(" ");
			HashSet<Integer> skipSet = new HashSet<Integer>();
			boolean added;
			double y;
			do {
				added = false;
				long newTotal = total;
				for (Integer skipped : skipSet)
					newTotal -= scoresS[skipped];
				int newContestants = contestantsN - skipSet.size();
				int score = scoresS[i];
				y = ((double) newTotal + total - score * newContestants) / (newContestants * total);
				if (y < 0)
					y = 0;
				double myNewScore = score + (y * total);
				for (int j = 0; j < scoresS.length; j++)
					if (!skipSet.contains(j)) {
						if (scoresS[j] > myNewScore) {
							skipSet.add(j);
							added = true;
						}
					}
			} while (added);
			sb.append(y * 100.0);
		}
		return sb.toString();
	}

	private static int indexOf(int[] scoresS, int needle, int start) {
		for (int i = start; i < scoresS.length; i++) {
			int j = scoresS[i];
			if (j == needle)
				return i;
		}
		return -1;
	}
}
