import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ManageYourEnergy {
	static int[] arr;
	static int g, e;
	static Integer[][] dp;

	public static int go(int index, int total) {
		if (total > e)
			return go(index, e);
		if (index == arr.length)
			return 0;
		if (dp[index][total] != null)
			return dp[index][total];
		int res = 0;
		for (int i = 0; i <= total; i++) {
			res = Math.max(res, i * arr[index] + go(index + 1, total - i + g));
		}
		return dp[index][total] = res;
	}

	public static void main(String[] args) throws Exception {
		InputReader r = new InputReader(new FileReader("B.txt"));
		PrintWriter out = new PrintWriter(new FileWriter("B.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			e = r.nextInt();
			g = r.nextInt();
			int n = r.nextInt();
			arr = new int[n];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = r.nextInt();
			}
			dp = new Integer[15][15];
			out.printf("Case #%d: %d\n", test, go(0, e));
			test++;
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
