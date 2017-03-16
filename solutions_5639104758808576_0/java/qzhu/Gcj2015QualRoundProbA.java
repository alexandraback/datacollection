/* 
 * Google Code Jam - 2015 - Qualification Round - Problem A "Standing Ovation"
 * Solution for large input by Qiyu Zhu
 */

import java.util.Scanner;
import java.util.zip.DataFormatException;


public class Gcj2015QualRoundProbA {
	
	public static void main(String[] args) throws DataFormatException {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %d%n", i + 1, handleCase(in));
	}
	
	
	private static int handleCase(Scanner in) throws DataFormatException {
		// Read input and convert format
		int maxShy = in.nextInt();
		String shyStr = in.next();
		if (shyStr.length() != maxShy + 1)
			throw new DataFormatException();
		int[] numShy = new int[shyStr.length()];
		for (int i = 0; i < numShy.length; i++)
			numShy[i] = shyStr.charAt(i) - '0';
		
		for (int i = 0; ; i++) {
			if (isStandingOvation(numShy, i))
				return i;
		}
	}
	
	
	private static boolean isStandingOvation(int[] numShy, int extraPeople) {
		int standing = extraPeople;
		for (int i = 0; i < numShy.length; i++) {
			if (standing < i && numShy[i] > 0)
				return false;
			else
				standing += numShy[i];
		}
		return true;
	}
	
}
