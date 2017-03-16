package org.soonk.codejam.round1B2013;

import java.util.Arrays;
import java.util.Scanner;

public class A {

	public void compute() {
		Scanner scanner = new Scanner(System.in);

		int testCases = scanner.nextInt();

		for (int t = 1; t <= testCases; t++) {

			int armin = scanner.nextInt();
			int numMotes = scanner.nextInt();
			int[] motes = new int[numMotes];
			for (int i = 0; i < numMotes; i++) {
				motes[i] = scanner.nextInt();
			}

			int result = handleTestCase(armin, motes);

			System.out.format("Case #%d: %d%n", t, result);
		}

		scanner.close();
	}

	private int handleTestCase(int armin, int[] motes) {
		Arrays.sort(motes);
		int count = 0;

		for (int i = 0; i < motes.length; i++) {
			// System.out.format("Armin = %d,  mote=%d, count=%d%n", armin,
			// motes[i], count);
			if (motes[i] < armin) {
				armin += motes[i]; // Can absorb
			} else if (armin == 1) {
				count++; // Cannot absorb, and cannot grow...must remove
			} else {
				int diff = motes[i] - armin;
				int incr = 0;
				while (diff >= 0) {
					armin += (armin - 1);
					incr++; // Compute times needed to grow
					diff = motes[i] - armin;
				}

				int left = motes.length - i;
				if (incr > left) {
					count += left;

					if (count > motes.length) {
						return motes.length;
					}

					return count;
				} else {
					count += incr;
				}
				armin += motes[i];

			}
		}
		if (count > motes.length) {
			return motes.length;
		}

		return count;
	}

	public static void main(String[] args) {
		A a = new A();
		a.compute();
	}
}
