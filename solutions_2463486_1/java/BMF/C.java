package main;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class C {
	
	public static void main(String[] args) {
		
		long top = (long)Math.pow(10, 7);
		List<Long> fairAndSquare = new LinkedList<Long>();
		
		for (long i = 1; i <= top; i++) {
			if (isPalindrome(i)) {
				long square = (long)Math.pow(i, 2);
				if (isPalindrome(square))
					fairAndSquare.add(square);
			}
		}
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt(); in.nextLine();
		
		for (int i = 1; i <= T; i++) {

			long A = in.nextLong();
			long B = in.nextLong();
			if (in.hasNextLine()) in.nextLine();
			
			int result = valuesBetween(fairAndSquare, A, B);
			
			System.out.format("Case #%d: %s\n", i, result);
		}
		
		in.close();
	}

	private static int valuesBetween(List<Long> fairAndSquare, long a, long b) {
		
		int result = 0;
		
		for (long val : fairAndSquare) {
			if (val >= a && val <= b)
				result++;
			else if (val > b)
				break;
		}
		
		return result;
	}

	public static boolean isPalindrome(long number) {
        long palindrome = number;
        long reverse = 0;

        while (palindrome != 0) {
            long remainder = palindrome % 10;
            reverse = reverse * 10 + remainder;
            palindrome = palindrome / 10;
        }

        if (number == reverse)
            return true;

        return false;
    }
}
