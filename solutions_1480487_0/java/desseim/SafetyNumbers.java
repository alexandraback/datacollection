import java.io.File;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;


public final class SafetyNumbers {

	private static double[] compute (final int[] contestantScores) {
		double total = 0;
		for (final int score : contestantScores)
			total += score;
		double contestantNb = contestantScores.length;
		double tmpTotal = total * 2;
		double mean = tmpTotal / contestantNb;
		final double[] contestantMins = new double[contestantScores.length];
		for (int i = 0; i < contestantMins.length && i < contestantScores.length; ++i) {
			if (contestantScores[i] > mean) {
				tmpTotal -= contestantScores[i];
				contestantNb--;
			}
		}
		mean = tmpTotal / contestantNb;
		for (int i = 0; i < contestantMins.length && i < contestantScores.length; ++i) {
			if (contestantScores[i] > mean)
				continue;
			final double toGo = mean - contestantScores[i];
			final double toGoPercentage = (toGo * 100) / total;
			contestantMins[i] = toGoPercentage >= 0 ? toGoPercentage : 0;
		}

		return contestantMins;
	}

	private static final String OUTPUT_FILE_EXTENSION = "out";

	public static void main (final String[] args) throws Exception {
		//input init
		if (args.length < 1)
			throw new IllegalArgumentException();

		final String inputFileName = args[0];
		final int lastDotIndex = inputFileName.lastIndexOf('.');
		final String fileName = (lastDotIndex < 0) ? inputFileName : inputFileName.substring(0, lastDotIndex);
		final String outputFileName = fileName + "." + OUTPUT_FILE_EXTENSION;

		final File inputFile = new File(inputFileName);
		final File outputFile = new File(outputFileName);
		Scanner inputScanner = null;
		PrintWriter outputWriter = null;

		try {
			inputScanner = new Scanner(inputFile);
			outputWriter = new PrintWriter(outputFile);
			final int numberLines = inputScanner.nextInt();
			inputScanner.nextLine();  //go to first text line
			for (int i = 0; i < numberLines; ++i) {
				final int contestantNb = inputScanner.nextInt();
				final int[] contestantScores = new int[contestantNb];
				for (int j = 0; j < contestantNb; ++j) {
					contestantScores[j] = inputScanner.nextInt();
				}
				final double[] contestantMins = compute(contestantScores);
				outputWriter.print("Case #" + (i+1) + ":");
				for (final double min : contestantMins) {
					outputWriter.printf(" %.6f", min);
				}
				outputWriter.println();
			}
		} catch (final NoSuchElementException noSuchElementException) {
			System.err.println("invalid input");
			throw noSuchElementException;
		} finally {
			if (inputScanner != null) {
				inputScanner.close();
			}
			if (outputWriter != null) {
				outputWriter.flush();
				outputWriter.close();
			}
		}
	}

}
