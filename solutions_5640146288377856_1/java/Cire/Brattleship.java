/*
 * Eric Schneider
 * 5/10
 */

import java.util.Scanner;


public class Brattleship {
	int [][][] Answer; //RCW
	public Brattleship() {
		Answer = new int[22][22][22];
	}
	
	public int Solve(int R, int C, int W) {
		if (C<W)
			return -10;
		if (Answer[R][C][W]>0)
			return Answer[R][C][W];
		if (R==1 && C==W)
			return W;
		int amax=W;
		if (R==1)
			amax = Math.min(W, C-W);
		int best = R*C+10;
		for(int a = 1; a <= amax; a++) {
			best = Math.min(best, Math.max(R+Solve(R,C-a,W), R-1+Solve(1,Math.min(C,a+W-1),W)));
		}
		Answer[R][C][W] = best;
		return best;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		Brattleship eng = new Brattleship();
		for(int i = 0; i < T; i++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int W = in.nextInt();
			int best = eng.Solve(R, C, W);
			System.out.println("Case #" + (i+1) + ": " + best);
		}
	}
			
}
