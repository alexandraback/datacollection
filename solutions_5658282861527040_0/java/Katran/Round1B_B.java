import java.io.*;
import java.math.*;
import java.util.*;

public class Round1B_B implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	boolean file = true;
	String fileName = "B-small";

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Round1B_B().run();
	}

	private String next() throws Exception {
		if (st == null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	private double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public void run() {
		try {
			if (file)
				in = new BufferedReader(new FileReader(fileName+".in"));
			else
				in = new BufferedReader(new InputStreamReader(System.in));
			if (file)
				out = new PrintWriter(new FileWriter(fileName+".out"));
			else
				out = new PrintWriter(System.out);
			solve();
		} catch (Exception ex) {
			throw new RuntimeException(ex);
		} finally {
			out.close();
		}
	}

	public void solve() throws Exception {
		long oo = 100000000000L;
		int cases = Integer.parseInt(in.readLine());
		for(int step = 1; step <= cases; step++){
			int a = nextInt(), b = nextInt(), k = nextInt(), cnt = 0;
			for(int i=0; i<a; i++) {
				for(int j = 0; j<b; j++) {
					int c = i&j;
					if(c < k)
						cnt++;
				}
			}
			out.println("Case #"+step+": "+cnt);
		}
		
	}
	
}