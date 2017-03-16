import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D_treasure {
	private static int[] prev = new int[1050000];
	private static int[][] paths = new int[1050000][];
	private static int[] skeys = new int[250];
	private static int[] copen = new int[25];
	private static int[][] ckeys = new int[25][250];
	private static int n;
	private static int[] keys = new int[250];
	
	private static boolean checkKeys(final int x) {
		System.arraycopy(skeys, 0, keys, 0, 250);
		for (int i = 0; i < n; ++i) {
			if ((x & (1 << i)) != 0) {
				keys[copen[i]]--;
				for (int j = 0; j < 250; ++j) {
					keys[j] += ckeys[i][j];
				}
			}
		}
		for (int j = 0; j < 250; ++j) {
			if (keys[j] < 0) {
				return false;
			}
		}
		return true;
	}
	
	private static int get(final int x) {
		if (prev[x] == -2) {
			run(x);
		}
		return prev[x];
	}
	
	private static boolean smaller(final int[] a, final int[] b) {
		if (b == null) {
			return true;
		}
		for (int i = 0; i < a.length; ++i) {
			if (a[i] < b[i]) {
				return true;
			}
			if (a[i] > b[i]) {
				return false;
			}
		}
		throw new RuntimeException("this should not happen");
	}
	
	private static void run(final int bits) {
		int[] best = null;
		int besti = -1;
		for (int i = 0; i < n; ++i) {
			if ((bits & (1 << i)) != 0) {
				final int x = bits ^ (1 << i);
				if (checkKeys(x) && keys[copen[i]] > 0 && get(x) >= 0) {
					if (smaller(paths[x], best)) {
						best = Arrays.copyOf(paths[x], paths[x].length + 1);
						best[best.length - 1] = i;
						besti = i;
					}
				}
			}
		}
		prev[bits] = besti;
		paths[bits] = best;
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "D-small-attempt1";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			final int k = sc.nextInt();
			n = sc.nextInt();
			Arrays.fill(prev, -2);
			Arrays.fill(skeys, 0);
			prev[0] = 0;
			paths[0] = new int[0];
			for (int j = 0; j < k; ++j) {
				final int x = sc.nextInt();
				skeys[x]++;
			}
			for (int j = 0; j < n; ++j) {
				copen[j] = sc.nextInt();
				final int ki = sc.nextInt();
				Arrays.fill(ckeys[j], 0);
				for (int l = 0; l < ki; ++l) {
					final int x = sc.nextInt();
					ckeys[j][x]++;
				}
			}
			boolean ok = get((1 << n) - 1) >= 0;
			pw.print("Case #" + i + ":");
			if (ok) {
				for (int j : paths[(1 << n) - 1]) {
					pw.print(" " + (j + 1));
				}
				pw.println();
			}
			else {
				pw.println(" IMPOSSIBLE");
			}
		}
		pw.close();
	}
}
