import java.io.*;
import java.util.*;

public class D {

	int[] bal;

	int[][] add;

	HashSet<String> was;

	
	int[] res;
	int[] curres;
	int[] need;

	void solve(boolean[] ws, int v) {
		if (v == n) {
			res = curres.clone();
			return;
		}
		if (was.contains(Arrays.toString(ws))) {
			return;
		}
		was.add(Arrays.toString(ws));
		for (int i = 0; i < n; i++) {
			if (!ws[i] && bal[need[i]] > 0 && res == null) {
				bal[need[i]]--;
				ws[i] = true;
				for (int j = 0; j < 200; j++) {
					bal[j] = bal[j] + add[i][j];
				}
				curres[v] = i;
				solve(ws, v + 1);
				for (int j = 0; j < 200; j++) {
					bal[j] = bal[j] - add[i][j];
				}
				ws[i] = false;
				bal[need[i]]++;
			}
		}
	}

	int n;

	void solve() throws IOException {
		was = new HashSet<>();
		bal = new int[200];
		int k = nextInt();
		n = nextInt();
		for (int i = 0; i < k; i++) {
			bal[nextInt() - 1]++;
		}
		add = new int[n][200];
		need = new int[n];
		for (int i = 0; i < n; i++) {
			need[i] = nextInt() - 1;
			k = nextInt();
			for (int j = 0; j < k; j++) {
				add[i][nextInt() - 1]++;
			}
		}
		res = null;
		curres = new int[200];
		boolean[] was = new boolean[n];
		solve(was, 0);
		if (res == null) {
			out.println("IMPOSSIBLE");
			return;
		}
		for (int i = 0; i < n - 1; i++) {
			out.print(res[i] + 1 + " ");
		}
		out.println(res[n - 1] + 1);
	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader("d.in"));
		out = new PrintWriter("d.out");
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println(i);
			out.print("Case #" + i + ": ");
			solve();
		}
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D().run();
	}

	BufferedReader br;
	StringTokenizer str;
	PrintWriter out;

	String next() throws IOException {
		while (str == null || !str.hasMoreTokens()) {
			String s = br.readLine();
			if (s != null) {
				str = new StringTokenizer(s);
			} else {
				return null;
			}
		}
		return str.nextToken();
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

}
