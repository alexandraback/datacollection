import java.util.Locale;
import java.util.Scanner;

public class B {

	int ny, nx;
	int[][] t;
	boolean[] ydone;
	boolean[] xdone;
	int currentH;

	void solve(int icase) {
		printf("Case #%d: ", icase);

		ny = si();
		nx = si();

		t = new int[ny][nx];
		ydone = new boolean[ny];
		xdone = new boolean[nx];
		currentH = 0;

		for (int y = 0; y < ny; y++) {
			for (int x = 0; x < nx; x++) {
				t[y][x] = si();
			}
		}

		for (int ii = 0; ii < ny * nx + 1; ii++) {
			int besth = Integer.MAX_VALUE;
			int besty = -1;
			int bestx = -1;

			for (int y = 0; y < ny; y++) {
				int yh = getYh(y, besth);
				if (yh != 0) {
					besth = yh;
					besty = y;
				}
			}

			for (int x = 0; x < nx; x++) {
				int xh = getXh(x, besth);
				if (xh != 0) {
					besth = xh;
					besty = -1;
					bestx = x;
				}
			}

			if (besth >= currentH && (besty != -1 || bestx != -1)) {
				if (besty != -1) {
					ydone[besty] = true;
					for (int x = 0; x < nx; x++) {
						t[besty][x] = 0;
					}
				} else {
					xdone[bestx] = true;
					for (int y = 0; y < ny; y++) {
						t[y][bestx] = 0;
					}
				}
				currentH = besth;
			} else {
				for (int y = 0; y < ny; y++) {
					for (int x = 0; x < nx; x++) {
						if (t[y][x] != 0) {
							printf("NO\n");
							return;
						}
					}
				}
				printf("YES\n");
				return;
			}
		}

		throw new RuntimeException();
	}

	int getYh(int y, int besth) {
		if (ydone[y]) {
			return 0;
		}

		int th = 0;
		for (int x = 0; x < nx; x++) {
			int a = t[y][x];
			if (a != 0) {
				if (th == 0) {
					if (a >= besth) {
						return 0;
					}
					th = a;
				} else if (th != a) {
					return 0;
				}
			}
		}
		return th;
	}

	int getXh(int x, int besth) {
		if (xdone[x]) {
			return 0;
		}

		int th = 0;
		for (int y = 0; y < ny; y++) {
			int a = t[y][x];
			if (a != 0) {
				if (th == 0) {
					if (a >= besth) {
						return 0;
					}
					th = a;
				} else if (th != a) {
					return 0;
				}
			}
		}
		return th;
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
