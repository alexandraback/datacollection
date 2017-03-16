package codejam2013.round1c;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class A {

	private static boolean[] vowels = new boolean[26];
	static {
		char[] v = new char[] { 'a', 'e', 'i', 'o', 'u' };
		for (int i = 0; i < v.length; ++i) {
			vowels[v[i] - 'a'] = true;
		}
	}

	public static long nValue(String word, int consonants) {
		long sum = 0;
		int currentCons = 0;
		int prevStart = -1;
		for (int i = 0, n = word.length(); i < n; ++i) {
			if (vowels[word.charAt(i) - 'a']) {
				currentCons = 0;
				continue;
			}

			currentCons++;
			if (currentCons == consonants) {
				int start = i - currentCons + 1;
				long before = start - (prevStart + 1);
				long after = n - (start + consonants);

				long substrings = 0;
				substrings += after;
				substrings += before;
				substrings += before * after;
				substrings++;

				sum += substrings;
				prevStart = start;
				currentCons--;
			}
		}

		return sum;
	}

	public static void solve(String fileName, String outputFileName)
			throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				new FileInputStream(fileName)));
		PrintWriter writer = new PrintWriter(outputFileName);

		int testCases = Integer.parseInt(reader.readLine());
		for (int t = 0; t < testCases; ++t) {
			String[] splits = reader.readLine().split(" ");
			String word = splits[0];
			int n = Integer.parseInt(splits[1]);
			writer.format("Case #%d: %s\n", t + 1, nValue(word, n));
		}

		writer.close();
		reader.close();
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		solve("A-large.in", "a.out");
		// System.out.println(nValue("tsetse", 2));
	}

}
