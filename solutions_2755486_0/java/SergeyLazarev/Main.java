package round1C2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
	
	private static final int MAX_DAY = 676060 + 1;
	private static final int MAX = 10000;//210000000;
	private int[] tree = new int[MAX * 4];
	private byte[] painted = new byte[MAX * 4];
	private ArrayList<Attack>[] attacks = new ArrayList[MAX_DAY];
	
	private void paint(int p, int l, int r, int a, int b, int val) {
		if (l == a && r == b) {
			tree[p] = val;
			painted[p] = 1;
			return;
		}
		
		int L = p << 1;
		int R = (p << 1) + 1;
		if (painted[p] == 1) {
			painted[p] = 0;
			painted[L] = painted[R] = 1;
			tree[L] = tree[R] = tree[p];
		}
		
		int m = (l + r) >> 1;
		if (b <= m) {
			paint(L, l, m, a, b, val);
		} else if (a > m) {
			paint(R, m + 1, r, a, b, val);
		} else {
			paint(L, l, m, a, m, val);
			paint(R, m + 1, r, m + 1, b, val);
		}
		
		tree[p] = Math.min(tree[L], tree[R]);
	}
	
	private int get(int p, int l, int r, int a, int b) {
		if (painted[p] == 1 || l == a && r == b) {
			return tree[p];
		}
		
		int L = p << 1;
		int R = (p << 1) + 1;
		int m = (l + r) >> 1;
		if (b <= m) {
			return get(L, l, m, a, b);
		} else if (a > m) {
			return get(R, m + 1, r, a, b);
		} else {
			return Math.min(
					get(L, l, m, a, m),
					get(R, m + 1, r, m + 1, b));
		}
	}
	

	private static class Attack {
		int l;
		int r;
		int s;

		public Attack(int l, int r, int s) {
			this.l = l + MAX / 2;
			this.r = r + MAX / 2 - 1;
			this.s = s;
		}
	}
	
	
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int t = 1; t <= tests; t++) {
			print("Case #" + t + ": ");

			Arrays.fill(tree, 0);
			Arrays.fill(painted, (byte)0);
			
			for (int i = 0; i < attacks.length; i++) {
				attacks[i] = new ArrayList<>();
			}
			
			int[] f = new int[MAX];
			
			int n = nextInt();
			for (int i = 0; i < n; i++) {
				int d = nextInt();
				int ni = nextInt();
				int w = nextInt();
				int e = nextInt();
				int s = nextInt();
				int dd = nextInt();
				int dp = nextInt();
				int ds = nextInt();
				
				for (int j = 0; j < ni; j++) {
					attacks[d].add(new Attack(w, e, s));
					d += dd;
					w += dp;
					e += dp;
					s += ds;
				}
			}
			
			int res = 0;
			for (int day = 0; day < MAX_DAY; day++) {
				for (Attack a: attacks[day]) {
					int min = Integer.MAX_VALUE;
					for (int i = a.l; i <= a.r; i++) {
						min = Math.min(min, f[i]);
					}
					if (min < a.s) {
						res++;
					}
//					if (get(1, 0, MAX - 1, a.l, a.r) < a.s) {
//						res++;
//					}
				}
				
				for (Attack a: attacks[day]) {
					for (int i = a.l; i <= a.r; i++) {
						if (f[i] < a.s) {
							f[i] = a.s;
						}
					}
//					if (get(1, 0, MAX - 1, a.l, a.r) < a.s) {
//						paint(1, 0, MAX - 1, a.l, a.r, a.s);
//					}
				}
			}
			
			println(res);
		}
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	private double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... o) {
		writer.printf(format, o);
	}

	public static void main(String[] args) {
		long time = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Main().run();
		System.err.printf("%.3f\n", 1e-3 * (System.currentTimeMillis() - time));
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void run() {
		try {
			reader = new BufferedReader(new FileReader(new File("input.in")));
			writer = new PrintWriter(new File("output.out"));
			solve();
			reader.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(13);
		}
	}
}