package com.googlecodejam.gcj2012.qualificationround;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class B {

//	public final static String INPUT_FILE_NAME = "test.in";
//	public final static String INPUT_FILE_NAME = "B-small-attempt0.in";
	public final static String INPUT_FILE_NAME = "B-large.in";
	
	public FileWriter outputWriter;
	public Scanner scanner;
	public String output = "";
	
	public void run() throws Exception {
		// Commons variables
		int testCaseNumber = 0;
		int testCaseResult = 0;
		// Test start
		{
			int nbTests = Integer.parseInt(scanner.nextLine());
			
			for (testCaseNumber = 0; testCaseNumber < nbTests; testCaseNumber++) {
				String[] values = scanner.nextLine().split(" ");
				int nbGooglers = Integer.parseInt(values[0]);
				int nbSurprisingTriplet = Integer.parseInt(values[1]);
				int p = Integer.parseInt(values[2]);
				testCaseResult = 0;
				int nbPossibleSurprisingTriplet = 0;
				for (int i = 0; i < nbGooglers; i++) {
					int score = Integer.parseInt(values[i + 3]);
					int score1 = Math.round(score / 3.f);
					int score2 = score1 + (score - 3 * score1);
					int maxScore = Math.max(score1, score2);
					if (maxScore >= p) {
						testCaseResult++;
					} else if (score > 0 && p <= score && (p - maxScore == 1) && (maxScore * 3 - score < 2)) {
						nbPossibleSurprisingTriplet++;
					}
				}
				testCaseResult += Math.min(nbSurprisingTriplet, nbPossibleSurprisingTriplet);
				
				output += "Case #" + (testCaseNumber+1) + ": " + testCaseResult + "\n";
			}
		}
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	public void init() throws Exception {
		File temp = new File("output/");
		if (!temp.exists()) {
			temp.mkdir();
		}
		// Output file
		outputWriter = new FileWriter("output/output.txt", false);
		// Input file
		scanner = new Scanner(new File("resources/" + INPUT_FILE_NAME));
	}

	public void stop() throws Exception {
		// Closing files
		outputWriter.write(output, 0, output.length());
		scanner.close();
		outputWriter.close();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		B instance = new B();
		long start = System.currentTimeMillis();
		
		instance.init();
		instance.run();
		instance.stop();
		
		System.out.println("Finished in " + (System.currentTimeMillis() - start) + " ms");
	}
	
}
