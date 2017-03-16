package com.google.code.qualification_round_2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

public class ProblemA {
	
	private static String inputFilePath = "/home/chiwang/Downloads/CodeJam/A-small-attempt0.in";
	private static String outputFilePath = "/home/chiwang/Downloads/CodeJam/Solution/";
	private static BufferedReader br;
	private static BufferedWriter bw;
	
	private static int[] audience;
	private static int[] audienceSpectrum;
	
	private static void compute() throws IOException {
	/*
	 * Fill in the implementation details
	 */
		final int T = Integer.parseInt(br.readLine());
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			String[] parts = br.readLine().split(" ");
			
			final int sM = Integer.parseInt(parts[0]);
			audience = new int[sM + 1];
			int numOfAudience = 0;
			
			for (int i = 0; i < parts[1].length(); i++) {
				audience[i] = Integer.parseInt(parts[1].charAt(i) + "");
				numOfAudience += audience[0];
			}
			
			int numOfStoodup = 0;
			int numOfFriends = 0;
			
			for (int i = 0; i <= sM; i++) {				
				while (numOfStoodup < i) {
					numOfFriends++;
					numOfStoodup++;
				}
				
				numOfStoodup += audience[i];
			}
			
			
			//System.out.println(numOfFriends);
			
			
			String result = String.format("Case #%d: %d%n", caseNum, numOfFriends);
			bw.write(result);
		}				
	}
	
	public static void main(String[] args) {
		
		// Initialisation
		try {
			outputFilePath += inputFilePath.substring(inputFilePath.lastIndexOf("/") + 1, inputFilePath.length() - 3) + ".out";
			
			br = new BufferedReader(new FileReader(inputFilePath));
			bw = new BufferedWriter(new FileWriter(outputFilePath));
			
			compute();		
			
		} catch (IOException ioe) {
			ioe.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
				if (bw != null)
					bw.close();
			} catch (IOException ioe) {
				ioe.printStackTrace();
			}
		}
		
		System.out.println("========================================");
		System.out.println("Done! :)");
	}

}

