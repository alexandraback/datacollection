package gcj2015.round1C.problemB;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public abstract class Main1C_B {
	
	private static final String IN_NAME = "B-small-attempt2";

	public static void main(String[] args) throws Exception {
		// Open input and output files. (stdin and stdout are not used because
		// of the lack of support for using a file as stdin in Eclipse.)
		InputStream inStream = new FileInputStream(
			String.format("input/%s.in", IN_NAME));
		OutputStream outStream = new FileOutputStream(
			String.format("output/%s-out.txt", IN_NAME));
		
		Scanner in = new Scanner(new BufferedInputStream(inStream));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(outStream));
		
		int numCases = in.nextInt();
		for (int caseIdx = 1; caseIdx <= numCases; caseIdx++) {
			
			// Read the test case.
			int numKeys = in.nextInt();
			int goalLength = in.nextInt();
			int bufferSize = in.nextInt();
			in.nextLine();
			String keys = in.next();
			String target = in.next();
			
			// Solve this test case;
			double result = solve(keys, target, bufferSize);
			
			// Print the result.
			String resultStr = String.format("%.10f", result);
			String fullResultStr = String.format("Case #%s: %s", caseIdx,
				resultStr);
			out.println(fullResultStr);
			System.out.println(fullResultStr);
		}
		
		in.close();
		out.close();
	}
	
	private static double solve(String keys, String target, int bufferSize) {
		if (target.length() > bufferSize) {
			return 0;
		}
		
		double[] distr = keysToDistr(keys);
		
		for (int i = 0; i < target.length(); i++) {
			if (distr[letterToIdx(target.charAt(i))] == 0) {
				return 0;
			}
		}
		
		int numOverlap = computeNumFree(target, target);
		
		int maxHits = computeMaxHits(target, bufferSize, numOverlap);
		
		Double[][] memoTable = new Double[bufferSize + 1][target.length()];
		
		double expectedHits = getExpectedHits(distr, target, numOverlap,
			bufferSize, 0, memoTable);
		
		return maxHits - expectedHits;
	}
	
	private static double[] keysToDistr(String keys) {
		double[] result = new double[26];
		for (int i = 0; i < keys.length(); i++) {
			char c = keys.charAt(i);
			result[letterToIdx(c)] += 1.0 / keys.length();
		}
		
		return result;
	}
	
	private static char idxToLetter(int idx) {
		return (char) ((int) 'A' + idx);
	}
	
	private static int letterToIdx(char letter) {
		return letter - 'A';
	}
	
	private static int computeMaxHits(String target, int bufferSize,
		int numOverlap)
	{
		assert(target.length() <= bufferSize);
		
		int remainingAfterFirst = bufferSize - target.length();
		int spacesNeededAfterFirst = target.length() - numOverlap;
		
		return 1 + remainingAfterFirst / spacesNeededAfterFirst;
	}
	
	private static double getExpectedHits(double[] distr, String goal,
		int numOverlap, int spacesLeft, int free, Double[][] memoTable)
	{
		if (free + spacesLeft < goal.length()) {
			return 0;
		}
		
		if (memoTable[spacesLeft][free] == null) {
			double result = 0;
			
			// Handle the case where the next letter is the one we want.
			int nextRightIdx = letterToIdx(goal.charAt(free));
			double chanceNextRight = distr[nextRightIdx];
			if (free < goal.length() - 1) {
				result += chanceNextRight * getExpectedHits(distr, goal,
					numOverlap, spacesLeft - 1, free + 1, memoTable);
			}
			else {
				result += chanceNextRight * (1 + getExpectedHits(distr, goal,
					numOverlap, spacesLeft - 1, numOverlap, memoTable));
			}
			
			// Handle the case where the next letter isn't what we want.
			for (int idx = 0; idx < distr.length; idx++) {
				double chance = distr[idx];
				if (idx != nextRightIdx && chance > 0) {
					StringBuilder prefix = new StringBuilder(
						goal.substring(0, free));
					prefix.append(idxToLetter(idx));
					
					result += chance * getExpectedHits(distr, goal, numOverlap,
						spacesLeft - 1, computeNumFree(prefix.toString(), goal),
						memoTable);
				}
			}
			
			memoTable[spacesLeft][free] = result;
		}
		
		return memoTable[spacesLeft][free];
	}
	
	private static int computeNumFree(String prefix, String goal) {
//		int numFree = 0;
//		
//		while (numFree < goal.length() - 1) {
//			if (goal.substring(0, numFree + 1).equals(
//				prefix.substring(prefix.length() - (numFree + 1),
//				prefix.length())))
//			{
//				numFree++;
//			}
//			else {
//				break;
//			}
//		}
//		
//		return numFree;
		
		int result = 0;
		for (int numFree = 1;
			numFree < Math.min(goal.length(), prefix.length() + 1);
			numFree++)
		{
			if (goal.substring(0, numFree).equals(prefix.substring(
					prefix.length() - numFree, prefix.length())))
			{
				result = numFree;
			}
		}
		
		return result;
	}
}