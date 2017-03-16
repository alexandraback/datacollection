import java.util.*;
import java.io.*;

//import java.math.*;

public class SolC implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolC()).start();
	}

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
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

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	private final String FNAME = "C-small";

	int[] A, B;
	long[] a, b;

	long bt(int i, int j, long used, long used2, long cnt) {
		if (i == A.length || j == B.length) {
			return cnt;
		}
		long ret = bt(i + 1, j, 0l, used2, cnt);
		while (j < B.length && B[j] != A[i]) {
			j++;
		}
		if (j < B.length) {
			if (a[i] - used == b[j] - used2) {
				long t = Math.min(a[i] - used, b[j] - used2);
				cnt += t;
				return Math.max(ret, bt(i + 1, j + 1, 0l, 0l, cnt));
			} else if (a[i] - used > b[j] - used2) {
				long t = Math.min(a[i] - used, b[j] - used2);
				cnt += t;
				used += t;
				used2 += t;
				return Math.max(ret, bt(i, j + 1, used, 0l, cnt));
			} else {
				long t = Math.min(a[i] - used, b[j] - used2);
				cnt += t;
				used += t;
				used2 += t;
				return Math.max(ret, bt(i + 1, j, 0l, used2, cnt));
			}
		}
		return ret;
	}

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + (test) + ": ");
			int n = nextInt();
			int m = nextInt();
			a = new long[n];
			A = new int[n];
			b = new long[m];
			B = new int[m];
			for (int i = 0; i < n; i++) {
				a[i] = nextLong();
				A[i] = nextInt();
			}
			for (int i = 0; i < m; i++) {
				b[i] = nextLong();
				B[i] = nextInt();
			}
			out.println(bt(0, 0, 0l, 0l, 0l));
		}
	}
}
