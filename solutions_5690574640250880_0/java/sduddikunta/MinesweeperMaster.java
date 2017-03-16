import java.util.Scanner;

public class MinesweeperMaster {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		nextCase: for (int ca = 1; ca <= cases; ca++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int M = in.nextInt();
			if (R * C == M) {
				System.out.printf("Case #%d: %nImpossible%n", ca);
				continue;
			}
			if (R * C == M + 1) {
				System.out.printf("Case #%d: %n", ca);
				for (int i = 0; i < R - 1; i++) {
					for (int k = 0; k < C; k++) {
						System.out.print("*");
					}
					System.out.println();
				}
				for (int k = 0; k < C - 1; k++) {
					System.out.print("*");
				}
				System.out.println("c");
				continue;
			}
			if (R == 1) {
				if (M < C - 1) {
					System.out.printf("Case #%d: %n", ca);
					for (int k = 0; k < M; k++) {
						System.out.print("*");
					}
					for (int k = M; k < C - 1; k++) {
						System.out.print(".");
					}
					System.out.println("c");
					continue;
				} else {
					System.out.printf("Case #%d: %nImpossible%n", ca);
					continue;
				}
			}
			if (C == 1) {
				if (M < R - 1) {
					System.out.printf("Case #%d: %n", ca);
					for (int k = 0; k < M; k++) {
						System.out.println("*");
					}
					for (int k = M; k < R - 1; k++) {
						System.out.println(".");
					}
					System.out.println("c");
					continue;
				} else {
					System.out.printf("Case #%d: %nImpossible%n", ca);
					continue;
				}
			}
			for (int rf = 0; rf < R - 2; rf++) {
				int Rl = R - rf;
				int Ml = M - (C * rf);
				if (Ml < 0)
					break;
				if (Ml % Rl == 0) {
					int Cf = Ml / Rl;
					if (Cf <= C - 2) {
						System.out.printf("Case #%d: %n", ca);
						for (int i = 0; i < rf; i++) {
							for (int k = 0; k < C; k++)
								System.out.print("*");
							System.out.println();
						}
						for (int i = 0; i < Rl - 1; i++) {
							for (int k = 0; k < Cf; k++) {
								System.out.print("*");
							}
							for (int k = Cf; k < C; k++) {
								System.out.print(".");
							}
							System.out.println();
						}
						for (int k = 0; k < Cf; k++) {
							System.out.print("*");
						}
						for (int k = Cf; k < C - 1; k++) {
							System.out.print(".");
						}
						System.out.println("c");
						continue nextCase;
					}
				}
			}
			boolean[][] mine = new boolean[R][C];
			outer: for (int i = 0; i < R - 2; i++) {
				if (M - C >= 0) {
					for (int k = 0; k < C; k++) {
						mine[i][k] = true;
					}
					M -= C;
					continue;
				}
				for (int k = 0; k < C - 2; k++) {
					if (M == 0)
						break outer;
					mine[i][k] = true;
					M--;
				}
			}
			if (M != 0) {
				int minesLastRow = -1;
				// last 2 rows, still have mines to place
				if (M % 2 == 1) {
					// attempt to borrow a mine from a line up
					if (R - 3 < 0 || mine[R - 3][C - 1] || !mine[R - 3][0]) {
						// that's a full row or doesn't exist, we can't
						System.out.printf("Case #%d: %nImpossible%n", ca);
						continue;
					}
					for (int k = C - 3; k >= 0; k--) {
						if (mine[R - 3][k]) {
							mine[R - 3][k] = false;
							M++;
							minesLastRow = k;
							break;
						}
					}
				}
				int minesPerRow = M / 2;
				if ((minesPerRow > C - 2)
						|| (minesLastRow != -1 && minesPerRow > minesLastRow)) {
					System.out.printf("Case #%d: %nImpossible%n", ca);
					continue;
				}
				for (int k = 0; k < minesPerRow; k++) {
					mine[R - 1][k] = true;
					mine[R - 2][k] = true;
				}
				M -= minesPerRow * 2;
			}
			if (M != 0)
				throw new IllegalStateException(); // check up
			System.out.printf("Case #%d: %n", ca);
			for (int i = 0; i < R - 1; i++) {
				for (int k = 0; k < C; k++) {
					System.out.print(mine[i][k] ? "*" : ".");
				}
				System.out.println();
			}
			for (int k = 0; k < C - 1; k++) {
				System.out.print(mine[R - 1][k] ? "*" : ".");
			}
			System.out.println("c");
		}
	}
}
