import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Money {

	public static void main(String[] args) throws Exception {
		Money object = new Money();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();

		for (int tc = 1; tc <= testCases; tc++) {

			int c = scanner.nextInt();
			int d = scanner.nextInt();
			int v = scanner.nextInt();

			int[] values = new int[d];
			for (int i = 0; i < d; i++)
				values[i] = scanner.nextInt();

			int result = object.solve(c, d, v, values);

			wr.write("Case #" + tc + ": " + result + "\r\n");
		}

		scanner.close();
		wr.close();
	}

	int result = -1;

	private int solve(int c, int d, int v, int[] values) {

		result = -1;

		int[] additional = new int[v + 1];
		Arrays.fill(additional, 0);

		check(v, values, additional, 0);
		return result;
	}

	private void check(int v, int[] values, int[] additional, int taken) {

		if (result != -1 && taken >= result)
			return;

		int[] dp = new int[v + 1];
		Arrays.fill(dp, 0);
		dp[0] = 1;

		List<Integer> current = new ArrayList<>();
		for (int value : values)
			current.add(value);

		for (int z = 0; z < additional.length; z++)
			if (additional[z] > 0)
				current.add(z);

		for (int c : current)
			for (int pos = v; pos >= c; pos--)
				if (dp[pos - c] > 0)
					dp[pos] = 1;

		int firstWrong = -1;
		for (int m = 1; m <= v; m++)
			if (dp[m] == 0) {
				firstWrong = m;
				break;
			}

		if (firstWrong == -1) {
			result = taken;
			return;
		}

		// we need to take something additional
		for (int take = 1; take <= firstWrong; take++)
			if (additional[take] == 0) {
				additional[take] = 1;
				check(v, values, additional, taken + 1);
				additional[take] = 0;
			}
	}

}
