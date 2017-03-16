import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class C{
	static Random r = new Random();
	static BigInteger rho(BigInteger n)
	{
		BigInteger x, y, z = n, offset;
		do {
			x = y = new BigInteger(n.bitLength() + 2, r).mod(n);
			offset = new BigInteger(n.bitLength() + 2, r).mod(n);
//			offset = BigInteger.ONE;
			do {
				x = x.multiply(x).add(offset).mod(n);
				y = y.multiply(y).add(offset).mod(n);
				y = y.multiply(y).add(offset).mod(n);
				z = n.gcd(x.subtract(y).abs());
			} while (z.equals(BigInteger.ONE));
		} while (z.equals(n));
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
			seen.add(num);
			System.out.print(num);
			for(int i = 2; i <= 10; i++)
			{
				System.out.print(" "+rho(cand[i]).toString());
			}
			System.out.println("");
		}
	}
}
