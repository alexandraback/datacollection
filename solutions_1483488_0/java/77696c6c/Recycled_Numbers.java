import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class Recycled_Numbers {
	public static void main(String[] args) {
		try {
			// Initialize
			InputStreamReader converter = new InputStreamReader(System.in);
			BufferedReader in = new BufferedReader(converter);
			String curLine = in.readLine();
			String[] numbers;
			int A;
			int B;
			
			// Find number of cases
			int N = Integer.parseInt(curLine);
			
			// Read line by line
			for (int line = 0; line < N; line++) {
				curLine = in.readLine();
				numbers = curLine.split(" ");
				A = Integer.parseInt(numbers[0]);
				B = Integer.parseInt(numbers[1]);
				int total = 0;
				HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
				
				for (int number = A; number <= B; number++) {
					// parse the number as a string
					String s = Integer.toString(number);
					String[] digits = new String[s.length()];
					int numZeroes = 0;
					// the array of possible recycled numbers in string form
					for (int digit = 0; digit < digits.length; digit++) {
						digits[digit] = s.substring(digit) + s.substring(0, digit);
						if (digits[digit].charAt(0) == '0') numZeroes++;
					}
					// convert to integers
					int[] dint = new int[digits.length-numZeroes];
					int intdigits = 0;
					for (int digit = 0; digit < digits.length; digit++) {
						if (digits[digit].charAt(0) != '0') {
							dint[intdigits++] = Integer.parseInt(digits[digit]);
						}
					}
					// check if in hashtable
					if (!hm.containsKey(dint[0])) {	
						// put into a set only if between A and B
						Set<Integer> set = new HashSet<Integer>();
						for (int digit = 0; digit < dint.length; digit++) {
							hm.put(dint[digit], 0);
							if (dint[digit] >= A && dint[digit] <= B)
								set.add(dint[digit]);
						}
						// find the set size and add the appropriate number of pairs
						int numSet = set.size();
						total += numSet * (numSet-1) / 2;
					}
				}
				
				System.out.println("Case #" + (line+1) + ": " + total);
			}
		} catch(Exception e) {
			System.out.println("Error: " + e.getMessage());
		}
	}
}
