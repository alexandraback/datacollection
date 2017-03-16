import java.util.*;
public class A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int ca = 1 ;ca <= T; ca++){
			int A = s.nextInt(), B = s.nextInt();
			double[] p = new double[A];
			double prod = 1;
			for (int i = 0; i < A; i++) {
				p[i] = s.nextDouble();
				prod *= p[i];
			}
			double min = B + 2;
			for (int d = 0, div = A-1; d <= A; d++, div--) {
				double exp = d + (1 - prod)*(B-A+d+B+2) + prod * (B-A+d+1);
				min = Math.min(min, exp);
				if (div >= 0) prod /= p[div];
			}
			System.out.printf("Case #%d: %.6f\n",ca,min);
		}
	}
}
