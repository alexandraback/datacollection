package round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Digits {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1/A-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1/output-A-small.out");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			String S = reader.readLine();
			generateOutput("Case #" + exercise + ": " + doExercise(S));
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static String doExercise(String S) {
		int[] answer = new int[10];
		int[] letters = countLetters(S); 
		answer[0] = subtract(letters, "ZERO", 'Z');
		answer[2] = subtract(letters, "TWO", 'W');
		answer[4] = subtract(letters, "FOUR", 'U');
		answer[8] = subtract(letters, "EIGHT", 'G');
		answer[6] = subtract(letters, "SIX", 'X');
		answer[1] = subtract(letters, "ONE", 'O');
		answer[3] = subtract(letters, "THREE", 'H');
		answer[5] = subtract(letters, "FIVE", 'F');
		answer[7] = subtract(letters, "SEVEN", 'S');
		answer[9] = subtract(letters, "NINE", 'I');
		
		String toReturn = "";
		for (int i = 0; i<10; i++) {
			for (int j = 0; j < answer[i]; j++) {
				toReturn += i;
			}
		}
		return toReturn;
	}

	private static int subtract(int[] letters, String digitName, char uniqueLetter) {
		int count = letters[uniqueLetter - 'A'];
		for (char c: digitName.toCharArray()) {
			letters[c-'A']-= count;
		}
		return count;
	}

	private static int[] countLetters(String S) {
		int[] answer = new int[26];
		for (char letter = 'A'; letter <= 'Z'; letter++) {
			answer[letter - 'A'] = count(S, letter);
		}
		return answer;
	}

	private static int count(String s, char letter) {
		int answer = 0;
		for (char c: s.toCharArray()) {
			if (c == letter) {
				answer++;
			}
		}
		return answer;
	}
}
