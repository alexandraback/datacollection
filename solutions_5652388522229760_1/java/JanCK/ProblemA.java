package jck.codejam.cj2016.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class ProblemA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		//String filenameInput = "A-sample.in";
		//String filenameOutput = "A-sample.out";

		//String filenameInput = "A-small-attempt0.in";
		//String filenameOutput = "A-small-attempt0.out";

		String filenameInput = "A-large.in";
		String filenameOutput = "A-large.out";

		Class currentClass = ProblemA.class;
		try {

			String path = "src/" + currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			// System.out.println("Number of Testcases: " + numOfTestcases);
			for (int i = 0; i < numOfTestcases; i++) {
				System.out.println("Testnumber : " + i);
				int startingNumber = readOneTestcase(input);

				boolean possible = true;

				System.out.println("Starting number : " + startingNumber);

				int result = 0;

				if (startingNumber != 0) {
					boolean[] digitsSeen = new boolean[10];
					int counter = 1;
					int currentNumber = startingNumber;
					addSeenDigits(digitsSeen, currentNumber);
					System.out.println("Current number : " + currentNumber);
					System.out.println("Currently seen digits: " + Arrays.toString(digitsSeen));
					while (!allTrue(digitsSeen) && counter < 10000) {
						currentNumber += startingNumber;
						addSeenDigits(digitsSeen, currentNumber);

						System.out.println("Current number : " + currentNumber);
						System.out.println("Currently seen digits: " + Arrays.toString(digitsSeen));
					}

					result = currentNumber;
					if (counter >= 10000) {
						result = -1;
					}

				}

				String outputString = "Case #" + (i + 1) + ": " + ((result == 0) ? "INSOMNIA" : result);

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

	private static int readOneTestcase(BufferedReader input) throws IOException {
		return Integer.parseInt(input.readLine());
	}

}
