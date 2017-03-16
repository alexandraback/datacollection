import java.util.Scanner;

public class Cookieclicker {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		double[] ans = new double [tests];
		for (int t = 0; t < tests; t++) {
			double c = in.nextDouble();
			double f = in.nextDouble();
			double x = in.nextDouble();
			ans[t] = Cookieclicker.solve(c, f, x);
            
		}
		for (int i = 0;i < tests;i++) {
			System.out.println("Case #" + String.valueOf(i+1) + ": " + ans[i]);
		}
	}
	
	static double solve(double c, double f, double x) {
		double p = 2;
		double ans = 0;
		while (true) {
			double a = c/f + c/p;
			double time = x/p;
			if (time < a) {
				return ans + time;
			}
            ans += c/p;
            p += f;
		}
	}
}
