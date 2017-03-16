import java.util.Scanner;


class ProblemA {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int I = 1; I <= T; ++I) {
			int A = in.nextInt(), B = in.nextInt();
			double[] p = new double[A+1];
			for (int i = 0; i < A; ++i) {
				p[i] = in.nextDouble();
			}
			
			double[] prods = new double[A+1];
			double[] probs = new double[A+1];
			double prevProd = 1;
			
			prods[A] = 1;
			for (int i = A-1; i >= 0; --i) {
				prods[i] = prods[i+1]*p[A-i-1];
			}
			
			//Calculate prob sums
//			probs[0] = prods[0];
//			for (int i = 1; i <= A; ++i) {
//				probs[i] = probs[i-1] + prods[i];
//			}
			
			double bestVal = 2 + B; //Just pressing en.ter
			
			for (int i = 0; i < probs.length; ++i) {
				int right = B-A + 1 + 2*i, wrong = 2*B - A + 2 + 2*i;
				double eV = prods[i]*right + (1-prods[i])*wrong;
				bestVal = Math.min(bestVal, eV);
			}
			
			System.out.printf("Case #%d: %.6f\n", I, bestVal);
		}
	}
}
