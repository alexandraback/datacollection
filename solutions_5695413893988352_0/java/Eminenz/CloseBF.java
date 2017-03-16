package pack;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class CloseBF {
	
	enum m {
		MIN, MAX, MATCH;
	}
	public static void main(String[] args) throws FileNotFoundException {
		String filename = "B-small-attempt1";
		Scanner sc = new Scanner(new File(filename + ".in"));
		System.setOut(new PrintStream(new File(filename + ".out")));
//		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();

		for (int c = 1; c <= t; c++) {

			String f = sc.next();
			String s = sc.next();
			Integer[] first = new Integer[f.length()];
			Integer[] second = new Integer[s.length()];
			
			int i = 0;
			for (char ch : f.toCharArray()) {
				if (ch != '?') {
					int val = Character.getNumericValue(ch);
					first[i++] = val;
				} else {
					first[i++] = null;
				}
			}
			i = 0;
			for (char ch : s.toCharArray()) {
				if (ch != '?') {
					int val = Character.getNumericValue(ch);
					second[i++] = val;
				} else {
					second[i++] = null;
				}
			}
			
			int minone = 1000;
			int mintwo = 1000;
			for (int one = 0; one < 1000; one++) {
				for (int two = 0; two < 1000; two++) {
					
					if (matches(one, first) && matches(two, first)) {
						int diff = Math.abs(one - two);
						if (diff < Math.abs(minone - mintwo) ) {
							minone = one;
							mintwo = two;
						} else if (diff == Math.abs(minone - mintwo) && one < minone) {
							minone = one;
							mintwo = two;
						} else if (diff == Math.abs(minone - mintwo) && one == minone && two < mintwo) {
							minone = one;
							mintwo = two;
						}
					}
				}
			}
			
			System.out.println("Case #" + c + ": " + minone + " " + mintwo);
		}
	}
	private static boolean matches(Integer one, Integer[] first) {
		
		String str = one.toString();
		if (str.length() > first.length) {
			return false;
		}
		int zeros = first.length - str.length();
		for (int i = 0; i < zeros; i++) {
			str = "0" + str;
		}
		for (int i = 0; i < str.length(); ++i) {
			  int digit = Integer.parseInt(str.charAt(i) + "");
			  if (first[i] != null && first[i] != digit) {
				  return false;
			  }
		}
		
		return true;
	}
}
