package round0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class CountingSheep {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round0/A-large.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round0/sheep-output.txt");
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
	
	private static String doExercise() throws IOException {
		int N = Integer.parseInt(reader.readLine());
		if (N == 0) {
			return "INSOMNIA";
		}
		boolean[] seenDigits = new boolean[10];
		int multiplier = 0;
		while (atLeastOneFalse(seenDigits)) {
			multiplier++;
			seeDigits(multiplier*N, seenDigits);
		}
		return "" + (multiplier*N);
	}

	private static void seeDigits(int number, boolean[] seenDigits) {
		while(number > 0) {
			seenDigits[number%10] = true;
			number/=10;
		}
	}

	private static boolean atLeastOneFalse(boolean[] seenDigits) {
		for (boolean digit: seenDigits) {
			if (!digit) {
				return true;
			}
		}
		return false;
	}
}
