import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class TaskB {
	public static void main(String[] args) throws FileNotFoundException {
		new TaskB().solve2();
	}

	private void solve() throws FileNotFoundException {
//		Scanner in = new Scanner(System.in);
//		PrintStream out = System.out;
		Scanner in = new Scanner(new File("B-small-attempt2.in"));
		PrintWriter out = new PrintWriter("taskB.out1");
		int testCase = in.nextInt();
		// int testCase = 1;

		for (int ii = 0; ii < testCase; ++ii) {
			double C = in.nextDouble();
			double F = in.nextDouble();
			double X = in.nextDouble();

			int N = (int) Math.ceil(X);

			int l = 0;
			int r = N;


			double ans = Integer.MAX_VALUE;
			for (int i = l; i <= r+10; ++i) {

				ans = Math.min(ans, calc(C, F, X, i));
			}
			
			out.printf("Case #%d: ", ii+1);
			out.printf("%.7f\n",ans);
		}
		out.close();
		in.close();
	}

	private void solve2() throws FileNotFoundException {
//		Scanner in = new Scanner(System.in);
//		PrintStream out = System.out;
//		Scanner in = new Scanner(new File("B-small-attempt3.in"));
//		PrintWriter out = new PrintWriter("taskB.out");
		Scanner in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter("taskB_large.out");
		int testCase = in.nextInt();
		// int testCase = 1;

		for (int ii = 0; ii < testCase; ++ii) {
			double C = in.nextDouble();
			double F = in.nextDouble();
			double X = in.nextDouble();

			int N = 1000000;

			int l = 0;
			int r = N;

			while ((r - l) / 3 != 0) {
				int d = (r - l) / 3;
				double lv = calc(C, F, X, l + d);
				double rv = calc(C, F, X, r - d);

				if (lv <= rv) {
					r = r - d;
				} else {
					l = l + d;
				}
			}
			double ans = Integer.MAX_VALUE;
			for (int i = l; i <= r+1; ++i) {

				ans = Math.min(ans, calc(C, F, X, i));
			}
			
			out.printf("Case #%d: ", ii+1);
			out.printf("%.7f\n",ans);
		}
		out.close();
		in.close();

	}

	private double calc(double c, double f, double x, double n) {
		double ret = x / (n * f + 2);
		for (int i = 0; i < n; ++i) {
			ret += (double) c / (i * f + 2);
		}

		return ret;
	}
}
