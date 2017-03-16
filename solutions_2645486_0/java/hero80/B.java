package codejam.round1A;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class B {

	private static long e, r, n;
	private static long[] values;
	private static BufferedReader br;

	private static long maxSum;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\test");
		setStreams("C:\\Users\\Yariv\\Desktop\\B-small-attempt0");
		// setStreams("C:\\Users\\Yariv\\Desktop\\B-large");
		br = new BufferedReader(new InputStreamReader(System.in));
		final int numCases = (int) readNumber();
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
		final long[] numbers = readNumbers();
		e = numbers[0];
		r = numbers[1];
		n = numbers[2];
		values = readNumbers();

		maxSum = -1;

		run(0, 0, e);
		System.out.println("Case #" + caseNumber + ": " + maxSum);
	}

	private static void run(final int activity, final long curSum,
			final long leftE) {
		if (activity == n - 1) {
			if (curSum + leftE * values[activity] > maxSum) {
				maxSum = curSum + leftE * values[activity];
			}
			return;
		}
		for (long i = 0; i <= leftE; i++) {
			final long newLeftE = Math.min(e, (leftE - i + r));
			final long newCurSum = curSum + i * values[activity];
			run(activity + 1, newCurSum, newLeftE);
		}

	}

	private static long readNumber() {
		final String line = readLine();
		final long number = Long.parseLong(line);
		return number;
	}

	private static long[] readNumbers() {
		final String line = readLine();
		final String[] numbersStr = line.split(" ");
		final long[] numbers = new long[numbersStr.length];
		for (int i = 0; i < numbersStr.length; i++) {
			numbers[i] = Long.parseLong(numbersStr[i]);
		}
		return numbers;
	}

	private static String readLine() {
		String line = null;
		try {
			line = br.readLine();
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return line;
	}

	private static void log(final String message) {
		System.out.println(message);
	}
}
