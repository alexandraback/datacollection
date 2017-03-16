import java.util.Locale;
import java.util.Scanner;

public class A {

	void solve(int icase) {
		String[] s = ss().split("/");
		long a = Long.parseLong(s[0]);
		long b = Long.parseLong(s[1]);

		printf("Case #%d: ", icase);

		a = (2L << 40) * a;
		if (a % b != 0) {
			printf("impossible\n");
			return;
		}

		a /= b;
		b = 2L << 40;

		int res = 1;
		while (2 * a < b) {
			b /= 2;
			res++;
		}

		printf("%d\n", res);
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().repSolve();
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
