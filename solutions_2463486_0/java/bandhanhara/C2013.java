import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Enumeration;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class C2013 {

	static int digitLimit = 8;
	static int array[] = new int[digitLimit];
	static List<Long> palindroms = new ArrayList<Long>();

	/**
	 * @param args
	 */
	public static void main(String args[]) {
		DecimalFormat dcf = new DecimalFormat("#");
		Scanner scn = new Scanner(System.in);

		String str = scn.nextLine();
		int T = Integer.parseInt(str);
		
		BigInteger sb;
		BigInteger eb;
		
		for (int t = 1; t <= T; t++) {
			
			str = scn.nextLine();
			String arr[] = str.split(" ");
			long d1 = Long.parseLong(arr[0]);
			long d2 = Long.parseLong(arr[1]);
			
			double dt1 = Math.sqrt(d1);
			long l1 = (long)dt1;
			
			double dt2 = Math.sqrt(d2);
			long l2 = (long)dt2;
			
			if(l1<dt1){
				l1 = l1+1;
			}
			
			palindroms = new ArrayList<Long>();
			
			for(int i=(""+l1).length();i<=(""+l2).length();i++){
				digitLimit = i;
				array = new int[digitLimit];
				init();
				generatePalindrome(1);
			}
			
			while (palindroms.get(0)*palindroms.get(0) < d1) {
				palindroms.remove(0);
			}
			
			Collections.sort(palindroms);
			
			while (palindroms.size()>0 && palindroms.get(palindroms.size()-1)*palindroms.get(palindroms.size()-1) > d2) {
				palindroms.remove(palindroms.size()-1);
			}
			
			int count = 0;
			for (long l : palindroms) {
				if( isPalindrom((l*l)+"")){
					count++;
				}
			}

			System.out.println("Case #" + t + ": "+count);

		}
	}
	

	private static boolean isPalindrom(String original) {
		int length = original.length();
		String reverse = "";
		for (int i = length - 1; i >= 0; i--)
			reverse = reverse + original.charAt(i);

		return original.equals(reverse);
	}

	public static Set<BigInteger> allPalindromic(BigInteger start, BigInteger limit) {
		 

	    return null;
	}

	public static BigInteger squareRoot(BigInteger testSubject, boolean round) {
		int digitsInTestSubject = testSubject.toString().length();

		double sPoint = (double) digitsInTestSubject / 2.0;

		BigInteger startPoint = BigInteger.valueOf(Math.round(sPoint));
		BigInteger lastGuess = null;
		BigInteger guess = null;

		BigInteger lower = null;
		BigInteger upper = null;

		if (digitsInTestSubject < 3) {
			lastGuess = BigInteger.valueOf(0L);
			lower = lastGuess;
			guess = BigInteger.valueOf(5L);
			upper = BigInteger.valueOf(10L);

		} else {
			startPoint = startPoint.subtract(BigInteger.valueOf(1L));
			startPoint = pow(BigInteger.valueOf(10L), startPoint);

			lastGuess = startPoint;
			lower = lastGuess;

			guess = startPoint.multiply(BigInteger.valueOf(5L));

			upper = startPoint.multiply(BigInteger.valueOf(10L));
		}

		int guesses = 0;
		while (true) {
			guesses++;
			BigInteger ans = guess.pow(2);

			if (ans.compareTo(testSubject) == 0) {
				break;
			}

			if (lastGuess.compareTo(guess) == 0) {
				if (round) {
					if (guess.compareTo(testSubject) == 1) {
						guess = guess.subtract(BigInteger.valueOf(1));
					} else {
						guess = guess.add(BigInteger.valueOf(1));
					}
				} else {
					guess = null;
				}
				break;
			}

			if (ans.compareTo(testSubject) == 1) {
				BigInteger tmp;

				if (guess.compareTo(lastGuess) == 1) {
					upper = guess;
					tmp = upper.subtract(lower);
					tmp = tmp.divide(BigInteger.valueOf(2L));
					tmp = lower.add(tmp);
				} else {
					upper = guess;
					tmp = upper.subtract(upper.subtract(lower).divide(
							BigInteger.valueOf(2L)));
				}

				lastGuess = guess;
				guess = tmp;
			} else {
				BigInteger tmp;
				if (guess.compareTo(lastGuess) == 1) {
					lower = guess;
					tmp = upper.subtract(lower);
					tmp = tmp.divide(BigInteger.valueOf(2L));
					tmp = upper.subtract(tmp);
				} else {
					lower = guess;
					tmp = lower.add(upper.subtract(lower).divide(
							BigInteger.valueOf(2L)));
				}

				lastGuess = guess;
				guess = tmp;
			}
		}

		return guess;
	}

	public static BigInteger pow(BigInteger testSubject, BigInteger pow) {
		BigInteger index = BigInteger.valueOf(1L);
		BigInteger retVal = BigInteger.valueOf(10L);

		while (index.compareTo(pow) != 0) {
			retVal = retVal.multiply(testSubject);
			index = index.add(BigInteger.valueOf(1L));
		}

		return retVal;
	}
	
	public static void generatePalindrome(int pos) {
		int i;
		if (pos == 1) // if first position than set i=1 else i=0 as smallest
						// palindrome
						// with any given limit is 1.......1
			i = 1;
		else
			i = 0;
		if (pos == Math.ceil((float) digitLimit / 2)) // base case - checks if
														// the middle number is
														// reached
		{
			for (; i <= 9; i++) // how many times to increment middle position
			{
				
				printArray_(); // print the number from the array
				array[pos - 1]++; // increments the number
				if (digitLimit % 2 == 0) // if number of digits is even than two
											// middle positions will be there
					array[digitLimit - pos]++;
			}
			array[pos - 1] = 0; // resets both middle positions numbers to 0
			if (digitLimit % 2 == 0)
				array[digitLimit - pos] = 0;
			return;
		}

		for (; i <= 9; i++) // loop to increment this position and
							// digitLimit-pos position
							// at the same time and each time call
							// generatePalindrome with pos+1
							// to generate all the greater positions palindromes
							// and than come back
							// to increment this by one and again call till all
							// 10 numbers are filled
							// in case of positions greater than 1 and 9 if 1.
		{
			generatePalindrome(pos + 1);
			array[pos - 1]++;
			array[digitLimit - pos]++;
		}
		array[pos - 1] = 0;
		array[digitLimit - pos] = 0;
	}

	public static void init() // initializes the array with zeros except the
								// first and the last
	{
		int i;
		array[0] = array[digitLimit - 1] = 1;
		for (i = 1; i < digitLimit - 1; i++) {
			array[i] = 0;
		}
	}

	public static void printArray_() // prints the array
	{
		int i;
		String str = "";
		for (i = 0; i < digitLimit; i++) {
			str += array[i];
		}
		
		palindroms.add(Long.parseLong(str));

	}

}
