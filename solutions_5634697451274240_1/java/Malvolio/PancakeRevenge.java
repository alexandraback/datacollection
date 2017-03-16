package round0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class PancakeRevenge {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round0/B-large.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round0/revenge-output.txt");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			generateOutput("Case #" + exercise + ": " + doExercise());
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static int doExercise() throws IOException {
		String pancakes = reader.readLine();
		int swaps = 0;
		for (int p = 1; p < pancakes.length(); p++) {
			if (pancakes.charAt(p-1) != pancakes.charAt(p)) {
				swaps++;
			}
		}
		if (pancakes.charAt(pancakes.length() - 1) == '-') {
			swaps++;
		}
		return swaps;
	}

}
