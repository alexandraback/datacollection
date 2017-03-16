

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

// Using the Google Guava library.
public class A {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/A-large.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			String s = in.next();
			int [] sf = freq(s);
			StringBuilder buf = new StringBuilder();
            p(sf, 0, "ZERO", 'Z', buf);
            p(sf, 6, "SIX", 'X', buf);
            p(sf, 2, "TWO", 'W', buf);
            p(sf, 8, "EIGHT", 'G', buf);
            p(sf, 4, "FOUR", 'U', buf);
            p(sf, 5, "FIVE", 'F', buf);
            p(sf, 7, "SEVEN", 'V', buf);
            p(sf, 3, "THREE", 'T', buf);
            p(sf, 1, "ONE", 'O', buf);
            p(sf, 9, "NINE", 'I', buf);
            char [] a = buf.toString().toCharArray();
            Arrays.sort(a);
			String ans = "Case #"+cs+": " + new String(a);
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
	
	private static void p(int [] sf, int digitInt, String digit, char key, StringBuilder buf) {
	    int [] ds = freq(digit);
	    int occur = sf[key - 'A'];
	    for (int i = 0; i < occur; i++) {
	        buf.append(String.valueOf(digitInt));
	    }
	    for (int i = 0; i < ds.length; i++) {
	        sf[i] = sf[i] - ds[i] * occur;
	    }
	}
	
	private static int [] freq(String s) {
	    int [] ret = new int[26];
	    for (char c : s.toCharArray()) {
	        ret[c - 'A']++;
	    }
	    return ret;
	}
}
