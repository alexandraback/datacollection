import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Dijkstra {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("Couldn't open input file.\n" + e.getMessage());
			e.printStackTrace();
		}
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e) {
			System.out.println("Couldn't open/make output file."
					+ e.getMessage());
			e.printStackTrace();
		}

		int numTrials = scanner.nextInt();
		for (int trial = 1; trial <= numTrials; trial++) {
			System.out.println("Trial: " + trial);
			try {
				writer.write("Case #" + trial + ": ");
				solveTrial(scanner, writer);
				writer.write("\n");
			} catch (IOException e) {
				System.out.println("Error on trial #" + trial + "\n"
						+ e.getMessage());
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
		System.out.println("Completed Trials!");
	}

	// 0 = 1, 1 = i, 2 = j, 3 = k
	static int[][] multTable = { { 0, 1, 2, 3 }, { 1, 0, 3, 2 },
			{ 2, 3, 0, 1 }, { 3, 2, 1, 0 } };
	// 1 = positive, 0 = negative
	static int[][] multTableSign = { { 1, 1, 1, 1 }, { 1, -1, 1, -1 },
			{ 1, -1, -1, 1 }, { 1, 1, -1, -1 } };

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		int L = scanner.nextInt();
		int X = scanner.nextInt();
		scanner.nextLine();
		if (X % 4 == 0) {
			scanner.nextLine();
			writer.write("NO");
			return;
		} else {
			scanner.useDelimiter("");
			int[] vals = new int[L];
			int product = 0;// 1
			int productSign = 1;
			for (int i = 0; i < L; i++) {
				int c = scanner.next().charAt(0) - 'h';
				vals[i] = c;
				productSign *= multTableSign[product][c];
				product = multTable[product][c];
			}
			scanner.useDelimiter("\\p{javaWhitespace}+");
			int maxIterations = 0;
			if (X % 2 == 1) {
				if (product != 0 || productSign != -1) { //product must be -1
					writer.write("NO");
					return;
				} else
					maxIterations = 4;
			} else { // X%4 == 2
				if (product == 0) { //product must be +- i,j,k
					writer.write("NO");
					return;
				} else
					maxIterations = 8;
			}
			int currentProduct = 0;
			int currentSign = 1;
			maxIterations = Math.min(maxIterations, X);
			boolean foundI = false;
			for (int iter = 0; iter < maxIterations; iter++) {
				for (int i = 0; i < L; i++) {
					currentSign *= multTableSign[currentProduct][vals[i]];
					currentProduct = multTable[currentProduct][vals[i]];
					if (foundI) {
						if (currentProduct == 2 && currentSign == 1) {
							writer.write("YES");
							return;
						}
					} else if (currentProduct == 1 && currentSign == 1){
						foundI = true;
						//reset the product and look for j
						currentProduct = 0;
						currentSign = 1;
					}
				}
			}
			writer.write("NO");
		}
	}

}