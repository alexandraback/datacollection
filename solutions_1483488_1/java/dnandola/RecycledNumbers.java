package qualify3;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Vector;

public class RecycledNumbers {
	
	public static void main (String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File ("src//qualify3/input.in"));
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			Integer A = in.nextInt();
			Integer B = in.nextInt();
			String strA = A.toString();
			String strB = B.toString();
			Vector <Integer> cycles = new Vector<Integer>();
			if (strA.length() != 1) {
				for (Integer j = A; j <= B; j++) {
					
						cycles.addAll(getCycledValues(j.toString(), strB));
				}
			}
			
			System.out.println("Case #" + (i  + 1) + ": " + cycles.size());
		}
	}
	
	public static Vector<Integer> getCycledValues (String str1, String str2) {
		
		Vector <Integer> cycledNumbers = new Vector<Integer>();
		String no = new String (str1);
		int size = str1.length();
		while (true) {
			String str = "";
			str = str + no.charAt(size - 1);
			
			for (int i = 0; i < size - 1; i++) {
				str = str + no.charAt(i);
			}
					
			
			if (Integer.parseInt(str) == Integer.parseInt(str1))
				break;
			
			int cyclicNumber = Integer.parseInt(str);
			
			if (cyclicNumber >= Integer.parseInt(str1) && cyclicNumber <= Integer.parseInt(str2)) {
				cycledNumbers.add(cyclicNumber);
			}
			
			no = str;
		}
		return cycledNumbers;		
	}
}
