package y2012.round1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		String testName = "B";
		Scanner in = new Scanner(new File("d:\\Downloads\\" + testName + ".in"));
		PrintWriter out = new PrintWriter(new File("d:\\Downloads\\" + testName
				+ ".out"));
		int nTestCase = Integer.parseInt(in.nextLine());
		for (int testCase = 1; testCase <= nTestCase; testCase++) {
			int n = in.nextInt();
			Level[] levels = new Level[n];
			PriorityQueue<X> all = new PriorityQueue<X>(2 * n,
					new Comparator<X>() {
						@Override
						public int compare(X x1, X x2) {
							return (x1.starsNeeded == x2.starsNeeded) ? 0
									: (x1.starsNeeded < x2.starsNeeded ? -1 : 1);
						}
					});
			for (int i = 0; i < n; i++) {
				int a = in.nextInt();
				int b = in.nextInt();
				levels[i] = new Level(a, b);
				all.add(new X(levels[i], true));
				all.add(new X(levels[i], false));
			}
			PriorityQueue<X> candidates = new PriorityQueue<X>(2 * n,
					new Comparator<X>() {
						@Override
						public int compare(X x1, X x2) {
							if (x1.first)
								if (x2.first)
									return (x1.l.b == x2.l.b) ? ((x1.hashCode() < x2
											.hashCode()) ? 1 : -1)
											: (x1.l.b < x2.l.b ? 1 : -1);
								else
									return 1;
							else if (x2.first)
								return -1;
							else
								return (x1.hashCode() < x2.hashCode()) ? 1 : -1;
						}
					});

			int tStars = 0, res = 0;
			while (true) {
				while (!all.isEmpty() && all.peek().starsNeeded <= tStars) {
					X x = all.poll();
					// System.out.println(x);
					if (!x.l.secondUsed)
						candidates.add(x);
				}
				if (candidates.isEmpty())
					break;

				X x = candidates.poll();
				// System.out.println("\t" + x + " " + tStars + " " +
				// candidates);
				if (x.l.secondUsed)
					continue;
				if (x.first || x.l.firstUsed)
					tStars++;
				else
					tStars += 2;
				if (x.first)
					x.l.firstUsed = true;
				else
					x.l.secondUsed = true;
				res++;
			}

			if (candidates.isEmpty() && all.isEmpty())
				out.println("Case #" + testCase + ": " + res);
			else
				out.println("Case #" + testCase + ": Too Bad");

			// System.out.println("---------");
		}
		in.close();
		out.close();
	}

	public static class Level {
		int a, b;
		boolean firstUsed, secondUsed;
		Level(int a, int b) {
			this.a = a;
			this.b = b;
			firstUsed = false;
			secondUsed = false;
		}
	}
	public static class X {
		Level l;
		boolean first;
		int starsNeeded;

		X(Level l, boolean first) {
			this.l = l;
			this.first = first;
			starsNeeded = first ? l.a : l.b;
		}

		@Override
		public String toString() {
			return "[" + l.a + ", " + l.b + ", " + first + "]";
		}
	}
}
