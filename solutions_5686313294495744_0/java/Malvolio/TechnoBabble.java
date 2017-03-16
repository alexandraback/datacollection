package round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class TechnoBabble {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1/C-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1/C-small-attempt0.out");
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
		int numberOfSignups = Integer.parseInt(reader.readLine());
		Set<String> firstWords = new HashSet<>();
		Set<String> secondWords = new HashSet<>();
		List<Edge> edges = new ArrayList<>();
		for (int i = 0; i < numberOfSignups; i++) {
			String[] words = reader.readLine().split(" ");
			firstWords.add(words[0]);
			secondWords.add(words[1]);
			edges.add(new Edge(words[0], words[1]));
		}
		
		return numberOfSignups - minimalEdgeCover(firstWords, secondWords, edges, 0);
	}

	private static int minimalEdgeCover(Set<String> firstWords, Set<String> secondWords, List<Edge> edges, int start) {
		if (start == edges.size()) {
			if (isCovered(firstWords, edges, 1) && isCovered(secondWords, edges, 2)) {
				return numberOfEdgesInCover(edges);
			}
			else {
				return edges.size();
			}
		}
		Edge edge = edges.get(start);
		edge.inCover = true;
		int minimum1 = minimalEdgeCover(firstWords, secondWords, edges, start+1);
		edge.inCover = false;
		int minimum2 = minimalEdgeCover(firstWords, secondWords, edges, start+1);
		
		return minimum1 < minimum2 ? minimum1 : minimum2;
	}

	private static int numberOfEdgesInCover(List<Edge> edges) {
		int answer = 0;
		for (Edge e : edges) {
			if (e.inCover) {
				answer++;
			}
		}
		return answer;
	}

	private static boolean isCovered(Set<String> firstWords, List<Edge> edges, int vertice) {
		for (String word: firstWords) {
			if (!isCovered(word, edges, vertice)) {
				return false;
			}
		}
		return true;
	}

	private static boolean isCovered(String word, List<Edge> edges, int vertice) {
		for (Edge e: edges) {
			if (e.inCover && e.getWord(vertice).equals(word)) {
				return true;
			}
		}
		return false;
	}
	
	private static class Edge {
		String firstWord;
		String secondWord;
		boolean inCover = false;
		
		Edge(String first, String second) {
			firstWord = first;
			secondWord = second;
		}
		
		String getWord(int i) {
			return i == 1 ? firstWord: secondWord;
		}
	}
}
