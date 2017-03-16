import java.util.Locale;
import java.util.Scanner;

public class C {

	int n;
	int[] s;

	int[] a;
	int[] b;
	int na;
	int nb;

	void solve(int icase) {
		n = si();
		s = new int[n];

		for (int i = 0; i < n; i++) {
			s[i] = si();
		}

		a = new int[n];
		b = new int[n];

		printf("Case #%d:\n", icase);
		if (find(0, 0, 0, 0, 0)) {
			for (int i = 0; i < na; i++) {
				printf(i == 0 ? "%d" : " %d", a[i]);
			}
			printf("\n");
			for (int i = 0; i < nb; i++) {
				printf(i == 0 ? "%d" : " %d", b[i]);
			}
			printf("\n");
		} else {
			printf("Impossible\n");
		}
	}

	boolean find(int indexS, int indexA, int indexB, int sumA, int sumB) {
		if (sumA == sumB && sumA > 0) {
			na = indexA;
			nb = indexB;
			return true;
		}

		if (indexS >= n) {
			return false;
		}

		int x = s[indexS];

		a[indexA] = x;
		if (find(indexS + 1, indexA + 1, indexB, sumA + x, sumB)) {
			return true;
		}

		b[indexB] = x;
		if (find(indexS + 1, indexA, indexB + 1, sumA, sumB + x)) {
			return true;
		}

		if (find(indexS + 1, indexA, indexB, sumA, sumB)) {
			return true;
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
