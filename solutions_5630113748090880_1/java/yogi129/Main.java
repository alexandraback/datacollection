import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

class Main {

	public static void main(String args[]) {
		MyScanner input = new MyScanner();

		int T = input.nextInt();

		for (int t = 0; t < T; ++t) {
			int N = input.nextInt();

			Map<Integer, Integer> map = new TreeMap<Integer, Integer>();

			for (int i = 0; i < 2 * N - 1; ++i) {
				for (int j = 0; j < N; ++j) {
					int h = input.nextInt();

					if (map.containsKey(h)) {
						map.put(h, map.get(h) + 1);
					} else {
						map.put(h, 1);
					}
				}
			}

			System.out.print("Case #" + (t + 1) + ": ");

			for (int h : map.keySet()) {
				if (map.get(h) % 2 != 0) {
					System.out.print(h + " ");
				}
			}

			System.out.println();
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
