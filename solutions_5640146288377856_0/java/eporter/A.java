

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

// Using the Google Guava library.
public class A {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/A-small-1.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			int r = in.nextInt();
			int c = in.nextInt();
			int w = in.nextInt();
			int moves = moves(r, c, w);
			String ans = "Case #"+cs+": "+moves;
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
	
	static int moves(int r, int c, int w) {
	    if (w == 1) { return r * c; }
        int toFind = (c / w) * r + w;
        if (c % w == 0) {
            toFind--;
        }
	    return toFind;
	}
}
