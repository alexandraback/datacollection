import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SafetyInNumbers {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("data/A-large.in"));
		PrintWriter out = new PrintWriter(new File("data/output.txt"));

		Integer count = sc.nextInt();
		System.out.println("Total cases " + count);

		for (int i = 0; i < count; i++) {
			// System.out.println(i);

			// INPUT
			Integer contestantsCount = sc.nextInt();
			List<Integer> judgesScores = new ArrayList<>();
			for (int ii = 0; ii < contestantsCount; ii++) {
				judgesScores.add(sc.nextInt());
			}

			// OUTPUT
			System.out.println("Case #" + (i + 1) + ": " + judgesScores);
			out.print("Case #" + (i + 1) + ":");
			List<Double> scores = calculateAudienceScores(contestantsCount,
					judgesScores);
			System.out.println("\t" + scores);
			for (Double d : scores) {
				out.print(" " + new DecimalFormat("#.######").format(d));
			}
			out.println();
		}

		out.close();
	}

	private static class Contestant {
		private Integer judgeScore;
		private Double pubScore;

		public Contestant(Integer judgeScore) {
			this.judgeScore = judgeScore;
			this.pubScore = 0.0;
		}

		public Double getTotalScore() {
			return pubScore + judgeScore;
		}

		public Double getPubScore() {
			return pubScore;
		}

		public void incrementPubScore(Double val) {
			pubScore += val;
		}

	}

	private static List<Double> calculateAudienceScores(
			Integer contestantsCount, List<Integer> judgesScores) {
		List<Double> result = new ArrayList<>();
		List<Contestant> contestants = new ArrayList<>();

		Integer totalScore = 0;
		for (Integer s : judgesScores) {
			totalScore += s;
			contestants.add(new Contestant(s));
		}

		// allocate scores
		Double increment = (double) (1) / 100;
		for (int i = 1; i <= totalScore * 100; i++) {
			// find lowest
			Contestant minContestant = null;
			for (Contestant c : contestants) {
				if (minContestant == null) {
					minContestant = c;
				} else if (c.getTotalScore() < minContestant.getTotalScore()) {
					minContestant = c;
				}
			}
			minContestant.incrementPubScore(increment);
		}

		// calculate resuts
		for (Contestant c : contestants) {
			result.add(c.getPubScore().doubleValue() / totalScore.doubleValue()
					* 100);
		}
		return result;
	}
}
