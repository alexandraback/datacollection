package round1B;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author Roman Elizarov
 */
public class A {
	public static void main(String[] args) throws IOException {
		new A().go();
	}

	Scanner in;
	PrintWriter out;

	private void go() throws IOException  {
		in = new Scanner(new File("src\\round1B\\a.in"));
		out = new PrintWriter(new File("src\\round1B\\a.out"));
		int t = in.nextInt();
		for (int tn = 1; tn <= t; tn++) {
			out.println("Case #" + tn + ": " + solveCase());
		}
		in.close();
		out.close();
	}

	private String solveCase() {
		int n = in.nextInt();
		int[] s = new int[n];
		double x = 0;
		for (int i = 0; i < n; i++) {
			s[i] = in.nextInt();
			x += s[i];
		}
		double[] y = new double[n];
		Arrays.fill(y, 1.0);
		int nzc;
		int nzc2;
		do {
			nzc = 0;
			double nzs = 0;
			for (int i = 0; i < n; i++)
				if (y[i] > 0) {
					nzc++;
					nzs += s[i];
				}
			for (int i = 0; i < n; i++)
				if (y[i] > 0)
					y[i] = Math.max(0.0, (x + nzs) / (x * nzc) - s[i] / x);
			nzc2 = 0;
			for (int i = 0; i < n; i++)
				if (y[i] > 0)
					nzc2++;
		} while (nzc2 < nzc);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			if (i > 0)
				sb.append(' ');
			sb.append(y[i] * 100);
		}
		return sb.toString();
	}
}
