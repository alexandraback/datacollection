package cc.sixi.cj2016;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class ProblemC1B {
	// private final static String input = "C-test.in";
	// private final static String output = "C-test.out";

//	 private final static String input = "C-small-attempt0.in.1";
//	 private final static String output = "C-small-attempt0.out.1";
//
	private final static String input = "C-large.in";
	private final static String output = "C-large.out";

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

	public static Set<String> count(List<String[]> titles, int idx, int skip) {
		Set<String> set1 = new TreeSet<>();
		for (int i = 0; i < titles.size(); i++) {
			if (i == skip) {
				continue;
			}
			set1.add(titles.get(i)[idx]);
		}
		return set1;
	}

	private static int processTestCase(final String[][] rrr, int testNo) {
		int max = 0;

		for (int qqq = 0; qqq < 50; qqq++) {
			List<String[]> titles = new ArrayList<>(Arrays.asList(rrr));
			Collections.shuffle(titles);
			Set<String> set1Initial = count(titles, 0, -1);
			Set<String> set2Initial = count(titles, 1, -1);

			int count = 0;
			boolean changed;
			do {
				changed = false;
				int i = 0;
				while (i < titles.size()) {
					Set<String> set1 = count(titles, 0, i);
					if (set1.equals(set1Initial)) {
						Set<String> set2 = count(titles, 1, i);
						if (set2.equals(set2Initial)) {
							changed = true;
							count++;
							titles.remove(i);
							continue;
						}
					}
					i++;
				}
			} while (changed);
			max = Math.max(count, max);
		}
		return max;
	}
}
