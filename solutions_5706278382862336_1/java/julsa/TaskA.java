import java.util.*;
import java.io.*;

public class TaskA {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int tt = in.nextInt();
		for (int t = 1; t <= tt; t++) {
			out.print("Case #" + t + ": ");
			String s = in.next();
			long x = Long.parseLong(s.split("/")[0]);
			long y = Long.parseLong(s.split("/")[1]);
			long xx = x;
			long yy = y;
			while ((x > 0) && (y > 0)) {
				if (x > y) {
					x = x % y;
				} else {
					y = y % x;
				}
			}
			xx = xx / (x + y);
			yy = yy / (x + y);
			y = yy;
			int k = 0;
			while (y % 2 == 0) {
				k++;
				y = y / 2;
			}
			if ((k > 40) || (y > 1)) {
				out.println("impossible");
			} else {
				int p = 0;
				while (xx > 1) {
					xx = xx / 2;
					p++;
				}
				out.println(k - p);
			}

		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("TaskA.in"));
			out = new PrintWriter(new File("TaskA.out"));

			solve();

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
				e.printStackTrace();
			}
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
	}

	public static void main(String[] arg) {
		new TaskA().run();
	}
}