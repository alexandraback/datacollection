package codejam.year2016.round1B;

import java.util.*;
import java.io.*;
import java.math.*;

public class B {
	private static Scanner sc;

	static int min = 100000;

	static String resC;
	static String resJ;
	static String checkC;
	static String checkJ;
	static String c, j;
	static String format;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\test");
		setStreams("C:\\Users\\Yariv\\Desktop\\B-small-attempt0");
		// setStreams("C:\\Users\\Yariv\\Desktop\\B-large");
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
		c = sc.next();
		j = sc.next();

		resC = c;
		resJ = j;
		checkC = c;
		checkJ = j;
		min = 10000;

		format = "%0" + c.length() + "d";

		check(0);

		System.out.println("Case #" + caseNumber + ": " + resC + " " + resJ);
	}

	private static void check(int index) {
		if (index == c.length()) {
			int valC = Integer.parseInt(checkC);
			int valJ = Integer.parseInt(checkJ);
			// System.out.println("Check: " + valC + " " + valJ);
			if (Math.abs(valC - valJ) < min) {
				min = Math.abs(valC - valJ);
				resC = String.format(format, valC);
				resJ = String.format(format, valJ);
			} else if (Math.abs(valC - valJ) == min) {
				if (resC.contains("?") || valC < Integer.parseInt(resC)) {
					resC = String.format(format, valC);
					resJ = String.format(format, valJ);
				} else if (valC == Integer.parseInt(resC)) {
					if (valJ < Integer.parseInt(resJ)) {
						resC = String.format(format, valC);
						resJ = String.format(format, valJ);
					}
				}
			}
		}

		else {
			if (c.charAt(index) == '?') {
				for (int i = 0; i < 10; i++) {
					checkC = checkC.substring(0, index) + String.valueOf(i)
							+ checkC.substring(index + 1);
					if (j.charAt(index) == '?') {
						for (int j2 = 0; j2 < 10; j2++) {
							checkJ = checkJ.substring(0, index)
									+ String.valueOf(j2)
									+ checkJ.substring(index + 1);
							check(index + 1);
						}
						checkJ = checkJ.substring(0, index) + "?"
								+ checkJ.substring(index + 1);
					} else {
						check(index + 1);
					}
				}
				checkC = checkC.substring(0, index) + "?"
						+ checkC.substring(index + 1);
			} else {
				if (j.charAt(index) == '?') {
					for (int j2 = 0; j2 < 10; j2++) {
						checkJ = checkJ.substring(0, index)
								+ String.valueOf(j2)
								+ checkJ.substring(index + 1);
						check(index + 1);
					}
					checkJ = checkJ.substring(0, index) + "?"
							+ checkJ.substring(index + 1);
				} else {
					check(index + 1);
				}
			}
		}
	}

	private static void log(final String message) {
		// System.out.println(message);
	}
}
