import java.util.Scanner;

public class A {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int T = in.nextInt();

		for (int t = 1; t <= T; t++) {

			long n = in.nextLong();

			if (n <= 20) {
				System.out.format("Case #%d: %d\n", t, n);
				continue;
			}

			long res = 1;

			if (n % 10 == 0) {
				res++;
				n--;
			}

			long i = 1;
			int di = 1;
			int dn = digits(n);

			while (di < dn) {
				res += calc(i, di);
				i *= 10;
				di++;
			}

			res += calcSame(i, n, dn);

			System.out.format("Case #%d: %d\n", t, res);

		}

		in.close();
	}

	private static long calcSame(long x, long n, int dn) {
		long resR = 0;
		long resL = 0;
		int mod = 1;

		for (int i = 0; i < (dn + 1) / 2; i++) {
			mod *= 10;
		}

		resR = n % mod;
		n /= mod;

		for (int i = 0; i < dn / 2; i++) {
			resL = 10 * resL + n % 10;
			n /= 10;
		}

		if (resL == 1)
			return resR;
		return resL + resR;
	}

	private static long calc(long x, int dx) {
		if (x == 1)
			return 9;
		int res = 0;
		int y = 0;
		for (int i = 0; i < dx / 2; i++) {
			res = 10 * res + 9;
		}
		y = res;
		for (int i = 0; i < (dx + 1) / 2; i++) {
			y *= 10;
		}
		res += (10 * x - y);
		return res;
	}

	private static int digits(long n) {
		int d = 0;
		while (n > 0) {
			d++;
			n /= 10;
		}
		return d;
	}

}
