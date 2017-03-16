import java.util.Scanner;

public class Enclosure {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		int N, M, K;
		int i, j, k;
		int ans;
		int min;
		boolean matrix[][];
		int arr[];
		int num;
		int stoneCount;
		int pointCount;
		int l, r, u, d;
		boolean isValid;
		boolean isStoneFound;

		for (k = 0; k < T; k++) {
			N = scanner.nextInt();
			M = scanner.nextInt();
			K = scanner.nextInt();

			matrix = new boolean[N][M];
			arr = new int[32];
			ans = 0;
			min = Integer.MAX_VALUE;

			for (i = 0; i <= (Math.pow(2, N * M - 1) + 0.5); i++) {
				for (j = 0; j < 20; j++) {
					arr[j] = 0;
				}
				for (int ii = 0; ii < N; ii++) {
					for (int jj = 0; jj < M; jj++) {
						matrix[ii][jj] = false;
					}
				}

				num = i;
				for (j = 0; j < 20; j++) {
					arr[j] = ((num >> j) & 1);
				}

				stoneCount = 0;
				pointCount = 0;
				for (j = 0; j < 20; j++) {
					if (arr[j] == 1) {
						stoneCount++;
						matrix[j / M][j % M] = true;
					}
				}

				for (int ii = 0; ii < N; ii++) {
					for (int jj = 0; jj < M; jj++) {
						if (matrix[ii][jj] == true) {
							pointCount++;
						} else {
							isValid = true;

							isStoneFound = false;
							for (l = jj - 1; l >= 0; l--) {
								isStoneFound = false;
								if (matrix[ii][l] == true) {
									isStoneFound = true;
									break;
								}
							}
							if (isStoneFound == false) {
								isValid = false;
							}

							isStoneFound = false;
							for (r = jj + 1; r < M; r++) {
								isStoneFound = false;
								if (matrix[ii][r] == true) {
									isStoneFound = true;
									break;
								}
							}
							if (isStoneFound == false) {
								isValid = false;
							}

							isStoneFound = false;
							for (u = ii - 1; u >= 0; u--) {
								isStoneFound = false;
								if (matrix[u][jj] == true) {
									isStoneFound = true;
									break;
								}
							}
							if (isStoneFound == false) {
								isValid = false;
							}

							isStoneFound = false;
							for (d = ii + 1; d < N; d++) {
								isStoneFound = false;
								if (matrix[d][jj] == true) {
									isStoneFound = true;
									break;
								}
							}
							if (isStoneFound == false) {
								isValid = false;
							}

							if (isValid == true) {
								pointCount++;
							}
						}
					}
				}

				if (pointCount == K) {
					if (min > stoneCount) {
						min = stoneCount;
					}
				}
			}

			if (K == 1) {
				min = 1;
			}
			if (min == Integer.MAX_VALUE) {
				System.out.println("N=" + N + ",M=" + M + ",K=" + K);
			}
			ans = min;
			System.out.println("Case #" + (k + 1) + ": " + ans);
		}
	}
}
