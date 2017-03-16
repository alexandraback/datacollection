import java.io.*;
import java.util.*;

public class Lawnmower {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = in.nextInt();
			}
		}
		
		boolean[][] used = new boolean[n][m];
		
		while (true) {
			
			int minUnused = getMin(a, used);
			if (minUnused == Integer.MAX_VALUE) {
				break;
			}
			
			int findRow = -1, findCol = -1;
			for (int i = 0; i < n; i++) {
				boolean good = true;
				boolean hasUnused = false;
				for (int j = 0; j < m; j++) {
					if (!used[i][j]) {
						hasUnused = true;
						if (a[i][j] > minUnused) {
							good = false;
						}
					}
				}
				if (!hasUnused) {
					continue;
				}
				if (good) {
					findRow=  i;
					break;
				}
			}
			
			for (int j = 0; j < m; j++) {
				boolean good = true;
				boolean hasUnused = false;
				for (int i = 0; i < n; i++) {
					if (!used[i][j]) {
						hasUnused = true;
						if (a[i][j] > minUnused) {
							good = false;
						}
					}
				}
				if (!hasUnused) {
					continue;
				}
				if (good) {
					findCol = j;
					break;
				}
			}
//			System.err.println(minUnused + " " + findRow + " " + findCol);
			if (findRow != -1) {
				 for (int i = 0; i < m; i++) {
					 used[findRow][i] = true;
				 }
			} else if (findCol != -1) {
				for (int i = 0; i < n; i++) {
					used[i][findCol] = true;
				}
			} else {
				out.println("NO");
//				for (boolean[] b : used) {
//					for (boolean c : b) {
//						out.print(c + " ");
//					}
//					out.println();
//				}
				return;
			}

		}
		
		out.println("YES");
	}

	private int getMin(int[][] a, boolean[][] used) {
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				if (!used[i][j]) {
					min = Math.min(min, a[i][j]);
				}
			}
		}
		return min;
	}

	void run() throws FileNotFoundException {
		in = new FastScanner("input.txt");
		out = new PrintWriter("output.txt");
		int tests = in.nextInt();
		for (int i = 0; i < tests; i++) {
			out.printf("Case #%d: ", i + 1);
			solve();
		}
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String name) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(name)));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Lawnmower().run();
	}
}
