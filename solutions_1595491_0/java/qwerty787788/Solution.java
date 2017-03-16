import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int cases = in.nextInt();
		for (int nowCase = 1; nowCase <= cases; nowCase++) {
			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();
			int ans = 0;
			for (int i = 0; i < N; i++) {
				int t = in.nextInt();
				if ((t + 2) / 3 >= p) {
					ans++;
				} else {
					if ((t + 4) / 3 >= p && S > 0 && (t != 0)) {
						S --;
						ans++;
					}
				}
			}
			//
			out.print("Case #");
			out.print(nowCase);
			out.print(": ");
			//
			out.print(ans);
			//
			out.println();
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("b.in"));
			out = new PrintWriter(new File("b.out"));

			//in = new FastScanner(System.in);
			//out = new PrintWriter(System.out);

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

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
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
		
		String readLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return " ";
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}