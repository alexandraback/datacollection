package yulong.codejam;

import java.util.Scanner;

public class A {

	public static long need(long r, long n) {
		return n + 2 * n * r + 2 * n * (n - 1);
	}

	public static void main(String[] args) {
		System.err.println(need(1, 1));
		System.err.println(need(1, 2));
		System.err.println(need(1, 3));

		Scanner s = new Scanner(System.in);
		int T = s.nextInt();

		for (int t = 1; t <= T; t++) {
			long radius = s.nextLong();
			long total = s.nextLong();

			long low = 0;
			long high = 1;
			while (need(radius, high) < total) {
				high *= 2;
			}
			low = high / 2;

			long ok = low;
			while (low <= high) {
				long m = (low + high) / 2;
				long _need = need(radius, m);

				if (_need == total) {
					ok = m;
					break;
				} else if (_need < total) {
					ok = m;
					low = m + 1;
				} else {
					high = m - 1;
				}
			}

			System.out.println("Case #" + t + ": " + ok);
		}
		s.close();
	}
}
