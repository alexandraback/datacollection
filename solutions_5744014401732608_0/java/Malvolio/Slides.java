package round1c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Slides {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1c/B-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1c/outputB-small.out");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			String[] strings = reader.readLine().split(" ");
			int B = Integer.parseInt(strings[0]);
			long M = Long.parseLong(strings[1]);
			
			generateOutput("Case #" + exercise + ": " + doExercise(B,M));
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static String doExercise(int B, long M) {
		boolean[][] slides = new boolean[B][B];
		long[] ways = new long[B]; 
		ways[B-1] = 1;
		boolean possible = computeSlides(B, M, slides, ways, B-1, B-2);
		
		if (possible) {
			StringBuilder answer = new StringBuilder("POSSIBLE");
			for (int start = 0; start < B; start++) {
				answer.append('\n');
				for (int end = 0; end < B; end++) {
					if (slides[end][start]) {
						answer.append('1');
					}
					else {
						answer.append('0');
					}
				}
			}
			
			return answer.toString();
		}
		else {
			return "IMPOSSIBLE";
		}
	}

	private static boolean computeSlides(int B, long M, boolean[][] slides, long[] ways, int start, int end) {
		if (end == -1) {
			if (ways[0] == M) {
				return true;
			}
			return false;
		}
		if (start == end) {
			ways[end] = 0;
			for (int via = end + 1; via < B; via++) {
				if (slides[via][end]) {
					ways[end] += ways[via];
				}
			}
			return computeSlides(B, M, slides, ways, B-1, end-1);
		}
		slides[start][end] = false;
		boolean answer = computeSlides(B, M, slides, ways, start-1, end);
		if (!answer) {
			slides[start][end] = true;
			answer = computeSlides(B, M, slides, ways, start-1, end);
		}
		return answer;
	}
}
