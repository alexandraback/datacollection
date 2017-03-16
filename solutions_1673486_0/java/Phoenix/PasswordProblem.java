import java.util.Scanner;


public class PasswordProblem {
	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		int numCases = s.nextInt();
		for (int c = 0; c < numCases; c++) {
			s.nextLine();
			int numTyped = s.nextInt();
			int passLength = s.nextInt();
			s.nextLine();
			//probability of correctly typed letter
			double[] probabilities = new double[numTyped];
			for (int i = 0; i < numTyped; i++) {
				probabilities[i] = s.nextDouble();
			}
			// Press enter right away
			double bestResult = 1 + passLength + 1;
			//System.out.println("DEBUG: best " + bestResult);
			double pCorrect = 0;
			for (int backspaces = numTyped; backspaces >= 0; backspaces--) {
				// Initially pcorrect = 0, then the sum of first i probabilities
				if (backspaces == numTyped -1) {
					pCorrect = probabilities[numTyped-backspaces-1]; //==probabilities[0]
				} else if (backspaces < numTyped) {
					pCorrect *= probabilities[numTyped-backspaces-1];
				}
				int toType = passLength - numTyped + 1 + backspaces * 2;
				int toTypeIncorrect = toType + passLength + 1;
				if (backspaces == numTyped) {
					toTypeIncorrect = toType;
				}
				double expected = pCorrect * toType + //Correct
						(1-pCorrect) * toTypeIncorrect; //incorrect
				//System.out.println("DEBUG: expected " + expected);
				bestResult = Math.min(bestResult, expected);
			}
			System.out.println("Case #" + (c+1) + ": " + bestResult);
		}
	}

}
