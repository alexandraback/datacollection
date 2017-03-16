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
		int total = Integer.valueOf(inputArray[0]);
		String tmp;
		String[] tmpArray;
		int [][] list = new int[2][total];
		boolean [][] listComplete = new boolean[2][total];
		int star = 0;
		boolean isNotFinish = false;
		int times = 0;
		int tempStar = -1;
		boolean isContinue;

		for (int i = 0 ; i < total; i++) {
			tmp = br.readLine();
			tmpArray = tmp.split(" ");

			list[0][i] = Integer.valueOf(tmpArray[0]);
			list[1][i] = Integer.valueOf(tmpArray[1]);
			listComplete[0][i] = false;
			listComplete[1][i] = false;
		}
		
		while (true) {
			if (tempStar == star)
				break;

			tempStar = star;
			isContinue = false;

			for (int i = 0; i < total; i++) {
				if (!listComplete[1][i]) {
					//debug("1111", i, star, list[1][i]);
					if (star >= list[1][i]) {
						//debug("1111", i);
						times++;
						listComplete[1][i] = true;
						star++;

						if (!listComplete[0][i]) {
							//debug("2222", i);
							listComplete[0][i] = true;
							star++;
						}

						isContinue = true;
						break;
					}
				}
			}

			if (isContinue)
				continue;

			int maxIndex = 0;
			int max = 0;
			for (int i = 0; i < total; i++) {
				if (!listComplete[0][i]) {
					if (star >= list[0][i]) {
						if (list[1][i] > max) {
							maxIndex = i;
							max = list[1][i];
						}
					}
				}
			}

			if (max != 0) {
				times++;
				star++;
				listComplete[0][maxIndex] = true;
				continue;
			}

			for (int i = 0; i < total; i++) {
				if (!listComplete[0][i]) {
					//debug("1111", i, star, list[0][i]);
					if (star >= list[0][i]) {
						//debug("3333", i);
						times++;
						star++;
						listComplete[0][i] = true;
						break;
					}
				}
			}
		}

		for (int i = 0; i < total; i++) {
			if (!listComplete[0][i]) {
				isNotFinish = true;
				break;
			}

			if (!listComplete[1][i]) {
				isNotFinish = true;
				break;
			}
		}

		sb.append("Case #");
		sb.append(String.valueOf(t + 1));
		sb.append(": ");

		if (!isNotFinish)
			sb.append(String.valueOf(times));
		else
			sb.append("Too Bad");
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