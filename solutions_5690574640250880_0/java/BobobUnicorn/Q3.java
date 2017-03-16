import java.awt.Point;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.BitSet;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Q3 {
	public static void mapify(boolean[][] rg, BitSet bi) {
		for (int i = 0; i < rg.length; i++)
			for (int j = 0; j < rg[i].length; j++)
				rg[i][j] = bi.get(i * rg[i].length + j);
	}

	public static BitSet nextperm(BitSet bi, int len) {
		BitSet binew = bi;// (BitSet) bi.clone();
		int n = binew.previousSetBit(binew.length());
		int i = n;
		if (n == len - 1) {
			for (i = n; binew.get(i) && i >= 0; i--) {
				binew.set(i, false);
			}

			if (binew.isEmpty()) {
				return binew;
			}
		}

		int temp = binew.previousSetBit(binew.length());
		binew.set(temp, false);
		binew.set(temp + 1, true);

		if (n == len - 1) {
			for (int j = temp + 2; j - temp - 2 < n - i; j++) {
				binew.set(j, true);
			}
		}

		return binew;
	}

	public static boolean inbound(boolean[][] rg, int x, int y) {
		return x >= 0 && y >= 0 && x < rg.length && y < rg[x].length;
	}

	public static void fill(int[][] rgb, boolean[][] rg, int x, int y) {
		if (x < 0 || y < 0 || x >= rg.length || y >= rg[x].length) {
			return;
		}

		if (rg[x][y]) {
			rgb[x][y] = -1;
			return;
		}

		if (rgb[x][y] != 0) {
			return;
		}

		rgb[x][y] = 1;
		boolean mined = (inbound(rg, x - 1, y - 1) && rg[x - 1][y - 1]);
		mined |= (inbound(rg, x - 1, y) && rg[x - 1][y]);
		mined |= (inbound(rg, x - 1, y + 1) && rg[x - 1][y + 1]);
		mined |= (inbound(rg, x, y - 1) && rg[x][y - 1]);
		mined |= (inbound(rg, x, y + 1) && rg[x][y + 1]);
		mined |= (inbound(rg, x + 1, y - 1) && rg[x + 1][y - 1]);
		mined |= (inbound(rg, x + 1, y) && rg[x + 1][y]);
		mined |= (inbound(rg, x + 1, y + 1) && rg[x + 1][y + 1]);
		if (!mined) {
			fill(rgb, rg, x - 1, y - 1);
			fill(rgb, rg, x - 1, y);
			fill(rgb, rg, x - 1, y + 1);
			fill(rgb, rg, x, y - 1);
			fill(rgb, rg, x, y + 1);
			fill(rgb, rg, x + 1, y - 1);
			fill(rgb, rg, x + 1, y);
			fill(rgb, rg, x + 1, y + 1);
			// System.out.printf("%d %d\n",x, y);
		} else {
			//
		}

		return;
	}

	public static boolean check(boolean[][] rg, int x, int y) {
		int[][] rgb = new int[rg.length][rg[0].length];
		fill(rgb, rg, x, y);

		for (int i = 0; i < rg.length; i++) {
			for (int j = 0; j < rg[i].length; j++) {
				if (rg[i][j])
					continue;
				if (rgb[i][j] == 0)
					return false;
			}
		}

		return true;
	}

	public static Point canoneclick(boolean[][] rg) {
		// int[][] rgct = new int[rg.length][rg[0].length];

		Point empty = new Point(-1, -1);

		// 0 emans not inialized
		// -1 means no mines
		for (int i = 0; i < rg.length; i++) {
			for (int j = 0; j < rg[i].length; j++) {
				if (rg[i][j]) {
					// rgct[i][j] = -1;
					continue;
				}

				// lets do this again :(
				// flood fill
				if (check(rg, i, j)) {
					empty.setLocation(i, j);
					return empty;
				}
			}
		}
		
		return new Point(-1, -1);
	}

	public static void main(String[] args) throws IOException {
		File fin = new File("C-small-attempt2.in");
		Scanner in = new Scanner(fin);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"C-small.out")));

		int T = in.nextInt();

		// long startTime = 0;

		for (int i = 0; i < T; i++) {
			int r = 0, c = 0, m = 0;

			r = in.nextInt();
			c = in.nextInt();
			m = in.nextInt();
			
			boolean found = false;

			// we're just gonna do a stupid brute force
			// and be stupid
//			Set<BitSet> reached = new HashSet<BitSet>(r * c);

			// initialize our map
			BitSet current = new BitSet(r * c);
			for (int j = 0; j < m; j++) {
				current.set(j);
			}
			out.printf("Case #%d:\n", i + 1);

			do {
//				 System.out.println(current.toString());
//				 reached.add((BitSet)current.clone());
				boolean[][] map = new boolean[r][c];
				mapify(map, current);

				// System.out.println(Arrays.toString(map));

				// startTime = System.nanoTime();
				Point pt = canoneclick(map);
				// long duration = System.nanoTime() - startTime;
				// System.out.println(duration);

				if (pt.x >= 0) {
					for (int j = 0; j < r; j++) {
						for (int k = 0; k < c; k++) {
							if (j == pt.x && k == pt.y) {
								out.print('c');
							} else if (map[j][k]) {
								out.print('*');
							} else {
								out.print('.');
							}
						}
						out.println();
					}
					found = true;
					break;
				}
				nextperm(current, r * c);
			} while (!current.isEmpty());
			
//			BigInteger combs = BigInteger.valueOf(r * c);
//			for (int qw = r*c-1; qw > 1; qw--)
//				combs = combs.multiply(BigInteger.valueOf(qw));
//			for (int qw = 1; qw <= m; qw++)
//				combs = combs.divide(BigInteger.valueOf(qw));
//			for (int qw = 1; qw <= (r*c - m); qw++)
//				combs = combs.divide(BigInteger.valueOf(qw));
//			
//			
//			if (reached.size() != combs.intValue())
//			{
//				System.out.println(i+1);
//				System.out.println(reached.size());
//				System.out.println(combs.intValue());
////				throw new ArithmeticException();
//			}

			if (!found)
				out.println("Impossible");
		}

		in.close();
		out.close();
	}
}
