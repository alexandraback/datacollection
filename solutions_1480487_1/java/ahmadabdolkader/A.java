package cj2012.OneB;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws Exception {
		String fileName = "A-large";
		Scanner scan = new Scanner(new File("in/" + fileName + ".in"));
		int T = scan.nextInt(); scan.nextLine();
		PrintWriter out = new PrintWriter(new File("out/" + fileName + ".txt"));
		for (int z = 1; z <= T; z++) {
			int N = scan.nextInt();
			int x = 0;
			int[] s = new int[N];
			double[] p = new double[N];
			for (int i = 0; i < N; i++) {
				s[i] = scan.nextInt();
				x += s[i];
			}
			for (int i = 0; i < N; i++) {
				double a = 0, b = 1;
				while (b - a > 1E-7) {
					p[i] = (a + b) / 2;
					double ss = s[i] + p[i] * x;
					double pc = 0;
					for (int j = 0; j < N; j++)
						if (i != j && Double.compare(s[j], ss) < 0)
							pc += (ss - s[j]) / x;
					if (Double.compare(pc, 1 - p[i]) <= 0)
						a = p[i];
					else
						b = p[i];
				}
			}
			out.print("Case #" + z + ":");
			for (int i = 0; i < N; i++)
				out.printf(" %.6f", 100 * p[i]);
			out.println();
		}
		out.close();
	}
}
