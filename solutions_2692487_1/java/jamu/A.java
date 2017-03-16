import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class A {

	void solve(int icase) {
		long a = si();
		int n = si();

		int[] t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = si();
		}
		Arrays.sort(t);

		int min = n;
		int added = 0;

		if (a > 1) {
			for (int i = 0; i < n; i++) {
				int x = t[i];
				while (a <= x) {
					added++;
					a += a - 1;
				}
				a += x;

				int left = n - i - 1;
				min = Math.min(min, added + left);
			}
		}

		printf("Case #%d: %d\n", icase, min);
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
