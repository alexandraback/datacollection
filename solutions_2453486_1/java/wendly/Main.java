import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;

public class Main {
	public Main() throws IOException {
		String input;
		int t;

		input = br.readLine();
		t = Integer.valueOf(input);

		for (int i = 0; i < t; i++) {
			if (i > 0)
				sb.append("\r\n");

			sb.append("Case #");
			sb.append(i + 1);
			sb.append(": ");

			work(input, i);
		}

		System.out.print(sb);
	}

	private void work(String input, int t) throws IOException {
		//debug(t, input);
		int ret = 0;
		char[][] map = new char[4][4];
		boolean isFinish = true;

		for (int i = 0; i < 4; i++) {
			input = br.readLine();
			for (int j = 0 ; j < 4; j++) {
				char c = input.charAt(j);
				map[i][j] = c;
			}
		}
		input = br.readLine();

		for (int i = 0; i < 4; i++) {
			char start = 'T';
			boolean isWin = true;

			for (int j = 0 ; j < 4; j++) {
				if (map[i][j] == '.') {
					isFinish = false;
					isWin = false;
					break;
				}

				if (start == 'T') {
					start = map[i][j];
					continue;
				}

				if (map[i][j] == 'T')
					continue;

				if (start == map[i][j])
					continue;

				isWin = false;
				break;
			}

			if (!isWin)
				continue;

			sb.append("" + start + " won");
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			char start = 'T';
			boolean isWin = true;

			for (int j = 0 ; j < 4; j++) {
				if (map[j][i] == '.') {
					isFinish = false;
					isWin = false;
					break;
				}

				if (start == 'T') {
					start = map[j][i];
					continue;
				}

				if (map[j][i] == 'T')
					continue;

				if (start == map[j][i])
					continue;

				isWin = false;
				break;
			}

			if (!isWin)
				continue;

			sb.append("" + start + " won");
			return;
		}
		
		char start = 'T';
		boolean isWin = true;
		for (int i = 0; i < 4; i++) {
			if (map[i][i] == '.') {
				isFinish = false;
				isWin = false;
				break;
			}

			if (start == 'T') {
				start = map[i][i];
				continue;
			}

			if (map[i][i] == 'T')
				continue;

			if (start == map[i][i])
				continue;

			isWin = false;
			break;
		}

		if (isWin) {
			sb.append("" + start + " won");
			return;
		}

		start = 'T';
		isWin = true;
		for (int i = 0; i < 4; i++) {
			if (map[3 - i][i] == '.') {
				isFinish = false;
				isWin = false;
				break;
			}

			if (start == 'T') {
				start = map[3 - i][i];
				continue;
			}

			if (map[3 - i][i] == 'T')
				continue;

			if (start == map[3 - i][i])
				continue;

			isWin = false;
			break;
		}

		if (isWin) {
			sb.append("" + start + " won");
			return;
		}

		if (isFinish)
			sb.append("Draw");
		else
			sb.append("Game has not completed");
	}

	StringBuilder sb = new StringBuilder();
	BufferedReader br = new BufferedReader(
		new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
			new Main();
	}

	public static void debug(Object... arr) {
		System.err.println(Arrays.deepToString(arr));
	}
}
