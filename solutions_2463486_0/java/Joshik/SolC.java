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

	private final String FNAME = "C-small-attempt0";
	
	int[] ch = new int[15];
	
	boolean pal(long t) {
		int len = 0;
		while (t > 0) {
			ch[len] = (int) (t % 10);
			t /= 10;
			len++;
		}
		for (int i = 0; i < len - i - 1; i++) {
			if (ch[i] != ch[len - i - 1]) return false;
		}
		return true;
	}

	void solve() {
		int MAX = 10000000;
		ArrayList<Long> good = new ArrayList<Long>();
		for (long a = 1; a <= MAX; a++) {
			if (pal(a) && pal(a * a)) {
				good.add(a * a);
//				System.err.println(a + " " + a * a);
			}
		}
//		System.err.println(good.size());
		int tests = nextInt();
		all: for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			long a = nextLong();
			long b = nextLong();
			int ans = 0;
			for (long t : good) {
				if (t >= a && t <= b) {
					ans++;
				}
			}
			out.println(ans);
		}
	}
}
