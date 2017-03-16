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
			// solveB();
			solveC();
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
			ArrayList<Integer> a = new ArrayList<Integer>();
			ArrayList<Integer> b = new ArrayList<Integer>();
			ArrayList<Integer> c = new ArrayList<Integer>();
			int A = nextInt(), B = nextInt(), C = nextInt();
			int k = nextInt();
			int used[] = new int[10000];
			for (int i = 1; i <= A; ++i) {
				for (int j = 1; j <= B; j++) {
					for (int u = 1; u <= C; u++) {
						if (used[i * 200 + u] < k && used[j * 20 + u] < k && used[i * 200 + j * 20] < k) {
							a.add(i);
							b.add(j);
							c.add(u);
							used[i * 200 + u]++;
							used[i * 200 + j * 20]++;
							used[j * 20 + u]++;
						}
					}
				}
			}
			while (true) {
				boolean bet = false;
				for (int iu = 0; iu < a.size(); ++iu) {
					int aa = a.get(iu);
					int bb = b.get(iu);
					int cc = c.get(iu);
					used[aa * 200 + cc]--;
					used[aa * 200 + bb * 20]--;
					used[bb * 20 + cc]--;
					int h = 0;
					a.remove(iu);
					b.remove(iu);
					c.remove(iu);
					//System.out.println("Remove: " + aa + " " + bb + " " + cc);
					//System.out.println("Remove: \n " + a + "\n " + b + "\n " + c);
					for (int i = 1; i <= A; ++i) {
						for (int j = 1; j <= B; j++) {
							for (int u = 1; u <= C; u++) {
								if (i == aa && j == bb && u == cc)
									continue;
								if (a.contains(i) && b.contains(j) && c.contains(u))
									continue;
								if (used[i * 200 + u] < k && used[j * 20 + u] < k && used[i * 200 + j * 20] < k) {
									h++;
									a.add(i);
									b.add(j);
									c.add(u);
									used[i * 200 + u]++;
									used[i * 200 + j * 20]++;
									used[j * 20 + u]++;
								}
							}
						}
					}
					if (h <= 1) {
						if (h == 0) {
							a.add(aa);
							b.add(bb);
							c.add(cc);
						}
					} else {
						System.out.println("Replace!");
						bet = true;
						break;
					}
				}
				if (!bet)
					break;
				//break;
			}

			cout.print("Case #" + (tt + 1) + ": ");

			cout.println(a.size());
			for (int i = 0; i < a.size(); ++i) {
				cout.println(a.get(i) + " " + b.get(i) + " " + c.get(i));
			}
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