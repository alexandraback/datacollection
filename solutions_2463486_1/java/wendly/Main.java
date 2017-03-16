import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;

public class Main {
	long[] dp = new long[11111110 * 2];
	ArrayList<Long> dp1 = new ArrayList<Long>();
	int index = 0;

	private void cal() {
		byte[] dp2 =  new byte[10000000 * 14];

		Arrays.fill(dp2, (byte)0);

		dp2[0] = 0x30;
		for (int i = 1; i < 10; i++) {
			dp2[i * 14 + 0] = (byte)(i + 0x30);
			dp[index] = Long.valueOf(new String(dp2, i * 14, 1));
			index++;
		}

		for (int i = 1; i < 7; i++) {
			byte[] temp = dp2.clone();
			int index1 = 0;
			int index2 = 0;

			while (temp[index1 * 14 + 0] != 0) {
				for (int j = 0; j < 10; j++) {
					dp2[index2 * 14 + 0] = (byte)(j + 0x30);
					for (int k = 0; k < i * 2 - 1; k++) {
						dp2[index2 * 14 + k + 1] = temp[index1 * 14 + k];
					}
					dp2[index2 * 14 + i * 2] = (byte)(j + 0x30);

					if (j != 0) {
						dp[index] = Long.valueOf(new String(dp2, index2 * 14, i * 2 + 1));
						index++;
					}
					index2++;
				}
				index1++;
			}
		}

		Arrays.fill(dp2, (byte)0);
		dp2[0] = 0x30;
		dp2[1] = 0x30;
		for (int i = 1; i < 10; i++) {
			dp2[i * 14 + 0] = (byte)(i + 0x30);
			dp2[i * 14 + 1] = (byte)(i + 0x30);
			dp[index] = Long.valueOf(new String(dp2, i * 14, 2));
			index++;
		}

		for (int i = 1; i < 7; i++) {
			byte[] temp = dp2.clone();
			int index1 = 0;
			int index2 = 0;

			while (temp[index1 * 14 + 0] != 0) {
				for (int j = 0; j < 10; j++) {
					dp2[index2 * 14 + 0] = (byte)(j + 0x30);
					for (int k = 0; k < i * 2; k++) {
						dp2[index2 * 14 + k + 1] = temp[index1 * 14 + k];
					}
					dp2[index2 * 14 + (i + 1) * 2 - 1] = (byte)(j + 0x30);

					if (j != 0) {
						dp[index] = Long.valueOf(new String(dp2, index2 * 14, (i + 1) * 2));
						index++;
					}
					index2++;
				}
				index1++;
			}
		}
		Arrays.sort(dp);

		for (int i = 0; i < dp.length; i++) {
			if (dp[i] == 0)
				continue;

			long square = dp[i] * dp[i];

			if (square > dp[dp.length - 1])
				break;

			int search = Arrays.binarySearch(dp, square);

			if (search < 0)
				continue;

			dp1.add(square);
		}
		Collections.sort(dp1);
	}

	public Main() throws IOException {
		String input;
		int t;

		cal();

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

	private void work(String input, int t) {
		//debug(t, input);
		int ret = 0;
		String[] inputArray = input.split(" ");
		long start = Long.valueOf(inputArray[0]);
		long end = Long.valueOf(inputArray[1]);

		for (int i = 0; i < dp1.size(); i++) {
			long num = dp1.get(i);

			if ((start <= num) && (num <= end))
				ret++;
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
