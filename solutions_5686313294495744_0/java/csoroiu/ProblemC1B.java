package cc.sixi.cj2016;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class ProblemC1B {
//	private final static String input = "C-test.in";
//	private final static String output = "C-test.out";

	 private final static String input = "C-small-attempt0.in";
	 private final static String output = "C-small-attempt0.out";

	// private final static String input = "C-large.in";
	// private final static String output = "C-large.out";

	public static void main(String[] args) throws FileNotFoundException {
		BufferedInputStream source = new BufferedInputStream(
				new FileInputStream(input));
		try (Scanner scan = new Scanner(source);
				PrintWriter pw = new PrintWriter(output);) {
			int t = scan.nextInt();
			for (int i = 1; i <= t; i++) {
				int count = scan.nextInt();
				String[][] titles = new String[count][2];
				for (int j = 0; j < count; j++) {
					titles[j][0] = scan.next();
					titles[j][1] = scan.next();
				}
				int result = processTestCase(titles, i);
				pw.printf("Case #%d: %s\n", i, result);
			}
		}
	}

	private static int processTestCase(final String[][] titles, int testNo) {
		int max = 0;
		for (int i = 0; i < 2 << titles.length; i++) {
			String s = pad(Integer.toBinaryString(i), titles.length);
			max = Math.max(max, evaluate2(titles, s));
		}

		return max;
	}

	private static String pad(String binaryString, int len) {
		while (binaryString.length() < len) {
			binaryString = '0' + binaryString;
		}
		return binaryString;
	}

	private static int evaluate2(String[][] titles, String s) {
		HashMap<String, Integer> set1 = new HashMap<>();
		HashMap<String, Integer> set2 = new HashMap<>();
		for (int i = 0; i < titles.length; i++) {
			if (s.charAt(i) == '1') {
				set1.put(titles[i][0], Integer.valueOf(0));
				set2.put(titles[i][1], Integer.valueOf(0));
			}
		}
		int count = 0;
		for (int i = 0; i < titles.length; i++) {
			if (s.charAt(i) == '0') {
				if (set1.containsKey(titles[i][0])
						&& set2.containsKey(titles[i][1])) {
					count++;
				} else {
					return -1;
				}
			}
		}
		return count;
	}

	private static int evaluate(final String[][] titles) {
		HashMap<String, Integer> set1 = new HashMap<>();
		HashMap<String, Integer> set2 = new HashMap<>();
		int result = 0;
		for (int i = 0; i < titles.length; i++) {
			if (set1.containsKey(titles[i][0])
					&& set2
					.containsKey(titles[i][1])) {
				result++;
			}
			set1.put(titles[i][0], Integer.valueOf(0));
			set2.put(titles[i][1], Integer.valueOf(0));
		}
		return result;
	}
}
