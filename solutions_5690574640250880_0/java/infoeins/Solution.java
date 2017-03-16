import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class Solution {

	private static BufferedReader in;
	private static FileWriter out;

	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader("C-small-attempt2.in"));
		// in = new BufferedReader(new FileReader("input"));
		out = new FileWriter("out");

		doWork();

		in.close();
		out.close();
	}

	private static void doWork() throws Exception {
		int t = Integer.parseInt(in.readLine());

		for (int i = 1; i <= t; i++) {
			String[] split = in.readLine().split(" ");
			int r = Integer.parseInt(split[0]);
			int c = Integer.parseInt(split[1]);
			int m = Integer.parseInt(split[2]);

			println("Case #" + i + ":\n" + solve(r, c, m));
		}
	}

	private static String solve(int r, int c, int m) {
		final boolean mirror = r > c;
		if (mirror) {
			int tmp = c;
			c = r;
			r = tmp;
		}

		int free = r * c - m;
		char[][] arr = new char[r][c];
		if (free == 1) {
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr[0].length; j++) {
					arr[i][j] = '*';
				}
			}
			arr[0][0] = 'c';
			return generateResultString(mirror, arr);
		}

		if (r == 1) {
			arr[0][0] = 'c';
			for (int i = 1; i < free; i++) {
				arr[0][i] = '.';
			}
			for (int i = free; i < arr[0].length; i++) {
				arr[0][i] = '*';
			}

			return generateResultString(mirror, arr);
		} else if (free == 2 || free == 3 || free == 5 || free == 7) {
			return "Impossible";
		}

		if (r == 2) {
			if (free % 2 == 0) {
				arr[0][0] = 'c';
				arr[1][0] = '.';
				for (int i = 1; i < free / 2; i++) {
					arr[0][i] = '.';
					arr[1][i] = '.';
				}
				for (int i = free / 2; i < arr[0].length; i++) {
					arr[0][i] = '*';
					arr[1][i] = '*';
				}

				return generateResultString(mirror, arr);
			} else {
				return "Impossible";
			}
		}

		int freeCols = free / r;
		final int rest = free % r;

		if (rest == 1) {
			freeCols--;
		}

		for (int i = 0; i < freeCols; i++) {
			for (int j = 0; j < arr.length; j++) {
				arr[j][i] = '.';
			}
		}
		if (rest > 1) {
			for (int i = 0; i < rest; i++) {
				arr[i][freeCols] = '.';
			}
			for (int i = rest; i < arr.length; i++) {
				arr[i][freeCols] = '*';
			}
			freeCols++;
		} else if (rest == 1) {
			for (int i = 0; i < arr.length - 1; i++) {
				arr[i][freeCols] = '.';
			}
			arr[arr.length - 1][freeCols++] = '*';

			arr[0][freeCols] = arr[1][freeCols] = '.';
			for (int i = 2; i < arr.length; i++) {
				arr[i][freeCols] = '*';
			}
			freeCols++;
		}

		for (int i = freeCols; i < arr[0].length; i++) {
			for (int j = 0; j < arr.length; j++) {
				arr[j][i] = '*';
			}
		}

		if (free <= r) {
			int half = rest != 0 ? rest / 2 : free / 2;
			for (int i = 0; i < half; i++) {
				arr[free - 1 - i][0] = '*';
				arr[i][1] = '.';
			}

			if (free % 2 == 1) {
				arr[0][2] = arr[1][2] = arr[2][2] = '.';
				arr[half - 1][0] = arr[half][0] = arr[half - 1][1] = '*';
			}
		} else if (free / r == 1) {
			int half = (r - rest) / 2;
			for (int i = 0; i < half; i++) {
				arr[r - 1 - i][0] = '*';
				arr[rest + i][1] = '.';
			}

			if ((r - rest) % 2 == 1) {
				arr[0][2] = arr[1][2] = arr[2][2] = '.';
				arr[rest + half - 1][0] = arr[rest + half][0] = arr[rest + half
						- 1][1] = '*';
			}
		} else if (free / r == 2 && rest == 1) {
			arr[arr.length - 1][0] = '*';
			arr[2][2] = '.';
		}

		arr[0][0] = 'c';

		return generateResultString(mirror, arr);
	}

	private static String generateResultString(final boolean mirror,
			char[][] arr) {
		String result = "";
		if (mirror) {
			for (int i = 0; i < arr[0].length; i++) {
				for (int j = 0; j < arr.length; j++) {
					result = result + arr[j][i];
				}
				if (i + 1 < arr[0].length) {
					result = result + '\n';
				}
			}
		} else {
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr[0].length; j++) {
					result = result + arr[i][j];
				}
				if (i + 1 < arr.length) {
					result = result + '\n';
				}
			}
		}

		return result;
	}

	static void println(String line) throws Exception {
		out.write(line + '\n');
		System.out.println(line);
	}
}
