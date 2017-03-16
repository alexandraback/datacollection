import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;

	public void run() {
		try {
//			br = new BufferedReader(new FileReader("A-sample.in"));
//			out = new PrintWriter("A-sample.out");
//			br = new BufferedReader(new FileReader("A-small-attempt0.in"));
//			out = new PrintWriter("A-small-attempt0.out");
			br = new BufferedReader(new FileReader("A-large.in"));
			out = new PrintWriter("A-large.out");
			solve();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(-1);
		} finally {
			out.close();
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	void solve() throws IOException {
		int T = nextInt();
		for (int test = 1; test <= T; ++test) {
			System.out.println("Case #" + test);
			out.print("Case #" + test + ": ");
			int a = nextInt();
			int b = nextInt();
			double ans = Math.min(b + 2, a + b + 1);
			double p = 1;
			for (int i = 0; i < a; ++i) {
				double pi = nextDouble();
				p *= pi;
				ans = Math.min(ans, (2 * (a - i - 1) + (b - a) + 1) + (b + 1 - p * (b + 1)));
			}
			
			out.println(ans);
			out.flush();
		}
	}
}
