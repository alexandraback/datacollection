import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int no = 1; no <= T; no++) {
			System.out.printf("Case #%d:%n", no);

			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();

			boolean possible = false;
			TASK: for (int bits = 0; bits < (1 << (R * C)); bits++) {
				if (Integer.bitCount(bits) != M)
					continue;
				for (int x = 0; x < C; x++) {
					for (int y = 0; y < R; y++) {
						int opened = open(bits, R, C, x, y, 0);
						// System.err.println(opened);
						if (Integer.bitCount(opened) == R * C - M) {
							possible = true;
							printMap(bits, R, C, x, y);
							break TASK;
						}
					}
				}
			}
			if (!possible) {
				System.out.println("Impossible");
			}
		}
	}

	private static int open(int map, int r, int c, int x, int y, int state) {
		if (x < 0 || x >= c || y < 0 || y >= r)
			return state;
		int ind = y * c + x;
		int bit = 1 << ind;
		if ((state & bit) != 0)
			return state;
		if ((map & bit) != 0)
			return state;
		state |= bit;
		boolean isZero = true;
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int ax = x + dx;
				int ay = y + dy;
				if (ax < 0 || ax >= c || ay < 0 || ay >= r)
					continue;
				if ((map & (1 << (ay * c + ax))) != 0)
					isZero = false;
			}
		}
		if (isZero) {
			for (int dx = -1; dx <= 1; dx++) {
				for (int dy = -1; dy <= 1; dy++) {
					int ax = x + dx;
					int ay = y + dy;
					state = open(map, r, c, ax, ay, state);
				}
			}
		}
		return state;
	}

	private static void printMap(int bits, int r, int c, int cx, int cy) {
		for (int y = 0; y < r; y++) {
			for (int x = 0; x < c; x++) {
				int ind = y * c + x;
				char ch = (((bits >> ind) & 0x1) == 1) ? '*' : '.';
				if (x == cx && y == cy)
					ch = 'c';
				System.out.print(ch);
			}
			System.out.println();
		}
	}

}
