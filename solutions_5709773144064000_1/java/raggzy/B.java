package y2014.qualification;

import template.Runner;
import template.Solver;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by raggzy on 4/12/14.
 */
public class B extends Solver {

	public static final double EPS = 0.0000001;

	public B(Scanner in, PrintStream out, int TC) {
		super(in, out, TC);
	}


	@Override
	public void solve() {
		double C = in.nextDouble();
		double F = in.nextDouble();
		double X = in.nextDouble();
		double t = 0;
		double a = X / 2;
		for (int i = 0; ; i++) {
			double tNext = t + C / (F * i + 2);
			double aNext = tNext + X / (F * (i + 1) + 2);
			if (aNext > a) {
				break;
			}
			if (Math.abs(aNext - a) < EPS) {
				break;
			}
			t = tNext;
			a = aNext;
		}
		println("Case #%d: %.7f", TC, a);
	}

	public static void main(String[] args) throws Exception {
		Runner.main(B.class);
	}
}
