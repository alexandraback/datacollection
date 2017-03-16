package year2012.DancingWiththeGooglers;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

final class DancingWiththeGooglers {

	/**
	 * @param args
	 * @throws IOException
	 */
	static class Triplet {
		public boolean ableMax = false;
		public boolean ableSurprising = true;
		public boolean beMaxMustSurprise = false;

		Triplet(int totalScore, int maxScore) {
			int mean = totalScore / 3;
			int remainder = totalScore % 3;
			if (totalScore == 29 || totalScore == 30) {
				ableMax = true;
			} 
			else if (totalScore == 0 || totalScore == 1)
			{
				ableSurprising = false;
				if (maxScore <= totalScore)
				{
					ableMax = true;
				}
				else ableMax = false;
			}
			else if (mean >= maxScore) {
				ableMax = true;
			} else if (mean == (maxScore - 1)) {
				if (remainder == 2 || remainder == 1)
					ableMax = true;
				if (remainder == 0)
					beMaxMustSurprise = true;
			} else if (mean == (maxScore - 2)) {
				if (remainder == 2)
					beMaxMustSurprise = true;
			}
		}
	}

	public static void main(String[] args) throws IOException {

		String file = "B-large";
		Scanner sc = new Scanner(new FileReader(file + ".in"));
		PrintWriter pw = new PrintWriter(new FileWriter(file + ".out"));

		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {

			int N = sc.nextInt();
			int S = sc.nextInt(); // surprising
			int p = sc.nextInt();

			int totalBeAlwaysMax = 0;
			int totalBeMaxMustSurprising = 0;
			int totalNotSurpriseAbleMax = 0;

			int result = 0;

			for (int i1 = 0; i1 < N; i1++) {
				Triplet temp = new Triplet(sc.nextInt(), p);
				if (temp.ableMax  && temp.ableSurprising)
					totalBeAlwaysMax++;
				if (temp.beMaxMustSurprise == true)
					totalBeMaxMustSurprising++;
				if (!temp.ableSurprising && temp.ableMax)
				{
					totalNotSurpriseAbleMax++;
				}
				
			}

			if (S <= totalBeMaxMustSurprising) {
				result = totalBeAlwaysMax + S + totalNotSurpriseAbleMax ;
			} else {
				result = totalBeAlwaysMax + totalBeMaxMustSurprising + totalNotSurpriseAbleMax;
			}

			pw.println("Case #" + (i + 1) + ": " + result);
			// pw.println();

		}
		pw.flush();
		pw.close();
		sc.close();
	}
}
