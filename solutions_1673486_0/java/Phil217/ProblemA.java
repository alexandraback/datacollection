package problemA;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("A-practice.in"));
		 Scanner sc = new Scanner(new File("A-small.in"));
		// Scanner sc = new Scanner(new File("A-large.in"));
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			double[] p = new double[A];
			for (int j = 0; j < p.length; j++) {
				p[j] = sc.nextDouble();
			}
			// give up right away
			double min = B + 2;
			double probRight = 1;
			
			for (int j = 0; j < p.length; j++) {
				probRight *= p[j];
				int strokesRight = (A - j - 1) + (B - j - 1) + 1;
				double strokes = probRight * strokesRight + (1 - probRight)
						* (strokesRight + B + 1);
				if (strokes < min) {
					min = strokes;
				}
			}
			// do case things here
			System.out.format("Case #%d: %f\n", i, min);
		}
	}
}
