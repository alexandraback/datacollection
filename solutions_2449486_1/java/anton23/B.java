import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int[][] a = new int[N][M];
			boolean[][] ok = new boolean[N][M];

			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					a[n][m] = sc.nextInt();
				}
			}
			// Rows
			for (int n = 0; n < N; n++) {
				int rowMax = 0;
				for (int m = 0; m < M; m++) {
					rowMax = Math.max(rowMax, a[n][m]);
				}
				for (int m = 0; m < M; m++) {
					if (a[n][m] == rowMax) {
						ok[n][m] = true;
					}
				}
			}
			// Rows
			for (int m = 0; m < M; m++) {
				int colMax = 0;
				for (int n = 0; n < N; n++) {
					colMax = Math.max(colMax, a[n][m]);
				}
				for (int n = 0; n < N; n++) {
					if (a[n][m] == colMax) {
						ok[n][m] = true;
					}
				}
			}

			boolean all = true;
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					if (!ok[n][m]) {
						all = false;
					}
				}
			}
			String res = "NO";
			if (all)
				res = "YES";
			System.out.println("Case #" + t + ": " + res);

		}
	}
}
