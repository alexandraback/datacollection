import java.util.*;
import java.io.*;

public class CopyOfTaskB {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int tt = in.nextInt();
		int md = 1000000007;
		for (int t = 1; t <= tt; t++) {
			long ans = 1;
			boolean val = true;
			out.print("Case #" + t + ": ");
			int n = in.nextInt();
			String[] a = new String[n];
			int[] b = new int[30];
			int[] c = new int[30];
			int[] d = new int[30];
			int[] e = new int[30];
			for (int i = 0; i < n; i++) {
				String x = in.next();
				int j = 1;
				a[i] = "" + x.charAt(0);
				while (j < x.length()) {
					if (x.charAt(j - 1) != x.charAt(j)) {
						a[i] = a[i] + x.charAt(j);
					}
					j++;
				}
				if (a[i].length() == 1) {
					b[a[i].charAt(0) - 'a']++;
				}
				for (j = 1; j < a[i].length() - 1; j++) {
					c[a[i].charAt(j) - 'a']++;
				}
				if (a[i].length() > 1) {
					if (a[i].charAt(0) == a[i].charAt(a[i].length()-1)) {
						val = false;
					}
					d[a[i].charAt(0) - 'a']++;
					e[a[i].charAt(a[i].length() - 1) - 'a']++;
				}
				a[i] = "" + a[i].charAt(0) + a[i].charAt(a[i].length() - 1);
			}
			for (int i = 0; i < 30; i++) {
				if (b[i] > 0) {
					for (int j = 1; j <= b[i]; j++) {
						ans = (ans * j) % md;
					}
				}
			}
			int k = 0;
			int p = 0;
			for (int i = 0; i < 30; i++) {
				if (c[i] > 1) {
					val = false;
				}
				if ((c[i] == 1) && ((d[i] > 0) || (e[i] > 0))) {
					val = false;
				}
				if ((d[i] > 1) || (e[i] > 1)) {
					val = false;
				}
				d[i] += e[i];
				if (d[i] == 1) {
					k++;
				}
				if ((d[i] == 0) && (b[i] > 0)) {
					p++;
				}
			}
			k = k / 2 + p;
			if (val) {
				for (int i = 1; i <= k; i++) {
					ans = (ans * i) % md;
				}
				out.println(ans);
			} else {
				out.println(0);
			}

		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("TaskBB.in"));
			out = new PrintWriter(new File("TaskBB.out"));

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
		new CopyOfTaskB().run();
	}
}