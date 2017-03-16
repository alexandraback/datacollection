

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

// Using the Google Guava library.
public class A {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/A-small-attempt0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			String s = in.next();
			String a = String.valueOf(s.charAt(0));
			for (int i = 1; i < s.length(); i++) {
			    String b = s.charAt(i) + a;
			    String c = a + s.charAt(i);
			    if (b.compareTo(c) < 0) {
			        a = c;
			    } else {
			        a = b;
			    }
			}
			String ans = "Case #"+cs+": "+a;
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
}
