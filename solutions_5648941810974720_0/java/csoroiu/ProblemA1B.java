package cc.sixi.cj2016;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA1B {
	// private final static String input = "A-test.in";
	// private final static String output = "A-test.out";

	private final static String input = "A-small-attempt1.in";
	private final static String output = "A-small-attempt1.out";

	// private final static String input = "A-large.in";
	// private final static String output = "A-large.out";

	public static void main(String[] args) throws FileNotFoundException {
		BufferedInputStream source = new BufferedInputStream(
				new FileInputStream(input));
		try (Scanner scan = new Scanner(source);
				PrintWriter pw = new PrintWriter(output);) {
			int t = scan.nextInt();
			for (int i = 1; i <= t; i++) {
				String s = scan.next();
				String result = processTestCase(s, i);
				pw.printf("Case #%d: %s\n", i, result);
			}
		}
	}

	final static String digitsS[] = { "ZERO", "TWO", "EIGHT", "FOUR", "SIX",
		"THREE", "ONE", "FIVE", "SEVEN", "NINE" };
	final static int digitsV[] = { 0, 2, 8, 4, 6, 3, 1, 5, 7, 9 };

	// final static String digitsS[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR",
	// "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	// final static int digitsV[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	private static String processTestCase(final String s, int testNo) {
		int freq[] = new int[26];
		int digitsO[] = new int[10];

		for (int i = 0; i < s.length(); i++) {
			freq[s.charAt(i) - 'A']++;
		}
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < 10; i++) {
			int digit = digitsV[i];
			int freqD[] = getFreq(digitsS[i]);
			int count = 0;
			boolean found;
			do {
				found = true;
				for (int j = 0; j < 26; j++) {
					if (freq[j] < freqD[j]) {
						found = false;
					}
				}
				if (found) {
					count++;
					for (int j = 0; j < 26; j++) {
						freq[j] -= freqD[j];
					}
				}
			} while (found);
			digitsO[digit] = count;
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < digitsO[i]; j++) {
				sb.append(i);
			}
		}
		boolean kk = false;
		for (int i = 0; i < freq.length; i++) {
			if (freq[i] != 0) {
				kk = true;
			}
		}
		if (kk) {
			System.err.println(testNo + " kkk " + s + " " + sb.toString());
		}
		return sb.toString();
	}

	private static int[] getFreq(String s) {
		int freq[] = new int[26];
		for (int i = 0; i < s.length(); i++) {
			freq[s.charAt(i) - 'A']++;
		}
		return freq;
	}
}
