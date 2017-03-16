package codejam.recycle;

import java.util.HashSet;
import java.util.Set;

public class Recycle {

	public String solve(String s) {

		String[] ss = s.split(" ");
		int a = Integer.parseInt(ss[0]);
		int b = Integer.parseInt(ss[1]);

		int n = ("" + a).length();
		int m = 0;

		for (int i = a; i <= b; i++) {
			int[] digits = collectDigits(i);
			Set<Integer> done = new HashSet<Integer>();
			for (int j = 1; j < n; j++) {
				int t = offsetNum(digits, j);
				if (t <= b && t > i && done.add(t)) {
					m++;
				}
			}
		}

		return "" + m;
	}

	private int[] collectDigits(int num) {
		int n = ("" + num).length();
		int[] digits = new int[n];
		int i = n;
		while (i > 0) {
			digits[--i] = num % 10;
			num = (int) (num / 10d);
		}
		return digits;
	}

	private int offsetNum(int[] x, int m) {

		int a = 0;

		for (int i = 0; i < x.length; i++) {
			a += x[(i + m) % x.length] * Math.pow(10, x.length - 1 - i);
		}

		return a;
	}
}
