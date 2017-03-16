import java.util.*;


public class Main_Round1C_2016_B {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		for (int casei = 1; casei <= t; casei++) {
			int b = sc.nextInt();
			long m = sc.nextLong();

			long max = pow(2, b - 2);

			if (m > max) {
				System.out.printf("Case #%d: %s\n", casei, "IMPOSSIBLE");
			} else {
				System.out.printf("Case #%d: %s\n", casei, "POSSIBLE");

				int[][] ret = new int[b][b];
				for (int i = 1; i < b; i++) {
					for (int j = i + 1; j < b; j++) {
						ret[i][j] = 1;
					}
				}

				if (m == max) {
					for (int j = 1; j < b; j++) {
						ret[0][j] = 1;
					}
				} else {
					int bit = b - 2;
					while (m > 0) {
						if (m % 2 != 0) {
							ret[0][bit] = 1;
						}
						bit--;
						m /= 2;
					}
				}

				for (int i = 0; i < b; i++) {
					StringBuilder sb = new StringBuilder();
					for (int j = 0; j < b; j++) {
						sb.append((char)('0' + ret[i][j]));
					}
					System.out.println(sb);
				}
			}
		}

		sc.close();
	}

	private static long pow(int x, int n) {
		long ret = 1;
		for (int i = 0; i < n; i++) {
			ret *= x;
		}

		return ret;
	}
}
