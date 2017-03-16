import java.io.*;
import java.util.*;

public class C
{
	private static boolean isPerfectSquare(long i) {
		long tst = (long)(Math.sqrt(i) + 0.5);
		return tst*tst == i;
	}
	
	private static boolean isPalindrome(long n) {
		String s = ""+n;
		int len = s.length();
		for(int i = 0; i<len/2; i++) {
			if(s.charAt(i) != s.charAt(len-1-i)) {
				return false;
			}
		}
		return true;
	}
	
	private static void solve(int casenum, long from, long to) {
		long numsfound = 0;
		for(long i = from; i <= to; i++) {
			if(isPalindrome(i) && isPerfectSquare(i) && isPalindrome((long)(Math.sqrt(i)+0.5))) {
				numsfound++;
			}
		}
		System.out.println("Case #"+casenum+": "+numsfound);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int numCases = Integer.parseInt(br.readLine());
		for(int i = 0; i < numCases; i++) {
			String line = br.readLine();
			String[] parts = line.split(" ");
			solve(i+1, Long.parseLong(parts[0]), Long.parseLong(parts[1]));
		}
	}

}