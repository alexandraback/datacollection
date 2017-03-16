import java.util.Scanner;

public class ProbA extends CodeJamProblem {
	@Override
	protected Object run(Scanner scan) {
		int numTyped = scan.nextInt();
		int numTotal = scan.nextInt();
		double[] expected = new double[numTyped + 1];
		double probPerfect = 1;
		for (int i = 0; i <= numTyped; i++) {
			expected[i] = ((numTyped - i) * 2 + numTotal - numTyped + 1)
					+ (1 - probPerfect) * (numTotal + 1);
			if (i < numTyped)
				probPerfect *= scan.nextDouble();
		}
		double res = 2 + numTotal;
		for (int i = 0; i <= numTyped; i++)
			res = Math.min(res, expected[i]);
		return res;
	}
}
