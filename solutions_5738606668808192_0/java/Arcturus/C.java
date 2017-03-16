//this was mostly taken from
//https://github.com/shubhtibrewal/SPOJ/blob/master/Pollard-rho%20brent%20Integer%20factorisation%2820-digits%29.java
//I am too lazy to write my own factorization program.

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.security.SecureRandom;

public class C {
	final static BigInteger ZERO = new BigInteger("0");
	final static BigInteger ONE  = new BigInteger("1");
	final static BigInteger TWO  = new BigInteger("2");
	final static SecureRandom random = new SecureRandom();
	final static InputStreamReader istream = new InputStreamReader(System.in);
	final static BufferedReader stdin = new BufferedReader(istream);
	static BigInteger[] facts = new BigInteger[11];

	public static BigInteger rho(BigInteger N) {
		BigInteger divisor;
		BigInteger c  = new BigInteger(N.bitLength(), random);
		BigInteger x  = new BigInteger(N.bitLength(), random);
		BigInteger xx = x;

		if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;
		
		do {
			x  =  x.multiply(x).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			divisor = x.subtract(xx).gcd(N);
		} while((divisor.compareTo(ONE)) == 0);
		
		return divisor;
	}
	
	public static BigInteger factor(BigInteger N) {
		if (N.isProbablePrime(20)) {
			return ZERO;
		}
		
		while(true){
			BigInteger n = rho(N);
			if(n != N) return n;
		}
	}

	public static void main(String[] args) throws Exception {
		int need = 50;
		System.out.println("Case #1:");
		for(int nn=65535; need>0; nn-=2) {
			String s = Integer.toString(nn, 2);
			boolean isGood = true;
			for(int i=2; i<=10; i++){
				BigInteger b = factor(new BigInteger(s, i));
				if(b == ZERO){
					isGood = false;
					break;
				}else{
					facts[i] = b;
				}
			}
			
			if(isGood){
				need--;
				System.out.print(s);
				System.out.print(" ");
				
				for(int i=2; i<=10; i++){
					System.out.print(facts[i]);
					if(i==10) System.out.println();
					else System.out.print(" ");
				}
			}
		}
	}
}