import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class EqualSums {
	public static void main(final String... args) throws IOException {
		final String fname = "C-small-attempt0";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			final int n = sc.nextInt();
			final int[] a = new int[n];
			for (int j = 0; j < n; ++j) {
				a[j] = sc.nextInt();
			}
			final int[] b = new int[3000000];
			Arrays.fill(b, -1);
			int s1 = -1;
			int s2 = -1;
			for (int j = 0; j < (1 << n); ++j) {
				int x = j;
				int k = 0;
				int s = 0;
				while (x > 0) {
					if ((x & 1) != 0) {
						s += a[k];
					}
					x >>= 1;
					++k;
				}
				if (b[s] >= 0) {
					s1 = b[s];
					s2 = j;
					break;
				}
				b[s] = j;
			}
			pw.println("Case #" + i + ":");
			if (s1 < 0) {
				pw.println("Impossible");
			}
			else {
				int k = 0;
				while (s1 > 0) {
					if ((s1 & 1) != 0) {
						pw.print(a[k] + " ");
					}
					s1 >>= 1;
					++k;
				}
				pw.println();
				k = 0;
				while (s2 > 0) {
					if ((s2 & 1) != 0) {
						pw.print(a[k] + " ");
					}
					s2 >>= 1;
					++k;
				}
				pw.println();
			}
		}
		pw.close();
	}
}
