import java.util.Locale;
import java.util.Scanner;

public class A {

	void solve(int icase) {
		printf("Case #%d:", icase);

		byte[][] a = new byte[4][];
		boolean hasEmpty = false;

		for (int i = 0; i < 4; i++) {
			a[i] = sline().getBytes();
			for (int k = 0; k < 4; k++) {
				if (a[i][k] == '.') {
					hasEmpty = true;
				}
			}
		}

		if (won(a, 'X')) {
			printf(" X won\n");
		} else if (won(a, 'O')) {
			printf(" O won\n");
		} else if (hasEmpty) {
			printf(" Game has not completed\n");
		} else {
			printf(" Draw\n");
		}
	}

	boolean won(byte[][] a, char c) {
		for (int i = 0; i < 4; i++) {
			if (wonh(a[i], c) || wonv(a, i, c) || wond1(a, c) || wond2(a, c)) {
				return true;
			}
		}
		return false;
	}

	boolean wonh(byte[] a, char c) {
		for (int k = 0; k < 4; k++) {
			if (a[k] != c && a[k] != 'T') {
				return false;
			}
		}
		return true;
	}

	boolean wonv(byte[][] a, int i, char c) {
		for (int k = 0; k < 4; k++) {
			if (a[k][i] != c && a[k][i] != 'T') {
				return false;
			}
		}
		return true;
	}

	boolean wond1(byte[][] a, char c) {
		for (int k = 0; k < 4; k++) {
			if (a[k][k] != c && a[k][k] != 'T') {
				return false;
			}
		}
		return true;
	}

	boolean wond2(byte[][] a, char c) {
		for (int k = 0; k < 4; k++) {
			if (a[3 - k][k] != c && a[3 - k][k] != 'T') {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().repSolve();
	}

	void repSolve() throws Exception {
		scanner = new Scanner(System.in);
		// scanner = new Scanner(new java.io.File(""));
		int ncase = si();
		for (int icase = 1; icase <= ncase; icase++) {
			sline();
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
