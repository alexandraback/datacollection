import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Squares {
	public static void main(String[] args) {


		
		try {
			Scanner s = new Scanner(new File("input.txt"));
			int numCases = Integer.parseInt(s.nextLine());
			for(int c = 1;c<=numCases;c++) {
				String line = s.nextLine();
				String[] bounds = line.split(" ");
				int low = Integer.parseInt(bounds[0]);
				int high = Integer.parseInt(bounds[1]);
				int count = getCount(low,high);
				System.out.println("Case #" + c + ": " + count);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	public static int getCount(int low, int high) {
		int lowRoot = (int)Math.sqrt(low);
		int highRoot = (int)Math.sqrt(high);
	
		BigInteger bl = new BigInteger(Integer.toString(low));
		BigInteger hl = new BigInteger(Integer.toString(high));
		
		
		int floorLength = Integer.toString(lowRoot).length();
		int ceilLength = Integer.toString(highRoot).length();
		
		int count = 0;
		for(int length = floorLength;length<=ceilLength;length++) {
			ArrayList<String> palindromes = new ArrayList<String>();
			genPalindromes(length,"",palindromes);
			for(String x : palindromes) {
				
				BigInteger i = new BigInteger(x);
				
					
					BigInteger square = i.multiply(i);
					if(square.compareTo(bl) >=0 && square.compareTo(hl) <=0) {
					if(isPalindrome(square.toString())) {
						//System.out.println("MATCHED " + square);
						count++;
					}
				}

			}
		}
		return count;
	}
	public static boolean isPalindrome(String s) {
		return s.equals(reverse(s));
	}
	public static void genPalindromes(int numDigits,String soFar, ArrayList<String> result) {
		if(2*soFar.length()==numDigits) {
			
			result.add(soFar + reverse(soFar));
			return;
		}
		if(2*soFar.length()==numDigits-1) {
			String rev = reverse(soFar);
			for(int i = 0;i<10;i++) {
				result.add(soFar + i + rev);
			}
			return;
		}
		int start = 0;
		if(soFar.length()==0) {
			start = 1;
		}
		for(int x = start;x<10;x++) {
			genPalindromes(numDigits,soFar+x,result);
		}
		
	}
	public static String reverse(String s) {
		StringBuilder result = new StringBuilder();
		for(int i = s.length()-1;i>=0;i--) {
			result.append(s.charAt(i));
		}
		return result.toString();
	}
}
