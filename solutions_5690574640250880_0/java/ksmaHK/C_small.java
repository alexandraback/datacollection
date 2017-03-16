import java.util.*;

public class C_small {

static int[] d = new int[]{-1, 0, 1};

public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	String Impossible = new String("Impossible");
	
	
	
	for (int nc = 1; nc <= nCase; nc++) {
		int R = scanner.nextInt();
		int C = scanner.nextInt();
		int M = scanner.nextInt();
		
		int[][] board = new int[R][C]; // -1 means has mine
		boolean[][] open = new boolean[R][C];
		
		System.out.println("Case #" + nc + ":");
		
		int[] comb = new int[M];
		if (M == 0) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (i == 0 && j == 0)
						System.out.print('c');
					else
						System.out.print('.');
				}
				System.out.println();
			}
		} else {
			boolean finished = false;
			for (int i = 0, size = R*C; !finished && i < size - M + 1; i++) {
				comb[0] = i;
				finished = genCombin(comb, 1, size, M - 1, board, open);
			}

			if (!finished) {
				System.out.println(Impossible);
			}
		}
	}
}
public static boolean genCombin(int[] comb, int index, int N, int E, int[][] board, boolean[][] open) {
	if (index == comb.length) {
		int R = board.length;
		int C = board[0].length;
		
		// generate board
		for (int i = 0; i < R; i++)
			Arrays.fill(board[i], 0);
			
		for (int i = 0; i < comb.length; i++)
			board[comb[i]/C][comb[i]%C] = -1;
		
		// calculate numbers
		for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (board[i][j] == 0) {
				int cnt = 0;
				for (int x = 0; x < 3; x++)
				for (int y = 0; y < 3; y++) {
					int r = i + d[x];
					int c = j + d[y];
					if (0 <= r && r < R && 0 <= c && c < C && board[r][c] == -1)
						cnt++;
				}
				board[i][j] = cnt;
			}
		
		boolean finished = false;
		
		for (int i = 0; i < R && !finished; i++)
		for (int j = 0; j < C && !finished; j++)
			if (board[i][j] != -1) {
				for (int k = 0; k < R; k++)
					Arrays.fill(open[k], false);
				open[i][j] = true;
				LinkedList<Cell> list = new LinkedList<Cell>();
				list.add(new Cell(i, j));
				while (list.size() > 0) {
					Cell cell = list.remove();
					if (board[cell.r][cell.c] == 0) {
						for (int x = 0; x < 3; x++)
						for (int y = 0; y < 3; y++) {
							int r = cell.r + d[x];
							int c = cell.c + d[y];
							if (0 <= r && r < R && 0 <= c && c < C && !open[r][c]) {
								open[r][c] = true;
								list.add(new Cell(r, c));
							}
						}
					}
				}
				
				int cnt = 0;
				for (int x = 0; x < R; x++)
				for (int y = 0; y < C; y++) {
					if (!open[x][y])
						cnt++;
				}
				if (cnt == comb.length) {
					finished = true;
					board[i][j] = -2;
					for (int x = 0; x < R; x++) {
						for (int y = 0; y < C; y++)
							if (board[x][y] >= 0)
								System.out.print('.');
							else if (board[x][y] == -1)
								System.out.print('*');
							else
								System.out.print('c');
						System.out.println();				
					}
				}
			}
		
		return finished;
	}
	
	for (int i = comb[index-1] + 1; i < N - E + 1; i++) {
		comb[index] = i;
		boolean finished = genCombin(comb, index+1, N, E - 1, board, open);
		if (finished)
			return finished;
	}
	return false;
}

}

class Cell {
public int r;
public int c;
public Cell(int x, int y) {
	r = x;
	c = y;
}
}