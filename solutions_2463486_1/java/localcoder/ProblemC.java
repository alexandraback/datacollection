package y2013.qualification.c;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProblemC {

	private static final String[] allDigits = "0123456789".split("");

	public static void main(final String[] args) throws FileNotFoundException {
		new ProblemC().start();
	}

	private void start() throws FileNotFoundException {
		final Scanner s = new Scanner(new File("src/y2013/qualification/c/C-large-1.in"));
		final int numTests = s.nextInt();
		for (int i = 0; i < numTests; i++) {
			final long minValue = s.nextLong();
			final long maxValue = s.nextLong();

			final long solution = solve(minValue, maxValue);
			System.out.println("Case #" + (i+1) + ": " + solution);
		}
	}

	/* find numbers in the range which are:
		//1. a palendrome
		//2. a square
		//3. a square of a palendrome
		//which criteria lets us narrow this down most quickly?
		//(3 seems useful.)

		//I could grab a list from the internet of all palendromes up to some n.
		//That lets me cover a range up to n^2 - lots of websites have the first 2000 palendromes etc.

		//Oooh, or: "Revert your reasoning" (says stackoverflow)
		//- don't try to find the numbers, create them instead.

		//OK. Let's generate palendromes, square them, and then check if they're still palendromes
		//and then check if they're in the range.
	 */
	private long solve(final long minValue, final long maxValue) {
		long results = 0l;
		//find the root of each value
		//		final long rootMin = (long)Math.sqrt(minValue) - 1; //expand boundaries because i'm not sure : /
		final long rootMax = (long)Math.sqrt(maxValue) + 1;

		for (final Long littlePalendrome: allPalindromic(rootMax)) {
			//I'm a palendrome. Square me.
			final long bigValue = littlePalendrome*littlePalendrome;
			//we know bigValue is a square of a palendrome.
			//but is it in range?
			if (bigValue >= minValue && bigValue <= maxValue) {
				if (isPalendrome(bigValue)) {
					results++;
				}
			}
		}
		return results;
	}

	//more stackoverflow tricks
	private boolean isPalendrome(final long bigValue) {
		final String val = "" + bigValue;
		final int length = val.length();
		for (int i = 0; i < length / 2 + 1; i++) {
			if (val.charAt(i) != val.charAt(length - i - 1)) {
				return false;
			}
		}
		return true;
	}

	//Stackoverflow 'how to find out all palindromic numbers'
	public static Set<Long> allPalindromic(final long limit) {
		final Set<Long> result = new HashSet<Long>();

		for (long i = 0; i <= 9 && i <= limit; i++) {
			result.add(i);
		}

		boolean stillValid = true;
		for (int i = 1; stillValid; i++) {
			final StringBuffer reversed = new StringBuffer("" + i).reverse();
			stillValid = false;
			for (final String digit : allDigits) {
				final long n = Long.parseLong("" + i + digit + reversed);
				if (n <= limit) {
					stillValid = true;
					result.add(n);
				}
			}
		}

		return result;
	}

}
