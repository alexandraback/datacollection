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

public class ProblemB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

//		String filenameInput = "B-sample.in";
//		String filenameOutput = "B-sample.out";
//		 String filenameInput = "B-small-attempt0.in";
//		 String filenameOutput = "B-small-attempt0.out";
		 String filenameInput = "B-large.in";
		 String filenameOutput = "B-large.out";

		Class currentClass = ProblemB.class;
		try {

			String path = "src/" + currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			// System.out.println("Number of Testcases: " + numOfTestcases);
			for (int i = 0; i < numOfTestcases; i++) {
				System.out.println("Testnumber : " + i);
				boolean[] inputArray = readOneTestcase(input);
				int length = inputArray.length;
				int numSignChanges = 0;
				boolean lastSign = inputArray[length - 1];
				boolean currentSign = inputArray[0];
				for (int j = 1; j < length; j++) {
					if (currentSign != inputArray[j]) {
						currentSign = inputArray[j];
						numSignChanges++;
					}
				}
				int result = 0;
				result = numSignChanges + (lastSign?0:1);
				

				String outputString = "Case #" + (i + 1) + ": " + result;

				System.out.println(outputString);

				if (i + 1 != numOfTestcases) {
					outputString += "\n";
				}
				output.write(outputString);

			}

			output.flush();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static void addSeenDigits(boolean[] digitsSeen, int currentNumber) {
		String CurrentNumberAsString = Integer.toString(currentNumber);
		int length = CurrentNumberAsString.length();
		for (int i = 0; i < length; i++) {
			digitsSeen[CurrentNumberAsString.charAt(i) - '0'] = true;
		}

	}

	private static boolean allTrue(boolean[] digitsSeen) {
		int length = digitsSeen.length;
		for (int i = 0; i < length; i++) {
			if (digitsSeen[i] == false) {
				return false;
			}
		}
		System.out.println("all are true");
		return true;
	}

	private static boolean[] readOneTestcase(BufferedReader input) throws IOException {
		String oneLine = input.readLine();
		System.out.println("oneLine \"" + oneLine + "\"" + oneLine.length());
		String trimmed = oneLine.trim();
		System.out.println("trimmed  \"" + trimmed + "\"" + trimmed.length());
		int length = trimmed.length();
		boolean[] readInputArray = new boolean[length];
		for (int i = 0; i < length; i++) {
			readInputArray[i] = (trimmed.charAt(i) == '+');
		}
		System.out.println("readString " + Arrays.toString(readInputArray));
		return readInputArray;
	}

}
