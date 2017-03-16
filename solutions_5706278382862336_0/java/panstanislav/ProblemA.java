import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("A-small-attempt0.out"));

		int T = sc.nextInt();

		for (int testCase = 1; testCase <= T; testCase++) {
			String line = sc.next();
			String[] pair = line.split("/");
			long upper = Long.parseLong(pair[0]);
			long lower = Long.parseLong(pair[1]);
			if(upper > lower) {
				printAnswer(out, testCase, "impossible");
				continue;
			}
			while (upper % 2 == 0 && lower % 2 == 0) {
				upper /= 2;
				lower /= 2;
			}
			
			long cdt = 0;
			
			long tLower = lower;
			while(tLower % 2 == 0) {
				tLower /= 2;
			}
			
			if(upper % tLower != 0) {
				printAnswer(out, testCase, "impossible");
				continue;
			} else {
				upper /= tLower;
				lower /= tLower;
			}
			
			int count = 0;
			while(lower % 2 == 0) {
				lower /= 2;
				upper /= 2;
				if(upper == 0) {
					count++;
				}
			}
			
			if(upper % lower == 0) {
				printAnswer(out, testCase, "" + count);
			} else {
				printAnswer(out, testCase, "impossible");
			}
		}

		out.close();
	}


	private static void printAnswer(PrintWriter printer, int testCase,
			String answer) {
		System.out.println("Case #" + testCase + ": " + answer);
		printer.println("Case #" + testCase + ": " + answer);
	}

}
