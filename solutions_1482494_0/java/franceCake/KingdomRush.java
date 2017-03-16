package year2012.round1a.b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class KingdomRush {
	public static void main(String[] args) throws Exception {
		// GCJ共通
		String filename = "src/year2012/round1a/b/B-small-attempt4";
		PrintWriter out = new PrintWriter(new File(filename + ".out"));
		Scanner scan = new Scanner(new File(filename + ".in"));

		final int T = scan.nextInt();

		TESTCASE_LOOP: for (int i = 0; i < T; i++) {
			int ans = 0;
			int N = scan.nextInt();
			int[] oneStar = new int[N];
			int[] twoStar = new int[N];
			for (int j = 0; j < N; j++) {
				oneStar[j] = scan.nextInt();
				twoStar[j] = scan.nextInt();
			}
			int earnedStar = 0;
			int completed = 0;
			// 戦略1.「まだ取っていないレベル2のうち、今の星数で取れるもの」があれば、それを取る。取ったら-1を入れる。
			// 2.なければ、「まだ取っていないレベル1のうち、今の星数で取れるもの」を取る。取ったら-1を入れる。

			LOOP2: do {
				for (int j = 0; j < N; j++) {
					if (oneStar[j] != -1 && twoStar[j] != -1 && twoStar[j] <= earnedStar) {
						twoStar[j] = -1;
						earnedStar += 2;
						ans++;
						completed++;
						continue LOOP2;
					}else if (oneStar[j] == -1 && twoStar[j] != -1 && twoStar[j] <= earnedStar) {
						twoStar[j] = -1;
						earnedStar += 1;
						ans++;
						completed++;
						continue LOOP2;
					}
				}
				for (int j = 0; j < N; j++) {
					if (oneStar[j] != -1 && twoStar[j] != -1 && oneStar[j] <= earnedStar) {
						oneStar[j] = -1;
						earnedStar += 1;
						ans++;
						continue LOOP2;
					}
				}
				ans = -1;
				break LOOP2;

			} while (completed != N);

			// 出力
			if (ans == -1) {
				System.out.printf("Case #%d: %s\n", i + 1, "Too Bad");
				out.printf("Case #%d: %s\n", i + 1, "Too Bad");
			} else {

				System.out.printf("Case #%d: %s\n", i + 1, ans);
				out.printf("Case #%d: %s\n", i + 1, ans);
			}
		}
		out.flush();
	}

}