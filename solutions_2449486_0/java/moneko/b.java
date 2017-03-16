import java.util.*;

public class b {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		for(int t = 1; t <= T; t++) {	
			int N = in.nextInt();
			int M = in.nextInt();

			int[][] grid = new int[N][M];

			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)
					grid[i][j] = in.nextInt();

			boolean ans = true;
			for(int i = 0; i < N; i++) 
				for(int j = 0; j < M; j++) 
					ans &= test(i, j, grid);
			System.out.printf("Case #%d: %s\n", t, ans ? "YES" : "NO");
		}
	}	

	static boolean test(int r, int c, int[][] grid) {
		boolean one = true;
		for(int i = 0; i < grid[0].length; i++)
			if(grid[r][c] < grid[r][i])
			  one = false;
		boolean two = true;
		for(int j = 0; j < grid.length; j++)
			if(grid[r][c] < grid[j][c])
				two = false;
		return one || two;	
	}
}
