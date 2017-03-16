package Round1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Consonants {
	static String vowels = "aeiou";
	public static void main(String[] args) {
		Scanner input = null;
		try {	input = new Scanner(new File("bin\\Round1C\\A-large.in"));	} catch (FileNotFoundException e) {		e.printStackTrace();	}
		int T = input.nextInt();
		input.nextLine();
		for (int i = 1; i <= T; i++) {
			String[] s = input.nextLine().split(" ");
			String name = s[0];
			int n = Integer.parseInt(s[1]);
			System.out.print("Case #" + i + ": ");
			ArrayList<Long[]> consecutives = new ArrayList<Long[]>();
			int start = 0;
			boolean isConsecutive = false;
			for (int j = 0; j <= name.length(); j++) {
				if (isConsecutive){
					if (j == name.length() || vowels.contains(name.substring(j, j + 1))){
						isConsecutive = false;
						if (j - start >= n){
							Long[] found = {(long)start, (long)(j - 1)};
							consecutives.add(found);
						}
					}
				} else {
					if (j == name.length()) break;
					if (!vowels.contains(name.substring(j, j + 1))){
						isConsecutive = true;
						start = j;
					}
				}
			}
			int count = 0;
			for (int j = 0; j < consecutives.size(); j++) {
				Long[] bounds = consecutives.get(j);
				long a = j > 0 ? (bounds[0] - consecutives.get(j - 1)[1] + n - 2) : (bounds[0]);
				long b = name.length() - (bounds[0] + n - 1);
				count += a*b;
//				System.out.print(a*b + " ");
				a = bounds[1] - bounds[0] + 2 - n;
				b = name.length() - bounds[1] - 1;
				count += a * (a + 1) / 2;
//				System.out.print(a * (a + 1) / 2 + " ");
//				System.out.print(a*b + " ");
				count += a*b;
//				System.out.print("| ");
			}
			
//			System.out.println(" total=" + count);
			System.out.println(count);
		}
	}
	
}
