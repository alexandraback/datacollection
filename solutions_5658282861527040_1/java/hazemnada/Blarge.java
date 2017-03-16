import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Blarge {
	private static long K;
	private static long B;
	private static long A;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("B-large.in."));
		PrintWriter writer = new PrintWriter("BLarge.out");
		int tCases = Integer.parseInt(buf.readLine());
		for (int t = 1; t <= tCases; t++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			A = Integer.parseInt(str.nextToken());
			B = Integer.parseInt(str.nextToken());
			K = Integer.parseInt(str.nextToken());
			System.out.println();
			dp = new long[32][2][2][2];
			for (int i = 0; i < dp.length; i++)
				for (int j = 0; j < dp[i].length; j++)
					for (int k = 0; k < dp[0][0].length; k++)
						dp[i][j][k][0] = dp[i][j][k][1] = -1;
			writer.println("Case #" + t + ": " + go(31, 0, 0, 0));
		}
		writer.close();
	}

	static long dp[][][][];

	static long go(int bit, int flag1, int flag2, int flag3) {
		if (bit == -1 && flag1 + flag2 + flag3 == 3)
			return 1;
		else if (bit == -1)
			return 0;
		if (dp[bit][flag1][flag2][flag3] != -1)
			return dp[bit][flag1][flag2][flag3];
		int d1 = ((1 << bit) & A) == 0 ? 0 : 1;
		int d2 = ((1 << bit) & B) == 0 ? 0 : 1;
		int d3 = ((1 << bit) & K) == 0 ? 0 : 1;

		long sum = 0;
		ArrayList<Integer> a = new ArrayList<Integer>();
		ArrayList<Integer> b = new ArrayList<Integer>();
		if (flag1 == 0) {
			a.add(d1);
			if (d1 == 1)
				a.add(0);
		} else {
			a.add(0);
			a.add(1);
		}

		if (flag2 == 0) {
			b.add(d2);
			if (d2 == 1)
				b.add(0);
		} else {
			b.add(0);
			b.add(1);
		}
		for (int i = 0; i < a.size(); i++)
			for (int j = 0; j < b.size(); j++) {
				int res = a.get(i) & b.get(j);
				if (flag3 == 1 || d3 == res) {
					sum += go(bit - 1, (flag1 == 1) ? flag1
							: (a.get(i) != d1 ? 1 : 0), (flag2 == 1) ? flag2
							: (b.get(j) != d2 ? 1 : 0), flag3);
				} else if (d3 == 1 && res == 0) {
					sum += go(bit - 1, (flag1 == 1) ? flag1
							: (a.get(i) != d1 ? 1 : 0), (flag2 == 1) ? flag2
							: (b.get(j) != d2 ? 1 : 0), 1);
				}
			}
		return dp[bit][flag1][flag2][flag3] = sum;
	}
}
