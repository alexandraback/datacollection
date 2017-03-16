package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	// private static final String FILE_NAME = "A-large";
	private static final String FILE_NAME = "A-small-attempt0";

	// private static final String FILE_NAME = "A";

	private static void work(Scanner in, PrintStream out, int caseNum) {
		int res = 0, r = in.nextInt(), c = in.nextInt(), w = in.nextInt();
		if (w == 1) {
			out.print(r * c);
			return;
		}
		res += r * (c / w);
		res += w;

		if (c % w == 0) {
			res--;
		}
		out.print(res);

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
