import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) throws Exception {
		FileScanner in = new FileScanner("input.txt");
		PrintWriter out = new PrintWriter("output.txt");
		int t = in.nextInt();
		for (int k = 1; k <= t; k++) {
			out.print("Case #" + k + ": ");
			int n = in.nextInt();
			int m = in.nextInt();
			int[][] lawn = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					lawn[i][j] = in.nextInt();
				}
			}
			boolean res = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					int curr = lawn[i][j];
					boolean can = true;
					for (int x = 0; x < m; x++) {
						if (lawn[i][x] > curr) {
							can = false;
							break;
						}
					}
					if (can) {
						continue;
					}
					can = true;
					for (int y = 0; y < n; y++) {
						if (lawn[y][j] > curr) {
							can = false;
							break;
						}
					}
					if (!can) {
						res = false;
						break;
					}
				}
				if (!res) {
					break;
				}
			}
			if (res) {
				out.println("YES");
			} else {
				out.println("NO");
			}
		}
		out.close();
	}
	
	public static class FileScanner {
		BufferedReader br;
		StringTokenizer st;

		public FileScanner(String File) throws Exception {
			br = new BufferedReader(new FileReader(File));
		}

		public String getLine() throws IOException {
			return br.readLine();
		}

		String next() throws Exception {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		}

		public int nextInt() throws Exception {
			return Integer.parseInt(next());
		}

		public long nextLong() throws Exception {
			return Long.parseLong(next());
		}

		public double nextDouble() throws Exception {
			return Double.parseDouble(next());
		}
	}
}
