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

			input = br.readLine();

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
		String[] inputArray = input.split(" ");
		int N = Integer.valueOf(inputArray[0]);
		int M = Integer.valueOf(inputArray[1]);
		int[][] map = new int[N][M];
		boolean isDone = true;

		for (int i = 0; i < N; i++) {
			input = br.readLine();
			inputArray = input.split(" ");
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.valueOf(inputArray[j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int max = map[i][j];
				boolean isMax = true;

				for (int k = 0; k < N; k++) {
					if (map[k][j] > max) {
						isMax = false;
						break;
					}
				}

				if (isMax)
					continue;

				isMax = true;
				for (int k = 0; k < M; k++) {
					if (map[i][k] > max) {
						isMax = false;
						break;
					}
				}

				if (isMax)
					continue;

				isDone = false;
				break;
			}

			if (!isDone)
				break;
		}
		
		if (isDone)
			sb.append("YES");
		else
			sb.append("NO");
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
