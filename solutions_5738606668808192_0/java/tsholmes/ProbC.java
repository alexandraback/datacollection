package qual;

import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

public class ProbC {
	
	private static List<Long> genPrimes(List<Long> existing, long start, long end) {
		if ((start & 1) != 1) start++;
		
		List<Long> result = new ArrayList<Long>();
		
		for (long i = start; i <= end; i += 2) {
			boolean isp = true;
			for (long prime : existing) {
				if (prime * prime > i) break;
				if ((i % prime) == 0) {
					isp = false;
					break;
				}
			}
			if (isp) {
				result.add(i);
			}
		}
		return result;
	}
	
	private static long convert(long num, long base) {
		long mult = 1;
		long res = 0;
		while (num > 0) {
			if ((num & 1) == 1) {
				res += mult;
			}
			num >>= 1;
			mult *= base;
		}
		return res;
	}
	
	private static long isPrime(long num, List<Long> primes) {
		do {
			long last = primes.get(primes.size()-1);
			if (last * last > num) {
				break;
			}
			primes.addAll(genPrimes(primes, last + 1, last * 2));
		} while (true);
		for (long prime : primes) {
			if (prime * prime > num) {
				return 0;
			}
			if ((num % prime) == 0) {
				return prime;
			}
		}
		return 0;
	}
	
	public static void main(String[] args) {
		int N = 16;
		int J = 50;
		
		List<Long> smalls = new ArrayList<Long>();
		smalls.add(2L);
		smalls.addAll(genPrimes(smalls, 3, (1 << (N / 2 + 1))));
		
		long start = (1l << (N - 1)) + 1;
		
		int found = 0;
		
		long p = start;
		
		while (found < J) {
			if (isPrime(p, smalls) == 0) {
				p += 2;
				continue;
			}
			List<Long> factors = new ArrayList<Long>();
			boolean valid = true;
			for (int base = 2; base <= 10; base++) {
				long np = convert(p, base);
				long factor = isPrime(np, smalls);
				if (factor == 0) {
					valid = false;
					break;
				}
				factors.add(factor);
			}
			if (valid) {
				System.out.print(Long.toBinaryString(p));
				for (long f : factors) {
					System.out.print(" " + f);
				}
				System.out.println();
				System.out.flush();
				found++;
			}
			p += 2;
		}
	}
}
