import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

	ArrayList<String> small = new ArrayList<String>();
	/*
	int next [][] = new int [26][1125078];
	int termIndex[] = new int [1125078];
	*/
	
	int getCount (String s, int l, int r, String to) {
		int res = 0;
		int last = -5;
		for (int i = l, j = 0; i <= r; i++, j++) {
			if (s.charAt(i) == to.charAt(j)) continue;
			if (j - last <= 4) return -1;
			last = j;
			res++;
		}
		return res;
	}
	
	int getFirstAndLastChange (String s, int l, int r, String to) {
		int first = -1;
		int last = -1;
		for (int i = l, j = 0; i <= r; i++, j++) {
			if (s.charAt(i) == to.charAt(j)) continue;
			last = j;
			if (first == -1) first = j;
		}
		return (first << 15) + last;
	}
	
	/*
	boolean canCover (String s, int index) {
		int n = s.length();
		boolean dp [] = new boolean [n + 1];
		dp[0] = true;
		for (int i = 0; i < n; i++) {
			if (dp[i]) {
				int v = 0;
				for (int j = i; j < n; j++) {
					int c = s.charAt(j) - 'a';
					if (next[c][v] == -1) break;
					v = next[c][v];
					if (termIndex[v] != index && termIndex[v] != -1)
						dp[j + 1] = true;
				}
			}
		}
		return dp[n];
	}
	*/
	
	int getAnswer (String s) {
		int n = s.length();
		int dp[][] = new int [n + 1][5];
		for (int i = 0; i <= n; i++)
			Arrays.fill(dp[i], Integer.MAX_VALUE / 2);
		dp[0][4] = 0;
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < small.size(); k++) {
				String to = small.get(k);
				int len = to.length();
				if (len > i) continue;
				int add = getCount(s, i - len, i - 1, to);
				if (add == -1) continue;
				int p = getFirstAndLastChange(s, i - len, i - 1, to);
				int first = (p >> 15);
				int last = p & ((1 << 15) - 1);
				for (int j = 0; j <= 4; j++) {
					if (add == 0) {
						if (dp[i][min (4, j + len)] > dp[i - len][j] + add)
							dp[i][min (4, j + len)] = dp[i - len][j] + add;
					} else {
						if (j + first + 1 <= 4) continue;
						if (dp[i][min (len - last - 1, 4)] > dp[i - len][j] + add) {
							dp[i][min (len - last - 1, 4)] = dp[i - len][j] + add;
						}
					}
				}
			}
		}
		int res = Integer.MAX_VALUE / 2;
		for (int i = 0; i <= 4; i++)
			res = min (res, dp[n][i]);
		return res;
	}
	
	public void solve() throws Exception {
		
		/*
		 * int vCount = 1;
		for (int i = 0; i < 26; i++)
			Arrays.fill(next[i], -1);
		Arrays.fill(termIndex, -1);
		int it = 0;
		*/
		while (in2.ready()) {
			String s = in2.readLine();
			small.add(s);
			/*
			int v = 0;
			for (int i = 0; i < s.length(); i++) {
				int c = s.charAt(i) - 'a';
				if (next[c][v] != -1) {
					v = next[c][v];
				} else {
					next[c][v] = vCount;
					v = vCount;
					vCount++;
				}
			}
			termIndex[v] = it;
			it++;
			*/
		}
		
		/*
		 * for (int i = 0; i < small.size(); i++) {
			if (!canCover(small.get(i), i)) {
				out2.println(small.get(i));
			}
		}
		*/
		int tests = sc.nextInt();
		for (int test = 1; test <= tests; test++) {
			String s = sc.nextToken();
			int answer = getAnswer(s);
			out.println("Case #"+test+": "+answer);
			System.out.println("DONE TEST");
		}
	}
	
	static Throwable uncaught;
	
	BufferedReader in2;
	BufferedReader in;
	FastScanner sc;
	PrintWriter out;
	PrintWriter out2;
	
	@Override
	public void run() {
		try {
			in2 = new BufferedReader(new FileReader("nice_dictionary.txt"));
			in = new BufferedReader(new FileReader("input.txt"));			
			out = new PrintWriter(new FileWriter("output.txt"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable uncaught) {
			Solution.uncaught = uncaught;
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) throws Throwable {
		new Solution().run();
		if (Solution.uncaught != null) {
			throw Solution.uncaught;
		}
	}

}

class FastScanner {
	
	BufferedReader in;
	StringTokenizer st;
	
	public FastScanner(BufferedReader in) {
		this.in = in;
	}
	
	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}
	
	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}
	
	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}
	
}