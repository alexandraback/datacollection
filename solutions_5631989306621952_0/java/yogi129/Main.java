import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

	public static void main(String args[]) {
		MyScanner input = new MyScanner();

		int T = input.nextInt();

		for (int t = 0; t < T; ++t) {
			String S = input.next();

			StringBuilder sb = new StringBuilder();
			sb.append(S.charAt(0));

			for (int i = 1; i < S.length(); ++i) {
				char ch = S.charAt(i);

				if (ch >= sb.charAt(0)) {
					sb.insert(0, ch);
				} else {
					sb.append(ch);
				}
			}

			System.out.print("Case #" + (t + 1) + ": ");

			System.out.println(sb);
		}
	}

	// -----------MyScanner class for faster input----------
	static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		boolean hasNext() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				} catch (NullPointerException e) {
					return false;
				}
			}
			return true;
		}

		String next() {
			if (hasNext()) {
				return st.nextToken();
			}
			return null;
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

		float nextFloat() {
			return Float.parseFloat(next());
		}

		/**
		 * don't use this method along with any of above methods
		 * 
		 * @return
		 */
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}
