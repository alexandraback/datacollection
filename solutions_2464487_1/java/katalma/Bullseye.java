package hu.hke.gjc2013.a1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Date;
import java.util.Scanner;

public class Bullseye {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//readAndSolve("resource/gcj2013/a1/bullseye/sample.in", "resource/gcj2013/a1/bullseye/sample.out");
		//readAndSolve("resource/gcj2013/a1/bullseye/A-small-attempt0.in", "resource/gcj2013/a1/bullseye/A-small-attempt0.out");
		readAndSolve("resource/gcj2013/a1/bullseye/A-large.in", "resource/gcj2013/a1/bullseye/A-large.out");
	}

	private static void readAndSolve(String inputName, String outputName) {
		BufferedReader input = null;
		BufferedWriter output = null;
		Date d1 = new Date();
		try {
			input = new BufferedReader(new FileReader(inputName));
			output = new BufferedWriter(new FileWriter(outputName));
			String line1 = null;
			int expectedCases = 0;
			int actualCase = -1;
			line1 = input.readLine();
			expectedCases = Integer.parseInt(line1);
			for (actualCase = 1; actualCase<=expectedCases; actualCase++) {
				line1 = input.readLine();
				String result = solve(line1);
				output.write("Case #" + actualCase +": " + result + "\n");	
				System.out.println("Case #" + actualCase +": " + result );
			}
			input.close();
			output.close();
			Date d2 = new Date();
			System.out.println("");
			System.out.println( d2.getTime() - d1.getTime());
		} catch (Exception e) {
			e.printStackTrace();
		} finally {

		}
	}

	private static BigInteger TWO = new BigInteger("2"); 
	private static BigInteger EIGHT = new BigInteger("8"); 
	private static BigInteger FOUR = new BigInteger("4"); 
	private static String solve(String line1) {
		Scanner sc = new Scanner(line1);
		BigInteger r = sc.nextBigInteger();
		BigInteger t = sc.nextBigInteger();
		BigInteger result = null;
		BigInteger trm1 = r.multiply(TWO).subtract(BigInteger.ONE);
		result = trm1.pow(2).add(t.multiply(EIGHT));
		result = bigIntSqRootFloor(result);
		result = result.subtract(trm1).divide(FOUR);
		return result.toString();
	}

	public static BigInteger bigIntSqRootFloor(BigInteger x)
	        throws IllegalArgumentException {
	    if (x.compareTo(BigInteger.ZERO) < 0) {
	        throw new IllegalArgumentException("Negative argument.");
	    }
	    // square roots of 0 and 1 are trivial and
	    // y == 0 will cause a divide-by-zero exception
	    if (x.equals( BigInteger.ZERO )|| x.equals( BigInteger.ONE)) {
	        return x;
	    } // end if
	    BigInteger two = BigInteger.valueOf(2L);
	    BigInteger y;
	    // starting with y = x / 2 avoids magnitude issues with x squared
	    for (y = x.divide(two);
	            y.compareTo(x.divide(y)) > 0;
	            y = ((x.divide(y)).add(y)).divide(two));
	    return y;
	} // end bigIntSqRootFloor

}
