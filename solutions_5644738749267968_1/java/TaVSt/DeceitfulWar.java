import java.io.BufferedReader;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.FileWriter;

import java.util.*;

class DeceitfulWar {
	private static final String PROB_NAME = "deceitfulwar";

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(PROB_NAME + ".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter(PROB_NAME + ".out"));

		int numTestCases = Integer.parseInt(in.readLine());
		for (int caseNumber = 1; caseNumber <= numTestCases; caseNumber++) {
			out.write("Case #" + caseNumber + ": ");

			// SOLUTION HERE
			int numBlocks = Integer.parseInt(in.readLine());
			double[] naomiBlocks = new double[numBlocks], kenBlocks = new double[numBlocks];
			String[] line = in.readLine().split(" ");
			for (int i = 0; i < numBlocks; i++) {
				naomiBlocks[i] = Double.parseDouble(line[i]);
			}
			Arrays.sort(naomiBlocks);
			line = in.readLine().split(" ");
			for (int i = 0; i < numBlocks; i++) {
				kenBlocks[i] = Double.parseDouble(line[i]);
			}
			Arrays.sort(kenBlocks);

			int normalWar = 0;
			for (int i = 0; i < numBlocks; i++) {
				if (i + normalWar >= numBlocks) break;
				if (naomiBlocks[i] > kenBlocks[i + normalWar]) {
					i--;
					normalWar++;
				}
			}

			int deceitfulwar = 0;
			int burned = 0;
			while (burned != numBlocks) {
				if (naomiBlocks[burned] > kenBlocks[deceitfulwar]) {
					deceitfulwar++;
				}
				burned++;
			}

			out.write(deceitfulwar + " " + normalWar);

			out.write('\n');
		}

		out.close();
	}
}