package round_1C;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {
	public static void main(String[] args) throws FileNotFoundException {

		boolean[] consonants = { false, true, true, true, false, true, true, true, false, true, true, true, true, true,
				false, true, true, true, true, true, false, true, true, true, true, true };

		InputReader scanner = new InputReader(new FileInputStream("a.in"));

		int t = scanner.nextInt();
		int caseIndex = 1;

		while (t-- > 0) {

			String word = scanner.next();
			int n = scanner.nextInt();

			int consonantsCount = 0;
			long lastCalc = 0;
			long result = 0;

			for (int i = 0; i < word.length(); i++) {

				if (consonants[word.charAt(i) - 'a']) {
					consonantsCount++;
					if (consonantsCount >= n) {
						result += (i - n + 2 - lastCalc) * (word.length() - i);
						lastCalc = i - n + 2;
					}
				} else {
					consonantsCount = 0;
				}
			}

			System.out.println("Case #" + caseIndex + ": " + result);
			
			caseIndex++;

		}

	}

	private static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					String line = reader.readLine();
					if (line == null) {
						return null;
					}
					tokenizer = new StringTokenizer(line);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}

}
