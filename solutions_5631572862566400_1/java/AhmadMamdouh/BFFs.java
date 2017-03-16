import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BFFs {
	static int[] bff;
	static int n;
	static int res = 0;

	static void go(int current, int mask, int[] order) {
		if (mask == (1 << bff.length) - 1) {
			check(order);
			return;
		}
		for (int j = 0; j < bff.length; j++) {
			if ((mask & (1 << j)) == 0) {
				order[current] = j;
				go(current + 1, mask | (1 << j), order);
			}
		}
	}

	private static void check(int[] order) {
		for (int i = 2; i <= order.length; i++) {
			boolean can = true;
			for (int j = 0; j < i; j++) {
				if (order[(j + 1) % i] == bff[order[j]]
						|| order[j - 1 >= 0 ? j - 1 : i - 1] == bff[order[j]])
					continue;
				else
					can = false;
			}
			if (can)
				res = Math.max(res, i);
		}

	}
static ArrayList<Integer>[] adj;
	public static void main(String[] args) {
		InputReader r = new InputReader(System.in);
		int T = r.nextInt();
		int test = 1;
		while (test <= T) {
			n = r.nextInt();
			bff = new int[n];
			adj = new ArrayList[n];
			for (int i = 0; i < adj.length; i++) {
				adj[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < bff.length; i++) {
				bff[i] = r.nextInt() - 1;
				adj[bff[i]].add(i);
			}
			res = maxCycle();
			res = Math.max(res, detect());
			System.out.printf("Case #%d: %d\n", test, res);
			test++;
		}
	}
static Integer[] dp;
	private static int detect() {
		int res = 0;
		dp = new Integer[n];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(bff[i]==j&&bff[j]==i){
					adj[i].remove((Integer)j);
					adj[j].remove((Integer)i);
					res+=go(i)+go(j);
				}
			}
		}
		return res;
	}

	private static int go(int curr) {
		if(dp[curr]!=null)
			return dp[curr];
		int res = 1;
		for(int x:adj[curr])
			res = Math.max(res, 1+go(x));
		return dp[curr] = res;
	}

	static boolean[] vis;

	private static int maxCycle() {
		int res = 1;
		for (int i = 0; i < n; i++) {
			vis = new boolean[n];
			res = Math.max(res, dfs1(i, i));
		}
		return res;
	}

	static int dfs1(int start, int curr) {
		if (vis[curr])
			return curr==start?0:-1<<28;
		vis[curr] = true;
		return 1 + dfs1(start, bff[curr]);
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
