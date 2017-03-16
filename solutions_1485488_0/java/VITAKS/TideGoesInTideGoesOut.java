import java.io.*;
import java.util.*;

public class TideGoesInTideGoesOut implements Runnable {
	public static void main(String[] args) {
		new Thread(new TideGoesInTideGoesOut()).run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens())
			in = new StringTokenizer(br.readLine());
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public class Pair {
		int x, y;

		public Pair(int t, int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	int[] dx = { 1, 0, -1, 0 };
	int[] dy = { 0, 1, 0, -1 };

	public void solve() throws IOException {
		int H = nextInt();
		int n = nextInt();
		int m = nextInt();

		int[][] f = new int[n][m];
		int[][] c = new int[n][m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c[i][j] = nextInt();
			}
		}
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j <  m; j++){
				f[i][j] = nextInt();
			}
		}
		
		double[][] ans = new double[n][m];
		boolean[][] was = new boolean[n][m];

		for (int i = 0; i < ans.length; i++) {
			Arrays.fill(ans[i], Integer.MAX_VALUE);
		}

		ans[0][0] = 0;

		for (int i = 0; i < n * m; i++) {
			int mx = -1;
			int my = -1;
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					if (mx == -1 && !was[x][y]) {
						mx = x;
						my = y;
					}
					if (!was[x][y] && ans[x][y] < ans[mx][my]){
						mx = x;
						my = y;
					}
				}
			}

			was[mx][my] = true;
			for (int d = 0; d < 4; d++) {
				int nx = mx + dx[d];
				int ny = my + dy[d];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;

				if (c[nx][ny] - f[nx][ny] < 50)
					continue;
				if (c[nx][ny] - f[mx][my] < 50)
					continue;
				if (c[mx][my] - f[nx][ny] < 50)
					continue;

				double h = Math.max(H - 10 * ans[mx][my], 0);
				double minT = 0;
				minT = Math.max((50 - (c[nx][ny] - h)) / 10, minT);
				minT = Math.max((50 - (c[mx][my] - h)) / 10, minT);

				double t = ans[mx][my] + minT;

				if (t == 0)
					ans[nx][ny] = 0;
				
				ans[nx][ny] = Math.min(ans[nx][ny], t
						+ (H - 10 * t - f[mx][my] >= 20 ? 1 : 10));
			}
		}
		out.println(ans[n - 1][m - 1]);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("B.in"));
			out = new PrintWriter("B.out");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.err.println(i);
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
