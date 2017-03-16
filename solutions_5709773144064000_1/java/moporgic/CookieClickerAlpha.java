import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class CookieClickerAlpha {

	static {
		try {
			String input = "B-large.in";
			String output = input.substring(0, input.lastIndexOf('.')) + ".out";
			System.setIn(new FileInputStream(input));
			System.setOut(new PrintStream(new FileOutputStream(output), true));
			// System.setOut(new PrintStream(new FileOutputStream(
			// "B-large-test0.in"), true));
			// System.out.println(100);
			// for (int i = 0; i < 99; i++) {
			// double c = Math.round(Math.random() * 10000) + 1;
			// double f = Math.round(Math.random() * 100) + 1;
			// double x = Math.round(Math.random() * 100000) + 1;
			// c = Math.min(10000, c + Math.random());
			// f = Math.min(100, f + Math.random());
			// x = Math.min(100000, x + Math.random());
			// System.out.printf("%.7f %.7f %.7f\n", c, f, x);
			// }
			// System.out.printf("%.7f %.7f %.7f\n", 99.999, 2.0, 100000.0);
			// System.exit(0);
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for (int total = input.nextInt(), r = 1; r <= total; r++) {
			double c = input.nextDouble();
			double f = input.nextDouble();
			double x = input.nextDouble();
			double v = 2, t = 0, tx, tf;
			while (true) {
				tx = x / v;
				tf = c / v;
				v += f;
				if (tx > tf + (x / v)) {
					t += tf;
				} else {
					t += tx;
					break;
				}
			}
			System.out.printf("Case #%d: %.7f\n", r, t);
		}
		input.close();
	}

}
