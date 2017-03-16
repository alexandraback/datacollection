import java.util.*;
import java.io.*;

import static java.util.Arrays.*;
import static java.lang.Math.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner in = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	
	void run() {
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			out.printf("Case #%d: ", i);
			solve();
		}
	}
	void solve() {
		int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
		int comp = (1 << k) - 1;
		int ans = k;
		while (comp < 1 << (n * m)) {
			ans = min(ans, calc(comp, n, m));
			int x = comp & -comp, y = comp + x;
			comp = ((comp & ~y) / x >> 1) | y;
		}
		out.println(ans);
	}
	int calc(int c, int n, int m) {
		boolean[][] vis = new boolean[n][m];
		for (int i = 0; i < n * m; i++) {
			if ((c & (1 << i)) != 0) {
				vis[i / m][i % m] = true;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (fit(vis, i, j)) cnt++;
			}
		}
		return cnt;
	}
	void solve2() {
		int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
		out.print(n + " " + m + " " + k);
		boolean[][] vis = new boolean[n][m];
		PriorityQueue<Item> pq = new PriorityQueue<>();
		cx = (n - 1) / 2.0; cy = (m - 1) / 2.0;
		int ex = n / 2, ey = m / 2;
		pq.add(new Item(ex, ey));
		vis[ex][ey] = true;
		boolean[][] maps = new boolean[n][m];
		while (!pq.isEmpty()) {
			Item crt = pq.poll();
			int x = crt.x, y = crt.y;
			maps[x][y] = true;
			if (--k == 0) break;
			for (int i = 0; i < 4; i++) {
				int tx = x + dx[i], ty = y + dy[i];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty]) {
					vis[tx][ty] = true;
					pq.add(new Item(tx, ty));
				}
			}
		}
		print(maps);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (fit(maps, i, j)) cnt++;
			}
		}
		out.println(cnt);
	}
	void print(boolean[][] vis) {
		out.println();
		for (int i = 0; i < vis.length; i++) {
			for (int j = 0; j < vis[i].length; j++) {
				if (vis[i][j]) out.print(1);
				else out.print(0);
			}
			out.println();
		}
		
	}
	boolean fit(boolean[][] vis, int x, int y) {
		if (!vis[x][y]) return false;
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (!(tx >= 0 && tx < vis.length && ty >= 0 && ty < vis[0].length)
				|| !vis[tx][ty]) return true;
		}
		return false;
	}
	int[] dx = {0, -1, 1, 0};
	int[] dy = {-1, 0, 0, 1};
	double cx, cy;
	class Item implements Comparable<Item> {
		int x, y;
		double dis;
		public Item(int x, int y) {
			this.x = x;
			this.y = y;
			this.dis = (x - cx) * (x - cx) + (y - cy) * (y - cy);
		}
		@Override
		public int compareTo(Item o) {
			return Double.compare(dis, o.dis);
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