package codejam.quali_round_2016;

import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

import codejam.util.Helper;

/**
 * Coin Jam
 */
public class C {

	private static String solve(int N, int J) {
		int validCount = 0;
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<Math.pow(2, N-2) && validCount<J; i++) {
			String jamcoin = String.format("1%0" + (N-2) + "d1", Integer.parseInt(Integer.toString(i, 2)));
			boolean isValid = true;
			StringBuilder lineBuffer = new StringBuilder();
			lineBuffer.append(jamcoin);
			for (int base=2; isValid && base<=10; base++) {
				BigInteger num = new BigInteger(jamcoin, base);
				BigInteger nonTrivialDivisor = getNonTrivialDivisor(num);
				if (nonTrivialDivisor != null) {
					lineBuffer.append(" " + nonTrivialDivisor);
				} else {
					isValid = false;
					break;
				}
			}
			if (isValid) {
				if (sb.length() > 0) {
					sb.append('\n');
				}
				sb.append(lineBuffer);
				validCount++;
			}
		}
		return sb.toString();
	}
	
	
	
	private static BigInteger getNonTrivialDivisor(BigInteger n) {
		long[] primes = {2, 3, 5, 7};
		for (int i=0; i<primes.length; i++) {
			if (BigInteger.ZERO.equals(n.remainder(BigInteger.valueOf(primes[i]))))
				return BigInteger.valueOf(primes[i]);
		}
		for (long i=12; i<Math.sqrt(n.doubleValue()); i+=6) {
			if (BigInteger.ZERO.equals(n.remainder(BigInteger.valueOf(i-1)))) {
				return BigInteger.valueOf(i-1);
			} else if (BigInteger.ZERO.equals(n.remainder(BigInteger.valueOf(i+1)))) {
				return BigInteger.valueOf(i+1);
			}
		}
		return null;
	}
	
	public static void main(String[] args) {
		Helper helper = new Helper(C.class, args);
		try (Scanner sc = helper.getScanner(); PrintStream out = helper.getPrintStream()) {
			int T = sc.nextInt();
			for (int i=0; i<T; i++) {
				int N = sc.nextInt(), J = sc.nextInt();
				String result = solve(N, J);
				out.printf("Case #%d:%n%s%n", i+1, result);
			}
		}
	}
}
