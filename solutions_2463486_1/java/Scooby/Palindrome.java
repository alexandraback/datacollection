// Created by Brenton Philp
// 13 April 2013
import java.io.*;
import java.util.*;
import java.math.*;

public class Palindrome {
	public static void main(String[] args){
		
		String INPUT = args[0];
		int caseNumber = 1;
		int cases = 0;
		BigInteger UPPER_LIMIT= new BigInteger("10000000"); //Root 10^14 is approx 32
		// Find all Fair and Square numbers in the range.
		ArrayList<BigInteger> fandsnumbers = new ArrayList<BigInteger>();
		for (BigInteger b = BigInteger.ONE; b.compareTo(UPPER_LIMIT) <=0; b=b.add(BigInteger.ONE)){
			if (isPalindrome(b.toString()) && isPalindrome((b.multiply(b))+"")){
				fandsnumbers.add(b.multiply(b));
			}
		}

		try {
			Scanner scanner = new Scanner(new File(INPUT));
			cases = scanner.nextInt();
			scanner.nextLine();
			
			while (caseNumber <= cases){
				int result=0;
				//read variables
				BigInteger low = new BigInteger(scanner.next());
				BigInteger high = new BigInteger(scanner.next());
				scanner.nextLine();				
				//solve problem

				for (int i =0; i < fandsnumbers.size(); i++){
					if ( low.compareTo(fandsnumbers.get(i)) <= 0 && high.compareTo(fandsnumbers.get(i)) >= 0){
						result++;
					}
				}
				
				//print result
				System.out.println("Case #"+caseNumber+": "+result);
				caseNumber++;
			}
		} catch (Exception e){
			System.out.println(e);
		}
	}
	public static boolean isPalindrome(String s) {
		for (int i=0;i<(s.length() / 2) + 1;++i) {
			if (s.charAt(i) != s.charAt(s.length()-1 -i)) {
				return false;
			}
		}
		return true;
	}	
}