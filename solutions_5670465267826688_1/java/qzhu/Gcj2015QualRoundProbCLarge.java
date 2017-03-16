/* 
 * Google Code Jam - 2015 - Qualification Round - Problem C "Dijkstra"
 * Solution for large input by Qiyu Zhu
 */

import java.util.Scanner;
import java.util.zip.DataFormatException;


public class Gcj2015QualRoundProbCLarge {
	
	public static void main(String[] args) throws DataFormatException {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %s%n", i + 1, handleCase(in) ? "YES" : "NO");
	}
	
	
	private static boolean handleCase(Scanner in) throws DataFormatException {
		// Read input
		BigString bigStr;
		int blockLen = in.nextInt();
		{
			long reps = in.nextLong();
			String str = in.next();
			if (str.length() != blockLen)
				throw new DataFormatException();
			bigStr = new BigString(str, reps);
		}
		
		// Find shortest prefix that multiplies to i, but only search up to a certain point (otherwise things just repeat)
		int prefixLen = 0;
		byte product = 0;
		while (product != 2 && prefixLen < bigStr.length() && prefixLen < blockLen * 4) {
			product = MULTIPLICATION_TABLE[product][charToQuaternion(bigStr.charAt(prefixLen))];
			prefixLen++;
		}
		if (product != 2)
			return false;
		
		// Find shortest suffix that multiplies to k (with same caveat on search range)
		int suffixLen = 0;
		product = 0;
		while (product != 6 && suffixLen + prefixLen < bigStr.length() && suffixLen < blockLen * 4) {
			product = MULTIPLICATION_TABLE[charToQuaternion(bigStr.charAt(bigStr.length() - 1 - suffixLen))][product];
			suffixLen++;
		}
		if (product != 6)
			return false;
		
		// Multiply the rest of the middle
		return product(bigStr, prefixLen, bigStr.length() - suffixLen) == 4;
	}
	
	
	private static byte product(BigString bigStr, long start, long end) {
		if (!(0 <= start && start <= end && end <= bigStr.length()))
			throw new IndexOutOfBoundsException();
		
		byte product = 0;
		int blockLen = bigStr.string.length();
		long i = start;
		for (; i < end && i % blockLen != 0; i++)  // Multiply rest of current block
			product = MULTIPLICATION_TABLE[product][charToQuaternion(bigStr.charAt(i))];
		if (i == end)
			return product;
		
		int numBlocks = (int)((end - i) / blockLen % 4);  // We can modulo by 4 because {any member of our 8 unit quaternions} to the power of 4 is equal to 1
		for (int j = 0; j < blockLen * numBlocks; j++)
			product = MULTIPLICATION_TABLE[product][charToQuaternion(bigStr.charAt(j))];
		
		i = end / blockLen * blockLen;  // Multiply the head of the block containing the suffix
		for(; i < end; i++)
			product = MULTIPLICATION_TABLE[product][charToQuaternion(bigStr.charAt(i))];
		return product;
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
	
	
	
	private static final class BigString {
		
		public final String string;
		public final long repetitions;
		
		
		public BigString(String string, long repetitions) {
			if (string == null)
				throw new NullPointerException();
			if (string.length() == 0 || repetitions <= 0 || Long.MAX_VALUE / repetitions < string.length())
				throw new IllegalArgumentException();
			this.string = string;
			this.repetitions = repetitions;
		}
		
		
		public long length() {
			return string.length() * repetitions;  // Does not overflow
		}
		
		
		public char charAt(long index) {
			if (index < 0 || index >= length())
				throw new IndexOutOfBoundsException();
			return string.charAt((int)(index % string.length()));
		}
		
	}
	
}
