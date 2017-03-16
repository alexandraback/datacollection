import java.util.Arrays;
import java.util.Scanner;


class ProblemB {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt(), I = 0;
		while (T --> 0) {
			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();
			int[] scores = new int[N];
			for (int i = 0; i < N; ++i)
				scores[i] = in.nextInt();
			
			int result = 0;
			
			// Sort inputs
			Arrays.sort(scores);
			// Check [n/3]. If >= p, add to result and set to ignore in next phase
			for (int i = 0; i < scores.length; ++i)
				if ((scores[i]+2)/3 >= p) {
					++result;
					scores[i] = -10;
				}
			
			for (int i = scores.length - 1; i >= 0 && S > 0; --i) {
				if (scores[i] < 2) {
					if (scores[i] >= p) {
						++result;
						--S;
					}
				}
				else if ((scores[i]-2)/3 + 2 >= p) {
					++result;
					--S;
				}
			}
			
			System.out.printf("Case #%d: %d\n", ++I, result);
		}
	}
}
