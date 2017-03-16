package com.google.code.qualification_round_2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;

public class ProblemB {
	
	private static String inputFilePath = "/home/chiwang/Downloads/CodeJam/B-large.in";
	private static String outputFilePath = "/home/chiwang/Downloads/CodeJam/Solution/";
	private static BufferedReader br;
	private static BufferedWriter bw;
	
	private static int[] nonEmptyPlates;
	
	private static void compute() throws IOException {
	/*
	 * Fill in the implementation details
	 */
		final int T = Integer.parseInt(br.readLine());
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {			
			final int D = Integer.parseInt(br.readLine());
			nonEmptyPlates = new int[D];
			
			int max = 0;
			String[] parts = br.readLine().split(" ");
			for (int i = 0; i < D; i++) {
				nonEmptyPlates[i] = Integer.parseInt(parts[i]);
				if (max == 0 || max < nonEmptyPlates[i]) {
					max = nonEmptyPlates[i];
				}
			}
			
			Arrays.sort(nonEmptyPlates);

			// binary search with testPossible
			int upper = max;
			int lower = 0;
			boolean isPossible;
			int mid = max / 2;
						
			while (lower <= upper) {
				mid = (upper + lower) / 2;
				
				if (testPossible(mid)) {
					upper = mid - 1;
				} else {
					lower = mid + 1;
				}
			}
			
			int optValue = lower;
			
			String result = String.format("Case #%d: %d%n", caseNum, optValue);
			System.out.println(result);
			bw.write(result);
		}
	}
	
	private static boolean testPossible(int optCandidate) {
		for (int numOfCut = 0; numOfCut < optCandidate; numOfCut++) {
			int maxHeight = optCandidate - numOfCut;
			int cutCount = 0;
			
			for (int i = nonEmptyPlates.length - 1; i >= 0; i--) {
				if (nonEmptyPlates[i] > maxHeight) {
					//cutCount += nonEmptyPlates[i] / maxHeight;
					cutCount += Math.ceil((double) nonEmptyPlates[i] / maxHeight) - 1;
					if (cutCount > numOfCut) {
						break;
					}
				} else {
					break;
				}
			}
			
			if (cutCount <= numOfCut) {
				return true;
			}
		}
		return false;
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

