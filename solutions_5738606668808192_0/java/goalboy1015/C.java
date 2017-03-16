import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			System.out.println("Case #" + tc + ":");

			int N = sc.nextInt();
			int J = sc.nextInt();

			int foundNum = 0;
			long begin = (1L << (N - 1)) + 1;
			long end = (1L << N) - 1;
			for (long n = begin; foundNum < J && n <= end; n += 2) {
				String str = Long.toBinaryString(n);

				long[] divisors = solve(str);
				if (divisors != null) {
					System.out.print(str);
					for (long divisor : divisors) {
						System.out.print(" " + divisor);
					}
					System.out.println();

					foundNum++;
				}
			}
		}

		sc.close();
	}

	static long[] solve(String str) {
		long[] divisors = new long[9];
		for (int base = 2; base <= 10; base++) {
			long n = Long.parseLong(str, base);

			long divisor = searchDivisor(n);
			if (divisor < 0) {
				return null;
			}
			divisors[base - 2] = divisor;
		}
		return divisors;
	}

	static long searchDivisor(long n) {
		for (long i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return i;
			}
		}
		return -1;
	}
}
