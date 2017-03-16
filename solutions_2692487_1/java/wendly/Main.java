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
		int total = Integer.valueOf(inputArray[0]);
		int N = Integer.valueOf(inputArray[1]);
		int[] array = new int[N];
		int index = 0;
		int min = 101;
		
		input = br.readLine();
 		inputArray = input.split(" ");

		for (int i = 0; i < N; i++) {
			array[i] = Integer.valueOf(inputArray[i]);
		}

		Arrays.sort(array);

		while (index != N) {
			if (total > array[index]) {
				total += array[index];
				index++;
				continue;
			}

			min = Math.min(min, ret + N - index);
		
			if (total == 1) {
				ret = 101;
				break;
			}

			while (total <= array[index]) {
				total += total -1;
				ret++;
			}

			if (ret >= min)
				break;
		}

		min = Math.min(min, ret);
		sb.append(min);
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
