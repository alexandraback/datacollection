/**
 * 
 */
package google.codejam.fourteen.qua;

import google.codejam.tools.QuestionFile;

import java.io.IOException;

/**
 * @author ya
 * 
 */
public class C1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		QuestionFile file = new QuestionFile(
				A.class.getResourceAsStream("C-small-attempt4.in"), "C.out");
		int queNum = file.getLength();
		int t = 0;
		try {
			for (t = 0; t < queNum; t++) {
				String line = file.getLine();
				String[] nums = line.split(" ");
				Integer R = Integer.parseInt(nums[0]);
				Integer C = Integer.parseInt(nums[1]);
				Integer M = Integer.parseInt(nums[2]);

				char[][] result = solve(R, C, M);
				file.writeAns(t, "");
				if (result == null) {
					file.write("Impossible\n");
				} else {
					for (int i = 0; i < R; i++) {
						String w = new String(result[i]);
						file.write(w + "\n");
					}
				}
			}
			file.end();
		} catch (Exception e) {
			System.out.println(t);
			e.printStackTrace();
		}
	}

	static char[][] solve(int R, int C, int M) {
		int left = R * C - M;
		int l = left;

		char[][] result = new char[R][C];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				result[i][j] = '*';
			}
		}

		if (left < 0)
			return null;
		if (left == 0)
			return result;
		if (left == 1) {
			result[0][0] = 'c';
			return result;
		}

		result[0][0] = 'c';
		if (C == 1) {
			for (int i = 0; i < left; i++) {
				result[i][0] = '.';
			}
			result[0][0] = 'c';
			return result;
		}
		if (R == 1) {
			for (int i = 0; i < left; i++) {
				result[0][i] = '.';
			}
			result[0][0] = 'c';
			return result;
		}
		if (C == 2) {
			if (left % 2 != 0 || left == 2)
				return null;
			for (int i = 0; i < left / 2; i++) {
				result[i][0] = '.';
				result[i][1] = '.';
			}
			result[0][0] = 'c';
			return result;
		}
		if (R == 2) {
			if (left % 2 != 0 || left == 2)
				return null;
			for (int i = 0; i < left / 2; i++) {
				result[0][i] = '.';
				result[1][i] = '.';
			}
			result[0][0] = 'c';
			return result;
		}

		if (left < 4 || left == 5 || left == 7)
			return null;

		int i = 0;
		int j = 0;
		loop: for (; j < C; j++) {
			for (i = 0; i < 2; i++) {
				result[i][j] = '.';
				left--;
				if (left == 0)
					break loop;
			}
		}
		result[0][0] = 'c';

		if (left == 0) {
			if (l % 2 == 0)
				return result;
			else {
				result[0][j] = '*';
				result[0][j - 1] = '*';
				result[1][j - 1] = '*';
				result[2][0] = '.';
				result[2][1] = '.';
				result[2][2] = '.';
				return result;
			}
		}

		loop: for (i = 2; i < R && left > 0; i++) {
			for (j = 0; j < C && left > 0; j++) {
				result[i][j] = '.';
				left--;
				if (left == 0)
					break loop;
			}
		}

		if (j == 0) {
			if (i == 2) {
				result[0][C - 1] = '*';
				result[1][C - 1] = '*';
				result[i][1] = '.';
				result[i][2] = '.';
			} else {
				result[i - 1][C - 1] = '*';
				result[i][1] = '.';
			}
			return result;
		}

		return result;
	}
}
