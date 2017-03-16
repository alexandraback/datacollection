import java.util.Locale;
import java.util.Scanner;

public class B {

	String str(int i, int n, boolean c) {
		String ret = "";
		for (int k = 0; k <= i; k++) {
			ret += "0";
		}
		if (i + 1 < n) {
			for (int k = i + 2; k < n; k++) {
				ret += "1";
			}
			ret += c ? "1" : "0";
		}
		return ret + "\n";
	}

	void solve(int icase) {
		int b = si();
		long m = sl();

		printf("Case #%d: ", icase);

		if ((1L << (b - 2)) < m) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("POSSIBLE\n");
			if ((1L << (b - 2)) == m) {
				for (int i = 0; i < b; i++) {
					printf(str(i, b, true));
				}
			} else {
				printf(str(0, b, false));
				for (int i = 1; i < b; i++) {
					printf(str(i, b, m % 2 == 1));
					m /= 2;
				}
			}
		}
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
			// System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
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