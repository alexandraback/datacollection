package tochi.gcj2012;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class R1A_A {
	public static void main(String[] args) throws Exception {
		System.setOut(new PrintStream(new File("output_large.txt")));
		Scanner sc = new Scanner(new File("A-large.in"));
		int T = Integer.parseInt(sc.nextLine());
		for (int i = 1; i <= T; i++) {
			String[] strs = sc.nextLine().split(" ");
			int A = Integer.parseInt(strs[0]);
			int B = Integer.parseInt(strs[1]);
			String[] strs2 = sc.nextLine().split(" ");
			double[] p = new double[A];
			for (int j = 0; j < A; j++) {
				p[j] = Double.parseDouble(strs2[j]);
			}
			String format = String.format("Case #" + i + ": %.6f",
					answer(A, B, p));
			System.out.println(format);
		}
	}

	private static double answer(int A, int B, double[] p) {
		double enter = (double) (B + 2);
		double min = enter;
		double p1 = 1.0;

		for (int i = 0; i < p.length; i++) {
			p1 *= p[i];
			int t = p.length - i - 1;
			double keep = (B - A + 1 + 2 * t) * p1 + (2 * B - A + 2 + 2 * t)
					* (1 - p1);
			if (keep < min)
				min = keep;
		}

		return min;
	}
}
