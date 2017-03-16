package round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Lottery {
	private static BufferedWriter writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1B/B-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1B/output-lotterysmall.txt");
		writer = new BufferedWriter(new FileWriter(outputFile));
		
		int numberOfGames = Integer.parseInt(reader.readLine());
		for (int game = 1; game <= numberOfGames; game++) {
			String[] split = reader.readLine().split(" ");
			int A = Integer.parseInt(split[0]);
			int B = Integer.parseInt(split[1]);
			int K = Integer.parseInt(split[2]);
			
			generateOutput("Case #" + game + ": " + determineWinnings(A, B, K));
		}
		reader.close();
		writer.close();
	}

	private static long determineWinnings(int A, int B, int K) {
		long winnings = 0;
		for (int a = 0 ; a < A; a++) {
			for (int b = 0 ; b < B; b++) {
				if ((a&b) < K) {
					winnings++;
				}
			}
		}
		return winnings;
	}

	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
}
