//Problem: Google Code Jam 2013 Qualification Round C
//Name: Fair and Square
//Author: Bruce K. B. Tong
//Tag: BigInteger, Lookup Table

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;
import java.util.*;

public class C {
	final int MAX_DIGIT_SQRT = 8;
	final BigInteger ten = BigInteger.valueOf(10);
	ArrayList<BigInteger>[] bi = new ArrayList[MAX_DIGIT_SQRT+1];;
	ArrayList<BigInteger> num = new ArrayList<BigInteger>();
	private Boolean palindrome(BigInteger a) {
		int[] d = new int[MAX_DIGIT_SQRT*2+1];
		int k = 0;
		
		while (a.compareTo(BigInteger.ZERO) > 0) {
			d[k++] = a.remainder(ten).intValue();
			a = a.divide(ten);
		}
		if (d[k-1] == 0) return false;	//leading zero number
		for (int i = 0; i < k/2; i++)
			if (d[i] != d[k-i-1]) return false;
		return true;
	}

	private void preprocess() {
		for (int i = 1; i <= MAX_DIGIT_SQRT; i++)
			bi[i] = new ArrayList<BigInteger>();
		
		for (int i = 0; i <= 9; i++)
			bi[1].add(BigInteger.valueOf(i));
		for (int i = 0; i <= 9; i++)
			bi[2].add(BigInteger.valueOf(i*10+i));
		for (int k = 3, power = 100; k <= MAX_DIGIT_SQRT; k++, power *= 10)
			for (int i = 0; i <= 9; i++)	//note: i starts from 0
				for (int j = 0, offset = i*power+i; j < bi[k-2].size(); j++)
					bi[k].add(bi[k-2].get(j).multiply(ten).add(BigInteger.valueOf(offset)));
		for (int k = 1; k <= MAX_DIGIT_SQRT; k++)
			for (int i = 0; i < bi[k].size(); i++) {
				if (bi[k].get(i).compareTo(BigInteger.ZERO) == 0) continue;
				//System.out.print(bi[k].get(i));
				//System.out.print("*");
				BigInteger a = bi[k].get(i).multiply(bi[k].get(i));
				if (palindrome(a)) num.add(a);
			}
		//System.out.println();
		//for (int i = 0; i < num.size(); i++)
		//	System.out.print(num.get(i) + " ");
		//System.out.println();
	}

	private int solve(BigInteger A, BigInteger B) {
		int u = Collections.binarySearch(num, A);
		int v = Collections.binarySearch(num, B);
		//System.out.print(u + " * " + v);
		if (u < 0) u = -u-1;
		if (v < 0) v = -v-1 - 1;
		return v - u + 1;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		//String IN = "C-sample.in";
		//String OUT = "C-sample.out";
		String IN = "C-small-attempt1.in";
		String OUT = "C-small-attempt1.out";
		//String IN = "C-large.in";
		//String OUT = "C-large.out";
		Scanner in = new Scanner(new File(IN));
		PrintWriter out = new PrintWriter(new File(OUT));
		
		int T;					//1 <= T <= 100 (or 10,000, or 1,000)
		BigInteger A, B;		//1 <= A <= B <= 1,000 (or 10^14, or 10^100)
		C c = new C();
		c.preprocess();
		
		T = in.nextInt();
        for (int i = 1; i <= T; i++) {
    		A = in.nextBigInteger();
    		B = in.nextBigInteger();
        	String s = "Case #" + i + ": " + c.solve(A, B);
            out.println(s);
            System.out.println(s);
        }
        in.close();
        out.close();
	}
}
