package solution;

import java.util.Scanner;

public class B {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		int T = scanner.nextInt();

		for (int i = 1; i <= T; i++) {

			int N = scanner.nextInt();
			int M = scanner.nextInt();

			int[][] a = new int[N][];
			for (int j = 0; j < N; j++) {
				a[j] = new int[M];
				for (int k = 0; k < M; k++) {
					a[j][k] = scanner.nextInt();
				}
			}

			boolean passagePossible = true;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {

					boolean verticalPassagePossible = true;
					for (int j2 = 0; j2 < N; j2++) {
						if (a[j2][k] > a[j][k]) {
							verticalPassagePossible = false;
							break;
						}
					}
					if (verticalPassagePossible) {
						continue;
					}

					boolean horizontalPassagePossible = true;
					for (int k2 = 0; k2 < M; k2++) {
						if (a[j][k2] > a[j][k]) {
							horizontalPassagePossible = false;
							break;
						}
					}
					if (!horizontalPassagePossible) {
						passagePossible = false;
						break;
					}
				}
				if (!passagePossible) {
					break;
				}
			}

			if (passagePossible) {
				System.out.println("Case #" + i + ": YES");
			} else {
				System.out.println("Case #" + i + ": NO");
			}

		}

		scanner.close();

	}

}
