import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	long gcd(long a, long b) {
		while (b != 0) {
			a %= b;
			long temp = a;
			a = b;
			b = temp;
		}
		return a;
	}

    public void solve() throws Exception {
    	int T = sc.nextInt();
    	for (int Case = 1; Case <= T; Case++) {
    		String[] tokens = sc.nextToken().split("/");
    		long p = Long.parseLong(tokens[0]), q = Long.parseLong(tokens[1]);
    		long d = gcd(p, q);
    		p /= d;
    		q /= d;
    		out.printf(Locale.US, "Case #%d: ", Case);
    		if ((1L << 40) % q != 0) {
    			out.println("impossible");
    		} else {
    			int ans = 0;
    			while (p < q / (1L << ans)) {
    				ans++;
    			}
    			out.println(ans);
    		}
    	}
    }

    static Throwable uncaught;

    BufferedReader in;
    FastScanner sc;
    PrintWriter out;

    @Override
    public void run() {
        try {
        	in = new BufferedReader(new FileReader("A-small-attempt0.in"));
        	out = new PrintWriter(new FileWriter("A-small-attempt0.out"));
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