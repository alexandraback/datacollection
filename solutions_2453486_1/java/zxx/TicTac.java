import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TicTac {
	private static String[] res = { "X won", "O won", "Draw", "Game has not completed" };

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		for (int i = 1; i <= n; i++) {
			char[][] map = new char[4][4];
			for (int j = 0; j < 4; j++) {
				map[j] = br.readLine().toCharArray();
			}
			br.readLine();
			int calc = calc(map);
			System.out.println("Case #" + i + ": " + res[calc]);
		}
	}

	private static int calc(char[][] map) {
		for (int j = 0; j < 4; j++) {
			char c1 = map[0][j], c2 = map[j][0];
			for (int k = 1; k < 4; k++) {
				if (map[k][j] != c1 && map[k][j] != 'T') {
					if (c1 == 'T') {
						c1 = map[k][j];
					} else {
						c1 = 'W';
					}
				}
				if (map[j][k] != c2 && map[j][k] != 'T') {
					if (c2 == 'T') {
						c2 = map[j][k];
					} else {
						c2 = 'W';
					}
				}
			}
			if (c1 != 'W' && c1 != '.') {
				return c1 == 'X' ? 0 : 1;
			}
			if (c2 != 'W' && c2 != '.') {
				return c2 == 'X' ? 0 : 1;
			}
		}
		char c1 = map[0][0], c2 = map[0][3];
		for (int i = 1; i < 4; i++) {
			if (map[i][i] != c1 && map[i][i] != 'T') {
				if (c1 == 'T') {
					c1 = map[i][i];
				} else {
					c1 = 'W';
				}
			}
			if (map[i][3 - i] != c2 && map[i][3 - i] != 'T') {
				if (c2 == 'T') {
					c2 = map[i][3 - i];
				} else {
					c2 = 'W';
				}
			}
		}
		if (c1 != 'W' && c1 != '.') {
			return c1 == 'X' ? 0 : 1;
		}
		if (c2 != 'W' && c2 != '.') {
			return c2 == 'X' ? 0 : 1;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (map[i][j] == '.') {
					return 3;
				}
			}
		}
		return 2;
	}
}
