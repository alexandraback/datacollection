import java.io.*;
import java.util.*;

public class C implements Runnable {
	private MyScanner in;
	private PrintWriter out;

	private void solve() {
		int a = in.nextInt();
		int b = in.nextInt();
		int mul = 1;
		int pow = 0;
		while (a >= mul * 10) {
			mul *= 10;
			++pow;
		}
		int ans = 0;
		int[] lastSeen = new int[b + 1];
		for (int i = a; i <= b; ++i) {
			if (i == mul * 10) {
				mul *= 10;
				++pow;
			}
			int temp = i;
			for (int j = 0; j < pow; ++j) {
				temp = temp / 10 + mul * (temp % 10);
				if (temp > i && temp <= b && lastSeen[temp] < i) {
					++ans;
					lastSeen[temp] = i;
				}
			}
		}
		out.println(ans);
	}

	@Override
	public void run() {
		in = new MyScanner();
		try {
			out = new PrintWriter(new File("C-large.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int tests = in.nextInt();
		for (int i = 0; i < tests; ++i) {
			out.print("Case #" + (i + 1) + ": ");
			solve();
		}
		in.close();
		out.close();
	}

	public static void main(String[] args) {
		new C().run();
	}

	class MyScanner {
		private BufferedReader br;
		private StringTokenizer st;

		public MyScanner() {
			try {
				br = new BufferedReader(new FileReader("C-large.in"));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public void close() {
			try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		public boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
					return false;
				}
			}
			return st != null && st.hasMoreTokens();
		}

		private String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return null;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
					return null;
				}
			}
			return st.nextToken();
		}

		public String nextLine() {
			try {
				st = null;
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
				return null;
			}
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
}