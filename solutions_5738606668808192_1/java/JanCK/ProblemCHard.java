package jck.codejam.cj2016.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Arrays;
import java.util.Locale;

public class ProblemCHard {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// String filenameInput = "C-sample.in";
		// String filenameOutput = "C-sample.out";
		// String filenameInput = "C-small-attempt1.in";
		// String filenameOutput = "C-small-attempt1.out";
		 int lengthOfCoinJam = 16;
		 int J = 50;
		// String filenameInput = "C-large.in";
//		int lengthOfCoinJam = 32;
//		int J = 500;
		String filenameOutput = "C-large.out";

		Class currentClass = ProblemC.class;
		try {

			String path = "src/" + currentClass.getPackage().getName().replace(".", "/");
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(path + "/" + filenameOutput)));
			int numOfTestcases = 1;
			System.out.println("Number of Testcases: " + numOfTestcases);

			int found = 0;
			int maximumTries = 50000000;
			int counterOfTries = 0;
			long innerNMinus2Digits = 0;
			boolean[] coinJamCandidate = new boolean[lengthOfCoinJam];
			String additionalOutput = "";
			String currentNumberToBaseTen = "";

			int[] primeArray = { 2, 3, 5, 7, 11, 13 };
			int numberOfPrimesToCheck = primeArray.length;

			int[][][] residualsByBaseAndPrime = new int[9][numberOfPrimesToCheck][lengthOfCoinJam];

			for (int curbase = 2; curbase <= 10; curbase++) {
				for (int primeIndex = 0; primeIndex < numberOfPrimesToCheck; primeIndex++) {

					residualsByBaseAndPrime[curbase - 2][primeIndex][0] = 1;
					for (int k = 0; k < lengthOfCoinJam - 1; k++) {
						residualsByBaseAndPrime[curbase - 2][primeIndex][k
								+ 1] = (residualsByBaseAndPrime[curbase - 2][primeIndex][k] * curbase)
										% primeArray[primeIndex];
					}

				}
			}
			

			for (int curbase = 2; curbase <= 10; curbase++) {

				for (int primeIndex = 0; primeIndex < numberOfPrimesToCheck; primeIndex++) {
					System.out.println("base " + curbase);
					System.out.println("prime " + primeArray[primeIndex]);
					String residualsAsString = "";
					for (int k = 0; k < lengthOfCoinJam; k++) {
						residualsAsString += residualsByBaseAndPrime[curbase - 2][primeIndex][k
								] +",";
					}

					System.out.println(residualsAsString);

				}
			}

			
			
			while (found < J && counterOfTries < maximumTries) {
				if (counterOfTries % 10000 == 0) {
					System.out.println("counterOfTries " + counterOfTries + " currently found " + found);
				}
				counterOfTries++;
				coinJamCandidate[0] = true;
				coinJamCandidate[lengthOfCoinJam - 1] = true;

				for (int i = lengthOfCoinJam - 3; i >= 0; i--) {
					coinJamCandidate[i + 1] = (innerNMinus2Digits & (1 << i)) != 0;
				}

				// System.out.println("current array of booleans " +
				// Arrays.toString(coinJamCandidate));
				boolean isDivisbleInAllBases = true;

				long[] divisor = new long[9];
				for (int base = 2; base <= 10 && isDivisbleInAllBases; base++) {
					boolean foundDivisorInLimitedSet = false;
					int primeIndex = 0;
					while (!foundDivisorInLimitedSet && primeIndex < numberOfPrimesToCheck) {
						int residual = 0;
						for (int j = 0; j < lengthOfCoinJam; j++) {
							if (coinJamCandidate[j]) {
								residual += residualsByBaseAndPrime[base - 2][primeIndex][lengthOfCoinJam-j-1];
							}
						}

						if (residual%primeArray[primeIndex] == 0) {
							foundDivisorInLimitedSet = true;
							divisor[base - 2] = primeArray[primeIndex];
						} else {
							primeIndex++;
						}

					}
					if (!foundDivisorInLimitedSet) {
						isDivisbleInAllBases = false;
					}

				}
				if (isDivisbleInAllBases) {
					// found a coinJam
					found++;
					System.out.println("found coinjam " + found + " it is: " + Arrays.toString(coinJamCandidate));
					additionalOutput += booleanArrayToStringWith0And1(coinJamCandidate);
					for (int base = 2; base <= 10 && isDivisbleInAllBases; base++) {
						additionalOutput += " " + divisor[base - 2];
					}
					additionalOutput += "\n";

				}

				innerNMinus2Digits++;

			}

			String outputString = "Case #" + (1) + ":\n" + additionalOutput;
			System.out.println(outputString);

			output.write(outputString);

			output.flush();
			output.close();
		} catch (

		FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static String booleanArrayToStringWith0And1(boolean[] booleanArray) {
		String result = "";
		int length = booleanArray.length;
		for (int j = 0; j < length; j++) {
			result += booleanArray[length-j-1] ? "1" : "0";
		}
		return result;
	}

	private static long getDivisor(long num) {
		if (num < 2)
			return 0;
		if (num == 2)
			return 0;
		if (num % 2 == 0)
			return 2;
		for (long i = 3; i * i <= num; i += 2)
			if (num % i == 0)
				return i;
		return 0;
	}
}
