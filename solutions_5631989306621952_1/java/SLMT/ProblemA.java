package round1;

import java.util.LinkedList;
import java.util.Scanner;

public class ProblemA {
	
	public static void main(String[] args) {
		Scanner inputScanner = new Scanner(System.in);
		
		// Get the number of test cases
		String wordSet, result;
		int totalCases = inputScanner.nextInt();
		inputScanner.nextLine();
		for (int caseId = 1; caseId <= totalCases; caseId++) {
			// Read the word set
			wordSet = inputScanner.nextLine();
			result = findTheLastWord(wordSet.toCharArray());
			
			// Print the result
			System.out.println("Case #" + caseId + ": " + result);
		}
		
		inputScanner.close();
	}
	
	private static String findTheLastWord(char[] wordSet) {
		LinkedList<Character> list = new LinkedList<Character>();
		char firstC;
		
		for (char ch : wordSet) {
			if (list.isEmpty())
				list.addLast(ch);
			else {
				firstC = list.getFirst();
				if (ch >= firstC)
					list.addFirst(ch);
				else
					list.addLast(ch);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for (Character ch : list)
			sb.append(ch);
		return sb.toString();
	}
}
