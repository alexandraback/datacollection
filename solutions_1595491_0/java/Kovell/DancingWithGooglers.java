package codeJam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class DancingWithGooglers {
	private static int inputLength = 1;

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		String filename = "DancingWithGooglers/input.txt";
		if (args.length > 0) {
			filename = args[0];
		}
		
		try {
			Scanner sc = new Scanner (new File(filename));
		
			String input;
			int testCount = Integer.parseInt(sc.nextLine());
			String out = "";
			
			// Split the input into separate tests and collect the output.
			for (int i = 0; i < testCount; i++) {
				input = "";
				for (int row = 0; row < inputLength; row++) {
					input += sc.nextLine() + System.lineSeparator();
				}
				out += "Case #" + (i+1) + ": ";
				out += runTest(input);
				out += System.lineSeparator();
			}
			System.out.println(out);
			BufferedWriter output = new BufferedWriter(new FileWriter(
							"DancingWithGooglers/output.txt"));
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
		long googlers = sc.nextLong();
		int surprise = sc.nextInt();
		int p = sc.nextInt();
		ArrayList<Integer> scores = new ArrayList<Integer>();
		while(sc.hasNextInt()) {
			scores.add(sc.nextInt());
		}
		
		Long betterThan = new Long(0);
		
		int minPNormal = p - 1 < 0 ? 0 : p - 1;
		int minPSurprise = p - 2 < 0 ? 0 : p - 2;
		
		for (int score: scores) {
			if (score >= minPNormal * 2 + p) {
				betterThan++;
			} else if (surprise > 0 && score >= minPSurprise * 2 + p) {
				betterThan++;
				surprise--;
			}
			
		}
		
		return betterThan.toString();

	}

}
