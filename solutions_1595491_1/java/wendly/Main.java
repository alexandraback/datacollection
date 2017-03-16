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
			work(input, i);
		}

		System.out.print(sb);
	}

	boolean isGood(int score, int P) {
		int max = score / 3;
		
		if ((score % 3) > 0)
			max++;

		if (max >= P)
			return true;

		return false;
	}

	boolean isSurprise(int score, int P) {
		int max = score / 3;

		if (((score % 3) == 0) && (max > 0))
			max++;
		else
			max += score % 3;

		if (max >= P)
			return true;

		return false;
	}

	private void work(String input, int t) {
		//debug(input);
		int ret = 0;
		String[] inputArray = input.split(" ");
		int N = Integer.valueOf(inputArray[0]);
		int S = Integer.valueOf(inputArray[1]);
		int P = Integer.valueOf(inputArray[2]);

		for (int i = 3; i < N + 3; i++) {
			int score = Integer.valueOf(inputArray[i]);

			if (isGood(score, P)) {
				//debug("score:", score, " Good!!");
				ret++;
				continue;
			}

			if (S == 0)
				continue;

			if (isSurprise(score, P)) {
				//debug("score:", score, " Surprise!!");
				ret++;
				S--;
			}
		}

		sb.append("Case #");
		sb.append(String.valueOf(t + 1));
		sb.append(": ");
		sb.append(String.valueOf(ret));
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
