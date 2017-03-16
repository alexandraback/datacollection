package gcj.round1a;

import java.util.Scanner;

public class A {
	public static void main(String args[]) {
		new A();
	}

	public A() {
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		for(int x=0; x<T; x++) {
			int A = scan.nextInt();
			int B = scan.nextInt();
			double[] p = new double[A];
			for(int i=0; i<A; i++) {
				p[i] = scan.nextDouble();
			}

			double min_e = 2 + B;
			double e_type = 0.0;
			double pc = 1.0;
			double pf = 1.0;

			for(int n=0; n<=A; n++) {
				if(n==0) {
					e_type = A + B + 1;
				} else {
					e_type = pc * (A + B + 1 - 2 * n) + pf * (A + 2 * B + 2 - 2 * n);
				}

				if(min_e > e_type) {
					min_e = e_type;
				}

				if(n != A) {
					pc *= p[n];
					pf = 1.0 - pc;
				}
			}

			System.out.printf("Case #%d: %f\n", x+1, min_e);
		}
	}
}