import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class C{
	static Random r = new Random();
	static BigInteger two = new BigInteger("2");
	static BigInteger three = new BigInteger("3");
	static BigInteger five = new BigInteger("5");
	static BigInteger seven = new BigInteger("7");
	static BigInteger rho(BigInteger n)
	{
		BigInteger x, y, z = n, offset;
		int cnt = 0;
		if(n.mod(two).equals(BigInteger.ZERO)) return two;
		if(n.mod(three).equals(BigInteger.ZERO)) return three;
		if(n.mod(five).equals(BigInteger.ZERO)) return five;
		if(n.mod(seven).equals(BigInteger.ZERO)) return seven;
		do {
			x = y = new BigInteger(n.bitLength() + 2, r).mod(n);
//			offset = new BigInteger(n.bitLength() + 2, r).mod(n);
			offset = BigInteger.ONE;
			do {
				if(cnt++>2000) return BigInteger.ZERO;
				x = x.multiply(x).add(offset).mod(n);
				y = y.multiply(y).add(offset).mod(n);
				y = y.multiply(y).add(offset).mod(n);
				z = n.gcd(x.subtract(y).abs());
			} while (z.equals(BigInteger.ONE));
		} while (z.equals(n));
		System.err.println("cnt: "+cnt);
		return z;
	}
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T, N, J;
		T = sc.nextInt();
		N = sc.nextInt();
		J = sc.nextInt();
		System.out.println("Case #1:");
		TreeSet<String> seen = new TreeSet<String>();
		while(seen.size()<J)
		{
			StringBuilder sb = new StringBuilder("1");
			for(int i = 2; i < N; i++)
				sb.append(r.nextBoolean()?"1":"0");
			sb.append("1");
			String num = sb.toString();
			if(seen.contains(num)) continue;
			BigInteger cand[] = new BigInteger[11];
			boolean primeFlag=false;
			for(int i = 2; i <= 10 && !primeFlag; i++)
			{
				cand[i]=new BigInteger(num,i);
				primeFlag=cand[i].isProbablePrime(50);
			}
			if(primeFlag) continue;
			for(int i = 2; i <= 10 && !primeFlag; i++)
			{
				cand[i]=rho(cand[i]);
				primeFlag=(cand[i].equals(BigInteger.ZERO));
			}
			if(primeFlag) continue;
			seen.add(num);
			System.out.print(num);
			for(int i = 2; i <= 10; i++)
			{
				System.out.print(" "+cand[i].toString());
			}
			System.out.println("");
			System.err.println(seen.size());
		}
	}
}
