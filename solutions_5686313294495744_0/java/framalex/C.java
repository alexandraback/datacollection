
package gcj.c2016.r1b;


import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class C implements Runnable {


	public void run() {
		int tests = nextInt();
		for (int iter = 1; iter <= tests; ++iter) {
			int words = nextInt();
			HashMap<String, Integer> w1 = new HashMap<>();
			HashMap<String, Integer> w2 = new HashMap<>();
			ArrayList<String> ww1 = new ArrayList<>();
			ArrayList<String> ww2 = new ArrayList<>();
			for (int i = 0;  i< words; ++i) {
				String s1 = nextWord();
				if (!w1.containsKey(s1)) {
					w1.put(s1, 0);
				}
				int tmp = w1.get(s1);
				w1.put(s1, tmp+1);

				String s2 = nextWord();
				if (!w2.containsKey(s2)) {
					w2.put(s2, 0);
				}
				tmp = w2.get(s2);
				w2.put(s2, tmp+1);

				ww1.add(s1);
				ww2.add(s2);
			}

			int[][] dp = new int[1 << words][words];
			for (int i = 0; i < (1 << words); ++i) {
				int max = 0;
				for (int j = 0; j < words; ++j) {
					max = Math.max(dp[i][j], max);
				}
				for (int j = 0; j < words; ++j) {
					if ((i & (1<<j)) != 0) {
						continue;
					}

					boolean originalOne = true;
					boolean originalSec = true;
					for (int k = 0; k < words; ++k) {
						if ((i & (1<<k)) == 0) {
							continue;
						}

						if (ww1.get(k).equals(ww1.get(j))) {
							originalOne = false;
						}
						if (ww2.get(k).equals(ww2.get(j))) {
							originalSec = false;
						}
					}

					if (!originalOne && !originalSec) {
						dp[i | (1<<j)][j] = Math.max(dp[i | (1<<j)][j], max + 1);
					}
					else {
						dp[i | (1<<j)][j] = Math.max(dp[i | (1<<j)][j], max);
					}
				}
			}



			int ans2 = 0;
			for (int i = 0; i < words; ++i) {
				ans2 = Math.max(ans2, dp[(1<<words) - 1][i]);
			}
			out.println("Case #" + iter + ": " + ans2);
		}
		out.flush();
	}


	private static BufferedReader br = null;
	private static PrintWriter out = null;
	private static StringTokenizer stk = null;
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("C.txt")));
		out = new PrintWriter("CC.txt");
		(new C()).run();
	}

	private void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

	private String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	private int nextInt() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}

	private long nextLong() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Long.parseLong(stk.nextToken());
	}

	private double nextDouble() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}

	private String nextWord() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return (stk.nextToken());
	}
}
