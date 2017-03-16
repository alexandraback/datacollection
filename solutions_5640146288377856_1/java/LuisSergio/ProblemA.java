import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class ProblemA {	

	private static BufferedWriter writer;
	private static Scanner scanner;
	

private static long r, c, w, score;

	private static void processCase(int i) throws IOException {
		readInput();
		solve();
		outputResults(i);
	}

	private static void outputResults(int testCase) throws IOException {
		String out = String.format("Case #%d: %d", testCase + 1, score);
		System.err.println(out);
		writer.write(out);
		writer.newLine();
	}

	private static void solve() {
		long shipsPerRow = c/w;
		long minScore = 0;
	    for(long i = 0; i < r - 1; i++) {
	    	minScore += shipsPerRow;
	    }
	    long uncovered = c;
	    while (uncovered > w) {
	    	uncovered -= w;
	    	minScore++;
	    }
	    if (uncovered == w) {
	    	minScore += w;
	    } else {
		    minScore++;
		    minScore += (w-1);	    	
	    }
	    score = minScore;
	}

	private static void readInput() {
		r = scanner.nextLong();
		c = scanner.nextLong();
		w = scanner.nextLong();
	}

	public static void main(String[] args) throws IOException {
		Path input = Paths.get("input.in");
		Path output = Paths.get("output.txt");
		scanner = new Scanner(input);
		writer = Files.newBufferedWriter(output);
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			processCase(i);
		}
		writer.close();

	}

}
