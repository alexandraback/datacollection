import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.TreeSet;

public class FairAndSquare {
	
	public static TreeSet<Long> fairAndSquare = new TreeSet<Long>();
	
	public static void main(String args[]) throws IOException {
		Scanner scin = new Scanner(new File("in3.txt"));
		FileWriter fw = new FileWriter(new File("out3.txt"));
		
//		System.out.println(Math.pow(10,14) < Long.MAX_VALUE);
//		System.out.println(Math.pow(10,14));
//		System.out.println(Long.MAX_VALUE);
		
		generate();
		
		System.out.println(fairAndSquare);
		
		int T = scin.nextInt();
		
		for (int cs = 1; cs < T+1; cs++) {
			long A = scin.nextLong();
			long B = scin.nextLong();
			
			fw.write("Case #" + cs + ": " + fairAndSquare.tailSet(A, true).headSet(B, true).size() + "\n");
		}
		
		fw.close();
	}

	private static void generate() {
		long addend = 1;
		long limit = (long)Math.pow(10,14);
		for (long start = 1; start <= limit; start += addend) {
			long sqrt = (long)Math.sqrt(start);
			
			if (isPalindrome(sqrt) && isPalindrome(start)) {
				fairAndSquare.add(start);
			}
			
			addend += 2;
		}
		
	}

	private static boolean isPalindrome(long start) {
		if (start < 10) {
			return true;
		}
		
		if (start % 10 == 0) {
			return false;
		}
		
		return isPalindrome(""+start);
	}

	private static boolean isPalindrome(String string) {
		for (int i = 0; i < string.length()/2; i++) {
			if (string.charAt(i) != string.charAt(string.length()-i-1)) {
				return false;
			}
		}
		
		return true;
	}
}
