import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class B_2_pancakes {
	public void solve(final Scanner sc, final PrintWriter pw) {
		final int n = sc.nextInt();
		final List<Integer> l = new ArrayList<Integer>(n);
		for (int j = 0; j < n; ++j) {
			l.add(sc.nextInt());
		}
		Collections.sort(l);
		Collections.reverse(l);
		int r = l.get(0);
		for (int i = 1; i <= 1000; ++i) {
			int t = i;
			for (int x : l) {
				if (x > i) {
					t += (x - 1) / i;
				}
				else {
					break;
				}
			}
			if (t < r) {
				r = t;
			}
		}
		pw.println(r);
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "B-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new B_2_pancakes().solve(sc, pw);
		}
		pw.close();
	}
}
