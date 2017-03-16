import java.io.File;
import java.util.Formatter;
import java.util.Scanner;

public class B {
	private static final String ANS = "Case #%s: %.7f\n";

	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new File("io/B/B.small.in.txt")); Formatter out = new Formatter("io/B/B.small.out.txt")) {
			int tests = in.nextInt();
			for (int i = 1; i <= tests; ++i) {
				new B().solve(i, in, out);
			}
		}
	}

	private void solve(int testNo, Scanner in, Formatter out) {
		double c = in.nextDouble();
		double f = in.nextDouble();
		double x = in.nextDouble();
		double perSec = 2;
		double s = 0;

		while ((x - c) * f > c * perSec) {
			s += c / perSec;
			perSec += f;
		}
		s += x / perSec;

		out.format(ANS, testNo, s);
	}
}
