package gcj2016;


import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;

import org.junit.Assert;


public class JamCoin {
	private static final String INPUT_FILE_NAME = "C-small-attempt0.in";
	private static final String OUTPUT_FILE_NAME = "C-small.out";
	private static final BigInteger ZERO = new BigInteger("0");

	public static void main(String[] args) {
		new JamCoin().start();
	}

	private ArrayList<Integer> primes;
	private Random rand = new Random(System.currentTimeMillis());
	
	private void start() {
		findPrimesFactor((int)(Math.sqrt(2000000000)));
		test();
		try (
				MyReader reader = new MyReader(new BufferedReader(new FileReader(INPUT_FILE_NAME)));
				PrintWriter printer = new PrintWriter(new FileWriter(OUTPUT_FILE_NAME))) {
			Integer ncases = reader.nextInt();
			for(int i = 0 ; i < ncases ; i++) {
				int len = reader.nextInt();
				int numSamples = reader.nextInt();
				printer.println("Case #" + (i+1) + ": ");
				solve(printer,len,numSamples);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void findPrimesFactor(int MAXVALUE) {
		boolean[] isPrime = new boolean[MAXVALUE+1];
		Arrays.fill(isPrime, true);
		isPrime[0] = false;
		isPrime[1] = false;
		isPrime[2] = true;
		for(int x = 2 ; x <= MAXVALUE ; x++)
			if ( isPrime[x] ) {
				for(int d = 2 ; d * x <= MAXVALUE ; d++) {
					isPrime[d*x] = false;
				}
			}
		this.primes = new ArrayList<Integer>();
		for(int x = 2 ; x <= MAXVALUE ; x++)
			if ( isPrime[x]) {
				primes.add(x);
			}
	}

	private void test() {
		Assert.assertEquals(new BigInteger("1"),convertToBaseValue("1".toCharArray(), 2));
		Assert.assertEquals(new BigInteger("0"),convertToBaseValue("0".toCharArray(), 2));
		Assert.assertEquals(new BigInteger("0"),convertToBaseValue("0".toCharArray(), 10));
		Assert.assertEquals(new BigInteger("9"),convertToBaseValue("1001".toCharArray(), 2));
		Assert.assertEquals(new BigInteger("28"),convertToBaseValue("1001".toCharArray(), 3));
		Assert.assertEquals(new BigInteger("65"),convertToBaseValue("1001".toCharArray(), 4));
		Assert.assertEquals(new BigInteger("126"),convertToBaseValue("1001".toCharArray(), 5));
		Assert.assertEquals(new BigInteger("217"),convertToBaseValue("1001".toCharArray(), 6));
		Assert.assertEquals(new BigInteger("344"),convertToBaseValue("1001".toCharArray(), 7));
		Assert.assertEquals(new BigInteger("513"),convertToBaseValue("1001".toCharArray(), 8));
		Assert.assertEquals(new BigInteger("730"),convertToBaseValue("1001".toCharArray(), 9));
		Assert.assertEquals(new BigInteger("1001"),convertToBaseValue("1001".toCharArray(), 10));
//		Assert.assertEquals(new BigInteger("11001"),convertToBaseValue("1001".toCharArray(), 10));
		
		Assert.assertNull(possibleFactor(new BigInteger(""+1)));
		Assert.assertNull(possibleFactor(new BigInteger(""+2)));
		Assert.assertNull(possibleFactor(new BigInteger(""+3)));
		Assert.assertNull(possibleFactor(new BigInteger(""+5)));
		Assert.assertNull(possibleFactor(new BigInteger(""+7)));
		Assert.assertNull(possibleFactor(new BigInteger(""+11)));
		Assert.assertEquals(new Integer(2), possibleFactor(new BigInteger("4")));
		Assert.assertEquals(new Integer(2), possibleFactor(new BigInteger("6")));
		Assert.assertEquals(new Integer(3), possibleFactor(new BigInteger("9")));
		Assert.assertEquals(new Integer(7), possibleFactor(new BigInteger("1001")));
		Assert.assertEquals(new Integer(5), possibleFactor(new BigInteger("25")));
		Assert.assertEquals(new Integer(2), possibleFactor(new BigInteger("252134214124213213213124")));
		
	}
	private void solve(PrintWriter printer, int len, int numSamples) {
		//TODO: test function isJamCoin
		int cnt = 0 ;
		HashSet<String> coins = new HashSet<>();
		while ( cnt < numSamples) {
			String coin = findACoin(len);
			if ( !coins.contains(coin)) {
				cnt++;
				coins.add(coin);
			}
		}
		printResult(printer,coins);
	}

	private void printResult(PrintWriter printer, HashSet<String> coins) {
		for(String coin : coins) printLine(printer,coin); 
	}

	private void printLine(PrintWriter printer, String coin) {
		String s = coin;
		char[] rcoin = coin.toCharArray();
		for(int base = 2; base <= 10; base++) {
			BigInteger value = convertToBaseValue(rcoin, base);
			Integer factor = possibleFactor(value);
			s += " " + factor;
		}
		printer.println(s);
	}

	private String findACoin(int len) {
		while (true) {
			char[] rcoin = generateRandomCoin(len);
			if ( isJamCoin(rcoin)) 
				return new String(rcoin);
		}
	}

	private char[] generateRandomCoin(int len) {
		char[] d = new char[len];
		d[0] = d[d.length-1] = '1';
		for(int i = 1 ; i < d.length - 1 ; i++) {
			int v = rand.nextInt(2);
			d[i] = (char) (v + '0');
		}
		return d ;
	}

	private boolean isJamCoin(char[] rcoin) {
		if ( rcoin[0] != '1' || rcoin[rcoin.length-1] != '1') return false;
		for(int base = 2 ; base <= 10 ; base++) {
			BigInteger valueInBase = convertToBaseValue(rcoin,base);
			Integer fact = possibleFactor(valueInBase); //there would be a case that a number is NOT a prime, but still pass our test, and this function give back NULL
			if ( fact == null) return false;
		}
		return true;
	}

	private Integer possibleFactor(BigInteger x) {
		for(int p : primes) {
			BigInteger pBig = new BigInteger(""+p);
			if ( x.compareTo(pBig) <= 0 ) return null;
			BigInteger remainder = x.remainder(pBig);
			if (remainder.equals(ZERO)) return p;
		}
		return null;
	}

	private BigInteger convertToBaseValue(char[] rcoin, int base) {
		int[] d = new int[rcoin.length];
		for(int i = 0 ; i < d.length ; i++)
			d[i] = rcoin[i] - '0';
		BigInteger num = new BigInteger(""+0);
		BigInteger p = new BigInteger(""+1);
		for(int i = 0; i < d.length ; i++) {
			int digit = d[d.length-i-1];
			num = num.add((new BigInteger(""+digit)).multiply(p));
			p = p.multiply(new BigInteger(""+base));
		}
		return num;
	}

	public class MyReader implements AutoCloseable {

		private BufferedReader br;
		private int index;
		private String[] words;

		public MyReader(BufferedReader br) {
			this.br = br;
		}
				
		public Integer nextInt() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return Integer.parseInt(s);
			} catch (Exception e) {
				e.printStackTrace();
				return null;
			}
		}				
		
		private String getNextWord() throws IOException {
			if ( words == null || index >= words.length) {
				String line = br.readLine();
				if ( line == null ) return null;
				index = 0;
				words = line.split(" ");
			}
			return words[index++];
		}

		public String nextString() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return s;
			} catch (IOException e) {
				e.printStackTrace();
				return null;
			}
		}

		@Override
		public void close() throws Exception {
			try { this.br.close(); } catch (Exception e) {}
		}
	}
}
