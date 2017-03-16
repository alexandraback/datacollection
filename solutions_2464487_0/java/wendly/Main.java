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
		long r = Long.valueOf(inputArray[0]);
		Long tt = Long.valueOf(inputArray[1]);
		long lower = 0;
		long upper = Math.min(tt / r, (long)Math.sqrt(tt));
		long middle;
		long paint;
	
		while (true) {
			middle = (lower + upper) / 2;

			if (middle == lower)
				break;

			paint = ((2 * r + 2 * middle + 1) * (middle + 1));

			if (paint < tt)
				lower = middle;
			else if (paint > tt)
				upper = middle;
			else
				break;
		}
		
		sb.append(middle + 1);
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
