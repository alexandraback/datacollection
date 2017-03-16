import java.util.Locale;
import java.util.Scanner;

public class B {

	void solve(int icase) {
		int n = si();
		int s = si();
		int p = si();
		int[] t = new int[31];
		for (int i = 0; i < n; i++) {
			t[si()]++;
		}
		int res = Math.min(p < 2 ? 0 : t[3 * p - 4] + t[3 * p - 3], s);
		for (int i = Math.max(3 * p - 2, 0); i <= 30; i++) {
			res += t[i];
		}
		printf("Case #%d: %d\n", icase, res);
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
