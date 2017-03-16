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
				sb.append("\n");

			input = br.readLine();
			work(input, i);
		}

		System.out.print(sb);
	}

	private void work(String input, int t) {
		//debug(input);
		int ret = 0;
		char[] newArray = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
		char[] map = new char[128];

		map[' '] = ' ';

		for (int i = 'a'; i <= 'z'; i++)
			map[i] = newArray[i - 'a'];

		String[] inputArray = input.split(" ");

		sb.append("Case #");
		sb.append(String.valueOf(t + 1));

		sb.append(": ");
		for (int i = 0; i < input.length(); i++)
			sb.append(map[input.charAt(i)]);
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
