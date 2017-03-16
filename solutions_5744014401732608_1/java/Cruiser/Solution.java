import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}

	PrintWriter cout;

	BufferedReader cin;

	StringTokenizer stok;

	public void run() {
		try {
			cout = new PrintWriter("output.txt");
			cin = new BufferedReader(new FileReader("input.txt"));
			// solveA();
			solveB();
			// solveC();
			cin.close();
			cout.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(234);
		}
	}

	private void solveA() throws Exception {
		int t = nextInt();
		for (int tt = 0; tt < t; ++tt) {
			int n = nextInt();
			int k = 0;
			int[] p = new int[n];
			for (int i = 0; i < n; ++i) {
				p[i] = nextInt();
				k += p[i];
			}
			String res = "";
			while (k > 0) {
				if (k % 2 == 1) {
					int j = 0;
					for (int i = 0; i < n; ++i)
						if (p[i] > p[j])
							j = i;
					p[j]--;
					res = res + " " + (char) ('A' + j);
					--k;
				} else {
					int j = 0;
					for (int i = 0; i < n; ++i)
						if (p[i] > p[j])
							j = i;
					p[j]--;
					res = res + " " + (char) ('A' + j);
					--k;
					j = 0;
					for (int i = 0; i < n; ++i)
						if (p[i] > p[j])
							j = i;
					p[j]--;
					res = res + (char) ('A' + j);
					--k;
				}
			}

			cout.print("Case #" + (tt + 1) + ":" + res);

			cout.println();
		}
	}

	private void solveB() throws Exception {
		int t = nextInt();
		long mx[] = new long[55];
		mx[0] = 0;
		mx[1] = mx[2] = 1;
		for (int i = 3; i <= 52; i++) {
			mx[i] = mx[i - 1] * 2;
		}
		
		for (int tt = 0; tt < t; ++tt) {
			int n = nextInt();
			long m = nextLong();

			int a[] = new int[n];
			if (m > mx[n])
				cout.print("Case #" + (tt + 1) + ": IMPOSSIBLE\n");
			else {
				cout.print("Case #" + (tt + 1) + ": POSSIBLE\n");
				int i = 1;
				int nn = n;
				while (m > 0) {
					--nn;
					if (m >= mx[nn]) {
						m -= mx[nn];
						a[i] = 1;
					}
					++i;
				}
				for (int ti = 0; ti < n; ti++)
					cout.print(a[ti]);
				cout.println();
				for (int j = 1; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (k > j)
							cout.print("1");
						else
							cout.print("0");
					}

					cout.println();
				}

			}

		}
	}

	private void solveC() throws Exception {
		int t = nextInt();
		for (int tt = 0; tt < t; ++tt) {
			long res = 0;

			cout.print("Case #" + (tt + 1) + ": ");

			cout.println(res);
		}
	}

	private long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private String next() throws Exception {
		while (stok == null || !stok.hasMoreTokens()) {
			stok = new StringTokenizer(cin.readLine());
		}
		return stok.nextToken();
	}

}