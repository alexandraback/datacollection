import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Squares {
	public static void main(String[] args) {
		
		ArrayList<String> allPalindromes = new ArrayList<String>();
		for(int length = 1;length<8;length++) {
			genPalindromes(length,"",allPalindromes);
		}


		try {
			FileWriter out = new FileWriter(new File("output.txt"));
			Scanner s = new Scanner(new File("input.txt"));
			int numCases = Integer.parseInt(s.nextLine());
			for(int c = 1;c<=numCases;c++) {
				String line = s.nextLine();
				String[] bounds = line.split(" ");
				BigInteger low = new BigInteger(bounds[0]);
				BigInteger high = new BigInteger(bounds[1]);
				int count = getCount2(low,high,allPalindromes);
				out.write("Case #" + c + ": " + count + "\n");
				System.out.println("Case #" + c + ": " + count);
			}
			out.flush();
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		
	}
	public static int getCount2(BigInteger low, BigInteger high,ArrayList<String> palindromes) {
		int count = 0;
		
		for(String x : palindromes) {
			BigInteger i = new BigInteger(x);
			BigInteger square = i.multiply(i);
			if(square.compareTo(low) >=0 && square.compareTo(high) <=0) {
				if(isPalindrome(square.toString())) {
					count++;
				}
			}
			
		}
		
		return count;
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
						System.out.println("MATCHED " + square);
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
