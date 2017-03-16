package codejam.qualification;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {

	private final static boolean SMALL = false;
	private static double M;
	
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("src/B-" + (SMALL ? "small" : "big") + ".in"));
		PrintWriter output = new PrintWriter("src/B-" + (SMALL ? "small" : "big") + ".out");

		String out;
		int T = input.nextInt();
		for(int i = 1; i <= T; i++) {
			double C = input.nextDouble();
			double F = input.nextDouble();
			double X = input.nextDouble();			
			M = X/2;
			solve(C, F, X, 2, 0);
			out = "Case #" + i + ": " + M;
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}
	
	private static void solve(double C, double F, double X, double P, double S) {
		double time = X/P + S;
		if (time < M) {
			M = time;
		}
		if (S + C/P >= M) {
			return;
		}
		solve(C, F, X, P+F, S + C/P);
	}

}
