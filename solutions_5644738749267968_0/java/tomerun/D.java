import java.util.Arrays;
import java.util.Scanner;

public class D {

	static Scanner sc = new Scanner(System.in);
	static int N;
	static double[] W1, W2;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			N = sc.nextInt();
			W1 = new double[N];
			W2 = new double[N];
			for (int j = 0; j < N; ++j) {
				W1[j] = sc.nextDouble();
			}
			for (int j = 0; j < N; ++j) {
				W2[j] = sc.nextDouble();
			}
			Arrays.sort(W1);
			Arrays.sort(W2);
			System.out.printf("Case #%d: %d %d\n", i, solve1(), solve2());
		}
	}

	static int solve1() {
		for (int i = 0; i < N; ++i) {
			boolean ok = true;
			for (int j = i; j < N; ++j) {
				if (W1[j] < W2[j - i]) {
					ok = false;
					break;
				}
			}
			if (ok) return N - i;
		}
		return 0;
	}

	static int solve2() {
		int p1 = 0;
		int p2 = 0;
		while (p1 < N) {
			while (p2 < N && W1[p1] > W2[p2]) {
				++p2;
			}
			if (p2 == N) break;
			++p1;
			++p2;
		}
		return N - p1;
	}
}
