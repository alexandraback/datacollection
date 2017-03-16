import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class Password {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		new Password().run();
	}

	private double solve(int A, int B, double[] prob) {
		double[] mistakeAtProb = new double[A];
		double[] prod = new double[A];
		for (int i = 0; i < A; i++) {
			if (i == 0) {
				prod[i] = prob[i];
			} else {
				prod[i] = prod[i - 1] * prob[i];
			}
		}
		for (int i = 0; i < A; i++) {
			if (i == 0) {
				mistakeAtProb[i] = 1 - prob[i];
			} else {
				mistakeAtProb[i] = prod[i - 1] * (1 - prob[i]);
			}
		}
		double[] mistakeAtLess = new double[A];
		for (int i = 0; i < A; i++) {
			if (i == 0) {
				mistakeAtLess[0] = 0;
			} else {
				mistakeAtLess[i] = mistakeAtLess[i - 1] + mistakeAtProb[i - 1];
			}
		}
		// 1. keep typing
		double kt = prod[A - 1] * (B - A + 1) + (1 - prod[A - 1]) * (B - A + 1 + B + 1);
		// 2. retyping
		double rt = (B + 1 + 1);
		// 3. using backspace
		double[] er = new double[A];
		for (int i = 0; i < A; i++) {
			int keys = (A - i) + (B - i) + 1;
			er[i] = (1 - mistakeAtLess[i]) * (keys) + mistakeAtLess[i] * (keys + B + 1);
		}
		double min = Math.min(kt, rt);
		for (int i = 0; i < A; i++) {
			min = Math.min(min,  er[i]);
		}
		return min;
	}
	
	private void run() throws IOException {
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		//Scanner in = new Scanner("A-small-attempt0.in");
		//PrintWriter out = new PrintWriter("A-small-attempt0.out");
		
		
		int t = in.nextInt();
		for (int test = 0; test < t; test++) {
			int A = in.nextInt(), B = in.nextInt();
			double[] prob = new double[A];
			for (int i = 0; i < A; i++) {
				prob[i] = in.nextDouble();
			}
			double ans = solve(A, B, prob);
			out.println("Case #" + (test + 1) + ": " + ans);
		}
		
		out.close();
	}
}
