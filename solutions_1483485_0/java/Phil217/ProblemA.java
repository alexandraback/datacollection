package problemA;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("A-practice.in"));
		Scanner sc = new Scanner(new File("A-small.in"));
		// Scanner sc = new Scanner(new File("A-large.in"));

		String[] input = new String[3];
		String[] output = new String[3];
		input[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		input[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		input[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
		output[0] = "our language is impossible to understand";
		output[1] = "there are twenty six factorial possibilities";
		output[2] = "so it is okay if you want to just give up";
		HashMap<Character, Character> mapping = new HashMap<Character, Character>();
		for (int j = 0; j < output.length; j++) {
			for (int i = 0; i < output[j].length(); i++) {
				char c = input[j].charAt(i);
				char enc = output[j].charAt(i);
				if (c != ' ') {
					if (mapping.get(c) != null && mapping.get(c) != enc) {
						System.out.println("error");
					} else {
						mapping.put(c, enc);
					}

				}
			}
		}
		 mapping.put('z', 'q');
		 mapping.put('q', 'z');
		int cases = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= cases; i++) {
			// do case things here
			String s = sc.nextLine();

			String result = "";
			for (int j = 0; j < s.length(); j++) {
				char c = s.charAt(j);
				if (c == ' ') {
					result = result + " ";
				} else {
					result = result + mapping.get(s.charAt(j));
				}
			}
			System.out.format("Case #%d: %s\n", i, result);
		}
	}
}
