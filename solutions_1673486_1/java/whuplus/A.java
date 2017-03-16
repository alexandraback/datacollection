package round1;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A {
	public static Scanner in;
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File("in.txt"));
		out = new PrintStream(new File("out.txt"));

		int T = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= T; t++) {
			System.out.println(t);
			
			out.print("Case #" + t + ": ");
			solve();
			out.println();
		}
	}

	public static void solve() {
		int A, B;

		A = in.nextInt();
		B = in.nextInt();

		double[] p = new double[A];
		for (int i = 0; i < A; i++) {
			p[i] = in.nextDouble();
		}

		List<Double> res = new ArrayList<Double>();
		
		// strategy 1
		double pa = 1;
		for (int i = 0; i < A; i++) {
			pa *= p[i];
		}
		double x1 = (B - A + 1) * pa;
		double x2 = (B - A + 1 + B + 1) * (1 - pa);
//		System.out.println("s1 = " + (x1 + x2));
		res.add(x1 + x2);
		
		
		// strategy 2
		for (int i = 1; i <= A; i++) {
			double pb = 1;
			for (int j = 0; j < A - i; j++) {
				pb *= p[j];
			}
//		 	System.out.println("pb = " + pb);
//			System.out.println("pb = " + (B - A + i + 1 + i));
//			System.out.println("pb = " +  (B - A + i + 1 + i + B + 1));
			
			double x3 = (i + B - A + i + 1) * pb;
			double x4 = (i + B - A + i + 1 + B + 1) * (1 - pb);
//			System.out.println("s2 = " + (x3 + x4) );
			res.add(x3 + x4);
		}
		
		
		
		// strategy 3
//		System.out.println("s3 = " + (B + 2) + "\n\n");
		res.add((double) (B + 2));

		out.printf("%6f", Collections.min(res));
	}
}
