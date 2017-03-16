import java.util.Locale;
import java.util.Scanner;

public class B {

	void solve(int icase) {
		printf("Case #%d: ", icase);

		int n = si();
		int x = si();
		int y = si();

		int layer = (x + y) / 2 + 1;

		if (n >= numPyramid(layer)) {
			printf("1.0\n");
			return;
		}

		if (n <= numPyramid(layer - 1) || x == 0) {
			printf("0.0\n");
			return;
		}

		int k = n - numPyramid(layer - 1);
		if (k <= y) {
			printf("0.0\n");
			return;
		}

		int e = (layer - 1) * 2;

		if (y <= k - e - 1) {
			printf("1.0\n");
			return;
		}

		int s;
		int h;

		if (k > e) {
			s = 2 * e - k;
			h = y + 1 - (k - e);
		} else {
			s = k;
			h = y + 1;
		}

		if (h > s) {
			throw new RuntimeException();
		}

		double sum = 0.0;

		for (int i = h; i <= s; i++) {
			sum += nt(s, i);
		}

		double p = 1.0;

		for (int i = 0; i < s; i++) {
			p *= 2.0;
		}

		System.out.println(sum / p);
	}

	double nt(int n, int k) {
		int gk = Math.max(n - k, k);
		int lk = Math.min(n - k, k);

		double u = 1.0;

		for (int i = gk + 1; i <= n; i++) {
			u *= i;
		}

		double d = 1.0;

		for (int i = 2; i <= lk; i++) {
			d *= i;
		}

		return u / d;
	}

	int numPyramid(int k) {
		return k * (2 * k - 1);
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
