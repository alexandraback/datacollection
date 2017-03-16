/*
 * This code is meant to run under the Java Runtime Environment, version 1.7 or
 * later.
 */

package round1c.a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main0 {
	
	// This is used to work around the inability of Eclipse to use a file as
	// System.in when running a program.
	private static final String IN_FILE_NAME = "A-small-attempt0.in";
	
	private static final int OLDEST_GEN = 40;
	
	private static final BigInteger ANCESTORS_IN_OLDEST_GEN
		= BigInteger.valueOf(2).pow(OLDEST_GEN);

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE_NAME)));
		
		long numCases = in.nextLong();
		in.nextLine();
		
		for (long i = 1; i <= numCases; i++) {
			String line = in.nextLine();
//			System.out.println(line);
			String[] tokens = line.split("/");
			assert(tokens.length == 2);
			BigInteger P = new BigInteger(tokens[0]);
			BigInteger Q = new BigInteger(tokens[1]);
//			System.out.println("P: " + P + "; Q: " + Q);
			
			Integer result = solve(P, Q);
			String resultStr = (result == null) ?
				"impossible" : result.toString();
			
			System.out.println(String.format("Case #%s: %s", i, resultStr));
		}
		
		in.close();
	}
	
	private static Integer solve(BigInteger P, BigInteger Q) {
		assert(P.compareTo(Q) < 0);
		
		// Make sure the fraction is possible.
//		P.multiply(Q).mod(ANCESTORS_IN_OLDEST_GEN).equals(ZERO) {
//			
//		}
//		
		BigInteger[] divResult = P.multiply(ANCESTORS_IN_OLDEST_GEN).divideAndRemainder(Q);
		if (!divResult[1].equals(BigInteger.ZERO)) {
			return null;
		}
		
		// Determine the number of pure elf ancestors in the oldest generation.
		BigInteger numElfsInOldestGen = divResult[0]/*.multiply(P)*/;
		
		// Find the youngest generation such that the original number of pure
		// elfs is large enough for that generation to include a pure elf.
		for (int i = 1; i <= 40; i++) {
			BigInteger numOrigPureElfsRequired
				= BigInteger.valueOf(2).pow(40-i);
			if (numOrigPureElfsRequired.compareTo(numElfsInOldestGen) <= 0) {
				return i;
			}
		}
		
		// This should never be reached.
		assert(false);
		return null;
	}
}
