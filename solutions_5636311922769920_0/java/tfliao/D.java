import java.util.Scanner;

public class D {
	Scanner scanner = new Scanner(System.in);

	public static void main(String args[]) {
		new D().run();
	}

	void solv(int K, int C, int S) {
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= K; ++i) {
			sb.append(" ");
			sb.append(i);
		}
		System.out.println(sb.toString());
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
