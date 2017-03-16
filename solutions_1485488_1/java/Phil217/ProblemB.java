package problemB;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemB {
	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("B-practice.in"));
//		Scanner sc = new Scanner(new File("B-small.in"));
		 Scanner sc = new Scanner(new File("B-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			int H = sc.nextInt();
			int N = sc.nextInt();
			int M = sc.nextInt();
			int[][] ceiling = new int[N][M];
			int[][] floor = new int[N][M];
			for (int j = 0; j < ceiling.length; j++) {
				for (int k = 0; k < ceiling[j].length; k++) {
					ceiling[j][k] = sc.nextInt();
				}
			}
			for (int j = 0; j < floor.length; j++) {
				for (int k = 0; k < floor[j].length; k++) {
					floor[j][k] = sc.nextInt();
				}
			}
			boolean[][] reachable = new boolean[N][M];
			reachable[0][0] = true;
			reach(floor, ceiling, reachable, H, 0, 0);
			int[][] times = new int[N][M];
			for (int j = 0; j < times.length; j++) {
				for (int k = 0; k < times[j].length; k++) {
					if (reachable[j][k]) {
						times[j][k] = -2;
					} else {
						times[j][k] = -1;
					}
				}
			}
			simulate(floor, ceiling, reachable, times, H);
			// for (int j = 0; j < reachable.length; j++) {
			// System.out.println(Arrays.toString(reachable[j]));
			// }
			// for (int j = 0; j < reachable.length; j++) {
			// System.out.println(Arrays.toString(times[j]));
			// }
			// do case things here
			System.out.format(Locale.US, "Case #%d: ", i);
			if (times[times.length - 1][times[0].length - 1] == -2) {
				System.out.println("0.0");
			} else {
				System.out
						.println(times[times.length - 1][times[0].length - 1] / 10.0);
			}
		}
	}

	private static void simulate(int[][] floor, int[][] ceiling,
			boolean[][] reachable, int[][] times, int H) {
		int time = 0;
		while (H >= 0
				&& (!reachable[reachable.length - 1][reachable[0].length - 1] || times[times.length - 1][times[0].length - 1] > time + 10)) {
			for (int j = 0; j < reachable.length; j++) {
				for (int k = 0; k < reachable[j].length; k++) {
					if (reachable[j][k]) {
						if (times[j][k] == -2 || times[j][k] < time) {
							step(floor, ceiling, reachable, times, H, j, k,
									time);
						}
					}
				}
			}
			H--;
			time++;
		}

	}

	private static void update(int[][] floor, int[][] ceiling,
			boolean[][] reachable, int[][] times, int H, int x, int y, int time) {
		if (time >= times[x][y] && times[x][y] != -1) {
			return;
		}
		times[x][y] = time;
		step(floor, ceiling, reachable, times, H, x, y, time);
	}

	private static void step(int[][] floor, int[][] ceiling,
			boolean[][] reachable, int[][] times, int H, int x, int y, int time) {

		if (x > 0) {
			if (possibleXMin(floor, ceiling, H, x, y)) {
				if (!reachable[x - 1][y]) {
					reachable[x - 1][y] = true;
				}
				if (H - floor[x][y] >= 20) {
					update(floor, ceiling, reachable, times, H - 10, x - 1, y,
							time + 10);
				} else {
					update(floor, ceiling, reachable, times, H - 100, x - 1, y,
							time + 100);
				}
			}
		}

		if (y > 0) {
			if (possibleYMin(floor, ceiling, H, x, y)) {
				if (!reachable[x][y - 1]) {
					reachable[x][y - 1] = true;
				}
				if (H - floor[x][y] >= 20) {
					update(floor, ceiling, reachable, times, H - 10, x, y - 1,
							time + 10);
				} else {
					update(floor, ceiling, reachable, times, H - 100, x, y - 1,
							time + 100);
				}
			}
		}

		if (x < ceiling.length - 1) {
			if (possibleXPlus(floor, ceiling, H, x, y)) {
				if (!reachable[x + 1][y]) {
					reachable[x + 1][y] = true;
				}
				if (H - floor[x][y] >= 20) {
					update(floor, ceiling, reachable, times, H - 10, x + 1, y,
							time + 10);
				} else {
					update(floor, ceiling, reachable, times, H - 100, x + 1, y,
							time + 100);
				}
			}
		}
		if (y < ceiling[0].length - 1) {
			if (possibleYPlus(floor, ceiling, H, x, y)) {
				if (!reachable[x][y + 1]) {
					reachable[x][y + 1] = true;
				}
				if (H - floor[x][y] >= 20) {
					update(floor, ceiling, reachable, times, H - 10, x, y + 1,
							time + 10);
				} else {
					update(floor, ceiling, reachable, times, H - 100, x, y + 1,
							time + 100);
				}
			}
		}
	}

	private static void reach(int[][] floor, int[][] ceiling,
			boolean[][] reachable, int H, int x, int y) {
		if (x > 0) {
			if (!reachable[x - 1][y]) {
				if (possibleXMin(floor, ceiling, H, x, y)) {
					reachable[x - 1][y] = true;
					reach(floor, ceiling, reachable, H, x - 1, y);
				}
			}
		}
		if (y > 0) {
			if (!reachable[x][y - 1]) {
				if (possibleYMin(floor, ceiling, H, x, y)) {
					reachable[x][y - 1] = true;
					reach(floor, ceiling, reachable, H, x, y - 1);
				}
			}
		}

		if (x < ceiling.length - 1) {
			if (!reachable[x + 1][y]) {
				if (possibleXPlus(floor, ceiling, H, x, y)) {
					reachable[x + 1][y] = true;
					reach(floor, ceiling, reachable, H, x + 1, y);
				}
			}
		}
		if (y < ceiling[0].length - 1) {
			if (!reachable[x][y + 1]) {
				if (possibleYPlus(floor, ceiling, H, x, y)) {
					reachable[x][y + 1] = true;
					reach(floor, ceiling, reachable, H, x, y + 1);
				}
			}
		}
	}

	private static boolean possibleXMin(int[][] floor, int[][] ceiling, int H,
			int x, int y) {
		if (ceiling[x - 1][y] - floor[x - 1][y] >= 50
				&& ceiling[x - 1][y] - H >= 50
				&& ceiling[x - 1][y] - floor[x][y] >= 50
				&& ceiling[x][y] - floor[x - 1][y] >= 50) {
			return true;
		}
		return false;
	}

	private static boolean possibleYMin(int[][] floor, int[][] ceiling, int H,
			int x, int y) {
		if (ceiling[x][y - 1] - floor[x][y - 1] >= 50
				&& ceiling[x][y - 1] - H >= 50
				&& ceiling[x][y - 1] - floor[x][y] >= 50
				&& ceiling[x][y] - floor[x][y - 1] >= 50) {
			return true;
		}
		return false;
	}

	private static boolean possibleXPlus(int[][] floor, int[][] ceiling, int H,
			int x, int y) {

		if (ceiling[x + 1][y] - floor[x + 1][y] >= 50
				&& ceiling[x + 1][y] - H >= 50
				&& ceiling[x + 1][y] - floor[x][y] >= 50
				&& ceiling[x][y] - floor[x + 1][y] >= 50) {
			return true;
		}
		return false;
	}

	private static boolean possibleYPlus(int[][] floor, int[][] ceiling, int H,
			int x, int y) {

		if (ceiling[x][y + 1] - floor[x][y + 1] >= 50
				&& ceiling[x][y + 1] - H >= 50
				&& ceiling[x][y + 1] - floor[x][y] >= 50
				&& ceiling[x][y] - floor[x][y + 1] >= 50) {
			return true;
		}
		return false;
	}

}
