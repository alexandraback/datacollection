import java.util.Locale;
import java.util.Scanner;

public class C {

	void solve(int icase) {
		int y = si();
		int x = si();
		int m = si();

		printf("Case #%d:\n", icase);

		if (y * x - 1 == m) {
			printM1(y, x, m);
		} else if (y == 1 || x == 1) {
			print1(y, x, m);
		} else if (y == 2 || x == 2) {
			print2(y, x, m);
		} else {
			printN(y, x, m);
		}
	}

	void printImp() {
		printf("Impossible\n");
	}

	void printRep(int n, String s) {
		for (int i = 0; i < n; i++) {
			printf(s);
		}
	}

	void printM1(int y, int x, int m) {
		for (int iy = 0; iy < y; iy++) {
			for (int ix = 0; ix < x; ix++) {
				printf(iy == 0 && ix == 0 ? "c" : "*");
			}
			printf("\n");
		}
	}

	void print1(int y, int x, int m) {
		int k = Math.max(y, x);
		String endl = y > 1 ? "\n" : "";

		printf("c" + endl);
		printRep(k - m - 1, "." + endl);
		printRep(m, "*" + endl);

		if (endl.isEmpty()) {
			printf("\n");
		}
	}

	void print2(int y, int x, int m) {
		int left = y * x - m;

		if (left < 4 || left % 2 == 1) {
			printImp();
		} else if (x == 2) {
			printf("c.\n");
			printRep(left / 2 - 1, "..\n");
			printRep(m / 2, "**\n");
		} else {
			printf("c");
			printRep(left / 2 - 1, ".");
			printRep(m / 2, "*");
			printf("\n");

			printRep(left / 2, ".");
			printRep(m / 2, "*");
			printf("\n");
		}
	}

	void printN(int y, int x, int m) {
		int left = y * x - m;

		if (left < 4 || left == 5 || left == 7) {
			printImp();
			return;
		}

		boolean[][] t = new boolean[y][x];

		t[0][0] = t[0][1] = t[1][0] = t[1][1] = true;
		left -= 4;

		if (left > 0) {
			t[2][0] = t[2][1] = true;
			left -= 2;
		}

		for (int ix = 2; ix < x && left > 1; ix++) {
			t[0][ix] = t[1][ix] = true;
			left -= 2;
		}

		for (int iy = 3; iy < y && left > 1; iy++) {
			t[iy][0] = t[iy][1] = true;
			left -= 2;
		}

		for (int iy = 2; iy < y && left > 0; iy++) {
			for (int ix = 2; ix < x && left > 0; ix++) {
				t[iy][ix] = true;
				left--;
			}
		}

		for (int iy = 0; iy < y; iy++) {
			for (int ix = 0; ix < x; ix++) {
				if (iy == 0 && ix == 0) {
					printf("c");
				} else {
					printf(t[iy][ix] ? "." : "*");
				}
			}
			printf("\n");
		}
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
