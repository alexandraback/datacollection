package y2013.round1C.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProblemA {

	public static void main(final String[] args) throws FileNotFoundException {
		new ProblemA().start();
	}

	private void start() throws FileNotFoundException {
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');
		final Scanner s = new Scanner(new File("src/y2013/round1C/a/A-small-attempt0.in"));
		final int numTests = s.nextInt();
		for (int i = 0; i < numTests; i++) {
			final String name = s.next();
			final int n = s.nextInt();
			final int answer = solve(name, n);
			System.out.println("Case #" + (i + 1) + ": " + answer);
		}
	}

	// small data set: easy
	// large: Strings are up to 1000 000
	// only 100 strings though.
	// any single pass algorithm should work.

	private int solve(final String name, final int n) {
		int score = 0;
		for (int start = 0; start < name.length(); start++) {
			for (int end = start + n; end <= name.length(); end++) {
				final String subString = name.substring(start, end);
				if (hasNConsecutiveConts(subString, n)) {
					score++;
				}
			}
		}
		return score;
	}

	Set<Character> vowels = new HashSet<Character>();

	private boolean hasNConsecutiveConts(final String subString, final int n) {
		int constsInARow = 0;
		for (final char c : subString.toCharArray()) {
			if (vowels.contains(c)) {
				constsInARow = 0;
			} else {
				constsInARow++;
				if (constsInARow == n) {
					//					deb("+" + subString);
					return true;
				}
			}
		}
		//		deb("-" + subString);
		return false;
	}

	//	private void deb(final String a) {
	//		System.out.println(a);
	//	}

}
