import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Hehe {
	
	public static void main(String[] args) {
		int N = 32;
		int J = 500;
		System.out.println("Case #1:");

		ArrayList<String> result = new ArrayList<String>();
		while (result.size() < J) {
			
			for (int i = 0; i < 1 << N-2; i++) {
				StringBuilder sb = new StringBuilder();
				sb.append(1);
				String binString = Integer.toBinaryString(i);
				
				while (binString.length() < N - 2) {
					binString = 0 + binString;
				}
				sb.append(binString);
				sb.append(1);
				
				
				
				String num = sb.toString();
				StringBuilder answer = new StringBuilder();
				answer.append(num + " ");
				boolean ok = true;
				for (int base = 2; base <= 10; base++) {
					BigInteger n = new BigInteger(num, base);
					HashMap<BigInteger, Integer> factors = PR.getFactors(n);
					
					if (factors.size() > 1 || (factors.size() == 1 && isOk(factors))) {
						for (BigInteger b : factors.keySet()) {
							answer.append(b.toString() + " ");
							break;
						}
					} else {
						ok = false;
						break;
					}
				}
				
				if (ok) {
					result.add(answer.toString().trim());
					System.out.println(answer.toString().trim());
					if (result.size() == J) break;
				}
				
			}
		}
		
	}

	private static boolean isOk(HashMap<BigInteger, Integer> factors) {
		for (BigInteger b : factors.keySet()) {
			if (factors.get(b) == 1) {
				return false;
			} else {
				return true;
			}
		}
		
		return true;
	}
}


class PR {
	private final static BigInteger ZERO = new BigInteger("0");
	private final static BigInteger ONE = new BigInteger("1");
	private final static BigInteger TWO = new BigInteger("2");
	private final static Random random = new Random();
	static HashMap<BigInteger, Integer> factors = new HashMap<BigInteger, Integer>();

	public static BigInteger rho(BigInteger N) {
		BigInteger divisor;
		BigInteger c = new BigInteger(N.bitLength(), random);
		BigInteger x = new BigInteger(N.bitLength(), random);
		BigInteger xx = x;

		// check divisibility by 2
		if (N.mod(TWO).compareTo(ZERO) == 0)
			return TWO;

		do {
			x = x.multiply(x).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			divisor = x.subtract(xx).gcd(N);
		} while ((divisor.compareTo(ONE)) == 0);

		return divisor;
	}

	public static void factor(BigInteger N) {
		if (N.compareTo(ONE) == 0)
			return;
		if (N.isProbablePrime(15)) {
			if (factors.containsKey(N)) {
				factors.put(N, factors.get(N) + 1);
			} else {
				factors.put(N,  1);
			}
			return;
		}
		BigInteger divisor = rho(N);
		factor(divisor);
		factor(N.divide(divisor));
	}

	public static HashMap<BigInteger, Integer> getFactors(BigInteger N) {
		factors.clear();
		factor(N);
		return factors;
	}

}