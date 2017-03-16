import java.util.*;
public class Password {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			//Something
			int A = sc.nextInt();
			int B = sc.nextInt();
			double [] p1 = new double [A];
			for (int i = 0; i<A; ++i) p1[i] = sc.nextDouble();
			double [] correct = new double [A];
			correct[0] = p1[0];
			for (int i = 1; i<A; ++i) correct[i] = correct[i-1] * p1[i];
			
			
			double [] DP = new double [A+1];
			double BEST = 1 + (B+1);
			
			DP[0] = A + (B+1);
			BEST = Math.min(BEST, DP[0]);
			for (int i = 1; i<=A; ++i) {
				DP[i] = correct[i-1] * ((A - i) + (B - i + 1)) + (1.0 - correct[i-1]) * ((A-i) + (B - i + 1) + B+1);
				BEST = Math.min(BEST, DP[i]);
			}
					
			
			
			
			
			
			
			
			System.out.printf("Case #%d: %f\n",ii,BEST);
		}
	}
}