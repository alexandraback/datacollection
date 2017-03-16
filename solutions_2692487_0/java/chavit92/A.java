import java.io.*;
import java.util.*;

public class A {

	void solve() throws IOException {
		int our = nextInt();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int res = n;
		Arrays.sort(a);
		int ops = 0;
		for (int i = 0; i <= n; i++) {
			if (ops + n - i < res) {
				res = ops + n - i;
			}
			if (i == n) {
				break;
			}
			if (a[i] < our) {
				our += a[i];
			} else {
				if (our == 1) {
					break;
				}
				while (our <= a[i]) {
					our = 2 * our - 1;
					ops++;
				}
				our += a[i];
			}
		}
		out.println(res);
	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter("A.out");
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve();
		}
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().run();
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
