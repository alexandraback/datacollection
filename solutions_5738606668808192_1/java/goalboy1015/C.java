import java.math.BigInteger;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;

public class C {
	static Random random = new Random();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			System.out.println("Case #" + tc + ":");

			int N = sc.nextInt();
			int J = sc.nextInt();

			Set<String> history = new HashSet<String>();
			// long begin = (1L << (N - 1)) + 1;
			// long end = (1L << N) - 1;
			// for (long n = begin; history.size() < J && n <= end; n += 2) {
			// String str = Long.toBinaryString(n);

			while (history.size() < J) {
				String str = randomize(N);

				BigInteger[] divisors = solve(str);
				if (divisors != null) {
					System.out.print(str);
					for (BigInteger divisor : divisors) {
						System.out.print(" " + divisor);
					}
					System.out.println();

					history.add(str);
				}
			}
		}

		sc.close();
	}

	static String randomize(int N) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N - 2; i++) {
			sb.append(random.nextInt(2));
		}
		return "1" + sb.toString() + "1";
	}

	static BigInteger[] solve(String str) {
		BigInteger[] divisors = new BigInteger[9];
		for (int base = 2; base <= 10; base++) {
			BigInteger n = new BigInteger(str, base);

			BigInteger divisor = searchDivisor(n);
			if (divisor == null) {
				return null;
			}
			divisors[base - 2] = divisor;
		}
		return divisors;
	}

	static BigInteger searchDivisor(BigInteger n) {
		long i = 2;
		while (i < 1000) {
			BigInteger bi = BigInteger.valueOf(i);
			if (bi.multiply(bi).compareTo(n) > 0) {
				break;
			}
			if (n.mod(bi).equals(BigInteger.ZERO)) {
				return bi;
			}

			i++;
		}
		return null;
	}
}
