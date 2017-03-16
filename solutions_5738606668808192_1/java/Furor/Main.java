import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	private static ArrayList<Integer> primes;
	private static boolean[] isPrime;
	private static final int N_PRIMES = 1000;
	
	
	private static int[] checkJamCoin(int n) {
		int[] factors = new int[9];
		String binary = Integer.toBinaryString(n);
		for (int radix = 2; radix <= 10; radix++) {
			BigInteger v = new BigInteger(binary, radix);
			boolean hasDivisor = false;
			for (int i = 0; i < primes.size(); i++) {
				if (v.mod(BigInteger.valueOf(primes.get(i))).intValue() == 0) {
					hasDivisor = true;
					factors[radix - 2] = primes.get(i);
					break;
				}
			}
			if (! hasDivisor)
				return null;
		}
		return factors;
	}

	public static void main(String[] args) {
		int i, j, t, n, m;
		primes = new ArrayList<Integer>();
		isPrime = new boolean[N_PRIMES];
		for (i = 0; i < N_PRIMES; i++)
			isPrime[i] = true;
		for (i = 2; i < N_PRIMES; i++) {
			if (isPrime[i]) {
				primes.add(i);
				for (j = 2 * i; j < N_PRIMES; j += i)
					isPrime[j] = false;
			}
		}
		Scanner in = new Scanner(System.in);
		t = in.nextInt();
		n = in.nextInt();
		m = in.nextInt();
		int[] coins = new int[m];
		int[][] factors = new int[m][];
		int found = 0;
		for (int mid = 0; found < m; mid++) {
			int test = (mid << 1) | 1 | (1 << (n - 1));
			int[] factorsHere = checkJamCoin(test);
			if (factorsHere != null) {
				coins[found] = test;
				factors[found] = factorsHere;
				found++;
			}
		}
		System.out.println("Case #1:");
		for (i = 0; i < m; i++) {
			System.out.print(Integer.toBinaryString(coins[i]));
			for (j = 0; j < factors[i].length; j++)
				System.out.print(" " + factors[i][j]);
			System.out.println();
		}
		in.close();
	}

}
