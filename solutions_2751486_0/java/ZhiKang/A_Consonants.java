package com.zkgcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A_Consonants {
	
	private static final String inputPath = "A-small-attempt0.in";
	private static final String outputPath = "A-small-attempt0.out";

	/**
	 * @param args
	 */
	public static void main(String[] args) {		
		// Create input reader
		Scanner sc = null;
		try {
			sc = new Scanner(new File(inputPath));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		}
		
		
		// Create output writer
		File outputFile = new File(outputPath);
		PrintWriter pw = null;
		try {
			pw = new PrintWriter(outputFile);
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
			return;
		}

		// Read number of test cases
		int T = sc.nextInt();
		sc.nextLine();
		
		// Process test cases
		String name;
		int n;
		int res;
		for (int i = 0; i < T; i++) {
			// Read input
			name = sc.next();
			n = sc.nextInt();
			
			// Compute answer for this test case
			res = computeNval_all(name, n);
			
			// Move scanner to next line
			sc.nextLine();

			System.out.println("Case #" + (i + 1) + ": " + res);
			pw.println("Case #" + (i + 1) + ": " + res);
		}
		
		// Close
		sc.close();
		pw.close();
		System.out.println("Program finished");
	}
	
	private static int computeNval_all(String name, int n) {
		int nVal = 0;
		
		// Compute all substring permutations
		int L = name.length();
		String substring;
		for (int i = 0; i < L; i++) {
			for (int j = i + 1; j <= L; j++) {
				substring = name.substring(i, j);
				//System.out.println(substring);
				if (hasNconsecutiveConsonants(substring, n)) {
					nVal++;
				}
			}
		}
		
		return nVal;
	}
	
	private static boolean hasNconsecutiveConsonants(String substring, int n) {
		int L = substring.length();
		int numCC;
		char c;
		for (int i = 0; i <= L - n; i++) {
			numCC = 0;
			for (int j = 0; j < n; j++) {
				c = substring.charAt(i + j);
				if (isConsonant(c)) {
					if (++numCC == n)
						return true;
				} else {
					break;
				}
			}
		}
		
		return false;
	}
	
	private static char[] vowels = { 'a', 'e', 'i', 'o', 'u' };
	
	private static boolean isConsonant(char c) {
		for (int i = 0; i < vowels.length; i++) {
			if (c == vowels[i])
				return false;
		}
		
		return true;
	}

}
