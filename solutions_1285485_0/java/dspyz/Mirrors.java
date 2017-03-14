import java.awt.Point;
import java.util.Scanner;

public class Mirrors {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		for (int trial = 1; trial <= cases; trial++) {
			System.out.print("Case #" + trial + ": ");
			int height = scan.nextInt() * 2;
			int width = scan.nextInt() * 2;
			int d = scan.nextInt() * 2;
			boolean[][] map = new boolean[height][width];
			scan.nextLine();
			Point myPos = null;
			for (int row = 0; row < height; row += 2) {
				char[] line = scan.nextLine().toCharArray();
				for (int c = 0; c < line.length; c++) {
					int col = c * 2;
					map[row][col] = map[row + 1][col] = map[row][col + 1] = map[row + 1][col + 1] = (line[c] == '#');
					if (line[c] == 'X') {
						myPos = new Point(col + 1, row + 1);
					}
				}
			}
			int count = 0;
			for (int dr = -d; dr <= d; dr++) {
				for (int dc = -d; dc <= d; dc++) {
					if (dr * dr + dc * dc >= d * d || !relPrime(dr, dc))
						continue;
					FracVec init = new FracVec(new Frac(dr), new Frac(dc));
					FracVec dm = init;
					FracVec next = dm.add(init);
					while (next.compareLengthTo(d) <= 0) {
						dm = next;
						next = dm.add(init);
					}
					Frac t = Frac.ZERO;
					FracVec pos = new FracVec(myPos);
					do {
						Frac nextRow = pos.row.roundAddSig(dm.row);
						Frac nextCol = pos.col.roundAddSig(dm.col);
						Frac addRowT = intersectRowTAdd(pos, dm, nextRow);
						Frac addColT = intersectColTAdd(pos, dm, nextCol);
						Frac addT;
						if (dm.row.isZero())
							addT = addColT;
						else if (dm.col.isZero())
							addT = addRowT;
						else {
							if (addRowT.compareTo(addColT) < 0)
								addT = addRowT;
							else
								addT = addColT;
						}
						t = t.add(addT);
						pos = pos.add(dm.multiply(addT));
						if (pos.equals(myPos)) {
							count++;
							break;
						}
						if (pos.isCorner()) {
							Point farCorn = getMidCorn(pos, dm);
							boolean fc = map[farCorn.y][farCorn.x];
							Point vertCorn = getVertCorn(pos, dm);
							boolean vc = map[vertCorn.y][vertCorn.x];
							Point horizCorn = getHorizCorn(pos, dm);
							boolean hc = map[horizCorn.y][horizCorn.x];
							if (fc) {
								boolean found = false;
								if (vc) {
									dm = dm.flipHoriz();
									found = true;
								}
								if (hc) {
									dm = dm.flipVert();
									found = true;
								}
								if (!found)
									break;
							}
						} else {
							Point cell = pos.getNextCell(dm);
							boolean isWall = map[cell.y][cell.x];
							if (isWall) {
								if (pos.row.denom == 1) {
									assert pos.col.denom > 1;
									dm = dm.flipVert();
								} else if (pos.col.denom == 1) {
									assert pos.row.denom > 1;
									dm = dm.flipHoriz();
								} else
									assert false;
							}
						}
					} while (t.compareTo(Frac.ONE) < 0);
				}
			}
			System.out.println(count);
		}
	}

	private static Point getMidCorn(FracVec pos, FracVec dm) {
		return pos.getNextCell(dm);
	}

	private static Point getVertCorn(FracVec pos, FracVec dm) {
		return pos.getNextCell(dm.flipVert());
	}

	private static Point getHorizCorn(FracVec pos, FracVec dm) {
		return pos.getNextCell(dm.flipHoriz());
	}

	private static boolean relPrime(int dr, int dc) {
		int gcd = Frac.gcd(dr, dc);
		return Math.abs(gcd) == 1;
	}

	private static Frac intersectColTAdd(FracVec pos, FracVec dm, Frac nextCol) {
		if (nextCol == null)
			return null;
		else
			return nextCol.sub(pos.col).div(dm.col);
	}

	private static Frac intersectRowTAdd(FracVec pos, FracVec dm, Frac nextRow) {
		if (nextRow == null)
			return null;
		else
			return nextRow.sub(pos.row).div(dm.row);
	}
}
