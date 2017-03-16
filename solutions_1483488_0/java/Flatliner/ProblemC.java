package codejam.round1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class ProblemC {
	public static void main(String[] args) throws Exception {
		BufferedReader bufferedReader = new BufferedReader(new FileReader(args[0]));
		PrintStream out = new PrintStream(args[1]);

		int testsCount = Integer.parseInt(bufferedReader.readLine());
		for (int test = 1; test <= testsCount; test++) {
			String testString = bufferedReader.readLine();
			StringTokenizer tokenizer = new StringTokenizer(testString);
			int A = Integer.parseInt(tokenizer.nextToken());
			int B = Integer.parseInt(tokenizer.nextToken());

			int recycledCounts = 0;
			for (int i = A; i <= B; i++) {
				String n = Integer.toString(i);
				int digitsCount = n.length();
				int currentDigitIndex = 1;
				Set<Integer> mSet = new HashSet<Integer>();
				while (currentDigitIndex < digitsCount) {
					int currentDigit = Integer.parseInt("" + n.charAt(currentDigitIndex));
					int possibleM = Integer.parseInt(n.substring(currentDigitIndex) + n.substring(0, currentDigitIndex));
					if (currentDigit != 0 && !mSet.contains(possibleM) && possibleM <= B && i < possibleM) {
						mSet.add(possibleM);
						recycledCounts++;
					}
					currentDigitIndex++;
				}
			}
			out.println(String.format("Case #%s: %s", test, recycledCounts));
		}

		out.close();
		bufferedReader.close();

	}

}
