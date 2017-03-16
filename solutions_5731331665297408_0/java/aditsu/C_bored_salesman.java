import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

public class C_bored_salesman {
	private static final List<List<Integer>> e = new ArrayList<List<Integer>>();
	private static String[] zip;
	private static final List<Integer> l = new ArrayList<Integer>();
	private static boolean[] vis;
	private static PriorityQueue<Open> q = new PriorityQueue<Open>();
	private static StringBuilder sb = new StringBuilder();
	private static List<Open> later = new ArrayList<Open>();
	private static boolean[] reach;
	
	private static void check(final Set<Integer> ex, final int x) {
		if (ex.contains(x) || reach[x]) {
			return;
		}
		reach[x] = true;
		for (int y : e.get(x)) {
			check(ex, y);
		}
	}
	
	private static class Open implements Comparable<Open> {
		public int x;
		public int p;
		
		public Open(int x, int p) {
			this.x = x;
			this.p = p;
		}

		@Override
		public int compareTo(final Open o) {
			int t = zip[x].compareTo(zip[o.x]);
			if (t != 0) {
				return t;
			}
			return -zip[p].compareTo(zip[o.p]);
		}
	}
	
	private static void dfs(final int x) {
		vis[x] = true;
		l.add(x);
		sb.append(zip[x]);
		for (int y : e.get(x)) {
			if (!vis[y]) {
				q.add(new Open(y, x));
			}
		}
		while (true) {
			Open o = q.peek();
			if (o == null) {
				return;
			}
			if (vis[o.x]) {
				q.remove();
				continue;
			}
			if (o.p != x) {
				Arrays.fill(reach, false);
				check(new HashSet<Integer>(l.subList(l.indexOf(o.p) + 1, l.size())), l.get(0));
				boolean b = true;
				for (int r = 0; r < reach.length; ++r) {
					if (!vis[r] && !reach[r]) {
						b = false;
						break;
					}
				}
				if (!b) {
					later.add(q.remove());
					continue;
				}
				for (int y : e.get(x)) {
					if (!vis[y]) {
						e.get(y).remove((Integer) x);
					}
				}
				q.addAll(later);
				later.clear();
				return;
			}
			q.remove();
			dfs(o.x);
			q.addAll(later);
			later.clear();
		}
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "C-small-attempt0";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			final int n = sc.nextInt();
			final int m = sc.nextInt();
			sc.nextLine();
			zip = new String[n];
			vis = new boolean[n];
			reach = new boolean[n];
			e.clear();
			String smin = "aaaaaa";
			int min = 0;
			for (int j = 0; j < n; ++j) {
				zip[j] = sc.nextLine();
				e.add(new ArrayList<Integer>());
				if (zip[j].compareTo(smin) < 0) {
					smin = zip[j];
					min = j;
				}
			}
			for (int j = 0; j < m; ++j) {
				final int x = sc.nextInt() - 1;
				final int y = sc.nextInt() - 1;
				e.get(x).add(y);
				e.get(y).add(x);
			}
			l.clear();
			sb.setLength(0);
			q.clear();
			dfs(min);
			pw.println("Case #" + i + ": " + sb);
		}
		pw.close();
	}
}
