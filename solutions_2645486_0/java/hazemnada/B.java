import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
	private static int N;
	private static int R;
	private static int E;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new File("B.out"));

		int tcases = Integer.parseInt(buf.readLine());
		for (int i = 1; i <= tcases; i++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			E = Integer.parseInt(str.nextToken());
			R = Integer.parseInt(str.nextToken());
			N = Integer.parseInt(str.nextToken());
			int[] a = new int[N];
			str = new StringTokenizer(buf.readLine());
			for (int j = 0; j < N; j++)
				a[j] = Integer.parseInt(str.nextToken());
			int[][] dp = new int[N][E + 1];
			for (int j = 0; j < dp.length; j++)
				Arrays.fill(dp[j], -1);
			int max = go(dp, E, 0, a);

			writer.printf("Case #%d: %d\n", i, max);
		}
		writer.close();
	}

	private static int go(int[][] dp, int energy, int i, int[] a) {
		if (i == dp.length)
			return 0;
		else if (dp[i][energy] != -1)
			return dp[i][energy];
		else {
			int max = 0;
			for (int j = 0; j <= energy; j++)
				max = Math.max(max,
						go(dp, Math.min(energy + R - j, E), i + 1, a) + a[i]
								* j);
			return dp[i][energy] = max;

		}
	}

}
