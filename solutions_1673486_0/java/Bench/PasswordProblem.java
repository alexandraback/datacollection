import java.io.*;
import java.util.*;

public class PasswordProblem {
	public static void main(String[] args) {
		try {
			FileWriter output = new FileWriter(new File("output.txt"));
			Scanner s = new Scanner(new File("input.txt"));
			int trials = s.nextInt();
			s.nextLine();
			for (int i = 0; i < trials; i++) {
				int charsTyped = s.nextInt();
				int charsTotal = s.nextInt();
				double totalProbCorrect = 1;
				double minCount = Double.MAX_VALUE;
				for (int b = 0; b < charsTyped; b++) {
					double newD = s.nextDouble();
					double predictedForBackspace = (2 * (charsTyped - b))
							+ (charsTotal - charsTyped) + 1
							+ ((1 - totalProbCorrect) * (1 + charsTotal));
					minCount = Math.min(predictedForBackspace, minCount);
					totalProbCorrect *= newD;
				}
				double base = Math.min(doubleEnter(charsTotal),
						keepTyping(charsTotal, charsTyped, totalProbCorrect));
				output.write("Case #" + (i + 1) + ": "
						+ Math.min(base, minCount));
				output.write('\n');
			}
			s.close();
			output.close();
			System.out.println("Done");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static double doubleEnter(int wordLength) {
		return wordLength + 2;
	}

	public static double keepTyping(int wordLength, int charactersSoFar,
			double probabilityCorrect) {
		double ifNotCorrect = (wordLength - charactersSoFar) + wordLength + 2;
		double ifCorrect = wordLength - charactersSoFar + 1;
		return (ifCorrect * probabilityCorrect)
				+ (ifNotCorrect * (1 - probabilityCorrect));
	}
}
