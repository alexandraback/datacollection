import java.util.Arrays;
import java.util.Scanner;

public class C {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d:\n", i);
			char[][] map = solve();
			if (map == null) {
				System.out.println("Impossible");
			} else {
				for (int j = 0; j < map.length; ++j) {
					System.out.println(String.valueOf(map[j]));
				}
			}
		}
	}

	static char[][] solve() {
		int R = sc.nextInt();
		int C = sc.nextInt();
		int M = sc.nextInt();
		char[][] ret = new char[R][C];
		for (int i = 0; i < R; ++i) {
			Arrays.fill(ret[i], '*');
		}
		if (M == R * C - 1) {
			ret[0][0] = 'c';
			return ret;
		}
		if (R == 1) {
			ret[0][0] = 'c';
			for (int i = 1; i < C - M; ++i) {
				ret[0][i] = '.';
			}
			return ret;
		}
		if (C == 1) {
			ret[0][0] = 'c';
			for (int i = 1; i < R - M; ++i) {
				ret[i][0] = '.';
			}
			return ret;
		}

		for (int i = 2; i <= R; ++i) {
			for (int j = 2; j <= C; ++j) {
				int rest = R * C - M - (2 * i + 2 * j - 4);
				int rect = (i - 2) * (j - 2);
				if (rest < 0) break;
				if (rest <= rect) {
					for (int k = 0; k < i; ++k) {
						ret[k][0] = ret[k][1] = '.';
					}
					for (int k = 0; k < j; ++k) {
						ret[0][k] = ret[1][k] = '.';
					}
					int fullRow = rest == 0 ? 0 : rest / (j - 2);
					int partialRow = rest == 0 ? 0 : rest % (j - 2);
					for (int k = 0; k < fullRow; ++k) {
						for (int l = 2; l < j; ++l) {
							ret[2 + k][l] = '.';
						}
					}
					for (int k = 0; k < partialRow; ++k) {
						ret[2 + fullRow][2 + k] = '.';
					}
					ret[0][0] = 'c';
					return ret;
				}
			}
		}
		return null;
	}

}
