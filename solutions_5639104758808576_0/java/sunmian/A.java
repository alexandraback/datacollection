package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	private static final String FILE_NAME = "A-small-attempt1";

	private static void work(Scanner in, PrintStream out, int caseNum) {
		int num = in.nextInt();
		String levels = in.next();
		int standing = 0;
		int invited = 0;
		for (int i = 0; i < num + 1; ++i) {
			if (levels.charAt(i) - '0' != 0 && i - standing > 0) {
				invited += Math.max(0, (i - standing));
				standing += invited;
			}
			standing += levels.charAt(i) - '0';
		}
		out.print(" " + invited);
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File(FILE_NAME + ".in"));
		PrintStream out = new PrintStream(new File(FILE_NAME + ".out"));
		int loopNum = in.nextInt();

		for (int caseNum = 1; caseNum <= loopNum; caseNum++) {
			out.print("Case #" + caseNum + ":");
			work(in, out, caseNum);
			out.println();
		}

		in.close();
		out.close();
	}
}
