package com.googlecodejam.gcj2013.round1C;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {

//	public final static String INPUT_FILE_NAME = "test.in";
//	public final static String INPUT_FILE_NAME = "A-small-attempt1.in";
	public final static String INPUT_FILE_NAME = "A-large.in";
	
	public FileWriter outputWriter;
	public Scanner scanner;
	public StringBuilder output = new StringBuilder();
	
	public void run() throws Exception {
		// Commons variables
		int testCaseNumber = 0;
		double testCaseResult = 0;
		// Test start
		{
			int nbTests = Integer.parseInt(scanner.nextLine());
			
			for (testCaseNumber = 0; testCaseNumber < nbTests; testCaseNumber++) {
				String[] infos = scanner.nextLine().split(" ");
				String name = infos[0];
				int n = Integer.parseInt(infos[1]);
				
				int nameLength = name.length();
				int consecutiveConsonants = 0;
				int lastGroupIndex = -1;
				testCaseResult = 0;
				for (int i = 0; i < nameLength; i++) {
					char c = name.charAt(i);
					if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
						consecutiveConsonants = 0;
					} else {
						consecutiveConsonants++;
						if (consecutiveConsonants >= n) {
							double left = i - (lastGroupIndex != -1 ? lastGroupIndex + 1. : n - 1.);
							double right = nameLength - i - 1.;
							testCaseResult += left + 1 + right + left * right;
							lastGroupIndex = i;
						}
					}
				}
				
				output.append("Case #" + (testCaseNumber+1) + ": " + String.format("%.0f", testCaseResult) + "\n");
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
		outputWriter.write(output.toString(), 0, output.length());
		scanner.close();
		outputWriter.close();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		A instance = new A();
		long start = System.currentTimeMillis();
		
		instance.init();
		instance.run();
		instance.stop();
		
		System.out.println("Finished in " + (System.currentTimeMillis() - start) + " ms");
	}
	
}
