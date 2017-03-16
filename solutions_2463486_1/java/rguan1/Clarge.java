package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class Clarge {
	public static void main(String args[]) throws FileNotFoundException, IOException {
		
		String filein = "C-large.in";
		String fileout = "C-large.out";
		Scanner sc = new Scanner(new FileReader(new File(filein)));
		PrintWriter out = new PrintWriter(new FileWriter(new File(fileout)));
		
		int cases = sc.nextInt();
		BigInteger lo, hi;
		int count;
		BigInteger value;
		HashMap<BigInteger, BigInteger> hm = new HashMap<BigInteger, BigInteger>();
		
		for(int i = 0; i < 10000000; i++) {
			BigInteger integer = BigInteger.valueOf(i);
			BigInteger integerSquared = integer.pow(2);
			if(isPalindrome(BigInteger.valueOf(i).toString()) && isPalindrome(integerSquared.toString())) {
				hm.put(integer, integerSquared);
			}
		}
		
		for (int i = 0; i < cases; i++) {
			count = 0;
			lo = sc.nextBigInteger();
			hi = sc.nextBigInteger();
			
			Iterator it = hm.entrySet().iterator();
			while (it.hasNext()) {
				Map.Entry pairs = (Map.Entry)it.next();
				value = (BigInteger)pairs.getValue();
				if(value.compareTo(lo) >= 0 && value.compareTo(hi) <= 0) {
					count++;
				}
			}
			out.println("Case #" + (i + 1) + ": " + count);
		}
		out.close();   
	}
	
	public static boolean isPalindrome(String nString) {
		
		for (int i = 0; i < nString.length() / 2; i++) {
			if(nString.charAt(i) != nString.charAt(nString.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
}
