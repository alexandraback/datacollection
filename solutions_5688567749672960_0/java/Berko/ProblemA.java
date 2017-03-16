/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package GCJ;

import java.io.IOException;

/**
 *
 * @author t7639192
 */
public class ProblemA {

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		try {
			new GCJSolver("A-small-attempt1.in", "A-small-attempt1.out") {
				@Override
				public void solve() throws IOException {
					out.println(findMin(in.nextInt()));
				}

				private int findMin(int N) {
					if (N < 10) {
						return N;
					}
					if (N % 10 == 0) {
						int rN = reverse(N);
						if (rN >= N) {
							return findMin(N - 9) + 9;
						} else {
							return findMin(reverse(N)) + 1;
						}
					}
					if (N % 10 == 1) {
						int rN = reverse(N);
						if (rN >= N) {
							return findMin(N - 1) + 1;
						} else {
							return findMin(reverse(N)) + 1;
						}
					}
					return findMin((N / 10) * 10 + 1) + N % 10 - 1;
				}

				private int reverse(int n) {
					int r = 0;
					do {
						r = r * 10 + n % 10;
						n = n / 10;
					} while (n > 0);
					return r;
				}
			}.solveAll().close();
		} catch (Exception ex) {
			ex.fillInStackTrace();
		}
	}
}
