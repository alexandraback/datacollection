import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class BoxFactory {

	private static long[][] a;
	private static long[][] b;
	private static long[][] memo;
	private static int N;
	private static int M;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("inputC.txt"));
		PrintWriter pw = new PrintWriter("outputC.txt");
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			N = sc.nextInt();
			M = sc.nextInt();

			a = new long[N][2];
			for (int i = 0; i < a.length; i++) {
				a[i][0] = sc.nextLong();
				a[i][1] = sc.nextLong();
			}

			b = new long[M][2];
			for (int i = 0; i < b.length; i++) {
				b[i][0] = sc.nextLong();
				b[i][1] = sc.nextLong();
			}

			memo = new long[N + 1][M + 1];
			for (long[] ls : memo) {
				Arrays.fill(ls, -1);
			}

			pw.println("Case #" + t + ": " + solve(0, 0));
		}
		pw.flush();
		pw.close();
	}

	private static long solve(int indexA, int indexB) {
		long res = memo[indexA][indexB];
		if (res == -1) {
			if (indexA == N || indexB == M) {
				res = 0;
			} else {
				res = 0;
				long as = 0;
				for (int i = indexA; i < N; i++) {
					if (a[i][1] == a[indexA][1]) {
						as += a[i][0];
					}
					
					long bs = 0;
					for (int j = indexB; j < M; j++) {
						if (b[j][1] == b[indexB][1]) {
							bs += b[j][0];
						}

						if (a[indexA][1] == b[indexB][1]) {
							res = Math.max(res, Math.min(as, bs) + solve(i + 1, j + 1));
						}
						if (j != indexB) {
							res = Math.max(res, solve(indexA, j));
						}
					}
					if (i != indexA) {
						res = Math.max(res, solve(i, indexB));
					}
				}

			}
			memo[indexA][indexB] = res;
		}
		return res;
	}
}
