import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B_manage_your_energy {
	public static void main(final String... args) throws IOException {
		final String fname = "B-small-attempt0";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			final int e = sc.nextInt();
			final int r = sc.nextInt();
			final int n = sc.nextInt();
			final int s = 20;
			final long[] a1 = new long[s];
			final long[] a2 = new long[s];
			Arrays.fill(a1, -1);
			Arrays.fill(a2, -1);
			a1[e] = 0;
			for (int j = 0; j < n; ++j) {
				final long v = sc.nextLong();
				for (int k = 0; k < s; ++k) {
					if (a1[k] >= 0) {
						for (int l = 0; l <= k; ++l) {
							final long g = a1[k] + l * v;
							final int ne = Math.min(k - l + r, e);
							if (a2[ne] < g) {
								a2[ne] = g;
							}
						}
					}
				}
				System.arraycopy(a2, 0, a1, 0, s);
				Arrays.fill(a2, -1);
			}
			long b = -1;
			for (long l : a1) {
				if (l > b) {
					b = l;
				}
			}
			pw.println("Case #" + i + ": " + b);
		}
		pw.close();
	}
}
