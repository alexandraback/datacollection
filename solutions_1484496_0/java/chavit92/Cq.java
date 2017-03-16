import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.ArrayBlockingQueue;

public class Cq {
	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;
	String SK;

	String next() throws IOException {
		while ((str == null) || (!str.hasMoreTokens())) {
			SK = in.readLine();
			if (SK == null)
				return null;
			str = new StringTokenizer(SK);
		}
		return str.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[][] par = new int[n + 1][5000000];
		for (int i = 0; i <= n; i++) {
			Arrays.fill(par[i], -1);
		}
		int mid = 5000000 / 2;
		par[0][mid] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5000000; j++) {
				if (par[i][j] != -1) {
					par[i + 1][j + a[i]] = j;
					par[i + 1][j - a[i]] = j;
					if (par[i + 1][j] != 0) {
						par[i + 1][j] = j;
					}
				}
			}
		}
		int tek = 0;
		ArrayList<Integer> res1 = new ArrayList<Integer>();
		ArrayList<Integer> res2 = new ArrayList<Integer>();
		for (int i = n; i > 0; i--) {
			if (par[i][mid] < mid) {
				res2.add(a[i - 1]);
			} else if (par[i][mid] > mid) {
				res1.add(a[i - 1]);
			}
			mid = par[i][mid];
		}
		out.println();
		boolean is = false;
		for (int i : res1) {
			if (is) {
				out.print(" ");
			}
			is = true;
			out.print(i);
		}
		out.println();
		is = false;
		for (int i : res2) {
			if (is) {
				out.print(" ");
			}
			is = true;
			out.print(i);
		}

	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.print("Case #" + (i + 1) + ":");
			solve();
			out.println();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Cq().run();
	}

}