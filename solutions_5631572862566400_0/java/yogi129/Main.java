import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

class Main {

	public static void main(String args[]) {
		MyScanner input = new MyScanner();

		int T = input.nextInt();

		for (int t = 0; t < T; ++t) {
			int N = input.nextInt();

			int A[] = new int[N];

			for (int i = 0; i < N; ++i) {
				A[i] = input.nextInt() - 1;
			}

			int ans = 0;

			for (int i = 0; i < N; ++i) {
				Set<Integer> set = new HashSet<Integer>();

				int first = i;

				int start = i;
				set.add(start);

				int prev = -1;

				boolean flag = true;

				while (true) {
					int temp = A[start];

					if (temp == first) {
						break;
					}

					if (temp == prev) {
						for (int j = 0; j < N; ++j) {
							if (A[j] == first && set.contains(j) == false) {
								set.add(j);
								break;
							}
						}

						for (int j = 0; j < N; ++j) {
							if (A[j] == start && set.contains(j) == false) {
								set.add(j);
								break;
							}
						}

						break;
					}

					if (set.contains(temp)) {
						flag = false;
						break;
					}

					set.add(temp);

					prev = start;

					start = temp;
				}

				if (flag) {
					ans = Math.max(ans, set.size());
				}
			}

			System.out.print("Case #" + (t + 1) + ": ");

			System.out.println(ans);
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
