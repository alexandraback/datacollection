import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemB {

	public static void main(String[] args) {

		try {

			final String fileIn = ProblemB.class.getSimpleName().toLowerCase() + ".in";
			final String fileOut = ProblemB.class.getSimpleName().toLowerCase() + ".out";

			final Scanner in = new Scanner(new File(fileIn));
			final PrintWriter out = new PrintWriter(new File(fileOut));

			new ProblemB().solve(in, out);

			out.flush();
			out.close();

		} catch (Exception ex) {

			ex.printStackTrace();
		}
	}

	private final void solve(final Scanner in, final PrintWriter out) throws Exception {

		final int testCount = in.nextInt();

		for (int testCase = 1; testCase <= testCount; ++testCase) {

			final int n = in.nextInt();
			final int m = in.nextInt();

			final int[] rowMax = new int[n];
			final int[] colMax = new int[m];

			Arrays.fill(rowMax, -1);
			Arrays.fill(colMax, -1);

			final int lawn[][] = new int[n][m];

			for (int i = 0; i < n; ++i) {

				for (int j = 0; j < m; ++j) {

					lawn[i][j] = in.nextInt();

					rowMax[i] = Math.max(rowMax[i], lawn[i][j]);
					colMax[j] = Math.max(colMax[j], lawn[i][j]);
				}
			}

			boolean canBuild = true;

			for (int i = 0; i < n && canBuild; ++i) {

				for (int j = 0; j < m && canBuild; ++j) {

					if (lawn[i][j] < rowMax[i] && lawn[i][j] < colMax[j]) {

						canBuild = false;
					}
				}
			}

			final String result = canBuild ? "YES" : "NO";
			out.printf("Case #%d: %s%n", testCase, result);
		}
	}
}
