package y2012.round1a.a;

import java.util.Scanner;

public class APasswordProblem {

	//no sweat so far.
	//but what about the large dataset?
	//A and B are much larger.

	//but our greedy algorithm can handle it.
	//it'll loop 100,000 times per question, for 20 questions.
	//that's nothing. Let's try it!

	public static void main(final String[] args) {
		new APasswordProblem().start();
	}

	private void start() {
		final Scanner s = new Scanner(System.in);
		final int numTests = s.nextInt();
		for (int i = 0; i < numTests; i++) {
			final int charsTyped = s.nextInt();
			final int totalChars = s.nextInt();
			final double[] probs = new double[charsTyped];
			for (int j = 0; j < charsTyped; j++) {
				probs[j] = s.nextDouble();
			}
			double bestStrategySoFar = 1 + totalChars + 1;
			deb("enter cost: " + bestStrategySoFar);

			//backspacing:
			//note: we never backspace everything, hitting enter is cheaper.
			//so there's no case where numCharsNotBackspaced = 0;;
			double oddsAllCorrect = 1;
			for (int c = 0; c < charsTyped; c++) { //c is the "numCharsNotBackspaced - 1"
				oddsAllCorrect *= probs[c];
				final double backspaceCost = expectedCostOfBackspacing(c+1, charsTyped, totalChars, oddsAllCorrect);
				if (backspaceCost < bestStrategySoFar) {
					bestStrategySoFar = backspaceCost;
				}
			}
			System.out.println("Case #" + (i+1) + ": " + bestStrategySoFar);
		}
	}

	private double expectedCostOfBackspacing(final int charsNotBackspaced, final int charsTyped, final int totalChars, final double oddsAllCorrect) {
		final int numBackspaces = charsTyped - charsNotBackspaced;
		deb("backspace " + numBackspaces);
		deb("Odds all are correct: " + oddsAllCorrect);
		//type the remaining characters and hit enter.
		final double costIfCorrect = (totalChars - charsNotBackspaced + numBackspaces) + 1; //+1 for hitting enter.
		deb("cost to keep typing if all are correct: " + costIfCorrect);
		//if we were wrong, we do all that, then type it all over again and hit enter again.
		final double costIfIncorrect = costIfCorrect + totalChars + 1;
		deb("cost to keep typing if all are incorrect: " + costIfIncorrect);
		final double cost = (oddsAllCorrect * costIfCorrect)
		+ ((1 - oddsAllCorrect) * costIfIncorrect);
		deb("expected cost: " + cost);
		return cost;
	}

	private static void deb(final Object o) {
		if ("503".equals("NewNorthRoad")) {
			System.out.println(o.toString());
		}
	}
}
