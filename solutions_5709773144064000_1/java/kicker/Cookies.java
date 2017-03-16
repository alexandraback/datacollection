import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.Locale;
import java.util.Scanner;

public class Cookies {

	Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
	static final String FILENAME = "B-large";
	static final String IN = FILENAME + ".in";
	static final String OUT = FILENAME + ".out";
	PrintStream out;

	private void solve() {
		Double c = sc.nextDouble();
		Double f = sc.nextDouble();
		Double x = sc.nextDouble();
		Double res = 0.0;
		Double extra = 2.0;
		// greedy algorithm
		while (x > c && x / (extra + f) < (x - c) / extra) {
			res = res + c / extra;
			extra = extra + f;
		}
		res = res + x / extra;
		res = new BigDecimal(res).setScale(7, BigDecimal.ROUND_HALF_UP)
				.doubleValue();

		out.printf(Locale.US, "%.7f", res);

	}

	private void run() throws Exception {
		sc.useLocale(Locale.US);
		out = new PrintStream(new FileOutputStream(OUT));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sc.nextLine();
			out.print("Case #" + i + ": ");
			solve();
			out.println();
		}
		sc.close();
		out.close();
	}

	public static void main(String args[]) throws Exception {
		new Cookies().run();
	}

}