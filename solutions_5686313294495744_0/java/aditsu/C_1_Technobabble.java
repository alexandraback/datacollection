import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C_1_Technobabble {
	public void solve(final Scanner sc, final PrintWriter pw) {
		final int n = sc.nextInt();
		sc.nextLine();
		final String[][] a = new String[n][];
		for (int j = 0; j < n; ++j) {
			a[j] = sc.nextLine().split(" ");
		}
		final int[] dep = new int[n];
		final int[] rdep = new int[n];
		int r = 0;
		for (int k = 0; k < n; ++k) {
			Arrays.fill(dep, 0);
			Arrays.fill(rdep, 0);
			for (int i = k; i < n; ++i) {
				int f = 0;
				for (int j = k; j < n; ++j) if (j != i) {
					if (a[i][0].equals(a[j][0])) {
						f |= 1;
					}
					if (a[i][1].equals(a[j][1])) {
						f |= 2;
					}
				}
				if (f == 3) {
					for (int j = k; j < n; ++j) if (j != i) {
						if (a[i][0].equals(a[j][0]) || a[i][1].equals(a[j][1])) {
							dep[i]++;
							rdep[j]++;
						}
					}
				}
			}
			int best = -1;
			int bestDep = 9999;
			int bestRdep = -1;
			for (int i = k; i < n; ++i) {
				if (dep[i] < bestDep || (dep[i] == bestDep && rdep[i] > bestRdep)) {
					best = i;
					bestDep = dep[i];
					bestRdep = rdep[i];
				}
			}
			if (best != k) {
				String[] t = a[k];
				a[k] = a[best];
				a[best] = t;
			}
			int f = 0;
			for (int j = 0; j < k; ++j) {
				if (a[k][0].equals(a[j][0])) {
					f |= 1;
				}
				if (a[k][1].equals(a[j][1])) {
					f |= 2;
				}
			}
			if (f == 3) r++;
		}
		pw.println(r);
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "C-small-attempt0";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		sc.nextLine();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new C_1_Technobabble().solve(sc, pw);
		}
		pw.close();
	}
}
