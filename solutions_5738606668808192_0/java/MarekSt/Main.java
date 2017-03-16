import java.util.*;
import java.io.*;
import java.lang.*;

class Primes {
	private
		static ArrayList<Integer> primes = new ArrayList<Integer>(1000);
	    static int lastPrimeIndex = 0;

	static private int getNextPrime(int number){ // get Prime number >= prime
		while (getDivider(number)>1) {
			number++;
		}
		return number;
	}
	
	static public int getPrime(int i){
		if (i<0) return -1;
		if (i>=primes.size()){
			primes.add(getNextPrime(getPrime(i-1)+1));
		}
		return primes.get(i);
	}
	
	static public long getDivider(long number){
		int maxPossiblePrime = (int) Math.sqrt(number);
		int i=0;
		int prime=getPrime(i);
		while (prime <= maxPossiblePrime) {
			if (number % prime == 0) return prime;
			prime=getPrime(++i);
		}
		return 1;		
	}
	
	static{
		primes.add(2);
	}
}

/* *************************************** */

class CoinJam{
	
}

/* *************************************** */

// n>=2
class CoinJamGenerator{
	private
		int innerBits=0;
		int length;
		String format;
	
	public CoinJamGenerator(int n){
		length=n;
		format="1%"+(length-2)+"s1";
	}
	
	private String getNumberString(){
		return String.format(format, Integer.toBinaryString(innerBits++)).replace(' ', '0');
	}
	
	private long longBaseN(String number, int base)
	{
		long value=0;
	    int len = number.length();
	    for (int i = 0; i < len; i++) {
	    	value = value * base + (number.charAt(i)-'0');
	    }
	    return value;
	}
	
	private String isCoinJam(String number){
		String result = number;
		long divider=0;
		for(int base=2;base<=10;base++){
			long value=longBaseN(number, base);
	    	divider=Primes.getDivider(value);
	    	if (divider==1) return null;
	    	result+=" "+divider;
		}
		return result;
	}
	
	public String getCoinJam(){
		String number;
		String coinJam;
		do{
			number=getNumberString();
			if (number.length()>length) return "-";
			coinJam=isCoinJam(number);
		} while (coinJam==null);
		return coinJam; 
	}
}

/* *************************************** */

public class Main {
	public class nNumber{
		private
			long i;
			String number;
			
		nNumber(int innerBits, int innerLength, int base){
			//number='1'++'1';
		}
	}
	
	
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    for (int i = 1; i <= t; ++i) {
	      int n = in.nextInt();
	      int j = in.nextInt();
	      CoinJamGenerator gen = new CoinJamGenerator(n);
	      
	      System.out.println("Case #" + i + ":");
	      while(0<j--){
	    	  System.out.println(gen.getCoinJam());
	      }
	    }
	}
}
