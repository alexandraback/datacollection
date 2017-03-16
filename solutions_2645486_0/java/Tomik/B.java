package round1a;

import java.util.Arrays;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int E = sc.nextInt();
			int R = sc.nextInt();
			int N = sc.nextInt();
			long[] v = new long[N];
			for (int j = 0; j < N; j++) {
				v[j] = sc.nextLong();
			}
			
			long[][] a = new long[2][E+1];
			int c = 0;
			for (int j = 0; j < N; j++) {
				Arrays.fill(a[1-c], 0);
				for (int j2 = 0; j2 <= E; j2++) {
					for (int k = j2; k >= 0; k--) {
						int pe = Math.min(j2-k+R, E);
						a[1-c][pe] = Math.max(a[1-c][pe], a[c][j2] + k*v[j]);
					}
				}
				c = 1-c;
			}
			long m = 0;
			for (int j = 0; j <= E; j++) {
				m = Math.max(m, a[c][j]);
			}
			
			System.out.println("Case #" + i + ": " + m);
		}
	}

}
