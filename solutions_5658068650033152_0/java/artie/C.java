import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class C implements Runnable {

	private PrintWriter out;
	
	final String file = "src\\C-small";
	Random rnd = new Random(42);

	static class InputData {

        int n, m, k;
        int[][] col, set, escape;
		int[] dx = {0, -1, 0, 1};
		int[] dy = {-1, 0, 1, 0};
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            col = new int[n][m];
			set = new int[n][m];
			escape = new int[n][m];
		}
		
		void solve(PrintWriter out) {
			int ans = Integer.MAX_VALUE;
			int max = 1 << (n * m);
			int[] qi = new int[n * m];
			int[] qj = new int[n * m];
			for (int mask = 0; mask < max; mask++) {
				for (int i = 0; i < n; i++) {									
					Arrays.fill(set[i], 0);
					Arrays.fill(escape[i], 0);
				}
				if (mask == 14894 && n == 3 && m == 5)
					mask += 0;
				for (int i = 0; i < n * m; i++)
					if (((mask >> i) & 1) != 0)
						set[i / m][i % m] = 1;
				for (int i = 0; i < n * m; i++) {
					int sx = i / m;
					int sy = i % m;
					if (set[sx][sy] == 1) {
						escape[sx][sy] = 1;
						continue;
					}
					for (int j = 0; j < n; j++)
						Arrays.fill(col[j], 0);
					int tail = -1;
					int head = -1;
					qi[++head] = sx;
					qj[head] = sy;
					col[sx][sy] = 1;
					while (tail < head) {
						int cx = qi[++tail];
						int cy = qj[tail];
						for (int k = 0; k < 4; k++) {
							int nx = cx + dx[k];
							int ny = cy + dy[k];
							if (nx >= 0 && nx < n && ny >= 0 && ny < m && col[nx][ny] == 0 && set[nx][ny] == 0) {
								qi[++head] = nx;
								qj[head] = ny;
								col[nx][ny] = 1;
							}
						}
					}
					boolean esc = false;
					for (int j = 0; j < n; j++) {
						if (col[j][0] == 1 || col[j][m - 1] == 1)
							esc = true;
					}
					for (int j = 0; j < m; j++) {
						if (col[0][j] == 1 || col[n - 1][j] == 1)
							esc = true;
					}
					if (!esc)
						escape[sx][sy] = 1;
						
				}
				int c = 0;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						if (escape[i][j] == 1)
							c++;
				if (c >= k)
					ans = Math.min(ans, Integer.bitCount(mask));
			}
            out.println(ans);
		}

		private void dfs(int sx, int sy) {
			// TODO Auto-generated method stub
			col[sx][sy] = 1;
			if (set[sx][sy] == 1) {
				return;
			}
			int sc = 0;
			for (int k = 0; k < 4; k++) {
				int nx = sx + dx[k];
				int ny = sy + dy[k];
				if (nx < 0 || nx == n || ny < 0 || ny == m) {
					escape[sx][sy] = -1;
					return;
				}
				if (set[nx][ny] == 0 && col[nx][ny] == 0)
					dfs(nx, ny);
				if (set[nx][ny] == 1 || escape[nx][ny] == 1) {
					sc++;
				}
			}
			if (sc == 4) {
				escape[sx][sy] = 1;
			}			
		}
	}
	
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			StringWriter out = new StringWriter();
			data.solve(new PrintWriter(out));
			return out.toString();
		}
		
	}

	public void run() {
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
			out = new PrintWriter(file + ".out");
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(3);
			
			int tests = in.nextInt();
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(in)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static class FastReader {
		public FastReader(BufferedReader in) {
			this.in = in;
			eat("");
		}
		
		private StringTokenizer st;
		private BufferedReader in;
		
		void eat(String s) {
			st = new StringTokenizer(s);
		}
		
		String next() throws IOException {
			while (!st.hasMoreTokens()) {
				String line = in.readLine();
				if (line == null) {
					return null;
				}
				eat(line);
			}
			return st.nextToken();
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new C().run();
	}
	
}
