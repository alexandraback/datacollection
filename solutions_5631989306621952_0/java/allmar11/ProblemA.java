package round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProblemA {
	
	// Workaround for not being able to pipe a file to stdin in Eclipse.
	private static final String IN_FILE = "text/" + "A-small-attempt0.in";
	
	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE)))) {
			int numCases = in.nextInt();
			for (int i = 0; i < numCases; i++) {
				String word = in.next();
				
				String result = solve(word);
				String resultStr = result;
				
				System.out.println(String.format("Case #%s: %s", i+1, resultStr));
			}
		}
	}

	private static String solve(String word) {
		List<Integer> letters = new ArrayList<>();
		letters.add(word.charAt(0) - 'A');
		
		for (int i = 1; i < word.length(); i++) {
			int nextNum = word.charAt(i) - 'A';
			if (nextNum >= letters.get(0)) {
				letters.add(0, nextNum);
			}
			else {
				letters.add(nextNum);
			}
		}
		
		StringBuilder result = new StringBuilder();
		for (int letter : letters) {
			result.append((char) ('A' + letter));
		}
		
		return result.toString();
	}
}
