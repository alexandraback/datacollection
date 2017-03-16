import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %d\n", i, solve());
		}
	}

	static int solve() {
		double A = sc.nextDouble();
		double B = sc.nextDouble();
		double K = sc.nextDouble();
		int ret = 0;
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j < B; ++j) {
				if ((i & j) < K) ++ret;
			}
		}
		return ret;
	}

}
