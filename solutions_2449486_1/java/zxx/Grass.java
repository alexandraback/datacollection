import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Grass {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int totalCase = parseInt(br.readLine());
		outer: for (int caseNum = 1; caseNum <= totalCase; caseNum++) {
			String[] s = br.readLine().split(" ");
			int n = parseInt(s[0]), m = parseInt(s[1]);
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++) {
				String[] ss = br.readLine().split(" ");
				for (int j = 0; j < m; j++) {
					map[i][j] = parseInt(ss[j]);
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (check(map, i, j) == false) {
						System.out.println("Case #" + caseNum + ": NO");
						continue outer;
					}
				}
			}
			System.out.println("Case #" + caseNum + ": YES");
		}
	}

	private static boolean check(int[][] map, int x, int y) {
		int n = map.length, m = map[0].length;
		boolean flag1 = true, flag2 = true;
		for (int i = 0; i < n; i++) {
			if (map[i][y] > map[x][y]) {
				flag1 = false;
			}
		}
		for (int i = 0; i < m; i++) {
			if (map[x][i] > map[x][y]) {
				flag2 = false;
			}
		}
		return flag1 || flag2;
	}
}
