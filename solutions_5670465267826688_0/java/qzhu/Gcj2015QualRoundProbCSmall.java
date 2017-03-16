/* 
 * Google Code Jam - 2015 - Qualification Round - Problem C "Dijkstra"
 * Solution for small input by Qiyu Zhu
 */

import java.util.Scanner;
import java.util.zip.DataFormatException;


public class Gcj2015QualRoundProbCSmall {
	
	public static void main(String[] args) throws DataFormatException {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %s%n", i + 1, handleCase(in) ? "YES" : "NO");
	}
	
	
	private static boolean handleCase(Scanner in) throws DataFormatException {
		// Read input
		int len = in.nextInt();
		int reps = in.nextInt();
		String str = in.next();
		if (str.length() != len)
			throw new DataFormatException();
		
		// Apply string repetitions
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < reps; i++)
			sb.append(str);
		str = sb.toString();
		
		// Find shortest prefix that multiplies to i
		int prefixLen = 0;
		byte product = 0;
		while (product != 2 && prefixLen < str.length()) {
			product = MULTIPLICATION_TABLE[product][charToQuaternion(str.charAt(prefixLen))];
			prefixLen++;
		}
		if (prefixLen == str.length())
			return false;
		
		// Find shortest suffix that multiplies to k
		int suffixLen = 0;
		product = 0;
		while (product != 6 && suffixLen + prefixLen < str.length()) {
			product = MULTIPLICATION_TABLE[charToQuaternion(str.charAt(str.length() - 1 - suffixLen))][product];
			suffixLen++;
		}
		if (prefixLen + suffixLen == str.length())
			return false;
		
		// Multiply the rest of the middle
		product = 0;
		for (int i = prefixLen; i < str.length() - suffixLen; i++)
			product = MULTIPLICATION_TABLE[product][charToQuaternion(str.charAt(i))];
		return product == 4;
	}
	
	
	private static byte charToQuaternion(char c) {
		switch (c) {
			case 'i':  return 2;
			case 'j':  return 4;
			case 'k':  return 6;
			default:   throw new IllegalArgumentException();
		}
	}
	
	
	// MULTIPLICATION_TABLE[x][y] is represents x * y.
	// The possible values are: 0 = 1, 1 = -1, 2 = i, 3 = -i, 4 = j, 5 = -j, 6 = k, 7 = -k.
	private static byte[][] MULTIPLICATION_TABLE = {
		{0, 1, 2, 3, 4, 5, 6, 7},
		{1, 0, 3, 2, 5, 4, 7, 6},
		{2, 3, 1, 0, 6, 7, 5, 4},
		{3, 2, 0, 1, 7, 6, 4, 5},
		{4, 5, 7, 6, 1, 0, 2, 3},
		{5, 4, 6, 7, 0, 1, 3, 2},
		{6, 7, 4, 5, 3, 2, 1, 0},
		{7, 6, 5, 4, 2, 3, 0, 1},
	};
	
}
