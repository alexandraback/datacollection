import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class KingdomRush {
	public static void main(final String... args) throws IOException {
		final String fname = "B-small-attempt0";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		for (int i = 1; i <= t; ++i) {
			final int n = sc.nextInt();
			final int[] a = new int[n];
			final int[] b = new int[n];
			final int[] c = new int[n];
			for (int j = 0; j < n; ++j) {
				a[j] = sc.nextInt();
				b[j] = sc.nextInt();
			}
			final int[] d = new int[60000];
			int j = 1;
			while (true) {
				int x = j;
				int s = 0;
				for (int k = 0; k < n; ++k) {
					c[k] = x % 3;
					x /= 3;
					s += c[k];
				}
				if (x > 0) {
					break;
				}
				d[j] = -1;
				int p = 1;
				for (int k = 0; k < n; ++k) {
					if (c[k] == 2) {
						if (d[j - p] >= 0 && b[k] <= s - 1) {
							int q = d[j - p] + 1;
							if (d[j] < 0 || d[j] > q) {
								d[j] = q;
							}
						}
						if (d[j - 2 * p] >= 0 && b[k] <= s - 2) {
							int q = d[j - 2 * p] + 1;
							if (d[j] < 0 || d[j] > q) {
								d[j] = q;
							}
						}
					}
					else if (c[k] == 1) {
						if (d[j - p] >= 0 && a[k] <= s - 1) {
							int q = d[j - p] + 1;
							if (d[j] < 0 || d[j] > q) {
								d[j] = q;
							}
						}
					}
					p *= 3;
				}
				++j;
			}
			final int r = d[j - 1];
			pw.println("Case #" + i + ": " + (r < 0 ? "Too Bad" : r));
		}
		pw.close();
	}
}
