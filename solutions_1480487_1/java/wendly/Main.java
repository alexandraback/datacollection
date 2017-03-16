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

	double getMinValue(String[] inputArray, int totalNum, int sum, boolean[] isWin) {
		int temp;
		int num = 0;
		int max = 0;
		int maxIndex = 0;
		double minValue;
		int sum2 = 0;

		for (int i = 1; i <= totalNum; i++) {
			temp = Integer.valueOf(inputArray[i]);

			if (isWin[i - 1])
				continue;

			if (temp > max) {
				max = temp;
				maxIndex = i - 1;
			}

			sum2 += temp;
			num++;
		}

		temp = (max * num) - sum;
		minValue = (double)(sum2 + sum) / (double)num;

		//debug(temp, sum);

		if ((double)max < minValue) {
			//debug("minValue", minValue);
			return minValue;
		} else {
			isWin[maxIndex] = true;
			return getMinValue(inputArray, totalNum, sum, isWin);
		}
	}

	private void work(String input, int t) throws IOException {
		//debug(t, input);
		double ret = 0;
		String[] inputArray = input.split(" ");
		int num = Integer.valueOf(inputArray[0]);
		int max = 0;
		double minValue;
		int sum = 0;
		int temp;
		boolean[] isWin = new boolean[num];

		for (int i = 1; i <= num; i++) {
			temp = Integer.valueOf(inputArray[i]);
			isWin[i - 1] = false;
			sum += temp;
		}

		minValue = getMinValue(inputArray, num, sum, isWin);

		for (int i = 1; i <= num; i++) {
			if (i > 1)
				sb.append(" ");

			if (isWin[i - 1]) {
				sb.append(0);
				continue;
			}

			temp = Integer.valueOf(inputArray[i]);
			ret = (((double)(minValue - temp)) / (double)sum) * 100;
			sb.append(ret);
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