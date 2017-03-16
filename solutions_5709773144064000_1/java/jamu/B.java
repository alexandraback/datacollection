import java.util.Locale;
import java.util.Scanner;

public class B {

	void solve(int icase) {
		double c = sd();
		double f = sd();
		double x = sd();

		long n = Math.max(0, Math.round(Math.ceil((x * f - 2 * c) / (c * f))) - 1);

		double res = 0;
		for (long i = 0; i < n; i++) {
			res += c / (2 + i * f);
		}
		res += x / (2 + n * f);

		printf("Case #%d: %.8f\n", icase, res);
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new B().repSolve();
	}

	void repSolve() throws Exception {
		scanner = new Scanner(System.in);
		// scanner = new Scanner(new java.io.File(""));
		int ncase = si();
		sline();
		for (int icase = 1; icase <= ncase; icase++) {
			solve(icase);
			System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
	}

	double sd() {
		return scanner.nextDouble();
	}

	String ss() {
		return scanner.next();
	}

	String sline() {
		return scanner.nextLine();
	}

	void printf(String format, Object... args) {
		System.out.printf(format, args);
	}

}
