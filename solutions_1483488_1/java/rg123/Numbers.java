package codejam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Numbers {
	public static void main (String[] args) throws IOException {
		
		Scanner sc = new Scanner(new FileReader("numbers.in"));
		PrintWriter out = new PrintWriter(new FileWriter("NumbersClarge.out"));
		int cases = sc.nextInt();
		
		for (int i = 0; i < cases; i++) {
			String aString = sc.next();
			String bString = sc.next();
			int a = Integer.parseInt(aString);
			int b = Integer.parseInt(bString);
			int count = 0;
			
			for (int j = a; j <= b; j++) {
				String currentString = String.valueOf(j);
				ArrayList<String> list = new ArrayList<String>();
					for (int k = 1; k < currentString.length(); k++) {
						
						String thisNewString = currentString.substring(currentString.length() - k, currentString.length()) + currentString.substring(0, currentString.length() - k);

						if (isAnagram(currentString, thisNewString)) {

						if (Integer.parseInt(thisNewString) >= a && Integer.parseInt(thisNewString) <= b && !currentString.equals(thisNewString)) {
							if (!list.contains(thisNewString)) {
								count++;
							}
							list.add(thisNewString);
						}
					}
				}
			}
			out.println("Case #" + (i + 1) + ": " + count/2);
			
		}
		out.close();
	}
	
	public static boolean isAnagram(String s1, String s2) {
		
		int[] char_set = new int[10];
		
		if(s1.length() != s2.length()) {
			return false;
		}
		
		for (int i = 0; i < s1.length(); i++) {
			char_set[s1.charAt(i) % 48]++;
		}
		
		for (int j = 0; j < s1.length(); j++) {
			char_set[s1.charAt(j) % 48]--;
		}
		
		for(int k = 0; k < char_set.length; k++) {
			if (char_set[k] != 0) {
				return false;
			}
		}
		
		return true;
	}
}
