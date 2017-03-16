package r1a2012;

import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in).useLocale(Locale.US);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("A.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int n = in.nextInt(), m = in.nextInt();
			double[] p = new double[n];
			double all = 1;
			for (int i = 0; i < n; i++) all *= p[i] = in.nextDouble();
			double ans = Math.min(m + 2, all*(m-n+1) + (1-all)*(m-n+1+m+1));
			double first = 1;
			for (int i = 0; i < n; i++) {
				int ks = n-i;
				ans = Math.min(ans, first*(ks+ks+m-n+1) + (1-first)*(ks+ks+m-n+1+m+1));
				first *= p[i];
			}
			out.println(ans);
		}
		
		out.flush();
	}

}
