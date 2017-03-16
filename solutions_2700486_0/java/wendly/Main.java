import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;

public class Main {
	long[][] pascal = new long[1001][1001];

	void init() {
		for (int i = 0; i <= 1000; i++) {
			for (int j = 0; j <= 1000; j++) {
				pascal[i][j] = 0;
			}
		}

		pascal[1][1] = 1;

		for (int i = 2; i <= 1000; i++) {
			for (int j = 1; j <= 1000; j++) {
				pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
			}
		}
	}

	public Main() throws IOException {
		String input;
		int t;

		init();
		input = br.readLine();
		t = Integer.valueOf(input);

		for (int i = 0; i < t; i++) {
			if (i > 0)
				sb.append("\r\n");

			input = br.readLine();

			sb.append("Case #");
			sb.append(i + 1);
			sb.append(": ");

			work(input, i);
		}

		System.out.print(sb);
	}

	private void work(String input, int t) throws IOException {
		debug(t, input);
		double ret = 0;
		String[] inputArray = input.split(" ");
		int N = Integer.valueOf(inputArray[0]);
		int x = Integer.valueOf(inputArray[1]);
		int y = Integer.valueOf(inputArray[2]);
		int level = 1;

		if (N == 1) {
			if ((x == 0) && (y == 0)) {
				ret = 1;
			} else {
				ret = 0;
			}
			sb.append(ret);
			return;
		}

		N -= 1;
		while (N >= ((level + 1) * 2 + 1)) {
			N -= (level + 1) * 2 + 1;
			level++;
		}

		if (x == 0) {
			if (y < level * 2)
				ret = 1;
			else
				ret = 0;

			sb.append(ret);
			return;
		}

		if ((x + y) < level * 2) {
			ret = 1;
			sb.append(ret);
			debug(44444);
			return;
		} else if (((x + y) - level * 2) > 2) {
			ret = 0;
			sb.append(ret);
			debug(55555);
			return;
		}

		if (N > level + 1 + y) {
			ret = 1;
			sb.append(ret);
			debug(33333);
			return;
		}

		long total = 0;
		long add = 0;

		for (int i = 1; i <= N + 1; i++) {
			total += pascal[N + 1][i];
		}

		debug(8888888, N, y, level);
		for (int i = 0; i <= N; i++) {
			if (N - i <= y)
				break;

			add += pascal[N + 1][i + 1];
			debug(77777, add);
		}
		
		debug(666666, add, total);
		ret = ((double)add / (double)total);
		sb.append(ret);
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
