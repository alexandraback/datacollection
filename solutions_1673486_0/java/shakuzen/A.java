import java.util.Scanner;
/*
 * CodeJam 2012 Round 1A
 * Coder: Tommy Ludwig
 * Problem A: Password Problem
 */


public class A {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T, A, B;	//A = chars typed; B = total chars in pwd
		T = in.nextInt();
		
		for (int i = 1; i <= T; i++) {
			A = in.nextInt();
			B = in.nextInt();
			double [] p = new double[A];
			
			for (int j = 0; j < A; j++)
				p[j] = in.nextDouble();
			
			//keep trying
			double p_try;
			double correct = 1;
			for (int j = 0; j < A; j++)
				correct *= p[j];
			p_try = correct * (B-A+1);
			p_try += (1 - correct) * (B-A+1+B+1);
			
			//enter right away
			int p_enter = B + 2;
			
			//backspace __ times
			double [] p_back = new double[A];
			if (A == 1)
				p_back[0] = p_enter;
			if (A == 2) {
				double percent1 = p[0] * (1 - p[1]);
				double percent2 = 1 - (correct + percent1);
				p_back[0] = (correct + percent1) * (B-A+2+1) + (percent2) * (B-A+2+1+B+1);
				p_back[1] = p_enter + 1;
			}
			if (A == 3) {
				double percent1 = (p[0] * (1 - p[2]) * p[1]);
				double percent2 = 1 - (correct + percent1);
				p_back[0] = (correct + percent1) * (B-A+2+1) + (percent2) * (B-A+2+1+B+1);
				percent1 = correct + (p[0] * (1 - p[1]) * (1 - p[2])) + (p[0] * (1 - p[1]) * p[2]) + (p[0] * p[1] * (1 - p[2]));
				percent2 = 1 - percent1;
				p_back[1] = percent1 * (B-A+4+1) + (percent2) * (B-A+4+1+B+1);
				p_back[2] = 3 + B + 1;
			}
			double min_back = p_back[0];
			for (int j = 1; j < A; j++) {
				if (p_back[j] < min_back)
					min_back = p_back[j];
			}
			
			double min = Math.min(min_back, p_enter);
			
			double y = Math.min(min, p_try);
		
			System.out.printf("Case #%d: %f\n", i, y);	//y = expected # of keystrokes using optimal strat
		}
	}

}
