import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class TicTacToe {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("input.txt"));
		int k = sc.nextInt();
		int n = 4;
		PrintWriter out = new PrintWriter(new File("output.txt"));
		for (int t = 0; t < k; t++) {
			char[][] map = new char[4][4];
			for (int i = 0; i < n; i++) {
				String s = sc.next();
				for (int j = 0; j < n; j++) {
					map[i][j] = s.charAt(j);
				}
			}
			boolean hasEmpty = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					hasEmpty |= map[i][j] == '.';
				}
			}
			char winner = 'z';
			c:
			for (char c : new char[] {'X', 'O'}) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						for (int di = -1; di <= 1; di++) {
							for (int dj = -1; dj <= 1; dj++) {
								if (di * di + dj * dj > 0) {
									int cnt = 0;
									for (int ni = i, nj = j; ni >= 0 && ni < n && nj >= 0 && nj < n; ni += di, nj += dj) {
										if (map[ni][nj] == c || map[ni][nj] == 'T') {
											cnt++;
										} else {
											break;
										}
									}
									if (cnt == 4) {
										winner = c;
										break c;
									}
								}
							}
						}
					}
				}
			}
			String ans;
			if (winner != 'z') {
				ans = winner + " won";
			} else if (hasEmpty) {
				ans = "Game has not completed";
			} else {
				ans = "Draw";
			}
			out.println("Case #" + (t + 1) + ": " + ans);
		}
		out.close();
	}

}
