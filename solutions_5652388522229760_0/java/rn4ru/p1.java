package codejam2016.problema;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			long N = scanner.nextLong();
			f(i, N);
		}
	}

	private static void f(int i, long n) {
		if (n == 0) {
			System.out.println("Case #" + i + ": INSOMNIA");
			return;
		}
		boolean[] b = new boolean[10];
		for (int k = 1; k <= 100; k++) {
			long p = n * k;
			while (p > 0) {
				b[(int) p % 10] = true;
				p /= 10;
			}
			boolean f = false;
			for (int j = 0; j < 10; j++) {
				if (!b[j]) {
					f = true;
					break;
				}
			}
			if (f) {
				continue;
			} else {
				System.out.println("Case #" + i + ": " + (n * k));
				return;
			}
		}
		System.out.println("Case #" + i + ": INSOMNIA");
	}

}
