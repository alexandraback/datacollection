import java.io.*;
import java.util.*;

public class Second {

	int solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++ ){
			a[i] = nextInt();
		}
		int ans = 1000*(n+1);
		for (int t = 1; t <= 1000; t++) {
			int cand = t;
			for (int i = 0; i < n; i++) {
				cand += (a[i]-1)/t;
			}
			ans = Math.min(ans, cand);
		}
		return ans;
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("B.in"));
		out = new PrintWriter("B.out");
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.println("Case #"+(i+1)+": "+solve());
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Second().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String temp = in.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

}
