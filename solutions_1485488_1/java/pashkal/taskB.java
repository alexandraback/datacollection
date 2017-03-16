import java.io.*;
import java.util.*;

public class taskB {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	class state {
		int x, y, h;

		public state(int x, int y, int h) {
			super();
			this.x = x;
			this.y = y;
			this.h = h;
		}

	}

	public void solve() throws IOException {
		int h = nextInt();
		int n = nextInt();
		int m = nextInt();
		int[][] c = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c[i][j] = nextInt();
			}
		}
		int[][] f = new int[n][m];
		int[][] was = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				f[i][j] = nextInt();
				was[i][j] = Integer.MIN_VALUE;
			}
		}

		ArrayList<state> q = new ArrayList<state>();
		q.add(new state(0, 0, h));
		was[0][0] = h;

		double ans = Integer.MAX_VALUE;
		for (int i = 0; i < q.size(); i++) {
			state t = q.get(i);
			if ((t.x == n - 1) && (t.y == m - 1)) {
				ans = Math.min(((h - t.h) * 1.0 / 10), ans);
				
			}
			for (int dx = -1; dx < 2; dx++) {
				for (int dy = -1; dy < 2; dy++) {
					if (Math.abs(dx) + Math.abs(dy) != 1)
						continue;
					if ((t.x + dx < 0) || (t.x + dx >= n))
						continue;
					if ((t.y + dy < 0) || (t.y + dy >= m))
						continue;
					int nx = t.x + dx;
					int ny = t.y + dy;
					if (c[nx][ny]
							- Math.max(f[nx][ny], f[t.x][t.y]) < 50)
						continue;
					if (c[t.x][t.y] - f[nx][ny] < 50)
						continue;
					int th = t.h;
					if (c[nx][ny] - th < 50)
						th = c[nx][ny] - 50;
					if (th < h) {
						if (th - f[t.x][t.y] < 20)
							th -= 100;
						else
							th -= 10;
					}
					// th = Math.max(th, 0);
					if (th <= was[nx][ny])
						continue;
					was[nx][ny] = th;
					q.add(new state(nx, ny, th));
				}
			}
		}
		out.println(ans);
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("taskB.in"));
			out = new PrintWriter("taskB.out");

			int n = nextInt();
			for (int i = 0; i < n; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskB().run();
	}
}
