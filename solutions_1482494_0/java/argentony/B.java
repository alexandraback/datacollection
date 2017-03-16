import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;

	public void run() {
		try {
			br = new BufferedReader(new FileReader("B-small-attempt2.in"));
			out = new PrintWriter("B-small-attempt2.out");
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
			System.out.println(test);
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int[] a = new int[n];
			int[] b = new int[n];
			
			for (int i = 0; i < n; ++i) {
				a[i] = nextInt();
				b[i] = nextInt();
			}
			
			int[] p = new int[n];
			int m = 0;
			int ans = 0;
			while (m < 2 * n) {
				++ans;
				int t = -1;
				for (int i = 0; i < n; ++i) {
					if (b[i] <= m && p[i] < 2) {
						t = i;
						break;
					}
				}
 
				if (t >= 0) {
					m += 2 - p[t];
					p[t] = 2;
					continue;
				}
				
				for (int i = 0; i < n; ++i) {
					if (a[i] <= m && p[i] < 1 && (t < 0 || b[i] > b[t])) {
						t = i;
					}
				}
				
				if (t >= 0) {
					m += 1 - p[t];
					p[t] = 1;
					continue;
				}
				
				break;
			}
			
			if (m < 2 * n) {
				out.println("Too Bad");
			} else {
				out.println(ans);
			}
			out.flush();
		}
	}
}
