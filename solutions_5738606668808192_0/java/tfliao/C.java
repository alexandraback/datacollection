import java.util.Scanner;

public class C {
	Scanner scanner = new Scanner(System.in);

	public static void main(String args[]) {
		new C().run();
	}

	boolean test(long x, int base) {
		long v = 0, b = 1;
		while (x != 0) {
			v += (x % 2) * b;
			b *= base;
			x /= 2;
		}
		return v % (base + 1) == 0;
	}

	void solv(int N, int J) {
		long x = ((1 << (N - 1)) + 1);
		int cnt = 0;
		while (x < (1 << N)) {
			boolean succ = true;
			for (int b = 2; b <= 10; ++b) {
				if (!test(x, b)) {
					succ = false;
					break;
				}
			}
			if (succ) {
				System.out.println(String.format("%s 3 4 5 6 7 8 9 10 11",
						Long.toBinaryString(x)));
				++cnt;
				if (cnt == J)
					return;
			}

			x += 2;
		}
	}

	void run() {
		int T = scanner.nextInt();
		for (int i = 1; i <= T; ++i) {
			int N, J;
			N = scanner.nextInt();
			J = scanner.nextInt();
			System.out.println(String.format("Case #%d:", i));
			solv(N, J);
		}
	}
}
