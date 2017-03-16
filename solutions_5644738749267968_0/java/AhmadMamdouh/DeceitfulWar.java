import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DeceitfulWar {
	static String problem = "D";
	static double[] a, b;

	static int go(int leftA, int rightA, int index) {
		if (index == -1)
			return 0;
		int res = 0;
		res = Math.max(res, (a[leftA] > b[index] ? 1 : 0) + go(leftA + 1, rightA, index - 1));
		res = Math.max(res, (a[rightA] > b[index] ? 1 : 0) + go(leftA, rightA - 1, index - 1));
		return res;
	}

	public static void main(String[] args) throws Exception {
//		InputReader r = new InputReader(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		 InputReader r = new InputReader(new FileReader(problem +
		 ".in"));
		 PrintWriter out = new PrintWriter(new FileWriter(problem +
		 "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			int n = r.nextInt();
			a = new double[n];
			b = new double[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = r.nextDouble();
			}
			for (int i = 0; i < a.length; i++) {
				b[i] = r.nextDouble();
			}
			Arrays.sort(a);
			Arrays.sort(b);
			int warScore = 0;
			boolean[] vis = new boolean[n];
			for (int i = 0; i < a.length; i++) {
				double played = 1;
				int index = -1;
				for (int j = 0; j < b.length; j++)
					if (b[j] > a[i] && !vis[j]) {
						if (played > b[j]) {
							played = b[j];
							index = j;
						}
					}
				if (index != -1)
					vis[index] = true;
				else
					warScore++;
			}

			int deceiveScore = go(0, n - 1, n - 1);
			out.printf("Case #%d: %d %d\n", test++, deceiveScore, warScore);
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

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
