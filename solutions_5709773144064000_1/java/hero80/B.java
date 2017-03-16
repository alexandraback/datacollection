package codejam.year2014.qual;

import java.util.*;
import java.io.*;
import java.math.*;

public class B {

	private static Scanner sc;
	private static double c, f, x;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\testB");
		// setStreams("C:\\Users\\Yariv\\Desktop\\B-small");
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
		c = sc.nextDouble();
		f = sc.nextDouble();
		x = sc.nextDouble();

		final double res = calc(0, 0, x / 2);
		System.out.println("Case #" + caseNumber + ": " + res);
	}

	private static double calc(double spent, double n, double curr) {
		while (true) {
			final double timeToBuild = spent + (c / (2 + n * f));
			final double timeLeft = (x / (2 + (n + 1) * f));
			final double next = timeToBuild + timeLeft;

			if (curr <= next) {
				return curr;
			}
			spent = timeToBuild;
			n = n + 1;
			curr = next;
		}
	}

	private static void log(final String message) {
		System.out.println(message);
	}
}
