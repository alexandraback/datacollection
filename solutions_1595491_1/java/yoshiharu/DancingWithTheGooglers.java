package qual;

import java.util.Arrays;
import java.util.Scanner;

public class DancingWithTheGooglers {

	public static void main(String[] args) {
		new DancingWithTheGooglers().run();
	}

	private void run() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int testcase = 0; testcase < T; testcase++) {
			int N = sc.nextInt();
			int S = sc.nextInt();
			int p = sc.nextInt();
			int[] t = new int[N];
			for (int i = 0; i < N; i++) {
				t[i] = sc.nextInt();
			}
			int result = solve(N, S, p, t);
			System.out.printf("Case #%d: %d\n", testcase + 1, result);
		}
	}

	/**
	 * 
	 * @param N the number of Googlers
	 * @param S the number of surprising triplets of scores
	 * @param p
	 * @param t
	 * @return
	 */
	public int solve(int N, int S, int p, int[] t) {
		int result = 0;
		Arrays.sort(t);
		for (int i = N - 1; i >= 0; i--) {
			int b = (t[i] + 2) / 3;
			if (b >= p) {
				result++;
//				System.out.printf("(1) %d : %d\n", t[i], b);
			} else if (t[i] > 1 && S > 0 && b == p - 1 && ((t[i] - 1) % 3) != 0) {
				result++;
				S--;
//				System.out.printf("(2) %d : %d (S=%d)\n", t[i], b, S);
			}
		}
		return result;
	}

}
