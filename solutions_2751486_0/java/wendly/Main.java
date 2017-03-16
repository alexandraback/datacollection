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
		long ret = 0;
		String[] inputArray = input.split(" ");
		String str = inputArray[0];
		int n = Integer.valueOf(inputArray[1]);
		int index = 0;
		int num = 0;
		int head = 0;
		boolean[] arr = new boolean[256];

		Arrays.fill(arr, true);
		arr['a'] = false;
		arr['e'] = false;
		arr['i'] = false;
		arr['o'] = false;
		arr['u'] = false;

		while (index < str.length()) {
			if (!arr[str.charAt(index)]) {
				index ++;
				num = 0;
				continue;
			}

			num++;
			if (num < n) {
				index++;
				continue;
			}
			
			int A = index - n - head + 1;
			int B = str.length() - index - 1;

			ret += A * B + A + B + 1;
			head = index - n + 2;
			index++;
		}
		
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
