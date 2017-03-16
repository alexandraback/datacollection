import java.util.Scanner;

public class A {
	Scanner scanner = new Scanner(System.in);

	public static void main(String args[]) {
		new A().run();
	}

	long solv(long N) {
		boolean m[] = new boolean[10];
		int cnt = 0;
		for (int i = 0; i < 10; ++i)
			m[i] = true;

		long v = 0;
		do {
			v += N;
			long x = v;
			while (x != 0) {
				int d = (int) (x % 10);
				if (m[d])
					++cnt;
				m[d] = false;
				x /= 10;
			}

		} while (cnt < 10);

		return v;
	}

	void run() {
		int T = scanner.nextInt();
		for (int i = 1; i <= T; ++i) {
			long N = scanner.nextLong();
			if (0 == N) {
				System.out.println(String.format("Case #%d: INSOMNIA", i));
			} else {
				System.out.println(String.format("Case #%d: %d", i, solv(N)));
			}
		}
	}
}
