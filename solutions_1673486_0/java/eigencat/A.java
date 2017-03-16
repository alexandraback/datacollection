import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		// String file = "sample.in";
		String file = "A-small-attempt0.in";
		// String file = "A-large.in";
		System.setOut(new PrintStream("A-small-attempt0.out"));
		Scanner scan = new Scanner(new File(file));
		int t = scan.nextInt();
		for (int i = 0; i < t; i++)
			solve(scan, i + 1);
	}

	private static void solve(Scanner scan, int caseNum) {
		int a = scan.nextInt(); // chars typed
		int b = scan.nextInt(); // total chars
		double[] p = new double[a]; // probability correct
		for (int i = 0; i < a; i++)
			p[i] = scan.nextDouble();

		// just press enter
		double min = 1 + b + 1;

		double probFirstICorrect = 1;
		for (int i = 0; i <= a; i++) {
			// i = num characters to keep
			int d = a - i; // num delete
			double keys = d + d + (b - a) + 1 + (1 - probFirstICorrect)
			        * (b + 1);

			if (keys < min)
				min = keys;

			if (i != a)
				probFirstICorrect *= p[i];
		}

		System.out.printf("Case #%d: %f%n", caseNum, min);
	}
}