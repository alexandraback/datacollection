import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	FastScanner in;
	PrintWriter out;

	public String sol(int x, int y) {
		StringBuilder sb = new StringBuilder();
		int curX = 0, curY = 0;
		while (x != curX || y != curY) {
			if (curX < x) {
				sb.append('W');
				sb.append('E');
				curX++;
			}
			else if(curX > x) {
				sb.append('E');
				sb.append('W');
				curX--;
			}
			if (curY < y) {
				sb.append('S');
				sb.append('N');
				curY++;
			} else if (curY > y) {
				sb.append('N');
				sb.append('S');
				curY--;
			}
		}
		return sb.toString();
	}
	
	public void solve() throws IOException {
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			out.println("Case #" + (i + 1) + ": " + sol(x, y));
		}
	}

	public void run() {
		try {
			InputStream inputStream = System.in;
			in = new FastScanner(inputStream);
			out = new PrintWriter("out.out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		public boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String line = br.readLine();
					if (line == null) {
						return false;
					}
					st = new StringTokenizer(line);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			if (st != null && st.hasMoreTokens()) {
				return true;
			}
			return false;
		}

		public String next() {
			if (hasNext()) {
				return st.nextToken();
			}
			return null;
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}