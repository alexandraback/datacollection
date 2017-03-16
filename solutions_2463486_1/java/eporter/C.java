

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

import com.google.common.collect.Lists;

// Using the Google Guava library.
public class C {

	public static void main(String [] args) throws IOException {
		List<Long> fs = findAllFS();
		System.out.println(fs);
		String inputFile = "src/C-large1-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			long a = in.nextLong();
			long b = in.nextLong();
			int ai = Collections.binarySearch(fs, a);
			int bi = Collections.binarySearch(fs, b);
			int ans;
			if (bi >= 0) { // found
				if (ai >= 0) {
					ans = bi - ai + 1;
				} else {
					ans = bi + ai + 2;
				}
			} else {
				if (ai >= 0) {
					ans = -bi - ai - 1;
				} else {
					ans = ai - bi;
				}
			}
			String output = "Case #"+cs+": "+ans;
			out.print(output);
			out.println();
			System.out.println(output);
		}
		out.close();
	}
	
	private static List<Long> findAllFS() {
		List<Long> ret = Lists.newArrayList();
		for (long v = 1; v < 10000000; v++) {
			if (isPalindrome(v)) {
				long vs = v * v;
				if (isPalindrome(vs)) {
					ret.add(vs);
				}
			}
		}
		return ret;
	}
	
	private static boolean isPalindrome(long val) {
		String s = String.valueOf(val);
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
}
