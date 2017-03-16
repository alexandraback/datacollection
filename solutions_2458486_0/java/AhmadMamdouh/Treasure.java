import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Treasure {
	static int n;
	static int[] init;
	static int[] open;
	static int[][] keys;
	static Boolean[] dp;
	static Integer[] path = new Integer[1 << 20];

	public static boolean go(int mask) {
		if (mask == (1 << n) - 1)
			return true;
		if (dp[mask] != null)
			return dp[mask];
		ArrayList<Integer> aval = getAval(mask);
		for (int i = 0; i < n; i++) {
			if ((mask & (1 << i)) == 0) {
				if (aval.contains(open[i])) {
					if (go(mask | (1 << i))) {
						path[mask] = i;
						return dp[mask] = true;
					}
				}
			}
		}
		return dp[mask] = false;
	}

	private static ArrayList<Integer> getAval(int mask) {
		ArrayList<Integer> res = new ArrayList<Integer>();
		for (int k : init)
			res.add(k);
		for (int i = 0; i < n; i++) {
			if ((mask & (1 << i)) > 0) {
				for (int k : keys[i])
					res.add(k);
			}
		}
		for (int i = 0; i < n; i++) {
			if ((mask & (1 << i)) > 0) {
				res.remove((Integer) open[i]);
			}
		}
		return res;
	}

	public static void main(String[] args) throws Exception {
		InputReader r = new InputReader(new FileReader("D.in"));
		PrintWriter out = new PrintWriter(new FileWriter("D.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			int k = r.nextInt();
			n = r.nextInt();
			init = new int[k];
			for (int i = 0; i < k; i++)
				init[i] = r.nextInt();
			open = new int[n];
			keys = new int[n][];
			for (int i = 0; i < n; i++) {
				open[i] = r.nextInt();
				int kk = r.nextInt();
				keys[i] = new int[kk];
				for (int j = 0; j < kk; j++)
					keys[i][j] = r.nextInt();
			}
			dp = new Boolean[1 << n];
			if (go(0)) {
				int mask = 0;
				String sol = "";
				while (mask != (1 << n) - 1) {
					int next = path[mask];
					sol += (next + 1) + " ";
					mask |= (1 << next);
				}
				out.printf("Case #%d: %s\n", test++, sol.substring(0, sol.length() - 1));
			} else {
				out.printf("Case #%d: IMPOSSIBLE\n", test++);
			}
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
