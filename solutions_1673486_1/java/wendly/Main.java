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

	private void work(String input, int t) throws IOException {
		//debug(input);
		int ret = 0;
		String[] inputArray = input.split(" ");
		int A = Integer.valueOf(inputArray[0]);
		int B = Integer.valueOf(inputArray[1]);
		String tmp = br.readLine();
		String[] probabilityList = tmp.split(" ");
		double min = Double.MAX_VALUE;
		double probability;
		double probabilityTmp;

		probabilityTmp = 1;
		for (int i = 0; i < A; i++) {
			probabilityTmp *= Double.valueOf(probabilityList[i]);
		}

		probability = probabilityTmp * (B - A + 1) + (1 - probabilityTmp) * (B - A + B + 2);
		//debug("1111:", probability);

		min = Math.min(min, probability);

		probabilityTmp = 1;
		for (int i = 1; i < A; i++) {
			probabilityTmp *= Double.valueOf(probabilityList[i - 1]);

			probability = probabilityTmp * (2 + B - i) + (1 - probabilityTmp) * (2 + B - i + B + 1);
			//debug("2222(", i, "):", probability);
			min = Math.min(min, probability);
		}

		probability = (B + 2);
		min = Math.min(min, probability);

		//debug("3333:", probability);
		//debug("4444 min:", min);

		sb.append("Case #");
		sb.append(String.valueOf(t + 1));
		sb.append(": ");
		//sb.append(String.format("%08f", min));
		sb.append(String.valueOf(min));
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