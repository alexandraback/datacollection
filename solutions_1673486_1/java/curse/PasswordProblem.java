import java.io.*;
import java.util.*;

public class PasswordProblem {
	public static void main(String[] args) {
		try {
			BufferedReader ifStream = new BufferedReader(new FileReader("in"));
			PrintWriter ofStream = new PrintWriter(new FileWriter("out"));
			int numCases = Integer.parseInt(ifStream.readLine());

			for (int i=1; i<=numCases; i++) {
				String line1 = ifStream.readLine();
				String line2 = ifStream.readLine();
				ofStream.println("Case #"+i+": "+computeAns(line1, line2));
			}

			ifStream.close();
			ofStream.close();
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
	}

	private static double computeAns(String line1, String line2) {
		StringTokenizer st1 = new StringTokenizer(line1, " ", false);
		StringTokenizer st2 = new StringTokenizer(line2, " ", false);
		int numTyped = Integer.parseInt(st1.nextToken());
		int numKey = Integer.parseInt(st1.nextToken());
		double[] prob = new double[numTyped];
		double minExp = numKey + 2;
		double curExp = 0.0;

		for (int i=0; i<numTyped; i++) {
			prob[i] = Double.parseDouble(st2.nextToken());
		}

		for (int numBack=0; numBack<=numTyped; numBack++) {
			curExp = computeExp(numTyped, numBack, numKey, prob);
			if (curExp < minExp) {
				minExp = curExp;
			}
		}

		return minExp;
	}

	private static double computeExp(int numTyped, int numBack, int numKey,
									double[] prob) {
		double suProb = 1.0;
		double faProb = 1;
		int suStr = numBack + (numKey - (numTyped-numBack)) + 1;
		int faStr = numBack + (numKey - (numTyped-numBack)) + 1 + numKey + 1;

		for (int i=0; i<numTyped-numBack; i++) {
			suProb *= prob[i];
		}
		faProb = 1.0 - suProb;

		return suStr*suProb + faStr*faProb;
	}
}
