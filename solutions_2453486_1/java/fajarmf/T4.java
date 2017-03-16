import java.util.Scanner;

public class T4 {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int cases = reader.nextInt();
		reader.nextLine();
		char[][] map = new char[4][4];
		for (int i = 1; i <= cases; i++) {
			for (int row = 0; row < 4; row++) {
				map[row] = reader.nextLine().toCharArray();
			}
			reader.nextLine();
			String result = solve(map);
			System.out.println("Case #" + i + ": " + result);
		}
	}

	private static String word(int type) {
		switch (type) {
		case 0:
			return "X won";
		case 1:
			return "O won";
		case 2:
			return "Draw";
		default:
			return "Game has not completed";
		}
	}

	private static String solve(char[][] map) {
		int res = -1;
		for (int i = 0; i < 4; i++) {
			// check horizontal
			boolean xWon = check('X', map[i][0], map[i][1], map[i][2],
					map[i][3]);
			boolean oWon = check('O', map[i][0], map[i][1], map[i][2],
					map[i][3]);

			// check vertical
			xWon |= check('X', map[0][i], map[1][i], map[2][i], map[3][i]);
			oWon |= check('O', map[0][i], map[1][i], map[2][i], map[3][i]);

			if (xWon) {
				res = 0;
				break;
			}
			if (oWon) {
				res = 1;
				break;
			}
		}

		if (res == -1) {
			// check diagonal
			boolean oWon = check('O', map[0][0], map[1][1], map[2][2],
					map[3][3]);
			boolean xWon = check('X', map[0][0], map[1][1], map[2][2],
					map[3][3]);
			oWon |= check('O', map[0][3], map[1][2], map[2][1], map[3][0]);
			xWon |= check('X', map[0][3], map[1][2], map[2][1], map[3][0]);

			if (oWon)
				res = 1;
			else if (xWon)
				res = 0;
			else {
				int blank = 0;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (map[i][j] == '.')
							blank++;
					}
				}
				if (blank == 0) {
					res = 2;
				} else {
					res = 3;
				}
			}
		}

		return word(res);
	}

	private static boolean check(char target, char c, char d, char e, char f) {
		return ((c == 'T' || c == target) && (d == 'T' || d == target)
				&& (e == 'T' || e == target) && (f == 'T' || f == target));
	}
}
