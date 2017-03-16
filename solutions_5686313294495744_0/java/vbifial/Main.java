import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;

import java.util.*;
import java.io.*;

@SuppressWarnings("unused")
public class Main {
	private static final String FILENAME = "c";

	public static void main(String[] args) throws IOException {
//		new Thread(new Runnable() {
//			
//			@Override
//			public void run() {
//				try {
//					new Main().run();
//				} catch (Exception e) {
//					
//				}
//			}
//		}, 1 << 24) .start();
		new Main().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	private void run() throws IOException {
		in = new BufferedReader(new FileReader(FILENAME + ".in"));
		out = new PrintWriter(FILENAME + ".out");
		solve();
		in.close();
		out.close();
	}
	int N = 1000 * 10;
	
	int head[] = new int[N];
	int next[] = new int[N];
	int to[] = new int[N];
	int cnt = 0;
	
	int pair[] = new int[N];
	
	boolean used[] = new boolean[N];
	
	int lcnt = 0;
	int rcnt = 0;
	
	private void solve() throws IOException {
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			
			int n = nextInt();
			fill(head, -1);
			fill(pair, -1);
			cnt = 0;
			
			HashMap<String, Integer> first = new HashMap<String, Integer>();
			HashMap<String, Integer> second = new HashMap<String, Integer>();
			
			lcnt = 0;
			rcnt = 0;
			
			int ql[] = new int[n];
			int qr[] = new int[n];
			
			boolean ul[] = new boolean[n];
			boolean ur[] = new boolean[n];
			
			for (int i = 0; i < n; i++) {
				String ls = nextToken();
				String rs = nextToken();
				
				int li;
				if (first.containsKey(ls))
					li = first.get(ls);
				else {
					li = lcnt;
					first.put(ls, lcnt++);
				}
				int ri;
				if (second.containsKey(rs))
					ri = second.get(rs);
				else {
					ri = rcnt;
					second.put(rs, rcnt++);
				}
				
				ql[i] = li;
				qr[i] = ri;
				add(li, ri);
			}
			
			for (int i = 0; i < lcnt; i++) {
				fill(used, false);
				dfs(i);
			}
			
			int tcnt = 0;
			for (int i = 0; i < rcnt; i++) {
				if (pair[i] != -1) {
					ur[i] = true;
					ul[pair[i]] = true;
					tcnt++;
				}
			}
			
			for (int i = 0; i < lcnt; i++) {
				for (int j = head[i]; j != -1; j = next[j]) {
					int v = to[j];
					if (!ul[i] || !ur[v]) {
						tcnt++;
					}
					ul[i] = true;
					ur[v] = true;
				}
			}
			
			out.print("Case #" + (t + 1) + ": " + (n - tcnt));
			
			out.println();
		}
		
	}
	
	boolean dfs(int u) {
		if (used[u])
			return false;
		used[u] = true;
		for (int i = head[u]; i != -1; i = next[i]) {
			int v = to[i];
			if (pair[v] == u)
				continue;
			if (pair[v] == -1 || dfs(pair[v])) {
				pair[v] = u;
				return true;
			}
		}
		
		return false;
	}
	
	void add(int u, int v) {
		next[cnt] = head[u];
		to[cnt] = v;
		head[u] = cnt++;
	}
	
	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(Locale.US, fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
