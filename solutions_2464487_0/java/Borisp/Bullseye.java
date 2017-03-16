import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Bullseye {
	private static final BigInteger TWO = new BigInteger("2");
	private static final BigInteger THREE = new BigInteger("3");
	private static BigInteger makeFormula(BigInteger k, BigInteger t, BigInteger r) {
		BigInteger temp = TWO.multiply(k).multiply(k);
		temp = temp.add(k.multiply(TWO.multiply(r).subtract(BigInteger.ONE)));
		temp = temp.subtract(t);
		return temp;
	}
	public static void main(String[] args) throws IOException {
		File intput = new File("google.in");
		File output = new File("google.out");
		Scanner sc = new Scanner(intput);
		FileWriter outputBuffer = new FileWriter(output);
		BufferedWriter out = new BufferedWriter(outputBuffer);
		int numTests;
		numTests = sc.nextInt();
//		System.out.println(makeFormula(BigInteger.ONE, BigInteger.TEN, BigInteger.ONE));
//		System.out.println(makeFormula(TWO, BigInteger.TEN, BigInteger.ONE));
//		System.out.println(makeFormula(THREE, new BigInteger("40"), new BigInteger("3")));
		for(int o = 0; o < numTests; o++)
		{
			out.write("Case #" + (o + 1) + ": ");
			BigInteger t, r;
			r = sc.nextBigInteger();
			t = sc.nextBigInteger();
			
			BigInteger step = new BigInteger("" + (1L << 62));
			BigInteger cur = BigInteger.ZERO;
			while (step.compareTo(BigInteger.ZERO) > 0) {
				cur = cur.add(step);
				if (makeFormula(cur, t, r).compareTo(BigInteger.ZERO) > 0) {
					cur = cur.subtract(step);
				}
				step = step.divide(TWO);
			}
			out.write("" + cur);
			out.write("\n");
		}
		out.flush();
		out.close();
	}
}
