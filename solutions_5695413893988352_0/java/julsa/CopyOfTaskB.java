import java.util.*;
import java.io.*;

public class CopyOfTaskB {

	FastScanner in;
	PrintWriter out;

	public boolean tt(int[] a, int x, int p) {

		for (int i = 0; i < a.length; i++) {
			if (a[i] != -1) {
				if (a[i] != ((x / p) % 10)) {
					return false;
				}
			}
			p = p / 10;
		}
		return true;
	}

	public void solve() throws IOException {
		int q = in.nextInt();
		for (int qq = 1; qq <= q; qq++) {
			out.print("Case #" + qq + ": ");
			String s1 = in.next();
			String s2 = in.next();
			int n = s1.length();
			int p = 1;
			for (int i = 0; i < n - 1; i++) {
				p *= 10;
			}
			int[] a = new int[n];
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				if (s1.charAt(i) == '?') {
					a[i] = -1;
				} else {
					a[i] = s1.charAt(i) - '0';
				}
			}
			for (int i = 0; i < n; i++) {
				if (s2.charAt(i) == '?') {
					b[i] = -1;
				} else {
					b[i] = s2.charAt(i) - '0';
				}
			}
			int pp = p * 10;
			int x = -1;
			int y = -1;
			for (int i = 0; i < pp; i++) {
				for (int j = 0; j < pp; j++) {
					if (x < 0) {
						if (tt(a, i, p) && tt(b, j, p)) {
							x = i;
							y = j;
						}
					} else {
						if (tt(a, i, p) && tt(b, j, p)) {
							if (Math.abs(x - y) == Math.abs(i - j)) {
								if (x == i) {
									if (y > j) {
										x = i;
										y = j;
									}
								}
								if (x > i) {
									x = i;
									y = j;
								}
							}

							if (Math.abs(x - y) > Math.abs(i - j)) {

								x = i;
								y = j;
							}
						}
					}
				}
			}
			int w = p;
			for (int i = 0; i < n; i++) {
				if (a[i] == -1) {
					a[i] = (x / w) % 10;
				}
				w = w / 10;
			}
			w = p;
			for (int i = 0; i < n; i++) {
				if (b[i] == -1) {
					b[i] = (y / w) % 10;
				}
				w = w / 10;
			}
			for (int j = 0; j < n; j++) {
				out.print(a[j]);
			}
			out.print(" ");
			for (int j = 0; j < n; j++) {
				out.print(b[j]);
			}
			out.println();
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
		new CopyOfTaskB().run();
	}
}
