package qualC2016;

import java.util.*;

public class B {
	public static void main(String... args) {
		Scanner s = new Scanner(System.in);
		
		final int T = s.nextInt();
		for (int t = 1; t <= T; t++) {
			B = s.nextInt();
			M = s.nextLong();
			
			System.out.printf("Case #%d: ", t);
			solve();
		}
		
		s.close();
	}
	
	static void solve() {
		soln = new int[B][B];
		dyn = new long[B];
		
		long s = solveAux(0, 0);
		boolean found = s == M;
		
		if (found) {
			System.out.println("POSSIBLE");
			for (int[] i : soln) {
				for (int ii : i) {
					System.out.print(ii);
				}
				System.out.println();
			}
		} else {
			System.out.println("IMPOSSIBLE");
		}
	}
	
	static long solveAux(int p, long N) {
		soln[p][B-1] = 1;
		long s = 1, sOld;
		
		if (dyn[p] != 0) s = dyn[p];
		
		for (int i = p + 1; i < B - 1; i++) {
			if (s + N >= M) break;
			if (soln[p][i] == 1) continue;
			sOld = s;
			s = solveAux(i, s + N) - N;
			if (s + N <= M) {
				soln[p][i] = 1;
			} else {
				s = sOld;
			}
		}
		
		dyn[p] = s;
		return s + N;
	}
	
	static int B;
	static long M;
	
	static int[][] soln;
	static long[] dyn;
}
