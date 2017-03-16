package codejam.year2016.qual;

import java.util.*;
import java.io.*;
import java.math.*;

public class D {
	private static Scanner sc;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\test");
		// setStreams("C:\\Users\\Yariv\\Desktop\\D-small-attempt1");
		setStreams("C:\\Users\\Yariv\\Desktop\\D-large");
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
		final long K = sc.nextLong();
		final long C = sc.nextLong();
		final long S = sc.nextLong();

		final long numInGuess = Math.min(K, C);
		if (S * numInGuess < K) {
			System.out.println("Case #" + caseNumber + ": IMPOSSIBLE");
		} else {
			String res = "";
			long guessesNeeded = (K / numInGuess);
			if (K % numInGuess != 0) {
				guessesNeeded++;
			}
			for (long i = 0; i < guessesNeeded; i++) {
				long num = 1;
				for (long j = 0; j < numInGuess; j++) {
					num += Math.min((j + (i * numInGuess)), K - 1)
							* ipow(K, C - j - 1);
				}
				res += " " + num;
			}

			System.out.println("Case #" + caseNumber + ":" + res);
		}
	}

	private static long ipow(long base, long exp) {
		long result = 1;
		while (exp != 0) {
			if ((exp & 1) != 0) {
				result *= base;
			}
			exp >>= 1;
			base *= base;
		}

		return result;
	}

	private static void log(final String message) {
		// System.out.println(message);
	}
}
