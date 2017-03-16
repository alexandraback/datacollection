import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;

public class TicTacToeTomek {

	public static void main(String[] args) throws Exception {
		String filename = "A-small-attempt0.in";
		BufferedReader in = new BufferedReader(new FileReader(filename));

		int T = Integer.parseInt(in.readLine());

		for (int test = 1; test <= T; test++) {
			String[] lines = { in.readLine(), in.readLine(), in.readLine(),
					in.readLine() };
			in.readLine();
			System.out.println("Case #" + test + ": " + solve(lines));
		}
		in.close();
	}

	private static String solve(String[] lines) {
		int empty = 0;
		int[] x = new int[10];
		int[] o = new int[10];
		Arrays.fill(x, 0);
		Arrays.fill(o, 0);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				char ch = lines[i].charAt(j);
				if (ch == '.') {
					empty++;
				}
				if (ch == 'X' || ch == 'T') {
					x[i]++;// row
					x[4 + j]++;// col
					x[8] += i == j ? 1 : 0;// diag1
					x[9] += i + j == 3 ? 1 : 0;// diag2
				}
				if (ch == 'O' || ch == 'T') {
					o[i]++;// row
					o[4 + j]++;// col
					o[8] += i == j ? 1 : 0;// diag1
					o[9] += i + j == 3 ? 1 : 0;// diag2
				}
			}
		}

		for (int num : x) {
			if (num == 4) {
				return "X won";
			}
		}
		for (int num : o) {
			if (num == 4) {
				return "O won";
			}
		}

		return empty > 0 ? "Game has not completed" : "Draw";
	}

}
