package round1c;

import java.io.File;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Stack;

public class A {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("1c/A-small-attempt1.bin"));
		// Scanner in = new Scanner(new File("1c/A-test.in"));
		int T = in.nextInt();
		for (int zz = 1; zz <= T; ++zz) {
			final int N = in.nextInt();

			final Map<Integer, int[]> map = new HashMap<Integer, int[]>();

			for (int i = 1; i <= N; ++i) {
				final int M = in.nextInt();
				int[] list = new int[M];
				for (int m = 0; m < M; ++m) {
					list[m] = in.nextInt();
				}

				map.put(i, list);
			}

			boolean diamond = false;

			main: for (int i = 1; i <= N; ++i) {
				final int[] list = map.get(i);
				if (list.length < 2)
					continue;

				HashSet<Integer> inheritsL2 = new HashSet<Integer>();
				Stack<Integer> s = new Stack<Integer>();

				for (int inh : list) {
					s.add(inh);
					inheritsL2.add(inh);
				}

				while (!s.isEmpty()) {
					final int[] list2 = map.get(s.pop());
					for (int ci : list2) {
						if (!inheritsL2.add(ci)) {
							diamond = true;
							break main;
						}
						s.push(ci);
					}
				}
			}

			System.out.println("Case #" + zz + ": " + (diamond ? "Yes" : "No"));
		}

	}
}
