import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static final int SIEVE_SIZE = 1000 * 1000;
	public static final boolean[] IS_PRIME = new boolean[SIEVE_SIZE];
	public static final ArrayList<Integer> PRIMES = new ArrayList<Integer>();

	public static boolean isPrime(long p) {
		if (p < SIEVE_SIZE) {
			return IS_PRIME[(int) p];
		}
		return BigInteger.valueOf(p).isProbablePrime(20);
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		if (false) {
			System.setIn(new FileInputStream("input.txt"));
			System.setOut(new PrintStream("output.txt"));
		}
		
		for (int i = 0; i < SIEVE_SIZE; i++) IS_PRIME[i] = true;
		for (int i = 2; i * i < SIEVE_SIZE; i++) {
			if (IS_PRIME[i]) {
				for (int j = i * i; j < SIEVE_SIZE; j += i) {
					IS_PRIME[j] = false;
				}
			}
		}
		for (int i = 2; i < SIEVE_SIZE; i++) {
			if (IS_PRIME[i]) {
				PRIMES.add(i);
			}
		}

//		int t = 1, n = 16, j = 50;
//		int t = 1, n = 16, j = 50;
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt(), n = sc.nextInt(), j = sc.nextInt();

		System.out.println("Case #1:");

		long number = 1L + (1L << (n - 1));
		long limit = 1L << n;
//		System.out.println(number + " " + limit);

		long[] bases = new long[11], divs = new long[11];
		bases[10] = -1;
		for (long candidate = number; candidate < limit; candidate += 2) {
			if (isPrime(candidate)) {
				continue;
			}
			bases[2] = candidate;
			for (int b = 3; b <= 10; b++) {
				long num = candidate, base = 0, conv = 1;
				while (num > 0) {
					if ((num & 1) != 0) base += conv;
					num /= 2;
					conv *= b;
				}
				if (isPrime(base)) break;
				bases[b] = base;
			}
			if (bases[10] == -1) continue;

			boolean valid = true;
			for (int b = 2; b <= 10; b++) {
				long num = bases[b];
				divs[b] = -1;
				for (int i = 0; i < PRIMES.size(); i++) {
					if (num % PRIMES.get(i) == 0) {
						divs[b] = PRIMES.get(i);
						break;
					}
				}
				if (divs[b] == -1) {
					valid = false;
					break;
				}
			}
			if (!valid) continue;
			
			System.out.print(bases[10]);
			for (int b = 2; b <= 10; b++) {
				System.out.print(" " + divs[b]);
			}
			System.out.println();
			
			bases[10] = -1;
			if (--j <= 0) break;
		}
		if (j != 0) {
			System.err.println("Not completely done!");
		}
	}
}
