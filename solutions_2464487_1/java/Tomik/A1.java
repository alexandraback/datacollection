package round1a;

import java.math.BigInteger;
import java.util.Scanner;

public class A1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			BigInteger r = sc.nextBigInteger();
			BigInteger t = sc.nextBigInteger();
			
			BigInteger d = BigInteger.ZERO;
			BigInteger u = new BigInteger("10000000000");
			
			BigInteger bv = BigInteger.ZERO;
			while (d.compareTo(u) <= 0) {
				BigInteger m = d.add(u).divide(BigInteger.valueOf(2)); //(d+u) / 2;
				BigInteger tmp = r.multiply(BigInteger.valueOf(2)).add(BigInteger.ONE).multiply(m.add(BigInteger.ONE))
						.add( m.multiply(m.add(BigInteger.ONE)).divide(BigInteger.valueOf(2)).multiply(BigInteger.valueOf(4)) );
						// (2*r+1)*(m+1) + 4*((m*(m+1))/2) 
				if (tmp.compareTo(t) <= 0) {
					BigInteger tmp2 = m.add(BigInteger.ONE);
					if (tmp2.compareTo(bv) > 0) {
						bv = tmp2;
					}
					d = tmp2;
				} else {
					u = m.subtract(BigInteger.ONE);
				}
			}
			
			System.out.println("Case #" + i + ": " + bv);
		}
	}

}
