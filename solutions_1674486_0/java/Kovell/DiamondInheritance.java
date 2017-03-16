package codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DiamondInheritance {

	private static int inputLength = 1;

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		String filename = "DiamondInheritance/input.txt";
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
				inputLength = sc.nextInt();
				input = String.valueOf(inputLength) + "\n";
				sc.nextLine();
				for (int row = 0; row < inputLength; row++) {
					input += sc.nextLine() + System.lineSeparator();
				}
				out += "Case #" + (i + 1) + ": ";
				out += runTest(input);
				out += System.lineSeparator();
			}
			System.out.println(out);
			BufferedWriter output = new BufferedWriter(new FileWriter(
							"DiamondInheritance/output.txt"));
			output.write(out);
			output.close();
		} catch (FileNotFoundException ex) {
			System.err.println("Input file not found");
			System.exit(1);
		} catch (IOException ex) {
		}
	}

	public static String runTest(String input) {
		Scanner sc = new Scanner(input);
		int length = sc.nextInt();

		int[][] nodes = new int[length][];

		for (int i = 0; i < length; i++) {
			int curlength = sc.nextInt();
			nodes[i] = new int[curlength];
			for (int j = 0; j < curlength; j++) {
				nodes[i][j] = sc.nextInt() - 1;
			}
		}
		// Check each node for family issues.
		// TODO: Remember how to code.
		try {
			for(int i = 0; i < nodes.length; i++) {
				findChildren(nodes, i);
			}
		} catch (Exception ex) {
			return "Yes";
		}
		return  "No";
	}

	public static ArrayList<Integer> findChildren(int[][] nodes, int parent) throws Exception {
		ArrayList<Integer> found = new ArrayList<Integer>();
		//found.add(parent);
		for (int cur : nodes[parent]) {
			found.add(cur);
		}
		for (int cur : nodes[parent]) {
			for (int curKid: findChildren(nodes, cur)) {
				if (found.contains(curKid)) {
					throw new Exception();
				}
				found.add(curKid);
			}
			
		}
		return found;
	}
}
