package codejam2014.round1B;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class ProblemB {

	public static void main(String[] args) {
		String fileName = "B-small-attempt0";
		File folder = new File(new File("files", "codejam2014"), "round1B");
		File inputFile = new File(folder, fileName + ".in");
		File outputFile = new File(folder, fileName + ".out");
		try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
			try (PrintWriter writer = new PrintWriter(new FileWriter(outputFile))) {
				int count = Integer.parseInt(reader.readLine());
				for (int i = 0; i < count; i++) {
					String[] parameters = reader.readLine().split("\\s");
					writer.printf("Case #%d: %s\n", i+1,
							solveIt(Integer.parseInt(parameters[0]),
									Integer.parseInt(parameters[1]),
									Integer.parseInt(parameters[2])));
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("Done.");
	}

	private static String solveIt(int a, int b, int k) {
		long possiblePairs = 0L;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i & j) < k) {
					possiblePairs++;
				}
			}
		}
		return String.valueOf(possiblePairs);
	}
}
