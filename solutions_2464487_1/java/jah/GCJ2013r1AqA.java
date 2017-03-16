package gcj;

import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

/*
 * 5
1 9
1 10
3 40
1 1000000000000000000
10000000000000000 1000000000000000000


Output
 
Case #1: 1
Case #2: 2
Case #3: 3
Case #4: 707106780
Case #5: 49
 */
public class GCJ2013r1AqA {
	public static void main(String[] args) throws Exception {
		final String FILE_DIR = "/Users/jhorwitz/Downloads/";
		File inFile = new File(FILE_DIR + "A-large.in");
		File outFile = new File(FILE_DIR + "gcj2013-r1-qA-l.txt");
		Writer w = new FileWriter(outFile);
		Scanner s = new Scanner(inFile);

		int T = s.nextInt();
		for (int testCaseNum = 1; testCaseNum <= T; ++testCaseNum) {

			long r = s.nextLong();
			long t = s.nextLong();
//			long n = (long)((-2*r + 1 + Math.sqrt(4*r*r - 4*r + 8*t + 1))/4);
//			long n = (long)((-2*r + 1 + Math.sqrt(r)*Math.sqrt(4*r - 4 + 8.0*t/r + 1.0/r))/4);

			BigInteger bir = BigInteger.valueOf(r);
			BigInteger bit = BigInteger.valueOf(t);
			BigInteger radicand = bir.multiply(bir).multiply(BigInteger.valueOf(4L))
							.subtract(bir.multiply(BigInteger.valueOf(4L)))
							.add(bit.multiply(BigInteger.valueOf(8L)))
							.add(BigInteger.ONE);
			BigInteger sqrt = sqrt(radicand);
			BigInteger bin = (bir.multiply(BigInteger.valueOf(-2L)).add(BigInteger.ONE).add(sqrt))
					.divide(BigInteger.valueOf(4L));

//			output(w, testCaseNum, String.valueOf(n));
			output(w, testCaseNum, String.valueOf(bin));
		}
		s.close();
		w.close();
	}

	public static BigInteger sqrt(BigInteger x) {
		if (x == BigInteger.ZERO || x == BigInteger.ONE) return x;

		BigInteger two = BigInteger.valueOf(2L);
		BigInteger retVal = x.divide(two);

		while (retVal.compareTo(x.divide(retVal)) > 0) retVal = ((x.divide(retVal)).add(retVal)).divide(two);

		return retVal;
	}

	public static void output(Writer w, int t, String s) throws IOException {
		w.write("Case #" + t + ": " + s + "\n");
		System.out.println("Case #" + t + ": " + s);
	}
}