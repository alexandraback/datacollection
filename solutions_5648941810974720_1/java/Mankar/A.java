import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class A {
	
	public static ArrayList<Integer> phone = new ArrayList<Integer>();

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();
		
		in.nextLine();
		
		for (int testCase = 1; testCase <= t; testCase++) {
			
			String anagram = in.nextLine();
			phone = new ArrayList<Integer>();
			
			anagram = replaceLettersToDigit("Z", "ZERO", anagram, 0);
			anagram = replaceLettersToDigit("W", "TWO", anagram, 2);
			anagram = replaceLettersToDigit("U", "FOUR", anagram, 4);
			anagram = replaceLettersToDigit("X", "SIX", anagram, 6);
			anagram = replaceLettersToDigit("G", "EIGHT", anagram, 8);
			anagram = replaceLettersToDigit("T", "THREE", anagram, 3);
			anagram = replaceLettersToDigit("O", "ONE", anagram, 1);
			anagram = replaceLettersToDigit("F", "FIVE", anagram, 5);
			anagram = replaceLettersToDigit("V", "SEVEN", anagram, 7);
			anagram = replaceLettersToDigit("N", "NINE", anagram, 9);
			
			
			Collections.sort(phone);
			
			System.out.print("Case #" + testCase + ": ");
			for (Integer i : phone) {
				System.out.print(i);
			}
			System.out.println();
			
		}
	}

	private static String replaceLettersToDigit(String letter, String digitLetters,
			String phoneLetters, int digit) {
 
		String newPhoneLetters = phoneLetters;
		
		while (newPhoneLetters.contains(letter)) {
			phone.add(digit);
			
			for (char c : digitLetters.toCharArray()) {
				newPhoneLetters = newPhoneLetters.replaceFirst(Character.toString(c), "");
			}
		}

		return newPhoneLetters;
	}

}
