import java.util.Arrays;
import java.util.Scanner;

class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int I = 0;
		while (I++ < T) {
			int A = in.nextInt(), N = in.nextInt();
			int[] m = new int[N];
			for (int i = 0; i < N; ++i) {
				m[i] = in.nextInt();
			}
			
			Arrays.sort(m);
			
			// Remove all
			int best = N, sum = A;
			int curr = 0;
			if (A > 1) {
				for (int i = 0; i < N; ++i) {
					if (sum <= m[i]) {
						sum += sum - 1;
						++curr;
						--i;
					}
					else {
						sum += m[i];
					}
					best = Math.min(best, curr + N - i - 1);
				}
			}
			
			System.out.printf("Case #%d: %d\n", I, best);
		}

	}

}
