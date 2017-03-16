package round1c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Fashion {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1c/C-small-attempt1.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1c/outputC-small.out");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			String line[] = reader.readLine().split(" ");
			int J = Integer.parseInt(line[0]);
			int P = Integer.parseInt(line[1]);
			int S = Integer.parseInt(line[2]);
			int K = Integer.parseInt(line[3]);
			doExercise(exercise, J, P, S, K);
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static void doExercise(int exercise, int J, int P, int S, int K) throws IOException {
		System.out.println("J:" + J + " P:" + P + " S:" + S + " K:" + K);
		int answer;
		if (S <= K) {
			answer = J*P*S;
		}
		else {
			answer = J*P*K;
		}
		generateOutput("Case #" + exercise + ": " + answer);
		
		int[][] outfits = new int[3][answer];
		int outfit = 0;
		if (S <= K) {
			for (int j = 1; j <= J; j++) {
				for (int p = 1; p <= P; p++) {
					for (int s = 1; s <= S; s++) {
						outfits[0][outfit] = j;
						outfits[1][outfit] = p;
						outfits[2][outfit] = s;
						outfit++;
					}
				}
			}
		}
		else {
			for (int j = 1; j <= J; j++) {
				for (int p = 1; p <= P; p++) {
					for (int k = 1; k <= K; k++) {
						outfits[0][outfit] = j;
						outfits[1][outfit] = p;
						outfits[2][outfit] = k;
						outfit++;
					}
				}
			}
			tryShirts(S, K, outfits, 0);
		}
		print(outfits);
	}

	private static void print(int[][] outfits) throws IOException {
		for (int o = 0; o < outfits[0].length; o++) {
			generateOutput(outfits[0][o] + " " + outfits[1][o] + " " + outfits[2][o]);
		}
	}

	private static boolean tryShirts(int S, int K, int[][] outfits, int i) {
		if (i == outfits[0].length -1) {
			return checkOutfits(outfits, K, S);
		}
		for (int s = 1; s <= S; s++) {
			outfits[2][i] = s;
			if (tryShirts(S, K, outfits, i+1)) {
				return true;
			}
		}
		return false;
	}

	private static boolean checkOutfits(int[][] outfits, int K, int S) {
		boolean[][][] combos = new boolean[S+1][S+1][S+1];
		int[][] combos02 = new int[S+1][S+1];
		int[][] combos12 = new int[S+1][S+1];
		for (int o = 0; o < outfits[0].length; o++) {
			int j = outfits[0][o];
			int p = outfits[1][o];
			int s = outfits[2][o];
			combos02[j][s]++;
			if (combos02[j][s] > K) {
				return false;
			}
			combos12[p][s]++;
			if (combos12[p][s] > K) {
				return false;
			}
			if (combos[j][p][s]) {
				return false;
			}
			combos[j][p][s] = true;
		}
		return true;
	}
}
