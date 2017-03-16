package com.googlecodejam.gcj2012.qualificationround;

import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Scanner;

public class A {

//	public final static String INPUT_FILE_NAME = "test.in";
	public final static String INPUT_FILE_NAME = "A-small-attempt0.in";
//	public final static String INPUT_FILE_NAME = "A-large.in";
	
	public FileWriter outputWriter;
	public Scanner scanner;
	public String output = "";
	
	public void run() throws Exception {
		// Commons variables
		int testCaseNumber = 0;
		String testCaseResult = "";
		// Test start
		{
			HashMap<Character, Character> correspondanceTable = new HashMap<Character, Character>(27);
			{
				correspondanceTable.put('z', 'q');
				correspondanceTable.put('q', 'z');
				String googlereseExample = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
				String googlereseExampleTranslation = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
				int nbChars = googlereseExample.length();
				for (int i = 0; i < nbChars; i++) {
					char geChar = googlereseExample.charAt(i);
					char transChar = googlereseExampleTranslation.charAt(i);
					if (correspondanceTable.get(geChar) == null) {
						correspondanceTable.put(geChar, transChar);
					}
				}
			}
			
//			System.out.println(correspondanceTable);
			
			int nbTests = Integer.parseInt(scanner.nextLine());
			
			for (testCaseNumber = 0; testCaseNumber < nbTests; testCaseNumber++) {
				String line = scanner.nextLine();
				int nbChars = line.length();
				testCaseResult = "";
				for (int i = 0; i < nbChars; i++) {
					testCaseResult += String.valueOf(correspondanceTable.get(line.charAt(i)));
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
		A instance = new A();
		long start = System.currentTimeMillis();
		
		instance.init();
		instance.run();
		instance.stop();
		
		System.out.println("Finished in " + (System.currentTimeMillis() - start) + " ms");
	}
	
}
