import java.io.File;
import java.util.Scanner;

public class NewLotteryGame {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("B-small.in"));

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			int A = s.nextInt();
			int B = s.nextInt();
			int K = s.nextInt();

			System.out.println("Case #" + t + ": " + NewLotteryGame.solve(A, B, K));
		}
	}

	public static int solve(int A, int B, int K) {
		int winNum = 0;
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j < B; ++j) {
				if ((i & j) < K) {
					++winNum;
				}
			}
		}

		return winNum;
	}

}
