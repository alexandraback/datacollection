package codejam.year2016.qual;

import java.util.*;
import java.io.*;
import java.math.*;

public class C {
	private static Scanner sc;

	private static long curr = -1;

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
		final List<String> res = calc();

		System.out.println("Case #" + caseNumber + ": ");
		for (final String line : res) {
			System.out.println(line);
		}
	}

	private static List<String> calc() {
		final List<String> res = new ArrayList<String>();
		while (res.size() < 50) {
			final String f = findNext();
			res.add(f);
		}

		return res;
	}

	private static String findNext() {
		while (true) {
			curr++;
			final String binary = Long.toBinaryString(curr);
			final String check = "1"
					+ "00000000000000".substring(binary.length()) + binary
					+ "1";
			String divisors = "";

			for (int i = 2; i <= 10; i++) {
				final long numToCheck = Long.parseLong(check, i);
				boolean prime = true;
				long divisor = 0;
				for (long d = 2; d < Math.sqrt(numToCheck) + 1; d++) {
					if (numToCheck % d == 0) {
						prime = false;
						divisor = d;
						break;
					}
				}

				if (prime) {
					break;
				} else {
					divisors += String.valueOf(divisor);
					if (i < 10) {
						divisors += " ";
					} else {
						return check + " " + divisors;
					}
				}
			}
		}
	}

	private static void log(final String message) {
		// System.out.println(message);
	}
}
