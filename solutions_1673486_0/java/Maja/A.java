package y2012.round1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		String testName = "A";
		Scanner in = new Scanner(new File("d:\\Downloads\\" + testName + ".in"));
		PrintWriter out = new PrintWriter(new File("d:\\Downloads\\" + testName
				+ ".out"));
		int nTestCase = Integer.parseInt(in.nextLine());
		for (int testCase = 1; testCase <= nTestCase; testCase++) {
			int m = in.nextInt();
			int n = in.nextInt();
			double[] p = new double[m];
			for (int i = 0; i < m; i++)
				p[i] = in.nextDouble();
			double res = n + 2;

			double tp = 1;
			for (int i = 1; i <= m; i++) {
				tp *= p[i - 1];
				double tmp = tp * ((m - i) + (n - i) + 1) + (1 - tp)
						* ((m - i) + (n - i) + 1 + n + 1);
				if (tmp < res)
					res = tmp;
			}

			out.printf("Case #%d: %.6f\n", testCase, res);
		}
		in.close();
		out.close();
	}
}
