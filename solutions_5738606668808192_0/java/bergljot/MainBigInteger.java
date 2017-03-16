package jamcoins;

import java.math.BigInteger;
import java.util.Scanner;

public class MainBigInteger {
	
	static public String turnToJamcoin(int val, int max)
	{
		String coin = "1";
		while (max > 1)
		{
			//System.out.println("max val " + max + " " + val);
			if (val >= max / 2) 
			{
				coin += "1";
				val -= max / 2;
			}
			else coin += "0";
			max /= 2;
		}
		coin += "1";
		return coin;
	}
	
	static public BigInteger getDecFromBase(String num, int base)
	{
		if (num.length() < 1) return BigInteger.valueOf(0);
		BigInteger sum = BigInteger.valueOf(0);
		for (int ind = 0; ind < num.length(); ind++)
		{
			//sum *= base;
			sum = sum.multiply(BigInteger.valueOf(base));
			if (num.charAt(ind) == '1') sum = sum.add(BigInteger.valueOf(1));// sum += 1;
		}
		return sum;
		
	}
	static public BigInteger isPrime(BigInteger num)
	{
		//if (num <= 3) return 0;
		if (num.compareTo(BigInteger.valueOf(4)) < 0) return BigInteger.valueOf(0);
		BigInteger test = BigInteger.valueOf(2);
		while(test.multiply(test).compareTo(num) <= 0)
		{
			//if (num % test == 0) return test;
			//test++;
			if (num.mod(test).equals(BigInteger.valueOf(0))) return test;
			test = test.add(BigInteger.valueOf(1));
		}
		return BigInteger.valueOf(0);
	}
	
	static public BigInteger[] checkValidity(String num)
	{
		BigInteger[] factors = new BigInteger[9];
		for (int base = 2; base < 11; base++)
		{
			BigInteger maybePrime = getDecFromBase(num, base);
			BigInteger factor = isPrime(maybePrime);
			if (factor.equals(BigInteger.valueOf(0))) return null; // not a prime
			else factors[base - 2] = factor;
		}
		return factors;
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		in.nextLine();
		for(int i = 0; i < cases; i++)
		{
			int n = in.nextInt();
			int j = in.nextInt();
			System.out.println("Case #" + (i + 1) + ": ");
			int max = 1 << (n - 2);
			//System.out.println("n is " + n);
			int found = 0;
			for (int g = 0; g < max; g++) 
			{
				// System.out.println("found " + found);
				String jam = turnToJamcoin(g, max);
				//System.out.println(" " + getDecFromBase(turnToJamcoin(g, max), 2));
				BigInteger[] factors = checkValidity(jam);
				if (factors == null) continue;
				System.out.print(jam);
				found++;
				// print solution
				for (int f = 0; f < factors.length; f++) System.out.print(" " + factors[f]);
				System.out.println();
				if (found >= j) break;
			}
		}
		in.close();
		
	}
}
