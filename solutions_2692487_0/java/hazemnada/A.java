import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	private static int a;
	private static int n;
	private static int[] array;
	private static int[][] dp;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new File("A.out"));
		int tCases = Integer.parseInt(buf.readLine().trim());
		for (int t = 1; t <= tCases; t++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			a = Integer.parseInt(str.nextToken());
			n = Integer.parseInt(str.nextToken());
			array = new int[n];
			str = new StringTokenizer(buf.readLine());
			for (int i = 0; i < n; i++)
				array[i] = Integer.parseInt(str.nextToken());
			Arrays.sort(array);
			dp = new int[10100][101];
			for (int i = 0; i < dp.length; i++)
				Arrays.fill(dp[i], -1);
			int min = go(0, a);
			writer.printf("Case #%d: %d\n", t, min);
		}
		writer.close();
	}

	private static int go(int i, int value) {
		if (i == n)
			return 0;
		else if (dp[value][i] != -1)
			return dp[value][i];
		else {
			int min;
			if (value > array[i])
				min = go(i + 1, value + array[i]);
			else {
				if (value > 1)
					min = Math.min(1 + go(i, value + value - 1), n - i);
				else
					min = n - i;
			}
			return dp[value][i] = min;
		}
	}
}
