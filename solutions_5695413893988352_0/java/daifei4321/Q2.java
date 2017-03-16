package r1B;

import java.util.Scanner;

public class Q2 {
	public static void main(String... args) {
		try (Scanner in = new Scanner(System.in)) {
			int T = in.nextInt();
			for (int caseI = 0; caseI < T; caseI++) {
				String a = in.next();
				String b = in.next();
				assert(a.length() == b.length());
				int[] as = get(a);
				int[] bs = get(b);
				int finalAA = -1;
				int finalBB = -1;
				int finalDiff = Integer.MAX_VALUE;
				for (int aa : as) {
					for (int bb : bs) {
						int diff = Math.abs(aa - bb);
						if (finalDiff > diff ||
								(finalDiff == diff && aa < finalAA) ||
								(finalDiff == diff && aa == finalAA && bb < finalBB)) {
							finalAA = aa;
							finalBB = bb;
							finalDiff = diff;
						}
					}
				}
				System.out.println("Case #" + (caseI + 1) + ": "
						+ preFill(finalAA, a.length()) + " "
						+ preFill(finalBB, a.length()));
			}
		}
	}

	private static String preFill(int n, int length) {
		String s = Integer.toString(n);
		while (s.length() < length) {
			s = '0' + s;
		}
		return s;
	}

	private static int[] get(String a) {
		int[] vals = new int[] {0};
		for (int i = 0, iMax = a.length(); i < iMax; i++) {
			char c = a.charAt(i);
			if (c == '?') {
				int[] vals2 = new int[vals.length * 10];
				for (int j = 0, jMax = vals.length; j < jMax; j++) {
					for (int k = 0; k <= 9; k++) {
						vals2[j * 10 + k] = vals[j] * 10 + k;
					}
				}
				vals = vals2;
			} else {
				c -= '0';
				for (int j = 0, jMax = vals.length; j < jMax; j++) {
					vals[j] = vals[j] * 10 + c;
				}
			}
		}
		return vals;
	}
}
