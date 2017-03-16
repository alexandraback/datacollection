package codejam.year2016.qual;

import java.util.*;
import java.io.*;
import java.math.*;

public class B {
	private static Scanner sc;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\test");
		// setStreams("C:\\Users\\Yariv\\Desktop\\B-small-attempt0");
		setStreams("C:\\Users\\Yariv\\Desktop\\B-large");
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
		final String lineStr = sc.next();
		final long res = calc(lineStr, lineStr.length() - 1, true);

		System.out.println("Case #" + caseNumber + ": " + res);
	}

	private static long calc(final String line, final int pos,
			final boolean plus) {
		if (pos < 0) {
			return 0;
		}

		if (plus) {
			if (line.charAt(pos) == '+') {
				return calc(line, pos - 1, true);
			} else {
				return 1 + calc(line, pos - 1, false);
			}
		} else {
			if (line.charAt(pos) == '-') {
				return calc(line, pos - 1, false);
			} else {
				return 1 + calc(line, pos - 1, true);
			}
		}
	}

	private static void log(final String message) {
		// System.out.println(message);
	}
}
