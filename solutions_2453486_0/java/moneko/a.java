import java.util.*;
public class a {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		in.nextLine();
		for(int t = 1; t <= T; t++) {
			char[][] grid = new char[4][4];
			for(int i = 0; i < 4; i++) {
				String line = in.nextLine();
				for(int j = 0; j < 4; j++)
					grid[i][j] = line.charAt(j);
			}

			System.out.printf("Case #%d: ", t);
			if(won('X', grid))
				System.out.println("X won");
			else if(won('O', grid))
				System.out.println("O won");
			else if(full(grid))
				System.out.println("Draw");
			else
				System.out.println("Game has not completed");
			in.nextLine();
		}
	}
	static boolean won(char c, char[][] grid) {
		for(int i = 0; i < 4; i++) {
			int num = 0;
			boolean T = false;
			for(int j = 0; j < 4; j++) {
				num += grid[i][j] == c ? 1 : 0;
				T = T || grid[i][j] == 'T';
			}
			if(num == 4 || num == 3 && T)
				return true;
		}
		for(int i = 0; i < 4; i++) {
			int num = 0;
			boolean T = false;
			for(int j = 0; j < 4; j++) {
				num += grid[j][i] == c ? 1 : 0;
				T = T || grid[j][i] == 'T';
			}
			if(num == 4 || num == 3 && T)
				return true;
		}

		int num = 0;
		boolean T = false;
		for(int i = 0; i < 4; i++) {
			num += grid[i][i] == c ? 1 : 0;
			T = T || grid[i][i] == 'T';
		}
		if(num == 4 || num == 3 && T)
			return true;
		num = 0;
		T = false;
		for(int i = 0; i < 4; i++) {
			num += grid[4-i-1][i] == c ? 1 : 0;
			T = T || grid[4-i-1][i] == 'T';
		}
		if(num == 4 || num == 3 && T)
			return true;
		return false;
	}

	static boolean full(char[][] grid) {
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				if(grid[i][j] == '.')
					return false;
		return true;
	}
}
