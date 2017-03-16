import java.util.Locale;
import java.util.Scanner;

public class C {

	void solve(int icase) {
		int a = si();
		int b = si();

		int digits = ("" + a).length();

		int s = 1;
		for (int i = 0; i < digits; i++) {
			s *= 10;
		}

		long res = 0;

		for (int i = a; i < b; i++) {
			res += find(s, i, b);
		}

		printf("Case #%d: %d\n", icase, res);
	}

	int nused;
	int[] used = new int[10];

	int find(int s, int x, int b) {
		int ret = 0;

		nused = 0;

		for (int m = 10; m < x; m *= 10) {
			int y = x % m;

			if (y >= m / 10) {
				y *= s / m;
				y += x / m;

				if (y <= b && x < y && !used(y)) {
					ret++;
					used[nused++] = y;
				}
			}
		}

		return ret;
	}

	boolean used(int y) {
		for (int i = 0; i < nused; i++) {
			if (used[i] == y) {
				return true;
			}
		}
		return false;
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new C().repSolve();
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
