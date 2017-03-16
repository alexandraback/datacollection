package round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class TypewriterMonkey {
	private static Writer writer;
	private static BufferedReader reader;
	private static int max =0;

	public static void main(String[] args) throws IOException {
		File file = new File("round1/B-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1/outputB.txt");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			String[] split = reader.readLine().split(" ");
			int k = Integer.parseInt(split[0]);
			int l = Integer.parseInt(split[1]);
			int s = Integer.parseInt(split[2]);
			char[] keys = reader.readLine().toCharArray();
			char[] target = reader.readLine().toCharArray();

			generateOutput("Case #" + exercise + ": " + doExercise(k,l,s, keys, target));
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static double doExercise(int k, int l, int s, char[] keys, char[] target) {
		max = 0; 
		long N = numberOfMatches("", s, keys, target);
		
		return max - (1.0 * N)/Math.pow(k, s);
	}

	private static long numberOfMatches(String start, int s, char[] keys, char[] target) {
		if (start.length() == s) {
			return matches(start, target);
		}
		else {
			long answer = 0;
			for (char key: keys) {
				answer += numberOfMatches(start + key, s, keys, target);
			}
			return answer;
		}
	}

	private static long matches(String typed, char[] target) {
		int answer = 0;
		for (int c = 0; c < typed.length() - target.length + 1; c++) {
			boolean match = true;
			for (int l = 0; l < target.length; l++) {
				if (target[l] != typed.charAt(l+c)) {
					match = false;
				}
			}
			if (match) {
				answer++;
			}
		}
		if (answer > max) {
			max = answer;
		}
//		System.out.println(typed + ", " + String.copyValueOf(target) + ", " + answer);
		return answer;
		
	}

}
