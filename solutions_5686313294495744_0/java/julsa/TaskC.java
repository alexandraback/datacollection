import java.util.*;
import java.io.*;

public class TaskC {

	FastScanner in;
	PrintWriter out;

	public boolean tryk(int i, int s, int[][] gr, boolean[] visit, int[] m) {
		if (visit[i]) {
			return false;
		}
		visit[i] = true;
		for (int j = 0; j < s; j++) {
			if (gr[i][j] == 1) {
				if ((m[j] == -1) || (tryk(m[j], s, gr, visit, m))) {
					m[j] = i;
					return true;
				}
			}
		}
		return false;
	}

	public void solve() throws IOException {
		int q = in.nextInt();
		for (int qq = 1; qq <= q; qq++) {
			out.print("Case #" + qq + ": ");
			int n = in.nextInt();
			int[][] gr = new int[n][n];
			HashMap<String, Integer> hm1 = new HashMap<String, Integer>();
			HashMap<String, Integer> hm2 = new HashMap<String, Integer>();
			int h1 = 0;
			int h2 = 0;
			for (int i = 0; i < n; i++) {
				String s = in.next();
				int x = -1;
				int y = -1;
				if (hm1.containsKey(s)) {
					x = hm1.get(s);
				} else {
					x = h1;
					hm1.put(s, h1);
					h1++;
				}
				s = in.next();
				if (hm2.containsKey(s)) {
					y = hm2.get(s);
				} else {
					y = h2;
					hm2.put(s, h2);
					h2++;
				}
				gr[x][y] = 1;
			}
			boolean[] visit = new boolean[n];
			int[] m = new int[n];
			Arrays.fill(m, -1);
			for (int i = 0; i < h1; i++) {
				Arrays.fill(visit, false);
				tryk(i, h2, gr, visit, m);
			}
			int sum = 0;
			for (int i = 0; i < h2; i++) {
				if (m[i] != -1) {
					sum++;
				}
			}

			out.println(n - (h1 + h2 - sum));
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
		new TaskC().run();
	}
}
