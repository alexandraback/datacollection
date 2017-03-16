import java.util.Scanner;

public class B {
	Scanner scanner = new Scanner(System.in);

	public static void main(String args[]) {
		new B().run();
	}

	char stack[];

	void flip(int p) {
		for (int i = 0; i <= p - i; ++i) {
			int c = p - i;
			if (c == i) {
				stack[i] = (stack[i] == '+' ? '-' : '+');
			} else {
				char newC = (stack[i] == '+' ? '-' : '+');
				stack[i] = (stack[c] == '+' ? '-' : '+');
				stack[c] = newC;
			}
		}
	}

	int solv(String S) {
		stack = S.toCharArray();
		int cnt = 0;
		for (int p = S.length() - 1; p >= 0; --p) {
			if (stack[p] == '-') {
				int x = 0;
				while (stack[x] == '+')
					++x;

				if (x > 0) {
					flip(x - 1);
					++cnt;
				}
				flip(p);
				++cnt;
			}
		}
		return cnt;
	}

	void run() {
		int T = scanner.nextInt();
		for (int i = 1; i <= T; ++i) {
			String S = scanner.next();
			System.out.println(String.format("Case #%d: %d", i, solv(S)));
		}
	}
}
