import java.util.Scanner;

public class D {
	Scanner scanner = new Scanner(System.in);

	public static void main(String args[]) {
		new D().run();
	}

	void solv(int K, int C, int S) {
		if ((K + C - 1) / C > S)
			System.out.println(" IMPOSSIBLE");
		else {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < K; i += C) {
				long v = 0;
				for (int j = i; j < i + C && j < K; ++j) {
					v = v * C + j;
				}
				sb.append(" ");
				sb.append(v + 1);
			}
			System.out.println(sb.toString());
		}

	}

	void run() {
		int T = scanner.nextInt();
		for (int i = 1; i <= T; ++i) {
			int K, C, S;
			K = scanner.nextInt();
			C = scanner.nextInt();
			S = scanner.nextInt();

			System.out.print(String.format("Case #%d:", i));
			solv(K, C, S);
		}
	}
}
