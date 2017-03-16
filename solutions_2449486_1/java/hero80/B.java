package codejam.qual;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class B {

	private static BufferedReader br;

	private static int[][] result;
	private static int N;
	private static int M;

	public static void main(final String[] args) {
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
		N = (int) numbers[0];
		M = (int) numbers[1];

		result = new int[N][M];
		for (int i = 0; i < N; i++) {
			final long[] numbersLine = readNumbers();
			for (int j = 0; j < M; j++) {
				result[i][j] = (int) numbersLine[j];
			}
		}

		check(caseNumber);

		// log("@@@ " + number + " @@@");

		// System.out.println("Case #" + caseNumber + ": " + res);
	}

	private static void check(final int caseNumber) {
		final int[] maxRows = new int[N];
		final int[] maxCols = new int[M];
		for (int i = 0; i < N; i++) {
			maxRows[i] = 0;
			for (int j = 0; j < M; j++) {
				if (result[i][j] > maxRows[i]) {
					maxRows[i] = result[i][j];
					log("Max " + i + ": " + maxRows[i]);
				}
			}
		}

		for (int j = 0; j < M; j++) {
			maxCols[j] = 0;
			for (int i = 0; i < N; i++) {
				if (result[i][j] > maxCols[j]) {
					maxCols[j] = result[i][j];
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (result[i][j] != Math.min(maxRows[i], maxCols[j])) {
					log("Max row: " + i + ": " + maxRows[i] + " Max col: " + j
							+ ": " + maxCols[j] + " actual: " + result[i][j]);
					System.out.println("Case #" + caseNumber + ": NO");
					return;
				}
			}
		}

		System.out.println("Case #" + caseNumber + ": YES");
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
		// System.out.println(message);
	}
}
