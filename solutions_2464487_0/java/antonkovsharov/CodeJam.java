import java.util.*;
import java.io.*;

public class CodeJam {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		long r = in.nextLong(), t = in.nextLong();
		long left = 1, right = Long.MAX_VALUE / 8;
		while (right - left > 1) {
			long mid = (left + right) / 2;
			if (1.0 * (2 * r + 2 * mid - 1) * mid <= Long.MAX_VALUE / 2 && (2 * r + 2 * mid - 1) * mid <= t) {
				left = mid;
			} else {
				right = mid;
			}
		}
		out.println(left);
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));
			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
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