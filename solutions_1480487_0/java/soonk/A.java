package codejam.round1B2012;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class A {

	public String compute(int players, int[] scores) {

		double judgePoints = 0;
		for (int s : scores) {
			judgePoints += s;
		}

		double aPoints = judgePoints;

		double targetScore = (judgePoints + aPoints) / players;

		// System.out.println("TargetScore: " + targetScore);
		boolean reduced = false;

		do {
			reduced = false;
			for (int i = 0; i < scores.length; i++) {
				if (scores[i] >= targetScore) {
					players--;
					judgePoints -= scores[i];
					scores[i] = -1;
					reduced = true;
				}
			}

			if (reduced) {
				targetScore = (judgePoints + aPoints) / players;
			}

		} while (reduced);

		// System.out.println("TargetScore: " + targetScore);
		// System.out.println("Aponts: " + aPoints);

		StringBuilder sb = new StringBuilder();
		for (int s : scores) {

			// System.out.println("score " + s);
			double pctNeeded = 0.0;

			if (s >= 0) {

				pctNeeded = (targetScore - s) / aPoints;
				pctNeeded *= 100;
				if (pctNeeded < 0) {
					pctNeeded = 0.0;
				}
			}
			sb.append(pctNeeded);
			sb.append(" ");
		}

		return sb.toString();
	}

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));

		String line = in.readLine();
		int testCases = Integer.parseInt(line);

		A a = new A();

		// Read in all test cases
		for (int testCase = 1; testCase <= testCases; testCase++) {
			line = in.readLine();
			String[] data = line.split(" ");

			int players = Integer.parseInt(data[0]);
			int[] scores = new int[data.length - 1];
			for (int i = 1; i < data.length; i++) {
				scores[i - 1] = Integer.parseInt(data[i]);
			}

			out.println("Case #" + testCase + ": " + a.compute(players, scores));
		}

		out.flush();
	}

}
