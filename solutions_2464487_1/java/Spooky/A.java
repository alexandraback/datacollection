package r1a2013;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("A.out"));
		
		BigInteger THREE = new BigInteger("3");

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			BigInteger r = in.nextBigInteger(), m = in.nextBigInteger();
			BigInteger lo = BigInteger.ONE, hi = new BigInteger("1000000000000000000");
			while (hi.subtract(lo).compareTo(BigInteger.ONE) > 0) {
				BigInteger k = (lo.add(hi).add(BigInteger.ONE)).shiftRight(1);
				BigInteger x = k.multiply(r.shiftLeft(1).add(k.add(BigInteger.ONE).shiftLeft(1)).subtract(THREE));
				if (x.compareTo(m) <= 0) lo = k;
				else hi = k;
			}
			out.println(lo);
		}
		
		out.flush();
	}

}
