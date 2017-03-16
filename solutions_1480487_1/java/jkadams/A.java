import java.util.*;
public class A {
	public static double eps = 1e-9;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int ca = 1; ca <= T; ca++) {
			int N = s.nextInt();
			int[] A = new int[N];
			int X = 0;
			for (int i = 0; i < N; i++) { A[i] = s.nextInt(); X+=A[i]; }
			System.out.printf("Case #%d:",ca);
			for (int i = 0; i < N; i++) {
				double L = 0, R = 1;
				for (int q = 0; q < 80; q++) {
					double M = (L+R)/2;
					if (possible(M, A, X, i)) {
						L = M;
					} else {
						R = M;
					}
				}
				L *= 100.;
				System.out.printf(" %.6f",L);
			}
			System.out.println();
		}
	}
	public static boolean possible(double p, int[] A, double X, int i) {
		double P = p;
		for (int j = 0; j < A.length; j++) {
			if (i == j) continue;
			P += Math.max(0, p + (A[i] - A[j])/X);
		}
		if (P > 1 + eps) return false;
		return true;
	}
}
