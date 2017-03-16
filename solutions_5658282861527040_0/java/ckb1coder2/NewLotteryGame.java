import java.util.Scanner;

public class NewLotteryGame {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		int A, B, K;
		int i, j, k;
		long ans;
		int bitwiseAnd;

		for (k = 0; k < T; k++) {
			A = scanner.nextInt();
			B = scanner.nextInt();
			K = scanner.nextInt();
			ans = 0;

			for (i = 0; i < A; i++) {
				for (j = 0; j < B; j++) {
					bitwiseAnd = i & j;
					if (bitwiseAnd < K)
						ans++;
				}
			}

			System.out.println("Case #" + (k + 1) + ": " + ans);
		}
	}
}
