package round1b;

import java.util.*;

public class SafetyInNumbers {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		for (int k = 1; k <= T; k++) {
			
			int N = sc.nextInt();
			
			int[] s = new int[N];
			
			int X = 0;
			double Xd = 0;
			
			double[] sd = new double[N];
			
			for (int i = 0; i < N; i++) {
				s[i] = sc.nextInt();
				sd[i] = s[i];
				X += s[i];
				Xd += s[i];
			}
			
			Arrays.sort(sd);
			
			double ceiling = sd[0];
			int ix = 0;
			while (Xd > 0) {
				if (ix == N-1) {
					if (((2*X/(double)N) - ceiling) != Xd/N) {
						//System.out.println("Warning, " + (((2*X/(double)N) - ceiling) - Xd/N));
					}
					ceiling = 2*X/((double)N);
					break;
				}
				double diff = (sd[ix+1] - sd[ix]);
				if (diff*(ix+1) < Xd) {
					Xd -= diff*(ix+1);
					ceiling += diff;
				} else {
					ceiling += Xd/(ix+1);
					Xd = 0;
				}
				ix += 1;
			}
			
			System.out.print("Case #" + k + ":");
						
			for (int i = 0; i < N; i++) {
				int mine = s[i];
				double p = (ceiling - mine)/((double)X);
				System.out.print(" " + Math.max(p*100, 0));
			}
			System.out.println();
			
			
			
		}
		
	}

}
