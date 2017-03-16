import java.io.FileInputStream;
import java.util.Scanner;

public class MinesweeperEasy {
	private static int[][] board = new int[50][50];
	private static boolean[][] mine = new boolean[50][50];
	private static boolean[][] check = new boolean[50][50];
	private static int r, c, rs, cs, re, ce;
	private static int[] cc = {-1,0,1,1,1,0,-1,-1};
	private static int[] cr = {-1,-1,-1,0,1,1,1,0};
	
	private static void setZero(int sr, int sc)
	{
		check[sr][sc] = true;
		for (int cd = 0; cd < 8; cd++) {
			int nr = sr + cr[cd];
			int nc = sc + cc[cd];
			if (nr >= 0 && nr < r && nc >= 0 && nc < c && !mine[nr][nc] && board[nr][nc] == 0 && !check[nr][nc]) {
				setZero(nr, nc);
			}
		}
	}

	private static void addMine(int i, int j)
	{
		mine[i][j] = true;
		for (int cd = 0; cd < 8; cd++) {
			int nr = i + cr[cd];
			int nc = j + cc[cd];
			if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
				board[nr][nc]++;
			}
		}		
	}

	private static void removeMine(int i, int j)
	{
		mine[i][j] = false;
		for (int cd = 0; cd < 8; cd++) {
			int nr = i + cr[cd];
			int nc = j + cc[cd];
			if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
				board[nr][nc]--;
			}
		}		
	}
	
	private static boolean solve(int sr, int sc, int m)
	{
		if (m == 0) {
			// Check that the board is valid. We must have at least one zero,
			// and all zeroes must be connected.
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					check[i][j] = false;
				}					
			}
			boolean gotZero = false;
			int nonZero = 0;
			int nzr = 0, nzc = 0;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (mine[i][j]) {
						// Nothing to do.
					}
					else if (board[i][j] == 0) {
						if (!gotZero) {
							gotZero = true;
							setZero(i, j);
						}
						else if (!check[i][j]) {
							return false;
						}
					}
					else {
						nzr = i;
						nzc = j;
						nonZero++;
					}
				}
			}

			if (!gotZero) {
				if (nonZero == 1) {
					// Only one cell to click on. Pretend like it's a zero cell for
					// our printer.
					board[nzr][nzc] = 0;
					return true;
				}
				else {
					// No zero cells, and we have more than one cell to reveal :-(
					return false;
				}
			}
			
			
			// Make sure that our non-zero cells are are adjacent to zero ones.
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (mine[i][j] || board[i][j] == 0) {
						continue;
					}
					boolean ok = false;
					for (int cd = 0; cd < 8; cd++) {
						int nr = i + cr[cd];
						int nc = j + cc[cd];
						if (nr >= 0 && nr < r && nc >= 0 && nc < c && !mine[nr][nc] && board[nr][nc] == 0) {
							ok = true;
							break;
						}
					}
					if (!ok) {
						return false;
					}
				}
			}
			
			return true;
		}

		for (int i = sr; i < re; i++) {
			for (int j = (i == sr ? sc : cs); j < ce; j++) {
				if (mine[i][j]) {
					continue;
				}

				addMine(i, j);
				if (solve(i, j + 1, m - 1)) {
					return true;
				}
				removeMine(i, j);
			}
		}
		
		return false;
	}

	public static void main(String[] args)
	    throws Exception
	{
		//System.setIn(new FileInputStream("sample.in"));
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int caseNum = 1; caseNum <= t; caseNum++) {
			r = in.nextInt();
			c = in.nextInt();
			int m = in.nextInt();

			// Our algorithm prefers filling rows first, so if we have fewer rows
			// than columns then flip our grid. We'll flip it back later.
			boolean flip = false;
			if (r < c) {
				int x = r;
				r = c;
				c = x;
				flip = true;
			}

			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
				{
					board[i][j] = 0;
					mine[i][j] = false;
				}

			System.out.println("Case #" + caseNum + ":");
			boolean result;
			// If we have the right number of mines, then it's easy (and quick) to
			// lay them using brute force. The "right" number includes:
			//
			// 1) we have at least 2 free rows (and > 2 columns)
			// 2) we have a single column
			// 3) no mines!
			//
			if ((m <= (r - 2) * c && c > 2) || c == 1 || m == 0) {
				rs = 0; cs = 0; re = r; ce = c;
				result = solve(0, 0, m);
			}
			else {
				// Otherwise, we employ a two-phase approach. We first fill rows
				// until we have a square remaining board. We then apply an onion-
				// layer algorithm, completing filling in layers around the outer
				// edge of the remaining square until we cannot completely fill a
				// layer. The remaining mines are then places in a brute-force
				// fashion in the leftover space inside the layers.
			
				int origM = m;
				
				// We know that r >= c at this point. We also know that
				// m > (r - c) * c, since c >= 2 here.
				for (int i = r - c - 1; i >= 0; i--) {
					for (int j = 0; j < c; j++) {
						addMine(i, j);
					}
				}
				
				// Subtract off the mines we've laid so far.
				m -= (r - c) * c;
				
				// Now lay down as many layers as we can, but stop once we reach
				// a 5x5 empty space in the middle (since we can fill this using
				// brute force).
				int layer = 0;
				while (true && m > 0 && (c - layer * 2) > 5) {
					int required = (c - layer * 2 - 1) * 4;
					if (m >= required) {
						// Do it.
						for (int i = 0; i < c - layer * 2 - 1; i++) {
							addMine(r - c + layer + i, layer);
							addMine(r - c + layer, layer + i + 1);
							addMine(r - c + layer + i + 1, c - layer - 1);
							addMine(r - layer - 1, layer + i);
						}
						
						m -= required;
					}
					else {
						// Start brute-forcing inside the layers now.
						break;
					}
					layer++;
				}
				
				rs = r - c + layer;
				re = r - layer;
				cs = layer;
				ce = c - layer;
				result = solve(rs, cs, m);

				if (!result) {
					// Two-phase approach attempt 2 -- this works around corner cases
					// in the above algorithm. We accumulate all of our empty squares
					// into a corner of the grid, and then run brute force on this
					// corner. The trick is picking the right size for the corner...
					// we pick the smallest square shape that leaves no empty space
					// outside the square.
					for (int i = 0; i < r; i++)
						for (int j = 0; j < c; j++)
						{
							board[i][j] = 0;
							mine[i][j] = false;
						}
					
					int size = 1;
					m = origM;
					while (r * c - size * size > m) {
						size++;
					}
					
					// Fill everything except the top-left square with mines.
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							if (i >= size || j >= size) {
								addMine(i, j);
							}
						}
					}
					
					rs = 0;
					re = size;
					cs = 0;
					ce = size;
					result = solve(0, 0, m - (r * c - size * size));
				}
			}
			if (result) {
				if (flip) {
					// Flip our board back the right way around.
					int nb[][] = new int[50][50];
					boolean nm[][] = new boolean[50][50];
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							nb[j][i] = board[i][j];
							nm[j][i] = mine[i][j];
						}
					}
					board = nb;
					mine = nm;
					
					int x = r;
					r = c;
					c = x;
				}
				boolean clicked = false;
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (mine[i][j]) {
							System.out.print('*');
						}
						else if (board[i][j] == 0 && !clicked) {
							System.out.print('c');
							clicked = true;
						}
						else {
							System.out.print('.');
						}
					}
					System.out.println();
				}
			}
			else {
				System.out.println("Impossible");
			}
		}
	}
}
