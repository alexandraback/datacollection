import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class ProlblemC {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("C1in.txt"));
		int t = Integer.parseInt(buf.readLine());
		PrintWriter writer = new PrintWriter(new File("C1out.txt"));

		for (int i = 1; i <= t; i++) {
			String[] line = buf.readLine().split(" ");
			int n = Integer.parseInt(line[0]);
			int m = Integer.parseInt(line[1]);
			long[][] dp = new long[n + 1][m + 1];
			for (int j = 0; j < dp.length; j++)
				Arrays.fill(dp[j], -1);
			obj[] boxes = new obj[n];
			obj[] toys = new obj[m];
			line = buf.readLine().split(" ");
			int index1 = 0;
			int index2 = 0;
			while (index1 < line.length) {
				boxes[index2++] = new obj(Long.parseLong(line[index1++]),
						Integer.parseInt(line[index1++]));

			}
			index1 = 0;
			index2 = 0;
			line = buf.readLine().split(" ");
			while (index1 < line.length) {
				toys[index2++] = new obj(Long.parseLong(line[index1++]),
						Integer.parseInt(line[index1++]));

			}
			long max = go(dp, 0, 0, boxes, toys);
			writer.println("Case #" + i + ": " + max);

		}
		writer.close();

	}

	private static long go(long[][] dp, int n, int m, obj[] boxes, obj[] toys) {
		if (n == boxes.length || m == toys.length)
			return 0;
		else if (dp[n][m] != -1)
			return dp[n][m];
		else {
			long max = 0;
			max = Math.max(max, go(dp, n + 1, m, boxes, toys));
			max = Math.max(max, go(dp, n, m + 1, boxes, toys));
			if (toys[m].type == boxes[n].type) {
				long min = Math.min(toys[m].number, boxes[n].number);
				toys[m].number -= min;
				boxes[n].number -= min;
				if (toys[m].number == 0)
					max = Math.max(max, min + go(dp, n + 1, m, boxes, toys));
				else if (boxes[n].number == 0)
					max = Math.max(max, min + go(dp, n, m + 1, boxes, toys));

				toys[m].number += min;
				boxes[n].number += min;

			}
			return dp[n][m] = max;

		}
	}

	static class obj {
		long number;
		int type;

		public obj(long p, int t) {
			number = p;
			type = t;

		}
	}
}
