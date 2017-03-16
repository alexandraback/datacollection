import java.util.*;

public class Q2A {

	public static List<boolean[][]> genboards(int[][] board, int width) {
		List<boolean[][]> retval = new ArrayList<>();
		for (int r = 0; r < board.length; r++) {
			for (int c = 0; c < board[0].length - width + 1; c++) {
				// can place?
				boolean canPlace = true;
				for (int cc = 0; cc < width; cc++) {
					if (board[r][c+cc] == 1) { // miss
						canPlace = false;
						break;
					}
				}
				if (!canPlace) continue;
				boolean[][] shippos = new boolean[board.length][board[0].length];
				for (int cc = 0; cc < width; cc++) {
					shippos[r][c+cc] = true;
				}
				retval.add(shippos);
			}
		}
		return retval;
	}

	public static int solve(int rows, int cols, int width) {
		int[][] board = new int[rows][cols];
		int hitcount = 0;
		int turns = 0;
		while(hitcount < width) {
			List<boolean[][]> possibleships = genboards(board, width);
			int[][] counts = new int[rows][cols];
			for (boolean[][] ship: possibleships) {
				for (int r = 0; r < rows; r++) {
					for (int c = 0; c < cols; c++) {
						if (ship[r][c] && board[r][c]==0) counts[r][c]++;
					}
				}
			}
			int highcount = 0;
			int highrow = 0, highcol = 0;
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					if (counts[r][c] > highcount) {
						highrow = r;
						highcol = c;
						highcount = counts[r][c];
					}
				}
			}
			// ask for highrow, highcol
			// bro will pick board where highrow, highcol is not hit if possible
			boolean ismiss = false;
			for (boolean[][] ship: possibleships) {
				if (!ship[highrow][highcol]) {
					board[highrow][highcol] = 1; // miss
					ismiss = true;
					break;
				}
			}
			if (!ismiss) {
				board[highrow][highcol] = 2; // hit
				hitcount++;
			}
			turns++;
		}
		return turns;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numCases = scan.nextInt();
		for (int i = 0; i < numCases; i++) {
			int rows = scan.nextInt();
			int cols = scan.nextInt();
			int width = scan.nextInt();
			int result = solve(rows, cols, width);
			System.out.println("Case #" + (i + 1) + ": " + result);
		}
	}
}