import java.util.Scanner;


public class Password {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numCases = scan.nextInt();
		for(int i = 1; i <= numCases; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			double[] p = new double[a];
			for(int j = 0; j < a; j++) {
				p[j] = scan.nextDouble();
			}
			System.out.println("Case #" + i + ": " + min(a,b,p));
		}
	}
	
	public static double expected(int a, int b, double[] prob, int backspaces) {
		double probCorrect = 1;
		for(int i = 0; i < a-backspaces; i++) {
			probCorrect *= prob[i];
		}
		double left = b-a+2*backspaces+1;
		return left + (1-probCorrect)*(b+1);
	}
	
	public static double min(int a, int b, double[] prob) {
		double min = Double.POSITIVE_INFINITY;
		for(int i = 0; i <= a; i++) {
			double ex = expected(a, b, prob, i);
			if(ex<min) min = ex;
		}
		double so = 2 + b;
		if(so < min) min = so;
		return min;
	}

}
