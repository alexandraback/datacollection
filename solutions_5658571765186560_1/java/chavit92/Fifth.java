import java.io.*;
import java.util.*;

public class Fifth {

	boolean solve() throws IOException {
		int c = nextInt();
		int n = nextInt();
		int m = nextInt();
		if (c >= 7) {
			return false;
		}
		if (n * m % c != 0) {
			return false;
		}
		return (c - 1 <= n && c <= m) || (c - 1 <= m && c <= n);
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("D.in"));
		out = new PrintWriter("D.out");
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.println("Case #" + (i + 1) + ": "
					+ (solve() ? "GABRIEL" : "RICHARD"));
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Fifth().run();
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
