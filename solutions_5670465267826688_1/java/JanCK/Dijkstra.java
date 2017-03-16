package nickname.jck.googlecodejam.cj2015.q1.dijkstra;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Dijkstra {

	public static final int NUMBER1 = 0;
	public static final int NUMBERI = 1;
	public static final int NUMBERJ = 2;
	public static final int NUMBERK = 3;
	public static final int NUMBERMINUS1 = 4;
	public static final int NUMBERMINUSI = 5;
	public static final int NUMBERMINUSJ = 6;
	public static final int NUMBERMINUSK = 7;

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		// String filenameInput = "C-sample.in";
		// String filenameOutput = "C-sample.out";

		// String filenameInput = "C-small-attempt0.in";
		// String filenameOutput = "C-small-attempt0.out";

		//String filenameInput = "C-small-attempt-mine.in";
		//String filenameOutput = "C-small-attempt-mine.out";

		String filenameInput = "C-large.in";
		String filenameOutput = "C-large.out";

		testMultiplicationTable();

		Class currentClass = Dijkstra.class;
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
				System.out.println("+++++++++++++++++++++++++++++++++++++++");
				System.out.println("");
				System.out.println("Testnumber : " + i);
				String[] inputStringArray = input.readLine().split(" ");
				int L = Integer.parseInt(inputStringArray[0]);
				long X = Long.parseLong(inputStringArray[1]);
				String audienceMembersByShyness = inputStringArray[1];
				String ijkSequence = input.readLine();
				boolean foundI = false;
				boolean foundJ = false;
				boolean possible = true;
				int Xmod4 = (int) (X % 4);
				// System.out.println("Xmod4 " + Xmod4);
				// System.out.println(ijkSequence + " ^ " + X);
				if (Xmod4 == 0) {
					// the product of the first L digits is
					// 1, -1, i, -i, j, -j, k, -k
					// the product of all numbers must be ijk=-1
					// 1^X is not possible
					// (-1)^X is possible only for Xmod4 = 1 or Xmod4 = 3
					// for the rest
					// (-1)^X is possible only for Xmod4 = 2
					possible = false;
					// System.out.println("Xmod4 == 0 therefore its not possible");
				} else {
					int product = 0; // 1=0,i=1,j=2,k=3,-1=4,-i=5,-j=6,-k=7
					int productOfFirstL = -1;
					int positionModL = 0;
					long iterationsOfX = 0;
					int counterForAtMost4Iterations = 0;
					// System.out.println("foundI " + foundI +
					// " - iterationsOfX "
					// + iterationsOfX + " - X " + X
					// + " - still possible " + possible
					// + " - positionModL " + positionModL);
					// System.out
					// .println("starting first while loop searching for i ... ");
					while (foundI == false && iterationsOfX < X && possible) {
						int currentNumber = ijkSequence.charAt(positionModL) - 'h';// i=1,j=2,k=3
						product = quatmultiply(product, currentNumber);
						// System.out.println("current product: "
						// + numberToFixedWidthString(product)
						// + " after multiplying with "
						// + numberToFixedWidthString(currentNumber));
						if (product == NUMBERI) {
							foundI = true;
							System.out.println("found i");
						}
						positionModL++;
						if (positionModL == L) {
							if (productOfFirstL == -1) {
								productOfFirstL = product;
								possible = doesTheWholeProductFit(
										productOfFirstL, Xmod4);
							}
							if (counterForAtMost4Iterations > 5) {
								possible = false;
							}
							counterForAtMost4Iterations++;
							positionModL = 0;
							iterationsOfX++;
						}
//						 System.out.println("foundI " + foundI
//						 + " - iterationsOfX " + iterationsOfX + " - X "
//						 + X + " - still possible " + possible
//						 + " - positionModL" + positionModL);

					}
					// System.out
					// .println("starting second while loop searching for j ... ");
					int productOfIAndJ = quatmultiply(NUMBERI, NUMBERJ); // NUMBERK
//					 System.out.println("foundJ " + foundJ +
//					 " - iterationsOfX "
//					 + iterationsOfX + " - X " + X
//					 + " - still possible " + possible
//					 + " - positionModL" + positionModL);
					counterForAtMost4Iterations = 0;
					while (foundJ == false && iterationsOfX < X && possible) {
						int currentNumber = ijkSequence.charAt(positionModL) - 'h';// i=1,j=2,k=3
						product = quatmultiply(product, currentNumber);
//						 System.out.println("current product: "
//						 + numberToFixedWidthString(product)
//						 + " after multiplying with "
//						 + numberToFixedWidthString(currentNumber));
						if (product == productOfIAndJ) {
							foundJ = true;
							// System.out.println("found j");
						}
						positionModL++;
						if (positionModL == L) {
							if (productOfFirstL == -1) {
								productOfFirstL = product;
								possible = doesTheWholeProductFit(
										productOfFirstL, Xmod4);
								// System.out.println("possibly set to "
								// + possible + " at positionModL "
								// + positionModL);
							}
//							System.out
//									.println("iteration through L iterationsOfX "
//											+ iterationsOfX
//											+ " counterForAtMost4Iterations "
//											+ counterForAtMost4Iterations);
							if (counterForAtMost4Iterations > 5) {
								possible = false;
							}
							counterForAtMost4Iterations++;
							positionModL = 0;
							iterationsOfX++;
						}
						// System.out.println("foundJ " + foundJ
						// + " - iterationsOfX " + iterationsOfX + " - X "
						// + X + " - still possible " + possible
						// + " - positionModL" + positionModL);

					}

					// System.out.println("finishing reading - iterationsOfX "
					// + iterationsOfX + " - X " + X + " - still possible "
					// + possible + " - positionModL" + positionModL);
					while (positionModL < L && possible) {
						int currentNumber = ijkSequence.charAt(positionModL) - 'h';// i=1,j=2,k=3
						product = quatmultiply(product, currentNumber);
						// System.out.println("current product: "
						// + numberToFixedWidthString(product)
						// + " after multiplying with "
						// + numberToFixedWidthString(currentNumber));
						positionModL++;
						if (positionModL == L) {
							if (productOfFirstL == -1) {
								productOfFirstL = product;
								possible = doesTheWholeProductFit(
										productOfFirstL, Xmod4);
								// System.out.println("possibly set to "
								// + possible + " at positionModL "
								// + positionModL);
							}

						}
						// System.out.println("finishing reading - iterationsOfX "
						// + iterationsOfX + " - X " + X
						// + " - still possible " + possible
						// + " - positionModL" + positionModL);

					}
					// System.out.println("productOfFirstL"
					// + numberToFixedWidthString(productOfFirstL));
					if (!foundI) {
						// System.out.println("Never found i");
						possible = false;
					}
					if (!foundJ) {
						// System.out.println("Never found j");
						possible = false;
					}
				}

				String outputString = "Case #" + (i + 1) + ": "
						+ (possible ? "YES" : "NO");
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

	/**
	 * @param productOfFirstL
	 *            must be one of the 8 numbers 1, i, j, k, -1, -i, -j, -k
	 * @param xMod4
	 *            must be either 1, 2 or 3
	 */
	private static boolean doesTheWholeProductFit(int productOfFirstL, int xMod4) {
		boolean possible = true;
		switch (productOfFirstL) {
		case NUMBER1:
			possible = false;
			break;
		case NUMBERMINUS1:
			if (xMod4 == 2) {
				possible = false;
			}// else we are in the case of Xmod4 == 1 or
				// Xmod4 == 3 which is okay
			break;
		default:
			if (xMod4 == 1 || xMod4 == 3) {
				possible = false;
			}// else we are in the case of Xmod4 ==2
				// which is okay

		}
		// System.out.println((possible ? "Maybe " : "NOT ")
		// + "possible because productOfFirstL "
		// + numberToFixedWidthString(productOfFirstL) + " and Xmod4 "
		// + xMod4);

		return possible;
	}

	private static void testMultiplicationTable() {
		printMultiplicationTable(new int[] { NUMBER1, NUMBERI, NUMBERJ, NUMBERK });
		printMultiplicationTable(new int[] { NUMBER1, NUMBERI, NUMBERJ,
				NUMBERK, NUMBERMINUS1, NUMBERMINUSI, NUMBERMINUSJ, NUMBERMINUSK });

		for (int first : new int[] { NUMBER1, NUMBERI, NUMBERJ, NUMBERK }) {
			for (int second : new int[] { NUMBER1, NUMBERI, NUMBERJ, NUMBERK }) {
				boolean shouldBeEqual = false;
				shouldBeEqual = (negate(quatmultiply(first, second))) == quatmultiply(
						negate(first), second);
				if (!shouldBeEqual)
					throw new RuntimeException("negate first on multiplying "
							+ numberToFixedWidthString(first) + " with "
							+ numberToFixedWidthString(second));
				System.out.println(shouldBeEqual + " negate first");
				shouldBeEqual = (negate(quatmultiply(first, second))) == quatmultiply(
						first, negate(second));
				if (!shouldBeEqual)
					throw new RuntimeException("negate second on multiplying "
							+ numberToFixedWidthString(first) + " with "
							+ numberToFixedWidthString(second));
				System.out.println(shouldBeEqual + " negate second");
				shouldBeEqual = (quatmultiply(first, second)) == quatmultiply(
						negate(first), negate(second));
				if (!shouldBeEqual)
					throw new RuntimeException("negate both on multiplying "
							+ numberToFixedWidthString(first) + " with "
							+ numberToFixedWidthString(second));
				System.out.println(shouldBeEqual + " negate both");

				for (int third : new int[] { NUMBER1, NUMBERI, NUMBERJ, NUMBERK }) {
					shouldBeEqual = (quatmultiply(first,
							quatmultiply(second, third))) == quatmultiply(
							quatmultiply(first, second), third);
					if (!shouldBeEqual)
						throw new RuntimeException(
								"multiplication is associcative for "
										+ numberToFixedWidthString(first)
										+ " with "
										+ numberToFixedWidthString(second)
										+ " and "
										+ numberToFixedWidthString(third));
					System.out.println(shouldBeEqual + " associative");
				}
			}
		}

	}

	private static int negate(int number) {
		int result = -1;
		switch (number) {
		case NUMBER1:
			result = NUMBERMINUS1;
			break;
		case NUMBERI:
			result = NUMBERMINUSI;
			break;
		case NUMBERJ:
			result = NUMBERMINUSJ;
			break;
		case NUMBERK:
			result = NUMBERMINUSK;
			break;
		case NUMBERMINUS1:
			result = NUMBER1;
			break;
		case NUMBERMINUSI:
			result = NUMBERI;
			break;
		case NUMBERMINUSJ:
			result = NUMBERJ;
			break;
		case NUMBERMINUSK:
			result = NUMBERK;
			break;
		}
		return result;
	}

	private static void printMultiplicationTable(int[] numbers) {
		System.out.println("Multiplication table:");
		for (int first : numbers) {
			for (int second : numbers) {
				System.out.print(numberToFixedWidthString(quatmultiply(first,
						second)));
			}
			System.out.println();
		}
	}

	private static String numberToFixedWidthString(int number) {
		String result = "";
		switch (number) {
		case NUMBER1:
			result = "  1";
			break;
		case NUMBERI:
			result = "  i";
			break;
		case NUMBERJ:
			result = "  j";
			break;
		case NUMBERK:
			result = "  k";
			break;
		case NUMBERMINUS1:
			result = " -1";
			break;
		case NUMBERMINUSI:
			result = " -i";
			break;
		case NUMBERMINUSJ:
			result = " -j";
			break;
		case NUMBERMINUSK:
			result = " -k";
			break;
		default:
			result = "ERR";
		}
		return result;
	}

	private static int quatmultiply(int first, int second) {
		// 1=0,i=1,j=2,k=3,-1=4,-i=5,-j=6,-k=7
		int result = 0;
		switch (first) {
		case NUMBER1:
			switch (second) {
			case NUMBER1:
				result = NUMBER1;
				break;
			case NUMBERI:
				result = NUMBERI;
				break;
			case NUMBERJ:
				result = NUMBERJ;
				break;
			case NUMBERK:
				result = NUMBERK;
				break;
			case NUMBERMINUS1:
				result = NUMBERMINUS1;
				break;
			case NUMBERMINUSI:
				result = NUMBERMINUSI;
				break;
			case NUMBERMINUSJ:
				result = NUMBERMINUSJ;
				break;
			case NUMBERMINUSK:
				result = NUMBERMINUSK;
				break;
			}
			break;
		case NUMBERI:
			switch (second) {
			case NUMBER1:
				result = NUMBERI;
				break;
			case NUMBERI:
				result = NUMBERMINUS1;
				break;
			case NUMBERJ:
				result = NUMBERK;
				break;
			case NUMBERK:
				result = NUMBERMINUSJ;
				break;
			case NUMBERMINUS1:
				result = NUMBERMINUSI;
				break;
			case NUMBERMINUSI:
				result = NUMBER1;
				break;
			case NUMBERMINUSJ:
				result = NUMBERMINUSK;
				break;
			case NUMBERMINUSK:
				result = NUMBERJ;
				break;
			}
			break;
		case NUMBERJ:
			switch (second) {
			case NUMBER1:
				result = NUMBERJ;
				break;
			case NUMBERI:
				result = NUMBERMINUSK;
				break;
			case NUMBERJ:
				result = NUMBERMINUS1;
				break;
			case NUMBERK:
				result = NUMBERI;
				break;
			case NUMBERMINUS1:
				result = NUMBERMINUSJ;
				break;
			case NUMBERMINUSI:
				result = NUMBERK;
				break;
			case NUMBERMINUSJ:
				result = NUMBER1;
				break;
			case NUMBERMINUSK:
				result = NUMBERMINUSI;
				break;
			}
			break;
		case NUMBERK:
			switch (second) {
			case NUMBER1:
				result = NUMBERK;
				break;
			case NUMBERI:
				result = NUMBERJ;
				break;
			case NUMBERJ:
				result = NUMBERMINUSI;
				break;
			case NUMBERK:
				result = NUMBERMINUS1;
				break;
			case NUMBERMINUS1:
				result = NUMBERMINUSK;
				break;
			case NUMBERMINUSI:
				result = NUMBERMINUSJ;
				break;
			case NUMBERMINUSJ:
				result = NUMBERI;
				break;
			case NUMBERMINUSK:
				result = NUMBER1;
				break;
			}
			break;
		case NUMBERMINUS1:
			switch (second) {
			case NUMBER1:
				result = NUMBERMINUS1;
				break;
			case NUMBERI:
				result = NUMBERMINUSI;
				break;
			case NUMBERJ:
				result = NUMBERMINUSJ;
				break;
			case NUMBERK:
				result = NUMBERMINUSK;
				break;
			case NUMBERMINUS1:
				result = NUMBER1;
				break;
			case NUMBERMINUSI:
				result = NUMBERI;
				break;
			case NUMBERMINUSJ:
				result = NUMBERJ;
				break;
			case NUMBERMINUSK:
				result = NUMBERK;
				break;
			}
			break;
		case NUMBERMINUSI:
			switch (second) {
			case NUMBER1:
				result = NUMBERMINUSI;
				break;
			case NUMBERI:
				result = NUMBER1;
				break;
			case NUMBERJ:
				result = NUMBERMINUSK;
				break;
			case NUMBERK:
				result = NUMBERJ;
				break;
			case NUMBERMINUS1:
				result = NUMBERI;
				break;
			case NUMBERMINUSI:
				result = NUMBERMINUS1;
				break;
			case NUMBERMINUSJ:
				result = NUMBERK;
				break;
			case NUMBERMINUSK:
				result = NUMBERMINUSJ;
				break;
			}
			break;
		case NUMBERMINUSJ:
			switch (second) {
			case NUMBER1:
				result = NUMBERMINUSJ;
				break;
			case NUMBERI:
				result = NUMBERK;
				break;
			case NUMBERJ:
				result = NUMBER1;
				break;
			case NUMBERK:
				result = NUMBERMINUSI;
				break;
			case NUMBERMINUS1:
				result = NUMBERJ;
				break;
			case NUMBERMINUSI:
				result = NUMBERMINUSK;
				break;
			case NUMBERMINUSJ:
				result = NUMBERMINUS1;
				break;
			case NUMBERMINUSK:
				result = NUMBERI;
				break;
			}
			break;
		case NUMBERMINUSK:
			switch (second) {
			case NUMBER1:
				result = NUMBERMINUSK;
				break;
			case NUMBERI:
				result = NUMBERMINUSJ;
				break;
			case NUMBERJ:
				result = NUMBERI;
				break;
			case NUMBERK:
				result = NUMBER1;
				break;
			case NUMBERMINUS1:
				result = NUMBERK;
				break;
			case NUMBERMINUSI:
				result = NUMBERJ;
				break;
			case NUMBERMINUSJ:
				result = NUMBERMINUSI;
				break;
			case NUMBERMINUSK:
				result = NUMBERMINUS1;
				break;
			}
			break;
		}

		return result;
	}
}
