package Round1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Consonants {
	static String vowels = "aeiou";
	public static void main(String[] args) {
		Scanner input = null;
		try {	input = new Scanner(new File("bin\\Round1C\\A-small-attempt0.in"));	} catch (FileNotFoundException e) {		e.printStackTrace();	}
		int T = input.nextInt();
		input.nextLine();
		for (int i = 1; i <= T; i++) {
			String[] s = input.nextLine().split(" ");
			String name = s[0];
			int n = Integer.parseInt(s[1]);
			System.out.print("Case #" + i + ": ");
			ArrayList<Integer[]> consecutives = new ArrayList<Integer[]>();
			int start = 0;
			boolean isConsecutive = false;
			for (int j = 0; j <= name.length(); j++) {
				if (isConsecutive){
					if (j == name.length() || vowels.contains(name.substring(j, j + 1))){
						isConsecutive = false;
						if (j - start >= n){
							Integer[] found = {start, j - 1};
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
			for (int a = 0; a < name.length() - n + 1; a++) {
				for (int b = a + n - 1; b < name.length(); b++) {
					for (int j = 0; j < consecutives.size(); j++) {
						Integer[] bounds = consecutives.get(j);
						if (a <= (bounds[1] - n + 1) && b >= (Math.max(bounds[0], a) + n - 1)){
							count++;
							break;
						}
					}
				}
			}
			
			System.out.println(count);
		}
	}
	
}
