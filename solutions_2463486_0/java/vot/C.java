import java.util.*;
import java.io.*;

public class C {
	private void solve() throws Exception {
		long from = nextLong(), to = nextLong();
		//long from = 1, to = 100000000000000L;
		int ans = 0;
		for (long base : goodBases) {
			if (base * base < from || base * base > to) {
				continue;
			}
			++ans;
		}
		out.println(ans);
	}

	private boolean isPalindrome(long x) {
		char[] c = Long.toString(x).toCharArray();
		for (int i = 0; i < c.length / 2; ++i) {
			if (c[i] != c[c.length - i - 1]) {
				return false;
			}
		}
		return true;
	}
	
	ArrayList<Long> goodBases = new ArrayList<>();

	private void preProcess() {
		for (long base = 1; base * base <= 100000000000000L; ++base) {
			if (isPalindrome(base) && isPalindrome(base * base)) {
				System.out.println(base + " " + base * base);
				goodBases.add(base);
			}
		}
	}

	public void run() {
		try {
			preProcess();
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private C(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		new C("C").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
