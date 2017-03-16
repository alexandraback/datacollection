import java.io.*;
import java.util.*;

public class First {

	int solve() throws IOException {
		int n = nextInt();
		String str = next();
		int cnt = 0;
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			if (str.charAt(i) != '0' && i > cnt) {
				ans += i - cnt;
				cnt = i;
			}
			cnt += str.charAt(i) - '0';
		}
		return ans;
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter("A.out");
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.println("Case #"+(i+1)+": "+solve());
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new First().run();
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
