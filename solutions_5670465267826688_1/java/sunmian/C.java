package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class C {

	private static final int[][] TABLE = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 },
			{ 3, -4, -1, 2 }, { 4, 3, -2, -1 } };

	private static final String FILE_NAME = "C-large";

	private static final BigInteger FOUR = BigInteger.valueOf(4);

	private static void work(Scanner in, PrintStream out, int caseNum) {
		int l = in.nextInt();
		String xStr = in.next();
		BigInteger xBig = new BigInteger(xStr);

		if (xBig.mod(FOUR).equals(BigInteger.ZERO)) {
			in.next();
			out.print("NO");
			return;
		}
		if (xBig.compareTo(FOUR) > 0) {
			xBig = FOUR.add(xBig.mod(FOUR));
		}
		int x = xBig.intValue();
		String str = in.next();
		// no_match, i, k, -1
		int stage = 0;
		// i = 1, j = 2, k = 3
		int prefix = 1;
		boolean postive = true;
		for (int i = 0; i < x * l; ++i) {
			int idx = i % l;
			char c = str.charAt(idx);
			int cur;
			switch (c) {
			case 'i':
				cur = 1;
				break;
			case 'j':
				cur = 2;
				break;
			case 'k':
				cur = 3;
				break;
			default:
				throw new RuntimeException();
			}
			int tem = TABLE[prefix - 1][cur];
			if (tem < 0) {
				postive = !postive;
			}
			tem = Math.abs(tem);
			prefix = tem;
			if (stage == 0 && postive && prefix == 2) {
				++stage;
			} else if (stage == 1 && postive && prefix == 4) {
				++stage;
			} else if (stage == 2 && !postive && prefix == 1) {
				++stage;
			}
		}
		if (stage == 3 && !postive && prefix == 1) {
			out.print("YES");
		} else {
			out.print("NO");
		}

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
