package googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class PasswordProblem {

	private static int A;
	private static int B;
	private static double[] ps;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("inputA.txt"));
		sc.useLocale(Locale.US);
		PrintWriter pw = new PrintWriter("outputA.txt");
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			A = sc.nextInt();
			B = sc.nextInt();
			ps = new double[A];
			for (int i = 0; i < ps.length; i++) {
				ps[i] = sc.nextDouble();
			}
			pw.println("Case #" + t + ": " + getExpected());
		}
		pw.flush();
		pw.close();
	}

	private static double getExpected() {
		double[] calc = new double[A];
		calc[0] = ps[0];
		for (int i = 1; i < calc.length; i++) {
			calc[i] = ps[i] * calc[i - 1];
		}

		double res = B + 2; // enter immediately
		for (int backspace = 0; backspace < A; backspace++) {
			double p = calc[A - 1 - backspace];
			double exp = (1 - p) * (backspace + (B - A + backspace) + 1 + B + 1); // wrong
			exp += p * (backspace + (B - A + backspace) + 1); // right
			res = Math.min(res, exp);
		}
		res = Math.min(res, A + B + 1);
		return res;
	}
}
