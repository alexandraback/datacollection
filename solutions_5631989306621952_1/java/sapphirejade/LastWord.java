import java.util.*;
import java.io.*;

public class LastWord {
	public static void main (String[] args) {		
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = Integer.parseInt(in.nextLine());  // Scanner has functions to read ints, longs, strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			System.out.println("Case #" + i + ": " + findLastWord(in.nextLine()));
		}
	}
	
	private static String findLastWord (String s) {
		String newS = "";
		for (int i = 0; i < s.length(); i++) {
			if (newS.length() == 0 || s.charAt(i) >= newS.charAt(0)) {
				newS = s.charAt(i) + newS;
			} else {
				newS = newS+s.charAt(i);
			}
		}
		return newS;
	}
}