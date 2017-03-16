package jam;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

	public static char win(int prod) {
		if (prod != 0) {
			if (prod % 16 == 0) {
				return 'O';
			} else if (prod % 81 == 0) {
				return 'X';
			}
		}
		return 'N';
	}

	public static void f1() throws Exception {
		BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in), 1024 * 1024 * 2);
		int t = Integer.parseInt(br.readLine());
		String line;
		int i = 0, j = 0;
		HashMap<Character, Integer> values = new HashMap<Character, Integer>();
		values.put('O', 2);
		values.put('X', 3);
		values.put('T', 6);
		values.put('.', 0);
		int count = 1;
		StringBuilder sb = new StringBuilder();
		while (count <= t) {
			char winner = 'N';
			int[] colProd = new int[] { 1, 1, 1, 1 };
			int lineProd = 1;
			int diag1Prod = 1;
			int diag2Prod = 1;
			boolean notEnded = false;

			for (i = 0; i < 4; i++) {
				line = br.readLine();
				lineProd = 1;
				for (j = 0; j < 4; j++) {
					int val = values.get(line.charAt(j));
					lineProd *= val;
					colProd[j] *= val;
					if (i == j) {
						diag1Prod *= val;
					}
					if (i + j == 3) {
						diag2Prod *= val;
					}
				}
				if (lineProd != 0) {
					if (lineProd % 16 == 0) {
						winner = 'O';
						break;
					} else if (lineProd % 81 == 0) {
						winner = 'X';
						break;
					}
				}
			}
			// winner on line
			if (i < 4) {
				for (i = i + 1; i < 4; i++) {
					br.readLine();
				}
			} else {
				for (int x : colProd) {
					if (x != 0) {
						if (x % 16 == 0) {
							winner = 'O';
							break;
						} else if (x % 81 == 0) {
							winner = 'X';
							break;
						}
					} else {
						notEnded = true;
					}
				}
				if (winner == 'N')
					winner = win(diag1Prod);
				if (winner == 'N')
					winner = win(diag2Prod);
			}
			br.readLine();

			switch (winner) {
			case 'N':
				sb.append("Case #" + count + ": "
						+ (notEnded ? "Game has not completed " : "Draw")
						+ "\n");
				break;
			case 'X':
			case 'O':
				sb.append("Case #" + count + ": " + winner + " won\n");
				break;
			default:
				break;
			}
			count++;
		}
		System.out.print(sb.toString());
	}

	public static int[] readArrayLine(String line, int n) {
		int[] ret = new int[n];
		int start = 0;
		int end = line.indexOf(' ', start);
		for (int i = 0; i < n; i++) {
			if (end > 0)
				ret[i] = Integer.parseInt(line.substring(start, end));
			else
				ret[i] = Integer.parseInt(line.substring(start));
			start = end + 1;
			end = line.indexOf(' ', start);
		}
		return ret;
	}

	public static void main(String[] args) throws Exception {
		f1();
	}

}
