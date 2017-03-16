import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;



public class test5 {
	String lastWord(String s) {
		if (s == null || s.length() < 1) {
			return "";
		}
		String result = "";
		for (char c : s.toCharArray()) {
			if (result.length() == 0) {
				result = result + c;
			} else if (c >= result.charAt(0)) {
				result = c + result;
			} else {
				result = result + c;
			}
		}
		return result;
	}
	
	public static void main(String[] args) {
		test5 test = new test5();
	    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    Long t = in.nextLong();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    for (int i = 1; i <= t; ++i) {
	      String n = in.next();
	      System.out.print("Case #" + i + ": ");
	      System.out.println(test.lastWord(n));
	    }
	}
}
