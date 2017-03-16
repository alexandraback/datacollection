import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	String[] p;
	int ans;
	
	boolean check(String str) {
		boolean[] visited = new boolean[256];
		for (int i = 0; i < str.length(); ) {
			if (visited[str.charAt(i)]) {
				return false;
			}
			int j = i;
			while (j < str.length() && str.charAt(j) == str.charAt(i)) {
				j++;
			}
			visited[str.charAt(i)] = true;
			i = j;
		}
		return true;
	}
	
	void backtrack(int n, int pos) {
		if (pos == n) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < n; i++) {
				sb.append(p[i]);
			}
			if (check(sb.toString())) {
				ans++;
			}
		} else {
			for (int i = pos; i < n; i++) {
				String temp = p[i];
				p[i] = p[pos];
				p[pos] = temp;
				backtrack(n, pos + 1);
				temp = p[i];
				p[i] = p[pos];
				p[pos] = temp;
			}
		}
	}
	
    public void solve() throws Exception {
    	int T = sc.nextInt();
    	for (int Case = 1; Case <= T; Case++) {
    		int n = sc.nextInt();
    		p = new String[n];
    		ans = 0;
    		for (int i = 0; i < n; i++) {
    			p[i] = sc.nextToken();
    		}
    		backtrack(n, 0);
    		out.printf(Locale.US, "Case #%d: %d\n", Case, ans);
    		System.err.println(Case);
    	}
    }

    static Throwable uncaught;

    BufferedReader in;
    FastScanner sc;
    PrintWriter out;

    @Override
    public void run() {
        try {
        	in = new BufferedReader(new FileReader("B-small-attempt0.in"));
        	out = new PrintWriter(new FileWriter("B-small-attempt0.out"));
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