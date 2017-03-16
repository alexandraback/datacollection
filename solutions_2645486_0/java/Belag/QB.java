import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class QB {

	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("B-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);

			int E = sc.nextInt();
			int R = sc.nextInt();
			int N = sc.nextInt();
			int[] activities = new int[N];
			for (int i = 0; i < N; i++) {
				activities[i] = sc.nextInt();
			}
			int[][] ans = new int[E + 1][N];
			for (int i = 0; i <= E; i++) {
				ans[i][0] = activities[0] * (E - i);
			}
			for (int i = 1; i < N - 1; i++) {
				for (int j = 0; j <= E; j++) {
					int max = 0;
					for (int k = Math.max(j - R, 0); k <= E; k++) {
						if (max < ans[k][i - 1] + activities[i]
								* (k - j + Math.min(R, E - k))) {
							max = ans[k][i - 1] + activities[i]
									* (k - j + Math.min(R, E - k));
						}
					}
					ans[j][i] = max;
				}
			}
			int max = 0;
			if (N == 1) {
				for (int i = 0; i <= E; i++) {
					if (max < ans[i][0]) {
						max = ans[i][0];
					}
				}
			} else {
				for (int i = 0; i <= E; i++) {
					if (max < ans[i][N - 2] + activities[N - 1]
							* (i + Math.min(R, E - i))) {
						max = ans[i][N - 2] + activities[N - 1]
								* (i + Math.min(R, E - i));
					}
				}
			}
			pw.println("Case #" + caseNum + ": " + max);
		}

		pw.flush();
		pw.close();
		sc.close();
	}
}
