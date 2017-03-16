package qual;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProbDSmall {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("D-small.in"));
		PrintStream out = new PrintStream(new File("D-small.out"));
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int K = in.nextInt();
			int C = in.nextInt();
			int S = in.nextInt();
			assert K == S;
			out.printf("Case #%d:", caseNum);
			for (int i = 1; i <= S; i++) {
				out.print(" " + i);
			}
			out.println();
		}
	}
}
