import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class QB {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("/home/useruser/datacollection/input/1485488_0.in"));
		PrintWriter out = new PrintWriter(new FileWriter(
				new File("b-small.out")));

		int T = in.nextInt();

		for (int asdf = 0; asdf < T; asdf++) {
			int H = in.nextInt();
			int N = in.nextInt();
			int M = in.nextInt();

			int[][] ceilH = new int[N][M];
			int[][] floorH = new int[N][M];
			boolean[][] traversed = new boolean[N][M];

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					ceilH[i][j] = in.nextInt();
					// System.out.print(ceilH[i][j] + " ");
				}
				// System.out.println();
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					floorH[i][j] = in.nextInt();
				}
			}

			double time = 10 * timeFrozen(0, 0, 0, 0, H, ceilH, floorH, traversed);
			time = Math.round(time);
			time /= 10.0;

			out.println("Case #" + (asdf + 1) + ": " + time);
			System.out.println("Case #" + (asdf + 1) + ": " + time);
		}

		in.close();
		out.close();
	}

	static double timeFrozen(int x, int y, int xp, int yp, int water,
			int[][] ceilH, int[][] floorH, boolean[][] trav) {

		// System.out.println(x + " " + y);
		// oob
		if (x < 0 || y < 0 || x >= ceilH.length || y >= ceilH[0].length) {
			// System.out.println("OOB");
			return 1000000000.0;
		}
		if (trav[x][y]) {
			// System.out.println("TRAV");
			return 1000000000.0;
		}
		// not possible to traverse
		if (!(x == xp && y == yp)
				&& (ceilH[x][y] - 50 < floorH[x][y]
						|| ceilH[x][y] - 50 < water
						|| ceilH[x][y] - 50 < floorH[xp][yp] || ceilH[xp][yp] - 50 < floorH[x][y])) {
			return 1000000000.0;
		}
		
		if(x == ceilH.length && y == ceilH[0].length)
			return 0;

		trav[x][y] = true;
		boolean[][] asdf = new boolean[ceilH.length][ceilH[0].length];

		return Math
				.min(min(
						timeFrozen(x + 1, y, x, y, water, ceilH, floorH, trav),
						timeFrozen(x - 1, y, x, y, water, ceilH, floorH, trav),
						timeFrozen(x, y + 1, x, y, water, ceilH, floorH, trav),
						timeFrozen(x, y - 1, x, y, water, ceilH, floorH, trav)),
						time(x, y, x, y, water, ceilH, floorH, asdf));
	}

	static double time(int x, int y, int xp, int yp, int water, int[][] ceilH,
			int[][] floorH, boolean[][] trav) {
		// boolean[][] travs = new boolean[trav.length][trav[0].length];
		// for (int i = 0; i < trav.length; i++) {
		// for (int j = 0; j < trav[0].length; j++) {
		// travs[i][j] = trav[i][j];
		// }
		// }

		if (x < 0 || y < 0 || x >= ceilH.length || y >= ceilH[0].length) {
			return 1000000000.0;
		}
		if (trav[x][y])
			return 100000000.0;
		// not possible to traverse
		if (ceilH[x][y] - 50 < floorH[x][y]
				|| ceilH[x][y] - 50 < floorH[xp][yp]
				|| ceilH[xp][yp] - 50 < floorH[x][y]) {
			return 10000000.0;
		}

		double travTime = 0;
		// wait for water to go down
		if (ceilH[x][y] - 50 <= water) {
			travTime += 1 + (50 - (ceilH[x][y] - water)) / 10.0;
			water = ceilH[x][y] - 50;
		}

		// sanity check
		if (water <= 0)
			water = 0;

		if (water - floorH[xp][yp] >= 20) {
			travTime += 1;
			water -= 10;
		} else {
			travTime += 10;
			water -= 100;
		}
		// sanity check
		if (water <= 0)
			water = 0;

		if (x == xp && y == yp)
			travTime = 0;

		trav[x][y] = true;

		// System.out.println("("+xp+","+yp+") -> ("+x+","+y+"): t = " +
		// travTime);
		if (x == ceilH.length - 1 && y == ceilH[0].length - 1)
			return travTime;

		double a = time(x + 1, y, x, y, water, ceilH, floorH, trav);
		// if (a != 1000000000)
		// trav[x + 1][y] = false;
		double b = time(x - 1, y, x, y, water, ceilH, floorH, trav);
//		if (b != 1000000000)
//			trav[x - 1][y] = false;
		double c = time(x, y + 1, x, y, water, ceilH, floorH, trav);
//		if (c != 1000000000)
//			trav[x][y + 1] = false;
		double d = time(x, y - 1, x, y, water, ceilH, floorH, trav);
//		if (d != 1000000000)
//			trav[x][y - 1] = false;
		return travTime + min(a, b, c, d);
	}

	static double min(double a1, double a2, double a3, double a4) {
		return Math.min(Math.min(a1, a2), Math.min(a3, a4));
	}
}
