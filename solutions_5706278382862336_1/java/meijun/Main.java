import java.util.*;
import java.io.*;

import static java.util.Arrays.*;
import static java.lang.Math.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner in = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	long[] pw = new long[60];
	void run() {
		pw[0] = 1;
		for (int i = 1; i < 60; i++) pw[i] = pw[i - 1] * 2;
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			out.printf("Case #%d: ", i);
			solve();
		}
	}
	
	void solve() {
		String[] ss = in.next().split("/");
		long p = Long.parseLong(ss[0]), q = Long.parseLong(ss[1]);
		if (p > q) {im(); return ;}
		int cnt = 0;
		while (q % 2 == 0) {
			if (p >= q) break;
			q /= 2;
			cnt++;
		}
		if (p == q) out.println(cnt);
		else {
			p -= q;
			if (binarySearch(pw, q) < 0) im();
			else out.println(cnt);
		}
	}
	void im() {
		out.println("impossible");
	}
	
	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		long start = System.nanoTime();
		if (LOCAL) {
			try {
				System.setIn(new FileInputStream("./../in"));
				System.setOut(new PrintStream("./../out.txt"));
			} catch (IOException e) {
				LOCAL = false;
			}
		}
		Main main = new Main();
		main.run();
		main.out.close();
		if (LOCAL)
			System.err.printf("[Time %.6fs]%n",
					(System.nanoTime() - start) * 1e-9);
	}
}

class Scanner {
	BufferedReader br;
	StringTokenizer st;

	Scanner(InputStream in) {
		br = new BufferedReader(new InputStreamReader(in));
		eat("");
	}

	private void eat(String string) {
		st = new StringTokenizer(string);
	}

	String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			return null;
		}
	}

	boolean hasNext() {
		while (!st.hasMoreTokens()) {
			String s = nextLine();
			if (s == null)
				return false;
			eat(s);
		}
		return true;
	}

	String next() {
		hasNext();
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