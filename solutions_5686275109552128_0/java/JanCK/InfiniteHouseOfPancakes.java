package nickname.jck.googlecodejam.cj2015.q1.pancakes;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;

public class InfiniteHouseOfPancakes {

	public static void main(String[] args) {

		// String filenameInput = "B-sample.in";
		// String filenameOutput = "B-sample.out";

		String filenameInput = "B-small-attempt0.in";
		String filenameOutput = "B-small-attempt0.out";

		testNumberOfMoves();

		Class currentClass = InfiniteHouseOfPancakes.class;
		try {

			String path = "src/"
					+ currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(
					path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(
					path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			// System.out.println("Number of Testcases: " + numOfTestcases);
			for (int i = 0; i < numOfTestcases; i++) {
				System.out.println("");
				System.out.println("");
				System.out.println("+++++++++++++++++++++++++");
				System.out.println("");
				System.out.println("");
				
				
				System.out.println("Testnumber : " + i);
				int numberOfPlatesWithPancakes = Integer.parseInt(input
						.readLine());
				String[] inputStringArray = input.readLine().split(" ");
				int[] pancakes = new int[numberOfPlatesWithPancakes];
				for (int j = 0; j < numberOfPlatesWithPancakes; j++) {
					pancakes[j] = Integer.parseInt(inputStringArray[j]);
				}

//				System.out.println("unsorted " + Arrays.toString(pancakes));

				int numberOfMinutesNeeded = 0;

				Arrays.sort(pancakes);

//				System.out.println("sorted ascending " + Arrays.toString(pancakes));

				for (int j = 0; j < pancakes.length / 2; j++) {
					int temp = pancakes[j];
					pancakes[j] = pancakes[pancakes.length - j - 1];
					pancakes[pancakes.length - j - 1] = temp;
				}

//				System.out.println("sorted " + Arrays.toString(pancakes));

				numberOfMinutesNeeded = pancakes[0];

				int startEatingFrom = numberOfMinutesNeeded - 1;
				boolean minimumFound = false;
				while (!minimumFound && startEatingFrom > 0) {

//					System.out
//							.println("checking number of moves when eating would start at: "
//									+ startEatingFrom
//									+ ". The minimum is still: "
//									+ numberOfMinutesNeeded);
					int numberOfMoveOperations = 0;
					boolean moreMoveOperations = true;
					int indexThroughTables = 0;
					while (moreMoveOperations) {
						if (indexThroughTables < numberOfPlatesWithPancakes
								&& pancakes[indexThroughTables] > startEatingFrom) {
							numberOfMoveOperations += numberOfMoves(
									pancakes[indexThroughTables],
									startEatingFrom);
//							System.out.println(numberOfMoveOperations
//									+ " is the numberOfMoveOperations "
//									+ " for getting pancakes["
//									+ indexThroughTables + "] = "
//									+ pancakes[indexThroughTables] + " to "
//									+ startEatingFrom);
							indexThroughTables++;
						} else {
							moreMoveOperations = false;
						}

						if (indexThroughTables == numberOfPlatesWithPancakes) {
							moreMoveOperations = false;
						}

					}
//					System.out
//							.println(numberOfMoveOperations
//									+ " is the numberOfMoveOperations needed for getting all to "
//									+ " startEatingFrom " + startEatingFrom
//									+ " numberOfMinutesNeeded"
//									+ numberOfMinutesNeeded);

					if (numberOfMoveOperations + startEatingFrom < numberOfMinutesNeeded) {
						numberOfMinutesNeeded = numberOfMoveOperations
								+ startEatingFrom;
					}
					startEatingFrom--;

				}

				String outputString = "Case #" + (i + 1) + ": "
						+ numberOfMinutesNeeded;
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

	private static void testNumberOfMoves() {
		checkNumberOfMoves(9, 1, 8);
		checkNumberOfMoves(9, 2, 4);
		checkNumberOfMoves(9, 3, 2);
		checkNumberOfMoves(9, 4, 2);
		checkNumberOfMoves(9, 5, 1);
		checkNumberOfMoves(3, 1, 2);
		checkNumberOfMoves(3, 2, 1);
		checkNumberOfMoves(4, 1, 3);
		checkNumberOfMoves(4, 2, 1);
		checkNumberOfMoves(4, 3, 1);
		checkNumberOfMoves(5, 1, 4);
		checkNumberOfMoves(5, 2, 2);
		checkNumberOfMoves(5, 3, 1);
		checkNumberOfMoves(5, 4, 1);

	}

	private static void checkNumberOfMoves(int i, int j, int k) {
		System.out.println("Starting from: " + i + " going to " + j
				+ " should take " + k + " and needs " + numberOfMoves(i, j));
		if (k != numberOfMoves(i, j)) {
			throw new RuntimeException("Starting from: " + i + " going to " + j
					+ " should take " + k + " but it needs "
					+ numberOfMoves(i, j));
		}
	}

	private static int numberOfMoves(int i, int startEatingFrom) {
		return (int) Math.ceil((double) i / startEatingFrom) - 1;

	}

	private static int[] readSpecifiedLine(BufferedReader input)
			throws IOException {
		int desiredLineNumber = Integer.parseInt(input.readLine()) - 1;
		int[] result = new int[4];
		String desiredLine = "";
		for (int i = 0; i <= 3; i++) {
			if (i == desiredLineNumber) {
				desiredLine = input.readLine();
			} else {
				input.readLine();
			}
		}
		String[] numbersAsStrings = desiredLine.split(" ");
		for (int i = 0; i <= 3; i++) {
			result[i] = Integer.parseInt(numbersAsStrings[i]);
		}
		return result;
	}

}
