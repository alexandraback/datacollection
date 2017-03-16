import java.util.Scanner;
import java.math.BigInteger;

public class Bullseye2 {
	static BigInteger BIG1 = BigInteger.ONE;
	static BigInteger BIG2 = BigInteger.valueOf(2);
	static BigInteger BIG4 = BigInteger.valueOf(4);
	static BigInteger BIG8 = BigInteger.valueOf(8);
	
	public static void main(String[]Z) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int N = 1; N <= T; N++) {
			long r = in.nextLong();
			long t = in.nextLong();
			
			BigInteger bigr = new BigInteger(""+r);
			BigInteger bigt = new BigInteger(""+t);
			
			// prevent overflow
			BigInteger inside = bigr.pow(2).multiply(BIG4)
					.subtract(bigr.multiply(BIG4))
					.add(bigt.multiply(BIG8))
					.add(BIG1);
			
			BigInteger k = isqrt(inside, inside)
					.subtract(bigr.multiply(BIG2))
					.add(BIG1)
					.divide(BIG4);
			
			
			//long k = (long) (Math.sqrt(4*r*r - 4*r + 8*t + 1) - 2*r + 1) / 4;
			
			System.out.printf("Case #%d: %s\n", N, k);
		}
	}
	
	static BigInteger isqrt(BigInteger n, BigInteger x) {
		BigInteger next = x.add(n.divide(x)).divide(BigInteger.valueOf(2));
		
		if (next.subtract(x).abs().compareTo(BigInteger.ONE) < 0) {
			return next;
		} else {
			return isqrt(n, next);
		}
	}
}
