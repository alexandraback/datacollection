package qual;

import java.util.Scanner;

public class TicTacToeTomek {
	public static void main(String[] args) {
		new TicTacToeTomek().run();
	}

	private void run() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			char[][] map = new char[4][4];
			for (int i = 0; i < 4; i++) {
				String line = sc.next("....");
				for (int j = 0; j < 4; j++) {
					map[i][j] = line.charAt(j);
				}
			}
			String result = solve(map);
			System.out.printf("Case #%d: %s\n", t + 1, result);
		}
	}

	private boolean isComp(char[][] map, char s) {
		for (int i = 0; i < 4; i++) {
			if ((map[i][0] == s || map[i][0] == 'T') &&
					(map[i][1] == s || map[i][1] == 'T') &&
					(map[i][2] == s || map[i][2] == 'T') &&
					(map[i][3] == s || map[i][3] == 'T')) {
				return true;
			}
		}
		for (int i = 0; i < 4; i++) {
			if ((map[0][i] == s || map[0][i] == 'T') &&
					(map[1][i] == s || map[1][i] == 'T') &&
					(map[2][i] == s || map[2][i] == 'T') &&
					(map[3][i] == s || map[3][i] == 'T')) {
				return true;
			}
		}
		if ((map[0][0] == s || map[0][0] == 'T') &&
				(map[1][1] == s || map[1][1] == 'T') &&
				(map[2][2] == s || map[2][2] == 'T') &&
				(map[3][3] == s || map[3][3] == 'T')) {
			return true;
		}
		if ((map[0][3] == s || map[0][3] == 'T') &&
				(map[1][2] == s || map[1][2] == 'T') &&
				(map[2][1] == s || map[2][1] == 'T') &&
				(map[3][0] == s || map[3][0] == 'T')) {
			return true;
		}
		return false;
	}

	private String solve(char[][] map) {
		int dots = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (map[i][j] == '.') dots++;
			}
		}
		if (isComp(map, 'O')) {
			return "O won";
		} else if (isComp(map, 'X')) {
			return "X won";
		} else if (dots > 0) {
			return "Game has not completed";
		} else {
			return "Draw";					
		}
	}

}
