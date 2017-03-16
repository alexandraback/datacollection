import java.util.*;
import java.io.*;

public class CodeJam {
	FastScanner in;
	PrintWriter out;
	
	int r, n, m, k;
	double[][] count;
	
	public void solve() throws IOException {
		r = in.nextInt();
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		Random rng = new Random();
		count = new double[600][200];
		boolean[] was = new boolean[600];
		for (int i = 2; i <= m; i++) {
			for (int j = 2; j <= m; j++) {
				for (int k = 2; k <= m; k++) {
					int x = 100 * i + 10 * j + k;
					int sum = 100_000;
					was[x] = true;
					for (int ii = 0; ii < sum; ii++) {
						int mask = rng.nextInt(8);
						int mul = 1;
						if ((mask & 1) != 0) {
							mul *= i;
						}
						if ((mask & 2) != 0) {
							mul *= j;
						}
						if ((mask & 4) != 0) {
							mul *= k;
						}
						count[x][mul]++;
					}
					for (int ii = 0; ii < 200; ii++) {
						count[x][ii] /= sum;
					}
				}
			}
		}
		for (int i = 0; i < r; i++) {
			int[] a = new int[k];
			for (int j = 0; j < k; j++) {
				a[j] = in.nextInt();
			}
			int best = 0;
			double bestsum = 0;
			for (int j = 0; j < 600; j++) {
				if (was[j]) {
					double cur = 0;
					for (int x : a) {
						cur += count[j][x];
					}
					if (cur > bestsum) {
						bestsum = cur;
						best = j;
					}
				}
			}
			out.println(best);
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));
			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.println("Case #" + (i + 1) + ": ");
				solve();
			}
			
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return true;
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
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

	public static void main(String[] arg) {
		new CodeJam().run();
	}
}