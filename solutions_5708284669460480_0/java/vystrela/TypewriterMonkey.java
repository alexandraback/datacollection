package com.google.TypewriterMonkey;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TypewriterMonkey {
	
	static String largeString = "";

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));

		int numCases = Integer.parseInt(br.readLine());

		for (int i = 0; i < numCases; i++) {
			solve(br, i + 1);
		}

	}

	private static void solve(BufferedReader br, int i) throws IOException {

		String[] KLS = br.readLine().split(" ");
		
		int K = Integer.parseInt(KLS[0]);
		int L = Integer.parseInt(KLS[1]);
		int S = Integer.parseInt(KLS[2]);
		
		String alphabet = br.readLine();
		
		String target = br.readLine();
		
		boolean canFeasiblyTypeWord = true;
		
		for (char c : target.toCharArray()) {
			if (!alphabet.contains("" + c)) {
				canFeasiblyTypeWord = false;
				break;
			}
		}
		
		if (!canFeasiblyTypeWord) {
			System.out.println("Case #" + i + ": 0");
			return;
		}
		
		int[] freq = new int[26];
		
		for (char j = 'A'; j < 'Z'; j++) {
			int numChars = alphabet.length() - alphabet.replaceAll("" + j, "").length();
			freq[j - 'A'] += numChars;
		}
		
		int numBananasToTake = maxStringsInLength(target, S);
		
		int minAlphabetLength = 0;
		for (int j = 0; j < 26; j++) {
			if (freq[j] > 0) minAlphabetLength++;
		}
		
		int[] alphabetIndex = new int[minAlphabetLength];
		int indexA = 0;
		int indexB = 0;
		while (indexA < minAlphabetLength) {
			if (freq[indexB] > 0) {
				alphabetIndex[indexA] = indexB;
				indexA++;
			}
			indexB++;
		}
		
		float bananasToGive = 0;

		StringBuilder sb = new StringBuilder();
		for (int j = 0; j < Math.pow(minAlphabetLength, S); j++) {
			sb.delete(0, S);
			float chanceOf = 1.0f;
			for (int k = 0; k < S - 1; k++) {
				int column = (int) Math.pow(minAlphabetLength, S - k - 1);
				int m = (j / column) % minAlphabetLength;
				sb.append((char) ('A' + alphabetIndex[m]));
				chanceOf *= freq[alphabetIndex[m]] / (1.0f * alphabet.length());
			}
			int m = j % minAlphabetLength;
			sb.append((char) ('A' + alphabetIndex[m]));
			chanceOf *= freq[alphabetIndex[m]] / (1.0f * alphabet.length());
			
			bananasToGive += (chanceOf * instancesOf(sb.toString(), target));
		}
		
//		float likelihood = 1.0f * numBananasToTake;
//		
//		String ls = largeString;
//		
//		for (char c : ls.toCharArray()) {
//			double chance = freq[c - 'A'] / (1.0 * alphabet.length());
//			likelihood *= chance;
//			if (likelihood < 0.000001) {
//				System.out.println("Case #" + i + ": 0");
//				return;
//			}
//		}
//		
		System.out.println("Case #" + i + ": " + (numBananasToTake - bananasToGive));

		return;
	}
	
	static int instancesOf (String finalString, String target) {
		int retVal = 0;
		for (int i = 0; i < finalString.length() - target.length() + 1; i++) {
			if (finalString.substring(i).startsWith(target)) 
				retVal++;
		}
		
		return retVal;
	}
	
	static int maxStringsInLength(String str, int length) {
		for (int i = 1; i <= str.length(); i++) {
			String finalString = str.substring(0, i) + str;
			if (instancesOf(finalString, str) == 2) {
				int k = ((length - finalString.length()) / (finalString.length() - str.length()));
				
				StringBuilder sb = new StringBuilder();
				
				for (int j = 0; j < k; j++) {
					sb.append(str.substring(0, i));
				}
				
				sb.append(finalString);
				
				largeString = sb.toString();
				
				return k + 2;
			}
		}
		return 0;
	}

}
