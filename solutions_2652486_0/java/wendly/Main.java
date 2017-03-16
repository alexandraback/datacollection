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
		String[] inputArray;

		input = br.readLine();
		t = Integer.valueOf(input);

		input = br.readLine();
		inputArray = input.split(" ");
		int R = Integer.valueOf(inputArray[0]);
		int N = Integer.valueOf(inputArray[1]);
		int M = Integer.valueOf(inputArray[2]);
		int K = Integer.valueOf(inputArray[3]);

			sb.append("Case #");
			sb.append(t);
			sb.append(": \r\n");
		for (int i = 0; i < R; i++) {
			if (i > 0)
				sb.append("\r\n");

			input = br.readLine();


			work(input, i, N, M, K);
		}

		System.out.print(sb);
	}

	private void work(String input, int t, int N, int M, int K) throws IOException {
		//debug(t, input);
		int ret = 0;
		String[] inputArray = input.split(" ");
		int num3 = 0;
		int num5 = 0;
		int num2 = 0;
		int num4 = 0;
		int[] ks = new int[K];

		for (int i = 0; i < K; i++) {
			ks[i] = Integer.valueOf(inputArray[i]);

		}

		for (int i = 0; i < K; i++) {
			int val = ks[i];
			for (int j = 0; j < N; j++) {
				num3 = Math.max(num3, j);
				if (val % 3 > 0)
					break;

				val /= 3;
			}
		}

		for (int i = 0; i < K; i++) {
			int val = ks[i];
			for (int j = 0; j < N; j++) {
				num5 = Math.max(num5, j);
				if (val % 5 > 0)
					break;

				val /= 5;
			}
		}

		for (int i = 0; i < K; i++) {
			int val = ks[i];
			for (int j = 0; j < N; j++) {
				num2 = Math.max(num2, j);
				if (val % 2 > 0)
					break;

				val /= 2;
			}
		}

		while (true) {
			if ((num2 + num3 + num5 + num4) <= N)
				break;

			num2 -= 2;
			num4 +=1;
		}

		for (int i = 0; i < num3; i++)
			sb.append(3);

		for (int i = 0; i < num4; i++)
			sb.append(4);

		for (int i = 0; i < num5; i++)
			sb.append(5);

		for (int i = 0; i < (N - num3 - num4 - num5); i++)
			sb.append(2);
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
