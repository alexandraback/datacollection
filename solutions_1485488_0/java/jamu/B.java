import java.util.Locale;
import java.util.Scanner;

public class B {

	int water;
	int ny, nx;

	class Sq {
		int ceil, floor;
		int y, x;
		int time = -1;
		boolean done = false;
	}

	Sq[][] t;

	int[] dy = { -1, 0, 1, 0 };
	int[] dx = { 0, -1, 0, 1 };

	void solve(int icase) {
		water = si();
		ny = si();
		nx = si();

		t = new Sq[ny][nx];

		for (int iy = 0; iy < ny; iy++) {
			for (int ix = 0; ix < nx; ix++) {
				t[iy][ix] = new Sq();
				t[iy][ix].ceil = si();
				t[iy][ix].y = iy;
				t[iy][ix].x = ix;
			}
		}

		for (int iy = 0; iy < ny; iy++) {
			for (int ix = 0; ix < nx; ix++) {
				t[iy][ix].floor = si();
			}
		}

		t[0][0].time = 0;

		Sq exit = t[ny - 1][nx - 1];

		while (!exit.done) {
			Sq best = getBest();
			best.done = true;
			for (int dir = 0; dir < 4; dir++) {
				Sq next = next(best, dir);
				if (next != null) {
					int h = water - best.time;
					int wait = Math.max(0, h + 50 - next.ceil);
					if (best.time == 0 && wait == 0) {
						next.time = 0;
					} else {
						int tmp = nextTime(best, best.time + wait);
						if (next.time == -1 || next.time > tmp) {
							next.time = tmp;
						}
					}
				}
			}
		}

		printf("Case #%d: %d.%d\n", icase, exit.time / 10, exit.time % 10);
	}

	Sq getBest() {
		Sq best = null;
		for (int iy = 0; iy < ny; iy++) {
			for (int ix = 0; ix < nx; ix++) {
				Sq sq = t[iy][ix];
				if (!sq.done && sq.time != -1 && (best == null || sq.time < best.time)) {
					best = sq;
				}
			}
		}
		return best;
	}

	Sq next(Sq sq, int dir) {
		int y = sq.y + dy[dir];
		int x = sq.x + dx[dir];
		if (0 <= y && y < ny && 0 <= x && x < nx) {
			Sq next = t[y][x];
			if (next.floor + 50 <= next.ceil && sq.floor + 50 <= next.ceil && next.floor + 50 <= sq.ceil) {
				return next;
			}
		}
		return null;
	}

	int nextTime(Sq sq, int moveTime) {
		int h = water - moveTime;
		if (h - sq.floor >= 20) {
			return moveTime + 10;
		} else {
			return moveTime + 100;
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
