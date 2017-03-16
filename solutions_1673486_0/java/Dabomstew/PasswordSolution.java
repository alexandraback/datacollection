import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class PasswordSolution {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String inFilename = "A-small-attempt0.in";
		String outFilename = inFilename.substring(0, inFilename.length() - 3)
				+ ".out";
		try {
			Scanner sc = new Scanner(new File(inFilename));
			PrintStream ps = new PrintStream(new FileOutputStream(outFilename));
			int testCases = Integer.parseInt(sc.nextLine());
			for (int i = 1; i <= testCases; i++) {
				// logic
				if (i >= 1) {
					ps.println();
				}
				String params = sc.nextLine();
				String[] pParts = params.split(" ");
				int a_value = Integer.parseInt(pParts[0]);
				int b_value = Integer.parseInt(pParts[1]);
				double[] probabilities = new double[a_value];
				String probs = sc.nextLine();
				String[] probA = probs.split(" ");
				double multProbs = 1;
				for (int j = 0; j < a_value; j++) {
					probabilities[j] = Double.parseDouble(probA[j]);
					multProbs *= probabilities[j];
				}
				List<Double> expectedTimes = new ArrayList<Double>();
				expectedTimes.add((double) (b_value + 2));
				expectedTimes.add(multProbs * (b_value - a_value + 1)
						+ (1 - multProbs) * (b_value * 2 - a_value + 2));
				// Backspacing
				for (int j = a_value - 1; j >= 0; j--) {
					int times_backspaced = (a_value - j);
					multProbs /= probabilities[j];
					int chars_if_right = (b_value - a_value + times_backspaced)
							+ times_backspaced + 1;
					int chars_if_wrong = chars_if_right + b_value + 1;
					expectedTimes.add(multProbs * chars_if_right
							+ (1 - multProbs) * chars_if_wrong);
				}
				Collections.sort(expectedTimes);
				System.out.println("Case #" + i + ": "
						+ String.format("%.6f", expectedTimes.get(0)));
				ps.print("Case #" + i + ": "
						+ String.format("%.6f", expectedTimes.get(0)));
			}
			sc.close();
			ps.close();
		} catch (Exception ex) {
			ex.printStackTrace();
		}

	}

}
