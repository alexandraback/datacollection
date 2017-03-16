package qual;

import java.util.Scanner;

public class Lawnmower {
	public static void main(String[] args) {
		new Lawnmower().run();
	}

	private void run() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int[][] ptn = new int[N][M];
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					ptn[n][m] = sc.nextInt();
				}
			}
			boolean result = solve(N, M, ptn);
			System.out.printf("Case #%d: ", t + 1);
			if (result) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
	}

	private boolean solve(int N, int M, int[][] ptn) {
		int[][] map = new int[N][M];
		int m, n;

//		for (n = 0; n < N; n++) {
//			for (m = 0; m < M; m++) {
//				System.err.printf("%d ", ptn[n][m]);
//			}
//			System.err.println("");
//		}

		// init
		for (n = 0; n < N; n++) {
			for (m = 0; m < M; m++) {
				map[n][m] = 100;
			}
		}

		for (n = 0; n < N; n++) {
			int max = 0;
			for (m = 0; m < M; m++) {
				max = Math.max(max, ptn[n][m]);
			}
			for (m = 0; m < M; m++) {
				if (map[n][m] > max) {
					map[n][m] = max;
				}
			}
		}

		for (m = 0; m < M; m++) {
			int max = 0;
			for (n = 0; n < N; n++) {
				max = Math.max(max, ptn[n][m]);
			}
			for (n = 0; n < N; n++) {
				if (map[n][m] > max) {
					map[n][m] = max;
				}
			}
		}

//		for (n = 0; n < N; n++) {
//			for (m = 0; m < M; m++) {
//				System.err.printf("%d ", map[n][m]);
//			}
//			System.err.println("");
//		}

		// check
		for (n = 0; n < N; n++) {
			for (m = 0; m < M; m++) {
				if (map[n][m] != ptn[n][m]) {
					return false;
				}
			}
		}
		return true;
	}

}
