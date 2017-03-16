import java.util.*;

public class ProbA {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int t = s.nextInt();
		double[] sols = new double[t];
		
		for(int i = 0; i < t; i++) {
			int a = s.nextInt(); // number of characters already typed
			int b = s.nextInt(); // total number of characters in password
			//System.out.println("A is " + a  + " and B is " + b);
			
			double[] prob = new double[a];
			for(int j = 0; j < a; j++) {
				prob[j] = s.nextDouble();
				//System.out.println(prob[j]);
			}
			
			sols[i] = solve(a, b, prob);
		}
		s.close();
		for(int i = 0; i < t - 1; i++) {
			System.out.print("Case #" + (i+1) + ": ");
			System.out.printf("%.6f", sols[i]);
			System.out.println();
		}
		System.out.print("Case #" + t + ": ");
		System.out.printf("%.6f", sols[t - 1]);
	}
	
	public static double solve(int a, int b, double[] prob) {
		//int possible = (int) Math.pow(2, a);
		
		double probAllCorrect = 1.0;
		for(int i = 0; i < a; i++) {
			probAllCorrect *= prob[i];
		}
		
		double strat1exp = (b - a + 1)*probAllCorrect + (2*b - a + 2)*(1.0 - probAllCorrect);
		double strat3exp = (b + 2);
		
		double bestStrat = Math.min(strat1exp, strat3exp);
		
		for(int i = 1; i < a; i++) {
			double probCrt = 1.0;
			for(int j = 0; j < (a - i); j++) {
				probCrt *= prob[j];
			}
			
			double stratExp = (2*i + (b-a) + 1)*probCrt + (2*i + 2*b - a + 2)*(1.0 - probCrt);
			bestStrat = Math.min(bestStrat, stratExp);
		}
		
		return Math.min(bestStrat, a + b + 1);
	}

}
