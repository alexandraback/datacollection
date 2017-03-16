import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;

public class C_good_luck {
	public static void main(final String... args) throws IOException {
		final String fname = "C-small-1-attempt0";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			final int r = sc.nextInt();
			sc.nextInt();
			final int m = sc.nextInt();
			final int k = sc.nextInt();
			pw.println("Case #" + i + ":");
			final Map<Integer, Set<Integer>> map = new HashMap<Integer, Set<Integer>>();
			for (int n1 = 2; n1 <= m; ++n1) {
				for (int n2 = n1; n2 <= m; ++n2) {
					for (int n3 = n2; n3 <= m; ++n3) {
						final Set<Integer> set = new HashSet<Integer>();
						for (int j = 0; j < 8; ++j) {
							final int p1 = ((j & 1) == 0) ? 1 : n1;
							final int p2 = ((j & 2) == 0) ? 1 : n2;
							final int p3 = ((j & 4) == 0) ? 1 : n3;
							set.add(p1 * p2 * p3);
						}
						map.put(100 * n1 + 10 * n2 + n3, set);
					}
				}
			}
			for (int i1 = 0; i1 < r; ++i1) {
				final Set<Integer> set = new HashSet<Integer>();
				for (int i2 = 0; i2 < k; ++i2) {
					set.add(sc.nextInt());
				}
				for (Entry<Integer, Set<Integer>> e : map.entrySet()) {
					if (e.getValue().containsAll(set)) {
						pw.println(e.getKey());
						break;
					}
				}
			}
		}
		pw.close();
	}
}
