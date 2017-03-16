

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

//Using the Google Collections library.
public class B {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-small-attempt0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int c = 1; c <= cases; c++) {
			int n = in.nextInt();
			int s = in.nextInt();
			int p = in.nextInt();
			int noSurpriseThresh = p*3-2;
			int surpriseThresh = p*3 - 4;
			int count = 0;
			int surpriseCount = 0;
			for (int i = 0; i < n; i++) {
				int cur = in.nextInt();
				if (cur == 0 && p > 0) {
					continue;
				} else if (cur >= noSurpriseThresh) {
					count++;
				} else if (cur >= surpriseThresh) {
					surpriseCount++;
				}
			}
			count += Math.min(s, surpriseCount);
			out.print("Case #"+c+": "+count);
			out.println();
		}
		out.close();
	}
}
