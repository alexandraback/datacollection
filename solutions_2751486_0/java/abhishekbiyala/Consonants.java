package abhi;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Consonants {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileInputStream("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-small-attempt0.out"));
		
		int totalCases = sc.nextInt();
		
		String name;
		int n;
		
		//For each case
		for(int i = 1; i <= totalCases; i++) {
			name = sc.next();
			n = sc.nextInt();
			
			out.println("Case #"+i+": "+getNValue(name, n));

		}
		
		out.close();
	}

	private static long getNValue(String name, int n) {
		System.out.println("name: " + name);
		int nValue = 0;
		for(int i = 0; i < name.length(); i ++) {
			for(int j = n; j <= name.length() - i; j++) {
				String sub = name.substring(i, i+j);
	
				System.out.print("substring: " + sub);
				if(matches(sub, n)) {
					nValue++;
				}
			}
		}
		
		return nValue;
	}

	private static boolean matches(String sub, int n) {
		int counter = 0;
		for(char c: sub.toCharArray()) {
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				counter = 0;
				continue;
			}
			
			counter ++;
			
			if(counter == n) {
				System.out.println(". " + true);
				return true;
			}
		}
		
		System.out.println(". " + false);
		return false;
	}
}
