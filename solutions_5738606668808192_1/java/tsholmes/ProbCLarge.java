package qual;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;

public class ProbCLarge {
	
	private static BigInteger convert(long num, int base) {
		BigInteger res = BigInteger.ZERO;
		BigInteger mult = BigInteger.ONE;
		BigInteger BASE = BigInteger.valueOf(base);
		while (num > 0) {
			if ((num & 1) == 1) {
				res = res.add(mult);
				mult = mult.multiply(BASE);
			}
			num >>= 1;
		}
		return res;
	}
	
	private static BigInteger factor(BigInteger num, List<BigInteger> factors) {
		for (BigInteger f : factors) {
			if (num.mod(f).equals(BigInteger.ZERO)) {
				return f;
			}
		}
		return null;
	}
	
	public static void main(String[] args) throws Exception {
		List<BigInteger> primes = new ArrayList<BigInteger>();
		primes.add(BigInteger.valueOf(2));
		
		for (long i = 3; i < (2 << 10); i += 2) {
			boolean isp = true;
			BigInteger I = BigInteger.valueOf(i);
			for (BigInteger p : primes) {
				if (p.multiply(p).compareTo(I) > 0) break;
				if (I.mod(p).equals(BigInteger.ZERO)) {
					isp = false;
					break;
				}
			}
			if (isp) primes.add(I);
		}
		
		int count = 0;
		Random r = new Random();
		Set<Long> visited = new HashSet<Long>();
		while (count < 500) {
			long num = r.nextInt() & ((1l << 31) - 1);
			num = (1l << 31) | (num << 1) | 1;
			if (visited.contains(num)) {
				continue;
			}
			visited.add(num);
			boolean valid = true;
			List<BigInteger> factors = new ArrayList<BigInteger>();
			for (int base = 2; base <= 10; base++) {
				BigInteger f = factor(convert(num, base), primes);
				if (f != null) {
					factors.add(f);
				} else {
					valid = false;
					break;
				}
			}
			if (valid) {
				System.out.print(Long.toBinaryString(num));
				for (BigInteger f : factors) {
					System.out.print(" " + f.toString());
				}
				System.out.println();
				count++;
			}
		}
	}
}
