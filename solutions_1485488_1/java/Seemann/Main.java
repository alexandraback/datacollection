import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		try {
			inputStream = new FileInputStream("b.in");
			outputStream = new FileOutputStream("b.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		int n = in.nextInt();
		for (int i = 1; i <= n; i++) {
			solver.solve(i, in, out);
		}
		out.close();
	}
}

class Solver {
	public static final int INF = 1000000000;
	public int h, n, m;
	public class Cave implements Comparable<Cave>{
		public int f, c;
		public int x, y;
		public int d;
		public boolean use;
		public Cave() {
			this.d = INF;
			this.use = false;
		}
		public Cave(int f, int c, int x, int y) {
			this.f = f;
			this.c = c;
			this.x = x;
			this.y = y;
			this.d = INF;
			this.use = false;
		}
		public int compareTo(Cave b) {
			if (this.d != b.d)
				return (this.d < b.d)?(-1):(1);
			if (this.x != b.x)
				return (this.x < b.x)?(-1):(1);
			if (this.y != b.y)
				return (this.y < b.y)?(-1):(1);
			return 0;
		}
		public void relax(Cave d) {
			if (this.f > d.c - 50 || d.f > d.c - 50)
				return;
			if (d.f > this.c - 50)
				return;
			if (this.d == 0 && d.c - h >= 50) {
				d.d = 0;
				return;
			}
			int cur = h - this.d;
			int dt = this.d;
			if (cur > d.c - 50) {
				dt += cur - (d.c - 50);
				cur = (d.c - 50);
			}
			if (cur >= this.f + 20)
				dt += 10;
			else
				dt += 100;
			if (d.d > dt)
				d.d = dt;
			return;

		}
	}
	public static final int[][] mv = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		h = in.nextInt();
		n = in.nextInt();
		m = in.nextInt();
		Cave[][] g = new Cave[n][m];
		for (int i = 0; i < n; i++) {
			g[i] = new Cave[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				g[i][j] = new Cave();
				g[i][j].x = i;
				g[i][j].y = j;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				g[i][j].c = in.nextInt();
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				g[i][j].f = in.nextInt();
			}
		}
		g[0][0].d = 0;
		TreeSet<Cave> st = new TreeSet<Cave>();
		st.add(g[0][0]);
		while (st.size() > 0) {
			Cave cur = st.first();
			st.remove(cur);
			for (int i = 0; i < 4; i++) {
				int dx = cur.x + mv[i][0];
				int dy = cur.y + mv[i][1];
				if (dx < 0 || dy <0 || dx >= n || dy >= m)
					continue;
				Cave d = g[dx][dy];
				if (st.contains(d))
					st.remove(d);
				cur.relax(d);
				if (!d.use && d.d < INF)
					st.add(d);
			}
			cur.use = true;
		}
		out.format("Case #%d: %.1f\n", testNumber, ((double)g[n - 1][m - 1].d) / 10);
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
