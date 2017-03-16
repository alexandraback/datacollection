import java.util.Map;
import java.util.Scanner;

import com.google.common.collect.ImmutableMap;

public class A {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %s\n", i + 1, exec());
	}
	
	private static final Map<Character, Integer> TRANSLATE = ImmutableMap.of(
			'.', 0,
			'X', 1,
			'O', 2,
			'T', 3);
	
	public static String exec() {
		int[][] grid = new int[4][4];
		boolean complete = true;
		for (int y = 0; y < 4; y++) {
			String in = sc.nextLine().trim();
			if (in.isEmpty()) {
				y--;
				continue;
			}
			for (int x = 0; x < 4; x++) {
				grid[x][y] = TRANSLATE.get(in.charAt(x));
				if (grid[x][y] == 0) complete = false;
			}
		}
		
		// Check Horizontal
		for (int y = 0; y < 4; y++) {
			boolean xWins = true;
			boolean oWins = true;
			for (int x = 0; x < 4; x++) {
				if ((grid[x][y] & 1) == 0) xWins = false;
				if ((grid[x][y] & 2) == 0) oWins = false;
			}
			if (xWins) return "X won";
			if (oWins) return "O won";
		}
		
		// Check Vertical
		for (int x = 0; x < 4; x++) {
			boolean xWins = true;
			boolean oWins = true;
			for (int y = 0; y < 4; y++) {
				if ((grid[x][y] & 1) == 0) xWins = false;
				if ((grid[x][y] & 2) == 0) oWins = false;
			}
			if (xWins) return "X won";
			if (oWins) return "O won";
		}
		
		/* Check diagonals */ {
			boolean xWins1 = true;
			boolean oWins1 = true;
			boolean xWins2 = true;
			boolean oWins2 = true;
			for (int xy = 0; xy < 4; xy++) {
				if ((grid[xy][xy] & 1) == 0) xWins1 = false;
				if ((grid[xy][xy] & 2) == 0) oWins1 = false;
				if ((grid[xy][3 - xy] & 1) == 0) xWins2 = false;
				if ((grid[xy][3 - xy] & 2) == 0) oWins2 = false;
			}
			if (xWins1 || xWins2) return "X won";
			if (oWins1 || oWins2) return "O won";
		}
		
		return complete ? "Draw" : "Game has not completed";
	}
}
