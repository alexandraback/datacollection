package round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class CloseMatch {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1/B-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1/B-small-attempt0.out");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			String[] strings = reader.readLine().split(" ");
			generateOutput("Case #" + exercise + ": " + doExercise(strings[0], strings[1]));
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static String doExercise(String c, String j) {
		int max = (int) Math.pow(10, c.length());
		int answerC = 0;
		int answerJ = 0;
		int difference = max;
		
		for (int scoreC = 0; scoreC < max; scoreC++) {
			if (match(c, scoreC)) {
				for (int scoreJ = 0; scoreJ < max; scoreJ++) {
					if (match(j, scoreJ)) {
						if (Math.abs(scoreC - scoreJ) < difference) {
							difference = Math.abs(scoreC - scoreJ);
							answerC = scoreC;
							answerJ = scoreJ;
						}
					}
				}
			}
		}
		return toString(answerC, c.length()) + " " + toString(answerJ, j.length());
	}

	private static boolean match(String c, int scoreC) {
		String tS = toString(scoreC, c.length());
		for (int d = 0; d < c.length(); d++) {
			if (c.charAt(d) != '?') {
				if (c.charAt(d) != tS.charAt(d)) {
					return false;
				}
			}
		}
		return true;
	}

	private static String toString(int scoreC, int length) {
		String answer = "";
		for (int i = 0; i < length; i++) {
			answer = scoreC %10 + answer;
			scoreC/=10;
		}
		return answer;
	}
}
