package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class D {

	private static final String FILE_NAME = "D-large";

	// No Solutin: RICHARD
	private static void work(Scanner in, PrintStream out, int caseNum) {
		int x = in.nextInt(), r = in.nextInt(), c = in.nextInt();
		if (r < x && c < x) {
			out.print("RICHARD");
			return;
		}
		if ((r * c) % x != 0) {
			out.print("RICHARD");
			return;
		}
		if (x == 1 || x == 2) {
			out.print("GABRIEL");
			return;
		}
		if (r == 1 || c == 1) {
			out.print("RICHARD");
			return;
		}
		if (x == 3) {
			out.print("GABRIEL");
			return;
		}
		if (x == 4) {
			if (r <= 2 || c <= 2) {
				out.print("RICHARD");
				return;
			} else {
				out.print("GABRIEL");
				return;
			}
		}
		if (x == 5) {
			if (r <= 3 || c <= 3) {
				out.print("RICHARD");
				return;
			} else {
				out.print("GABRIEL");
				return;
			}
		}
		if (x == 6) {
			if (r <= 4 || c <= 4) {
				out.print("RICHARD");
				return;
			} else {
				out.print("GABRIEL");
				return;
			}
		}
		out.print("RICHARD");
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
