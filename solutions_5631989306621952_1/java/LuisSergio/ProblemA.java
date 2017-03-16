import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProblemA {	

	private static BufferedWriter writer;
	private static Scanner scanner;
	
	private static String s;
	
	private static String result;
	
	private static void processCase(int i) throws IOException {
		readInput();
		solve();
		outputResults(i);
	}

	private static void solve() {
		StringBuilder r = new StringBuilder(s.length());
		char[] letters = s.toCharArray();
		for(char c : letters) {
			if (r.length() == 0) {
				r.append(c);
			} else {
				char first = r.charAt(0);
				if (c < first) {
					r.append(c);
				} else {
					r.insert(0, c);
				}
			}
		}
		result  = r.toString();
	}
	
	private static void outputResults(int testCase) throws IOException {
		String out = String.format("Case #%d: %s", testCase + 1, result);
		System.err.println(out);
		writer.write(out);
		writer.newLine();
	}
	

	private static void readInput() {
		s = scanner.nextLine();
	}

	public static void main(String[] args) throws IOException {
		Path input = Paths.get("input.in");
		Path output = Paths.get("output.txt");
		scanner = new Scanner(input);
		writer = Files.newBufferedWriter(output);
		int testCases = scanner.nextInt();
		scanner.nextLine();
		for (int i = 0; i < testCases; i++) {
			processCase(i);
		}
		writer.close();

	}
	

}
