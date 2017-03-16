package gcj2016.r1a;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoC {
	public static void main(final String[] args) {

		final String base = "/home/jfortin/workspace-gcj/Codejam2016/r1a/ExoC/";
		final String input = base + "s1.in";
		final String output = base + "s1.out";

		try {
			final Scanner sc = new Scanner(new FileReader(input));
			final PrintWriter pw = new PrintWriter(output);

			final int n = sc.nextInt();
			sc.nextLine();
			for (int c = 0; c < n; c++) {
				System.out.println("Test case " + (c + 1) + "...");
				pw.print("Case #" + (c + 1) + ": ");
				test(sc, pw);
				pw.println();
			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (final FileNotFoundException ex) {
			Logger.getLogger(ExoC.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		int N = sc.nextInt();
		int[] bff = new int[N];

		for (int i = 0; i < bff.length; i++) {
			bff[i] = sc.nextInt() - 1;
		}

		int c1 = countStudentsInPairs(bff, N);
		int c2 = countLargestCycle(bff, N);

		pw.print(Math.max(c1, c2));

	}

	private static int countLargestCycle(final int[] bff, final int N) {
		int max = 0;
		for (int i = 0; i < N; i++) {
			int n = periodFromI(bff, i);

			if (n > max) {
				max = n;
			}
		}
		return max;
	}

	private static int periodFromI(final int[] bff, final int i) {
		int c1 = bff[i];
		int c2 = bff[c1];
		while (c1 != c2) {
			c1 = bff[c1];
			c2 = bff[bff[c2]];
		}
		int s = bff[c1];
		int n = 1;
		while (s != c1) {
			n++;
			s = bff[s];
		}
		return n;
	}

	private static int countStudentsInPairs(final int[] bff, final int N) {
		boolean inPair[] = new boolean[N];

		int pair = 0;
		for (int i = 0; i < N; i++) {
			if (bff[bff[i]] == i) {
				pair++;
				inPair[i] = true;
				inPair[bff[i]] = true;
			}
		}

		for (int i = 0; i < N; i++) {
			if (inPair[i]) {
				int longestToI = longestToI(bff, N, i);
				System.out.println("longest to " + i + " is " + longestToI);
				pair += longestToI;
			}
		}

		return pair;
	}

	private static int longestToI(final int[] bff, final int N, final int ci) {
		int max = 0;
		for (int i = 0; i < N; i++) {
			if (reachesI(bff, i, ci, N)) {
				int c = i;
				int n = 0;
				while (bff[bff[c]] != c) {
					n++;
					c = bff[c];
				}
				if (n > max) {
					max = n;
				}
			}
		}
		return max;
	}

	private static boolean reachesI(final int[] bff, final int i, final int ci, final int N) {
		int c = i;
		for (int k = 0; k <= N; k++) {
			if (c == ci) {
				return true;
			}
			if (bff[bff[c]] == c) {
				return false;
			}
			c = bff[c];
		}
		return false;
	}

}
