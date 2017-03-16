import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NewLotteryGame {
	static String problem = "BLarge";
	static int a, b, k;
	static Long[][][][] dp = new Long[32][2][2][2];

	static long go(int bit, int flag1, int flag2, int flag3) {
		if (bit == -1) {
			return 1;
		}
		if (dp[bit][flag1][flag2][flag3] != null)
			return dp[bit][flag1][flag2][flag3];
		long res = 0;
		int bitA = (a & (1 << bit)) > 0 ? 1 : 0;
		int maxA = flag1 == 0 ? bitA : 1;
		int bitB = (b & (1 << bit)) > 0 ? 1 : 0;
		int maxB = flag2 == 0 ? bitB : 1;
		int bitK = (k & (1 << bit)) > 0 ? 1 : 0;
		int maxK = flag3 == 0 ? bitK : 1;
		for (int b1 = 0; b1 <= maxA; b1++) {
			for (int b2 = 0; b2 <= maxB; b2++) {
				int and = (b1 & b2);
				int newFlag1 = flag1;
				if (flag1 == 0 && b1 < maxA)
					newFlag1 = 1;
				int newFlag2 = flag2;
				if (flag2 == 0 && b2 < maxB)
					newFlag2 = 1;
				int newFlag3 = flag3;
				if (flag3 == 0 && and < maxK)
					newFlag3 = 1;
				if (and <= maxK)
					res += go(bit - 1, newFlag1, newFlag2, newFlag3);
			}
		}
		return dp[bit][flag1][flag2][flag3] = res;
	}

	public static void main(String[] args) throws Exception {
		// InputReader r = new InputReader(System.in);
		// PrintWriter out = new PrintWriter(System.out);
		InputReader r = new InputReader(new FileReader(problem + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(problem
				+ "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			a = r.nextInt() - 1;
			b = r.nextInt() - 1;
			k = r.nextInt() - 1;
			dp = new Long[32][2][2][2];
			long res = go(30, 0, 0, 0);
			out.printf("Case #%d: %d\n", test++, res);
		}
		out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
