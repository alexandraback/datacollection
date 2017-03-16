package codejam.dancingwiththegooglers;

public class DancingScores {

	private int[] scoreSums;
	private int numberSuprisingScores;
	private int threshold;

	public DancingScores(String inputLine) {
		String[] split = inputLine.split(" ");
		int length = Integer.parseInt(split[0]);
		scoreSums = new int[length];
		numberSuprisingScores = Integer.parseInt(split[1]);
		threshold = Integer.parseInt(split[2]);
		for (int i = 0; i < scoreSums.length; i++) {
			scoreSums[i] = Integer.parseInt(split[i + 3]);
		}
	}

	public int maxNumberScoresAboveThreshold() {
		if (threshold == 0) {
			return scoreSums.length;
		}
		if (threshold == 1) {
			return numberScoresAtLeastOne();
		}

		int googlersAbove = 0;
		int couldBeSurprising = 0;
		int alwaysUnderSum = 3 * threshold - 4;
		int alwaysAboveSum = 3 * threshold - 3;
		for (int i = 0; i < scoreSums.length; i++) {
			if (scoreSums[i] > alwaysAboveSum) {
				googlersAbove++;
			} else if (scoreSums[i] >= alwaysUnderSum) {
				couldBeSurprising++;
			}
		}
		return googlersAbove
				+ Math.min(numberSuprisingScores, couldBeSurprising);
	}

	private int numberScoresAtLeastOne() {
		int result = 0;
		for (int i = 0; i < scoreSums.length; i++) {
			if (scoreSums[i] >= 1) {
				result++;
			}
		}
		return result;
	}

}
