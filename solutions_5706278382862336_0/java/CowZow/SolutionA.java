import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

import round1BST.Tree;


public class SolutionA {
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	    
		int testCases = Integer.parseInt(in.readLine());
		
		String input;
		
		for (int testCaseCount = 1; testCaseCount <= testCases; testCaseCount++) {
			input = in.readLine();
			
			int indexOfSlash = input.indexOf('/');
			int numer = Integer.parseInt(input.substring(0, indexOfSlash));
			int denom = Integer.parseInt(input.substring(indexOfSlash+1));
			
			int gcd = gcd(numer, denom);
			numer = numer / gcd;
			denom = denom / gcd;
			
			int count = 0;
			while (numer < denom && isPow2(denom)) {
				numer = numer * 2;
				gcd = gcd(numer, denom);
				numer = numer / gcd;
				denom = denom / gcd;
				count++;
			}
			
			if (!isPow2(denom)) {
				System.out.println("Case #" + testCaseCount + ": " + "impossible");
			} else {
				System.out.println("Case #" + testCaseCount + ": " + count);
			}
			
			
		}
		
	}
	
	public static int gcd(int a, int b){
	   if (b == 0) 
		   return a;
	   else
		   return gcd(b, a % b);
	}
	
	public static boolean isPow2(int i) {
		if ( i < 0 ) {
	        return false;
	    }
	    return (i & (i - 1)) == 0;
	}
}
