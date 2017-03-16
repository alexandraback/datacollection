package passwordproblem;

import template.Template;

public class PasswordProblem extends Template {
	public static void main(String[] args) throws Exception {

		init("src/passwordproblem/A-large");
		int lines = readInt();
		for (int i = 1; i <= lines; i++) {

			int[] ab = readIntArray();
			int a = ab[0];
			int b = ab[1];

			double[] p = readDoubleArray();

			double pa = 1;
			for (int j = 0; j < a; j++) {
				pa *= p[j];
			}

			double r2 = 2 * b + 1;
			for (int n = 1; n <= a; n++) {
				double r = 1;
				for (int k = 0; k < a - n; k++) {
					r *= p[k];
				}
				double rx = r * (2 * n + b - a + 1) + (1 - r)
						* (2 * n + b - a + 2 + b);
				if (n == a)
					rx = 2 * n + b - a + 1;
				r2 = Math.min(rx, r2);
			}

			double r1 = pa * (1 + b - a) + (1 - pa) * (2 + 2 * b - a);
			double r3 = 2 + b;

			write("Case #" + i + ": " + Math.min(r2, Math.min(r1, r3)));
		}
	}
}
