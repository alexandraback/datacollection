import java.io.FileInputStream;
import java.util.Scanner;

public class MinesweeperEasy {
	private static int[][] board = new int[50][50];
	private static boolean[][] mine = new boolean[50][50];
	private static boolean[][] check = new boolean[50][50];
	private static int r, c;
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
					// Not all zeroes are connected, or we have no cell to click in.
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

		for (int i = sr; i < r; i++) {
			for (int j = (i == sr ? sc : 0); j < c; j++) {
				mine[i][j] = true;
				for (int cd = 0; cd < 8; cd++) {
					int nr = i + cr[cd];
					int nc = j + cc[cd];
					if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
						board[nr][nc]++;
					}
				}
				if (solve(i, j + 1, m - 1)) {
					return true;
				}
				mine[i][j] = false;
				for (int cd = 0; cd < 8; cd++) {
					int nr = i + cr[cd];
					int nc = j + cc[cd];
					if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
						board[nr][nc]--;
					}
				}
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
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
				{
					board[i][j] = 0;
					mine[i][j] = false;
				}
			
			System.out.println("Case #" + caseNum + ":");
			if (solve(0, 0, m)) {
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
