package codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class KingdomRush {

	private static int inputLength = 0;

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		String filename = "KingdomRush/input.txt";
		if (args.length > 0) {
			filename = args[0];
		}

		try {
			Scanner sc = new Scanner(new File(filename));

			String input;
			int testCount = Integer.parseInt(sc.nextLine());
			String out = "";

			// Split the input into separate tests and collect the output.
			for (int i = 0; i < testCount; i++) {
				input = "";
				inputLength = sc.nextInt();
				sc.nextLine();
				for (int row = 0; row < inputLength; row++) {
					input += sc.nextLine() + System.lineSeparator();
				}
				out += "Case #" + (i + 1) + ": ";
				out += runTest(input, inputLength);
				out += System.lineSeparator();
			}
			System.out.println(out);
			BufferedWriter output = new BufferedWriter(new FileWriter(
							"KingdomRush/output.txt"));
			output.write(out);
			output.close();
		} catch (FileNotFoundException ex) {
			System.err.println("Input file not found");
			System.exit(1);
		} catch (IOException ex) {
		}
	}

	public static String runTest(String input, int rows) {
		Scanner sc = new Scanner(input);

		// lvl1, lvl2, complete (0/1/2)
		int[][] levels = new int[rows][3];
		for (int i = 0; i < rows; i++) {
			levels[i][0] = sc.nextInt();
			levels[i][1] = sc.nextInt();
		}

		// 0/1/2 totals
		int[] numberCompleted = new int[3];
		numberCompleted[0] = rows;
		int stars = 0;
		int levelsCompleted = 0;
		//int availableStars = available(levels, stars);

		int best = -1;
		int i = 0;
		while (true) {
			i = 0;
			while (i < levels.length) {
				if (levels[i][2] == 0 && levels[i][1] <= stars) {
					stars += 2;
					levels[i][2] = 2;
					levelsCompleted++;
					numberCompleted[2]++;
					numberCompleted[0]--;
					i = 0;
				} else {
					i++;
				}
			}

			best = -1;
			for (i = 0; i < levels.length; i++) {
				if (levels[i][2] == 1 && levels[i][1] <= stars
								&& (best == -1 || levels[i][1] > levels[best][1])) {
					best = i;
				}
			}
			
			if (best > -1) {
				stars += 1;
				levels[best][2] = 2;
				levelsCompleted++;
				numberCompleted[2]++;
				numberCompleted[1]--;
				continue;
			}
			
			best = -1;
			for (i = 0; i < levels.length; i++) {
				if (levels[i][2] == 0 && levels[i][0] <= stars
								&& (best == -1 || levels[i][0] > levels[best][0])) {
					best = i;
				}
			}
			
			if (best > -1) {
				stars += 1;
				levels[best][2] = 1;
				levelsCompleted++;
				numberCompleted[1]++;
				numberCompleted[0]--;
				continue;
			} else {
				break;
			}
			
			
		}
		for (i = 0; i < levels.length; i++) {
			if (levels[i][2] < 2) {
				return "Too Bad";
			}
		}
		return String.valueOf(levelsCompleted);
	}

	public static int available(int[][] levels, int stars) {
		int available = 0;
		for (int[] level : levels) {
			if (level[3] < 2 && level[2] < stars) {
				available += 2;
			} else if (level[3] < 1 && level[1] < stars) {
				available += 1;
			}
		}
		return available;
	}
}
