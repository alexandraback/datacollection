package QR;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.Random;
import java.util.Scanner;

public class C {

	private static Scanner reader;
	private static PrintWriter writer;
	
	private static LinkedList<Integer> primes;
	
	public static LinkedList<Integer> sieveToLinkedList(int n) {
		boolean[] prime = sieve(n);
		LinkedList<Integer> P = new LinkedList<>();
		for(int i = 2; i <= n; i++) {
			if(prime[i]) P.add(i);
		}
		return P;
	}
	
	public static boolean[] sieve(int n) {
		boolean[] prime = new boolean[n + 1];
		for(int i = 2; i <= n; i++) prime[i] = true;
		for(int i = 2; i * i <= n; i++)      {      
			if(prime[i]) { 
				/*
				 * we can start at i * i because
				 * all multiples of i of the for i * k
				 * with k < i have already been crossed.
				 */
				for(int j = i; j * i <= n; j++) {
					prime[i * j] = false; 
				}
			}
		}
		return prime;
	}
	
	public static void main(String[] args) throws IOException {
		
		primes = sieveToLinkedList(65536);
		
		reader = new Scanner(new FileReader("input.in"));
		writer = new PrintWriter(new FileWriter("output.out"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			int N = reader.nextInt();
			int J = reader.nextInt();
			HashMap<Long, BigInteger[]> jamcoins = new HashMap<>();
			Random rnd = new Random();
			while(jamcoins.size() < J) {
				long x = (1l << (N - 1)) + 1;
				for(int i = 1; i < N - 1; i++) {
					if(rnd.nextBoolean()) {
						x |= (1l << i);
					}
				}
				if(!jamcoins.containsKey(x)) {
					System.out.println(jamcoins.size());
					BigInteger[] div = findDivisors(x);
					if(div != null) {
						jamcoins.put(x, div);
					}
				}
			}
			writer.println("Case #" + tc + ":");
			for(Entry<Long, BigInteger[]> e : jamcoins.entrySet()) {
				String div = Arrays.toString(e.getValue());
				div = div.substring(1, div.length() - 1);
				div = div.replace(",", "");
				writer.println(Long.toBinaryString(e.getKey()) + " " + div);
			}
		}
		reader.close();
		writer.close();
	}
	
	private final static BigInteger ZERO = new BigInteger("0");
    private final static BigInteger ONE  = new BigInteger("1");
    private final static BigInteger TWO  = new BigInteger("2");
    private final static SecureRandom random = new SecureRandom();

	
	public static BigInteger rho(BigInteger N) {
        BigInteger divisor;
        BigInteger c  = new BigInteger(N.bitLength(), random);
        BigInteger x  = new BigInteger(N.bitLength(), random);
        BigInteger xx = x;

        // check divisibility by 2
        if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;

        do {
        	x  =  x.multiply(x).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            divisor = x.subtract(xx).gcd(N);
        } while((divisor.compareTo(ONE)) == 0);

        return divisor;
    }
	
	static BigInteger[] findDivisors(long x) {
		BigInteger[] div = new BigInteger[9];
		for(int b = 2; b <= 10; b++) {
			BigInteger B = new BigInteger(Long.toBinaryString(x), b);
			if(B.isProbablePrime(80)) return null;
			else {
				div[b - 2] = rho(B);
			}
			/*
			BB[b - 2] = B;
			for(long d : primes) {
				if(B % d == 0) {
					div[b - 2] = d;
					break;
				}
			}
			if(div[b - 2] == 0) {
				return null;
			}
			*/
		}
		return div;
	}
	
}
