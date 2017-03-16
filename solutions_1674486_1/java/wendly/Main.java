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

	boolean isBingo(int[][] array, boolean[] bingo, int index) {
		int num2 = array[index][0];
		boolean ret = false;

		if (bingo[index])
			return true;

		bingo[index] = true;
		for (int i = 0; i < num2; i++) {
			ret = isBingo(array, bingo, array[index][i + 1] - 1);

			if (ret)
				return ret;
		}

		return ret;
	}

	private void work(String input, int t) throws IOException {
		//debug(t, input);
		boolean ret = false;
		String[] inputArray = input.split(" ");
		int num = Integer.valueOf(inputArray[0]);
		int[][] array = new int[num][num + 1];
		boolean[] bingo = new boolean[num];
		boolean[] bingoFinal = new boolean[num];

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				array[i][j] = 0;
			}
		}

		for (int i = 0; i < num; i++) {
			String input2 = br.readLine();
			String[] inputArray2 = input2.split(" ");
			int num2 = Integer.valueOf(inputArray2[0]);

			array[i][0] = num2;
			for (int j = 0; j < num2; j++) {
				array[i][j + 1] =  Integer.valueOf(inputArray2[j + 1]);
			}
		}

		for (int j = 0; j < num; j++) {
			bingoFinal[j] = false;
		}

		for (int i = 0; i < num; i++) {
			if (bingoFinal[i])
				continue;

			for (int j = 0; j < num; j++) {
				bingo[j] = false;
			}

			ret = isBingo(array, bingo, i);
			if (ret)
				break;

			for (int j = 0; j < num; j++) {
				if (bingo[j])
					bingoFinal[j] = true;
			}
		}
		
		if (ret)
			sb.append("Yes");
		else
			sb.append("No");
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
