package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Csmall {
	public static void main(String args[]) throws FileNotFoundException, IOException {
		
		String filein = "C-small.in";
		String fileout = "C-small.out";
		Scanner sc = new Scanner(new FileReader(new File(filein)));
		PrintWriter out = new PrintWriter(new FileWriter(new File(fileout)));
		
		int cases = sc.nextInt();
		int low, hi, count;
		
		for (int i = 0; i < cases; i++){
			low = sc.nextInt();
			hi  = sc.nextInt();
			count = 0;
			
			for (int j = low; j <= hi; j++) {
				if (isPalindrome(j) && Math.sqrt(j) % 1 == 0 && isPalindrome((int)Math.sqrt(j))) {
					count++;
				}
			}
			out.println("Case #" + (i + 1) + ": " + count);
		}
		out.close();
	}
	
	public static boolean isPalindrome(int n) {
		
		String nString = Integer.toString(n);
		
		for (int i = 0; i < nString.length() / 2; i++) {
			if(nString.charAt(i) != nString.charAt(nString.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
}
