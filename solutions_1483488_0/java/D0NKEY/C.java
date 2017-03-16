package com.googlecodejam.gcj2012.qualificationround;

import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;

public class C {

//	public final static String INPUT_FILE_NAME = "test.in";
	public final static String INPUT_FILE_NAME = "C-small-attempt0.in";
//	public final static String INPUT_FILE_NAME = "C-large.in";
	
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
				String[] bounds = scanner.nextLine().split(" ");
				String sMinValue = bounds[0];
				String sMaxValue = bounds[1];
				int minValue = Integer.parseInt(sMinValue);
				int maxValue = Integer.parseInt(sMaxValue);
				int nbDigits = sMinValue.length();
				testCaseResult = 0;
				if (nbDigits > 1) {
					for (int currentValue = minValue; currentValue < maxValue; currentValue++) {
						HashSet<Integer> foundValues = new HashSet<Integer>();
						String sCurrentValue = Integer.toString(currentValue);
						char firstNumber = sCurrentValue.charAt(0);
						for (int i = nbDigits - 1; i > 0; i--) {
							char number = sCurrentValue.charAt(i);
							if (number >= firstNumber) {
								String firstPart = sCurrentValue.substring(0, i);
								String secondPart = sCurrentValue.substring(i);
								int val = Integer.parseInt(secondPart + firstPart);
								if (val <= maxValue && val > currentValue && !foundValues.contains(val)) {
									testCaseResult++;
									foundValues.add(val);
								}
							}
						}
					}
				}
				
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
		C instance = new C();
		long start = System.currentTimeMillis();
		
		instance.init();
		instance.run();
		instance.stop();
		
		System.out.println("Finished in " + (System.currentTimeMillis() - start) + " ms");
	}
	
}
