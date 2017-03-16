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
		//int ret = 0;
		String[] inputArray = input.split(" ");
		int x = Integer.valueOf(inputArray[0]);
		int y = Integer.valueOf(inputArray[1]);
		int x_out = 0;
		int y_out = 0;
		int index = 1;

		if (x > 0) {
			for (int i = 0; i < Math.abs(x); i++) {
				sb.append('W');
				sb.append('E');
			}
		} else if (x < 0) {
			for (int i = 0; i < Math.abs(x); i++) {
				sb.append('E');
				sb.append('W');
			}
		}
		
		if (y > 0) {
			for (int i = 0; i < Math.abs(y); i++) {
				sb.append('S');
				sb.append('N');
			}
		} else if (y < 0) {
			for (int i = 0; i < Math.abs(y); i++) {
				sb.append('N');
				sb.append('S');
			}
		}
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
