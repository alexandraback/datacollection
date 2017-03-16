import java.util.*;
import java.io.*;

public class C1_A {

	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int q = in.nextInt();
		for (int qq = 1; qq <= q; qq++) {
			out.print("Case #" + qq + ": ");
			int c = in.nextInt();
			int r = in.nextInt();
			int w = in.nextInt();
			int ans = (r / w) * c + w;
			if (r % w == 0) {
				ans--;
			}
			ans = Math.min(ans, r * c);
			out.println(ans);
		}

	}

	public void run() {
		try {
			in = new FastScanner(new File("input.in"));
			out = new PrintWriter(new File("output.out"));

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
		new C1_A().run();
	}
}
