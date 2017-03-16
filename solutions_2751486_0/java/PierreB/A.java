package y2013.Round1C;

import static java.util.Arrays.deepToString;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * 
 * @author PierreB Notes: How many substrings have n consecutive consonants?
 */
public class A {
	final String ROUND = "Round1C";
	String name;
	int n;
	char [] cons = {'a','e','i','o','u'};

	void read(Scanner sc) {
		name = sc.next();
		n = sc.nextInt();
	}

	void solve() {
		int count = 0;
		for (int c = 0; c < name.length(); c++) {
			for (int i = 1; i <= name.length() - c; i++) {
				String sub = name.substring(c, c + i);
				if(validSubstr(sub)) {
					count++;
				}
			}
		}
		System.out.println(count);
	}
	
	boolean validSubstr(String a) {
		int count = 0;
		boolean vowel = false;
		for (int i = 0; i < a.length(); i++) {
			for(char c : cons) {
				if(a.charAt(i) == c) {
					vowel = true;
				}
			}
			if(vowel) {count = 0;}
			else {count++;}
			if(count == n) {
				return true;
			}
			vowel = false;
		}
		return false;
	}

	// EXTRA METHODS

	void run() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("y2013/" + ROUND + "/a.in"));
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read(sc);
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		try {
			new A().run();
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			System.out.println(System.getProperty("user.dir"));
		}
	}
}