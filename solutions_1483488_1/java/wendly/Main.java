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

	private int rightShiftDec(int num) {
		int num2 = 10;

		if (num < 10)
			return num;

		while (true) {
			if (num < num2)
				break;

			num2 *= 10;
		}

		return num / 10 + (num % 10) * num2 / 10;
	}

	private void work(String input, int t) {
		//debug(input);
		int ret = 0;
		String[] inputArray = input.split(" ");
		int min = Integer.valueOf(inputArray[0]);
		int max = Integer.valueOf(inputArray[1]);
		boolean[] doneList = new boolean[2000001];
		int total;

		for (int i = min; i <= max; i++)
			doneList[i] = false;

		for (int i = min; i <= max; i++) {
			int num = i;
			int multiply = 1;

			if (doneList[i])
				continue;

			doneList[i] = true;

			while (true) {
				num /= 10;

				if (num == 0)
					break;

				multiply *= 10;
			}

			num = i;

			total = 0;

			while (true) {
				num = num / 10 + (num % 10) * multiply;
				//debug("i:", i, " num:", num);

				if (num < multiply)
					continue;

				if (num == i)
					break;

				if ((min <= num) && (num <= max)) {
					//debug("i:", i, " num:", num, " 1111");
					total++;
					doneList[num] = true;
				}
			}

			ret += (total + 1) * total / 2;
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
