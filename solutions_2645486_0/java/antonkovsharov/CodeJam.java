import java.util.*;
import java.io.*;

public class CodeJam {
	FastScanner in;
	PrintWriter out;
	
	long[] v;
	long e, r;
	int n;
	long ans = 0, curAns = 0;
	
	void gen(int i, long cur) {
		if (i == n) {
			if (curAns > ans) {
				ans = curAns;
			}
			return;
		}
		cur = Math.min(e, cur + r);
		for (int count = 0; count <= cur; count++) {
			curAns += count * v[i];
			gen(i + 1, cur - count);
			curAns -= count * v[i];
		}
	}
	
	public void solve() throws IOException {
		e = in.nextInt();
		r = in.nextInt();
		n = in.nextInt();
		v = new long[n];
		if (r > e) {
			r = e;
		}
		ans = 0;
		curAns = 0;
		for (int i = 0; i < n; i++) {
			v[i] = in.nextLong();
		}
		gen(0, e);
		out.println(ans);
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));
			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return true;
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new CodeJam().run();
	}
}