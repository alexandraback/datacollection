package qual;

import java.util.Scanner;

public class RecycledNumbers {

	public static void main(String[] args) {
		new RecycledNumbers().run();

	}

	private void run() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			int result = solve(A, B);
			System.out.printf("Case #%d: %d\n", t + 1, result);
		}
	}

	public int solve(int A, int B) {
		int result = 0;
		for (int i = A; i <= B; i++) {
			int dig = (int) Math.log10(A/*same as B*/) + 1;
			int aa = i;
			for (int d = 0; d < dig - 1; d++) {
				aa = (aa % 10) * (int)Math.pow(10, dig - 1) + (aa / 10);
				if (i == aa) {
					break;
				}
				if (i < aa && aa <= B) {
//					System.out.printf("(%d, %d) ", i, aa);
					result++;
				}
			}
		}
		return result;
	}

}
