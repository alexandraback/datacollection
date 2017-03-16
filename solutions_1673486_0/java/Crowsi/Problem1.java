import java.util.Scanner;


public class Problem1 {

	public static void main(String args[]) {
		
		Scanner s = new Scanner(System.in);
		
		int T = s.nextInt();
		
		for ( int t = 1; t <= T; t++) {
			
			int A = s.nextInt();
			int N = s.nextInt();
			double[] ps = new double[A];
			
			s.nextLine();
			
			String[] psStrings = s.nextLine().split(" ");
			
			for ( int j = 0; j < psStrings.length; j++ ) {
//				System.out.println(psStrings[j]);
				ps[j] = Double.parseDouble(psStrings[j]);
//				System.out.println(ps[j]);
			}
			
			System.out.println("Case #" + t + ": " + solve(A, ps, N));
			
		}
		
		
	}
	
	public static double solve(int A, double[] ps, int N) {
		
		// Precompute Prange
		double[] prange = new double[ps.length];
		
		prange[0] = ps[0];
		
		for ( int i = 1; i < prange.length; i++ ) {
			prange[i] = prange[i-1] * ps[i]; 
		}

		double minE = Double.MAX_VALUE;
		
		for ( int b = 0; b <= A; b++ ) {
			int Kb = N-A+2*b+1;
			int Kf = Kb+N+1;
			
			double E = -1;
			
			if ( A-b-1 < 0 ) {
				E = Kb;
//				System.out.println("E for " + b + " backspaces: " + E + " " + Kb + " " + 0 + " " + Kf + " " + (1));
			
			} else {
				E = Kb * prange[A-b-1] + Kf*(1-prange[A-b-1]);
		
//				System.out.println("E for " + b + " backspaces: " + E + " " + Kb + " " + prange[A-b-1] + " " + Kf + " " + (1-prange[A-b-1]));
			}
				
			if ( E < minE ) {
				minE = E;
			}
		}
		
		// TODO test case for if press enter directly!
		if ( N+2 < minE ) {
			minE = N+2;
		}

		return minE;
	}
	
}
