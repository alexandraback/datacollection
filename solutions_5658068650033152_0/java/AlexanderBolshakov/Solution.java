import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	int n, m;
	int[][] field;
	
	boolean inBounds(int i, int j) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}
	
	int dfs(int i, int j) {
		if (field[i][j] == 0) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				field[i][j] = 1;
			} else {
				field[i][j] = 2;
				if (inBounds(i - 1, j) && dfs(i - 1, j) == 1) {
					field[i][j] = 1;
				}
				if (inBounds(i + 1, j) && dfs(i + 1, j) == 1) {
					field[i][j] = 1;
				}
				if (inBounds(i, j - 1) && dfs(i, j - 1) == 1) {
					field[i][j] = 1;
				}
				if (inBounds(i, j + 1) && dfs(i, j + 1) == 1) {
					field[i][j] = 1;
				}
			}
		}
		return field[i][j];
	}

    public void solve() throws Exception {
    	int T = sc.nextInt();
    	for (int Case = 1; Case <= T; Case++) {
    		n = sc.nextInt();
    		m = sc.nextInt();
    		int k = sc.nextInt();
    		field = new int[n][m];
    		int ans = n * m;
    		for (int mask = 0; mask < (1 << (n * m)); mask++) {
    			for (int i = 0; i < n; i++) {
    				for (int j = 0; j < m; j++) {
    					if ((mask & (1 << (i * m + j))) != 0) {
    						field[i][j] = 2;
    					} else {
    						field[i][j] = 0;
    					}
    				}
    			}
    			int cnt = 0;
    			for (int i = 0; i < n; i++) {
    				for (int j = 0; j < m; j++) {
    					if (dfs(i, j) == 2) {
    						cnt++;
    					}
    				}
    			}
    			if (cnt >= k) {
    				ans = min(ans, Integer.bitCount(mask));
    			}
    		}
    		out.printf(Locale.US, "Case #%d: %d\n", Case, ans);
    		System.err.printf(Locale.US, "Case #%d: %d\n", Case, ans);
    	}
    }

    static Throwable uncaught;

    BufferedReader in;
    FastScanner sc;
    PrintWriter out;

    @Override
    public void run() {
        try {
        	in = new BufferedReader(new FileReader("C-small-attempt1.in"));
        	out = new PrintWriter(new FileWriter("C-small-attempt1.out"));
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
        Thread thread = new Thread(null, new Solution(), "", (1 << 26));
        thread.start();
        thread.join();
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