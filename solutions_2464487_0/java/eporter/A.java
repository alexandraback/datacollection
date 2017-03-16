

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

// Using the Google Guava library.
public class A {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/A-small-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			long r = in.nextLong();
			long t = in.nextLong();
			long s = r;
			long rings = 0;
			for ( ; ; s += 2) {
				long paintNeeded = (s+1)*(s+1) - s*s;
				if (paintNeeded <= t) {
					rings++;
					t -= paintNeeded;
				} else {
					break;
				}
			}
			out.print("Case #"+cs+": "+rings);
			out.println();
		}
		out.close();
	}
}
