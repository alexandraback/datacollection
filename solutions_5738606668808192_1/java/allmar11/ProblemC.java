package round0;

import java.io.BufferedReader;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class ProblemC {
	
	// Workaround for not being able to pipe a file to stdin in Eclipse.
	private static final String IN_FILE = "text/C-large.in";
	
	private static final int PRIMES_LIMIT = 1000000;
	
	private static final BigInteger[] PRIMES;
	static {
		PrimeInfo primesInfo = computePrimes(PRIMES_LIMIT);
		PRIMES = Arrays.stream(primesInfo.primes).mapToObj(i -> BigInteger.valueOf(i))
				.toArray(BigInteger[]::new);
	}
	
	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE)))) {
			int numCases = in.nextInt();
			for (int i = 0; i < numCases; i++) {
				int numDigits = in.nextInt();
				int numCoins = in.nextInt();
				
				String resultStr = solve(numDigits, numCoins, PRIMES);
				
				System.out.println(String.format("Case #%s:\n%s", i+1, resultStr));
			}
		}
	}
	
	private static String solve(int numDigits, int numCoins, BigInteger[] primes) {
		long startNum = (1L << (((long) numDigits) - 1)) + 1;
		long endNum = (1L << (numDigits + 1)) - 1;
		
		int numFound = 0;
		long[] coins = new long[numCoins];
		BigInteger[][] factors = new BigInteger[numCoins][];
		for (long num = startNum; num <= endNum; num += 2) {
			
			BigInteger[] numCheck = coinCheck(num, primes);
			if (numCheck != null) {
				coins[numFound] = num;
				factors[numFound] = numCheck;
				numFound++;
				
				if (numFound == numCoins) {
					StringBuilder result = new StringBuilder();
					for (int i = 0; i < numCoins; i++) {
						result.append(Long.toString(coins[i], 2));
						for (int j = 2; j <= 10; j++) {
							result.append(" ");
							result.append(factors[i][j-2]);
						}
						result.append("\n");
					}
					
					return result.toString();
				}
			}
		}
		
		return "FAILED";
	}
	
	/*
	 * Returns null if number could not be determined to be a jamcoin.
	 */
	private static BigInteger[] coinCheck(long coin, BigInteger[] primes) {
		String coinStr = Long.toString(coin, 2);
		BigInteger[] result = new BigInteger[9];
		
		for (int base = 2; base <= 10; base++) {
			BigInteger num = new BigInteger(coinStr, base);
			BigInteger factor = lookForFactor(num, primes);
			if (factor == null) {
				return null;
			}
			result[base-2] = factor;
		}
		
		return result;
	}
	
	private static BigInteger lookForFactor(BigInteger num, BigInteger[] primes) {
		// For the sake of computation time, only check some of the possible factors.
		for (BigInteger factor : primes) {
			if (factor.equals(num)) {
				return null;
			}
			if (num.mod(factor).equals(BigInteger.ZERO)) {
				return factor;
			}
		}
		
		return null;
	}
	
	private static PrimeInfo computePrimes(int limit) {
		boolean[] isPrime = new boolean[limit+1];
		int[] factors = new int[limit+1];
		isPrime[0] = false;
		isPrime[1] = false;
		factors[0] = 0;
		factors[1] = 1;
		for (int i = 2; i <= limit; i++) {
			isPrime[i] = true;
		}
		
		// Prime sieve.
		for (int next = 2; next * next <= limit; next += 2) {
			if (isPrime[next]) {
				factors[next] = next;
				for (int multiple = next * 2; multiple <= limit; multiple += next) {
					if (isPrime[multiple]) {
						isPrime[multiple] = false;
						factors[multiple] = next;
					}
				}
			}
		}
		
		return new PrimeInfo(isPrime, factors);
	}

	private static class PrimeInfo {
		public boolean[] isPrime;
		public int[] factors;
		
		public int[] primes;
		
		public PrimeInfo(boolean[] isPrime, int[] factors) {
			this.isPrime = isPrime;
			this.factors = factors;
			
			List<Integer> primesList = new ArrayList<>();
			for (int i = 0; i < isPrime.length; i++) {
				if (isPrime[i]) {
					primesList.add(i);
				}
			}
			this.primes = primesList.stream().mapToInt(i -> i).toArray();
		}
	}
}
