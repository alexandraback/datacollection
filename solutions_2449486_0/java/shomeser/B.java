public class B {
	public static final java.util.Scanner in = new java.util.Scanner(System.in);
	public static final java.io.PrintStream out = System.out;

	public static void main(String[] args) {
		final int t = in.nextInt();

		for (int i = 0; i < t; ++i) {
			int n = in.nextInt();
			int m = in.nextInt();

			int[][] nm = new int[n][m];
			int[] maxN = new int[n];
			int[] maxM = new int[m];

			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					int v = in.nextInt();

					nm[j][k] = v;

					if (v > maxN[j]) {
						maxN[j] = v;
					}

					if (v > maxM[k]) {
						maxM[k] = v;
					}
				}
			}

			out.print("Case #");
			out.print(i + 1);
			out.print(": ");
			out.println(solve(nm, maxN, maxM, n, m));
		}
	}

	private static String solve(int[][] nm, int[] maxN, int[] maxM, int n, int m) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (nm[j][k] != maxN[j] && nm[j][k] != maxM[k]) {
					return "NO";
				}
			}
		}

		return "YES";
	}
}
