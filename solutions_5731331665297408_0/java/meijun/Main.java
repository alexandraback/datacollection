import java.util.*;
import java.io.*;

import static java.util.Arrays.*;
import static java.lang.Math.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner in = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	private int n;
	private V[] vs;

	void run() {
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			out.printf("Case #%d: ", i);
			solve();
		}
	}
	
	class V extends ArrayList<V> implements Comparable<V> {
		int p;
		int id;
		boolean vis;
		V(int p) {
			this.p = p;
		}
		@Override
		public int compareTo(V o) {
			return p - o.p;
		}
	}
	void solve() {
		n = in.nextInt();
		int m = in.nextInt();
		vs = new V[n];
		for (int i = 0; i < n; i++) {
			vs[i] = new V(in.nextInt());
		}
		for (int i = 0; i < m; i++) {
			int u = in.nextInt() - 1, v = in.nextInt() - 1;
			vs[u].add(vs[v]);
			vs[v].add(vs[u]);
		}
		for (V v : vs) Collections.sort(v);
		sort(vs);
		c = 0;
		dfs(vs[0]);
	}
	int c;
	private void dfs(V v) {
		v.id = c;
		v.vis = true;
		if (c == n - 1) {
			for (int i = 0; i < n; i++) {
				for (V u : vs) if (u.id == i) out.print(u.p);
			}
			out.println();
		}
		c++;
		for (V u : v) {
			if (!u.vis) dfs(u);
		}
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