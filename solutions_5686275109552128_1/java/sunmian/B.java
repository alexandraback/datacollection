package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	private static final String FILE_NAME = "B-large";

	private static void work(Scanner in, PrintStream out, int caseNum) {
		int num = in.nextInt();
		int[] arr = new int[num];
		int max = 0;
		for (int i = 0; i < num; ++i) {
			arr[i] = in.nextInt();
			max = Math.max(max, arr[i]);
		}
		int min = max;
		for (int i = 1; i <= max; ++i) {
			int time = 0;
			for (int j = 0; j < num; ++j) {
				if (time >= min) {
					continue;
				}
				int k = arr[j];
				k -= 1;
				time += (k / i);
			}
			time += i;
			min = Math.min(min, time);
		}
		out.print(min);
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File(FILE_NAME + ".in"));
		PrintStream out = new PrintStream(new File(FILE_NAME + ".out"));
		int loopNum = in.nextInt();

		for (int caseNum = 1; caseNum <= loopNum; caseNum++) {
			out.print("Case #" + caseNum + ": ");
			work(in, out, caseNum);
			out.println();
		}

		in.close();
		out.close();
	}
}
