//Problem: Google Code Jam 2013 Round 1A A
//Name: Bullseye
//Author: Bruce K. B. Tong
//Tag: BigInteger, Maths

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;
import java.util.*;

public class A {
	private BigInteger sqrt(BigInteger n) {
		  BigInteger a = BigInteger.ONE;
		  BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		  while(b.compareTo(a) >= 0) {
		    BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		    if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		    else a = mid.add(BigInteger.ONE);
		  }
		  return a.subtract(BigInteger.ONE);
		}
	
	private BigInteger solve(BigInteger r, BigInteger t) {
		BigInteger x;
		x = BigInteger.ONE.subtract(r.multiply(BigInteger.valueOf(2)));
		BigInteger y = x.multiply(x).add(t.multiply(BigInteger.valueOf(8)));
		BigInteger ans = x.add(sqrt(y)).divide(BigInteger.valueOf(4));
		return ans;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		//String IN = "A-sample.in";
		//String OUT = "A-sample.out";
		//String IN = "A-small-attempt0.in";
		//String OUT = "A-small-attempt0.out";
		String IN = "A-large.in";
		String OUT = "A-large.out";
		Scanner in = new Scanner(new File(IN));
		PrintWriter out = new PrintWriter(new File(OUT));
		
		int T;				//1 <= T <= 1,000 (or 6,000)
		BigInteger r;		//1 <= r <= 1,000 (or 10^18)
		BigInteger t;		//1 <= t <= 1,000 (or 2x10^18)
		A a = new A();
		
		T = in.nextInt();
        for (int i = 1; i <= T; i++) {
    		r = in.nextBigInteger();
    		t = in.nextBigInteger();
        	String s = "Case #" + i + ": " + a.solve(r, t);
            out.println(s);
            System.out.println(s);
        }
        in.close();
        out.close();
	}
}
