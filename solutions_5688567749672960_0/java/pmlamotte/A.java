package gcj2;

import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {
	
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new FileInputStream(new File("input_a.txt")));
		System.setOut(new PrintStream(new File("output_a.txt")));
		int numCases = s.nextInt();
		for (int c = 0; c < numCases; c++) {
			
			int x = s.nextInt();
			System.out.printf("Case #%d: %d%n", c+1, compute(x));
		}
	}
	
	public static int revint(int num) {
		char[] digits = ("" + num).toCharArray();
		char[] reverse = Arrays.copyOf(digits, digits.length);
		for (int i = 0; i < reverse.length / 2; i++) {
			char tmp = reverse[i];
			reverse[i] = reverse[reverse.length - i - 1];
			reverse[reverse.length - i - 1] = tmp;
		}
		String rev = new String(reverse);
		return Integer.parseInt(rev);
	}
	
	public static int compute(int n) {
		
		int moves = 1;
		
		HashMap<Integer, Integer> oldnums = new HashMap<>();
		HashMap<Integer, Integer> nums = new HashMap<>();
		nums.put(1, 1);
		while (true) {
			
			if (nums.containsKey(n)) {
				return nums.get(n);
			}
			HashMap<Integer, Integer> newnums = new HashMap<>();	
			for (Map.Entry<Integer, Integer> e : nums.entrySet()) {
				if (!oldnums.containsKey(e.getKey())) {
					newnums.put(e.getKey()+1, e.getValue()+1);
					newnums.put(revint(e.getKey()), e.getValue()+1);					
					oldnums.put(e.getKey(), e.getValue());
				}
			}
			nums = newnums;
			moves++;
		}
	}
}
