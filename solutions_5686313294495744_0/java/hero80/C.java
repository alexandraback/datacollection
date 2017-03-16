package codejam.year2016.round1B;

import java.util.*;
import java.util.concurrent.ArrayBlockingQueue;
import java.io.*;
import java.math.*;

import javax.print.attribute.HashAttributeSet;

public class C {
	private static Scanner sc;

	static List<String> firsts;
	static List<String> seconds;
	static int N;
	static int max;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\test");
		setStreams("C:\\Users\\Yariv\\Desktop\\C-small-attempt0");
		// setStreams("C:\\Users\\Yariv\\Desktop\\C-large");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		firsts = new ArrayList<>();
		seconds = new ArrayList<>();
		max = 0;

		N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			String first = sc.next();
			String second = sc.next();

			firsts.add(first);
			seconds.add(second);
		}

		long checkTo = 1;
		for (int i = 0; i < N; i++) {
			checkTo *= 2;
		}
		for (long i = 0; i < checkTo; i++) {
			calc(i);
		}
		System.out.println("Case #" + caseNumber + ": " + max);
	}

	private static void calc(long val) {
		Set<String> allowedFirsts = new HashSet<>();
		Set<String> allowedSeconds = new HashSet<>();

		Set<String> exists = new HashSet<>();
		for (int i = 0; i < N; i++) {
			if ((val & (1L << i)) != 0) {
				allowedFirsts.add(firsts.get(i));
				allowedSeconds.add(seconds.get(i));
				exists.add(firsts.get(i) + " " + seconds.get(i));
			}
		}

		int counter = 0;
		boolean noFound = false;
		for (int i = 0; i < N; i++) {
			if ((val & (1L << i)) == 0) {
				counter++;
				if (allowedFirsts.contains(firsts.get(i))
						&& allowedSeconds.contains(seconds.get(i))
						&& !exists.contains(firsts.get(i) + " "
								+ seconds.get(i))) {
					exists.add(firsts.get(i) + " " + seconds.get(i));
				} else {
					noFound = true;
					break;
				}
			}
		}

		if (!noFound && counter > max) {
			max = counter;
		}
	}

	private static void log(final String message) {
		System.out.println(message);
	}
}
