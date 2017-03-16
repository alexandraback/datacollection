import java.io.*;
import java.util.*;
import java.math.*;

public class A{
	static BigInteger two = BigInteger.valueOf(2);

	public static BigInteger getRings(BigInteger rings, BigInteger a, BigInteger b){
		BigInteger res = b.multiply(rings).add(rings.multiply(rings.subtract(BigInteger.ONE)).divide(two).multiply(a));
		//System.out.println("gr " + rings + " " + a + " " + b + ": " + res);
		return res;
	}

	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int tc = scanner.nextInt();
		for(int tcc = 1; tcc <= tc; tcc++){
			System.out.print("Case #" + tcc + ": ");
			BigInteger r, t;
			r = scanner.nextBigInteger();
			t = scanner.nextBigInteger();
			BigInteger first = r.multiply(r);
			r = r.add(BigInteger.ONE);
			first = r.multiply(r).subtract(first);
			r = r.add(BigInteger.ONE);
			BigInteger second = r.multiply(r);
			r = r.add(BigInteger.ONE);
			second = r.multiply(r).subtract(second);
			BigInteger a = second.subtract(first);
			BigInteger b = first;
		//	System.out.println(first);
		//	System.out.println(second);
			BigInteger maxR = BigInteger.ONE;
			while(getRings(maxR, a, b).compareTo(t)<=0)maxR = maxR.multiply(two);
			BigInteger minR = BigInteger.ZERO;
			while(minR.compareTo(maxR) < 0){
				BigInteger mid = minR.add(maxR.subtract(minR).add(BigInteger.ONE).divide(two));
				if(getRings(mid, a, b).compareTo(t)<=0){
					minR = mid;
				} else {
					maxR = mid.subtract(BigInteger.ONE);
				}
			}
			System.out.println(minR);
		}
	}
}
