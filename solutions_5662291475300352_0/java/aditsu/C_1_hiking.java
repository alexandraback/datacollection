import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C_1_hiking {
	public void solve(final Scanner sc, final PrintWriter pw) {
		final int n = sc.nextInt();
		final List<Integer> dl = new ArrayList<Integer>();
		final List<Integer> ml = new ArrayList<Integer>();
		int t = 0;
		for (int i = 0; i < n; ++i) {
			final int d = sc.nextInt();
			final int h = sc.nextInt();
			final int m = sc.nextInt();
			for (int j = 0; j < h; ++j) {
				t++;
				dl.add(d);
				ml.add(m + j);
			}
		}
		if (t == 1) {
			pw.println(0);
			return;
		}
		long d0 = dl.get(0);
		long d1 = dl.get(1);
		long m0 = ml.get(0);
		long m1 = ml.get(1);
		int r = m0 * (360 - d0) < m1 * (720 - d1) && m1 * (360 - d1) < m0 * (720 - d0) ? 0 : 1;
		pw.println(r);
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "C-small-1-attempt1";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new C_1_hiking().solve(sc, pw);
		}
		pw.close();
	}
}
