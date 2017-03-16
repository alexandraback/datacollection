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

	int getMax(int[] vals, int E, int R, int N, int index, int value, int e) {
		int max = 0;
		if (index == N)
			return value;

		for (int i = 0; i <= e; i++) {
			max = Math.max(max, getMax(vals, E, R, N, index + 1, value + vals[index] * i, Math.min(E, e - i + R)));	
		}

		return max;
	}

	private void work(String input, int t) throws IOException {
		//debug(t, input);
		int ret = 0;
		String[] inputArray = input.split(" ");
		int E = Integer.valueOf(inputArray[0]);
		int R = Integer.valueOf(inputArray[1]);
		int N = Integer.valueOf(inputArray[2]);
		int[] vals = new int[N];
		int r = E / R;

		if ((E % R) > 0)
			r += 1;

		input = br.readLine();
		
		inputArray = input.split(" ");
		for (int i = 0; i < N; i++) {
			vals[i] = Integer.valueOf(inputArray[i]);
		}

		ret = getMax(vals, E, R, N, 0, 0, E);	
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
