package googlecodejam;

import java.awt.geom.Point2D;
import java.util.Scanner;

public class B {

	private static class Grid {
		int rows;
		int columns;
		int centerR;
		int centerC;
		char grid[][];
		int stones = 0;
		int enclosed = 0;

		private Grid(int rows, int columns) {
			this.rows = rows;
			this.columns = columns;
			this.centerR = rows / 2;
			this.centerC = columns / 2;
			this.grid = new char[rows][columns];
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < columns; c++) {
					grid[r][c] = '.';
				}
			}
		}

		public void increase() {
//			if (stones == 0) {
//				grid[centerR][centerC] = 'S';
//				stones++;
//				enclosed++;
//			} else {
				int minR = 0;
				int minC = 0;
				double minD = rows * columns;
				for (int r = 0; r < rows; r++) {
					for (int c = 0; c < columns; c++) {
						if (grid[r][c] == '.') {
							double dist = Point2D.distance(centerR, centerC, r, c);
							if (dist < minD) {
								minD = dist;
								minR = r;
								minC = c;
							}
						}
					}
				}
				grid[minR][minC] = 'S';
				stones++;
				enclosed++;
//			}
			removeStones();
		}

		private void removeStones() {
			for (int r = 1; r < rows - 1; r++) {
				for (int c = 1; c < columns - 1; c++) {
					if (grid[r][c] != 'x'
							&& (grid[r][c - 1] == 'S' || grid[r][c - 1] == 'x')
							&& (grid[r][c + 1] == 'S' || grid[r][c + 1] == 'x')
							&& (grid[r - 1][c] == 'S' || grid[r - 1][c] == 'x')
							&& (grid[r + 1][c] == 'S' || grid[r + 1][c] == 'x')) {
						grid[r][c] = 'x';
						stones--;
					}
				}
			}
		}

		private void simplify() {
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < columns; c++) {
					if (grid[r][c] == 'S' && isUnneccessaryCorner(r, c)) {
						grid[r][c] = '.';
						stones--;
						enclosed--;
					}
				}
			}
		}

		private boolean isUnneccessaryCorner(int r, int c) {
			return isCorner(r, c, -1, -1) || isCorner(r, c, -1, +1) || isCorner(r, c, +1, -1) || isCorner(r, c, +1, +1);
		}

		private boolean isCorner(int r, int c, int dr, int dc) {
			if (r + dr < 0 || r + dr == rows || c + dc < 0 || c + dc == columns) {
				return false;
			}
			return grid[r + dr][c] == 'S' && grid[r][c + dc] == 'S' && grid[r + dr][c + dc] == 'x';
		}

		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder();
			sb.append(enclosed + " : " + stones + "\n");
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < columns; c++) {
					sb.append(" ");
					sb.append(grid[r][c]);
				}
				sb.append("\n");
			}
			return sb.toString();
		}

		@Override
		protected Object clone() throws CloneNotSupportedException {
			Grid g2 = new Grid(rows, columns);
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < columns; c++) {
					g2.grid[r][c] = grid[r][c];
				}
			}
			g2.stones = stones;
			g2.enclosed = enclosed;
			return g2;
		}
	}

	public static void main(String[] args) throws CloneNotSupportedException {
		Scanner scanner = new Scanner(System.in);
		int totalTests = scanner.nextInt();
		for (int currentTest = 1; currentTest <= totalTests; currentTest++) {
			int N = scanner.nextInt();
			int M = scanner.nextInt();
			int K = scanner.nextInt();
			int minStones = N * K;
			Grid grid = new Grid(N, M);
			for (int i = 1; i <= N * M; i++) {
				grid.increase();
				//System.out.println("or " + grid.toString());
				if (grid.enclosed >= K && grid.stones < minStones) {
					minStones = grid.stones;
				}
				Grid g2 = (Grid) grid.clone();
				g2.simplify();
				//System.out.println("g2 " + g2.toString());
				if (g2.enclosed >= K && g2.stones < minStones) {
					minStones = g2.stones;
				}
			}
			System.out.println("Case #" + currentTest + ": " + minStones);
		}
	}
}
