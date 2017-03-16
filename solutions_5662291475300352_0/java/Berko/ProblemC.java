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
public class ProblemC {

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		try {
			new GCJSolver("C-small-1-attempt0.in", "C-small-1-attempt0.out") {
				@Override
				public void solve() throws IOException {
					//assuming total number is 2
					int N = in.nextInt();
					if (N == 1) {
						int D = in.nextInt();
						int H = in.nextInt();
						int M = in.nextInt();
						if (H == 1 || D * (M + 1) >= 360) {
							out.println(0);
						} else {
							out.println(1);
						}
					} else {
						int D1 = in.nextInt();
						in.nextInt();
						int M1 = in.nextInt();
						int D2 = in.nextInt();
						in.nextInt();
						int M2 = in.nextInt();
						if (M2 > M1) {
							if (M2 * D2 < 360 * (M2 - M1)) {
								out.println(1);
							} else {
								out.println(0);
							}
						} else if (M1 > M2) {
							if (M1 * D1 < 360 * (M1 - M2)) {
								out.println(1);
							} else {
								out.println(0);
							}
						} else {
							out.println(0);
						}
					}

				}
			}.solveAll().close();
		} catch (Exception ex) {
			ex.fillInStackTrace();
		}
	}
}
