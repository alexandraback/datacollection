import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Solution {

	static ArrayList<BigInteger> primes = new ArrayList<>();

	public static void main(String[] args) {
		makePrimes();
		Scanner sc = new Scanner(System.in);
		sc.nextInt();
		int N = sc.nextInt();
		int J = sc.nextInt();
		long lbound = 0x8001L;
		//long lbound = 0x21L;
		long ubound = 0xFFFFL;
		//long ubound = 0xFFL;
		if (N == 32) {
			lbound = 0x80000001L;
			ubound = 0xFFFFFFFFL;
		}
		
		System.out.println("Case #1:");
		int collected = 0;
		for (long i = lbound; collected < J && i <= ubound; i += 2) {
			String num = Long.toBinaryString(i);
			//System.out.println("Testing " + num);
			boolean composite = true;
			ArrayList<String> divisors = new ArrayList<>();
			for (int base = 2; composite == true && base <= 10; base++) {
				BigInteger target = new BigInteger(num, base);
				String val = getDivisor(target);
				//System.out.println("Testing " + num + " base " + base + " = " + Long.valueOf(num,base) + " div = " + val);
				if (val == null) {
					composite = false;
				}
				else {
					divisors.add(val);
				}
			}
			if (composite) {
				collected++;
				System.out.print(num);
				for (String div: divisors) {
					System.out.print(" " + div);
				}
				System.out.println();
			}
		}
	}
	
	private static void makePrimes() {
		primes.add(new BigInteger("2"));
		
		for (long i = 3; i < (1<<20); i += 2) {
			boolean prime = true;
			for (long div = 3; prime && div <= Math.sqrt(i); div += 2) {
				if (i % div == 0) prime = false;
			}
			if (prime) primes.add(new BigInteger(Long.toString(i)));
		}
		//System.out.println("primes found: " + primes.size());
	}
	public static String getDivisor(BigInteger val) {
		BigInteger zero = new BigInteger("0");
		for (BigInteger div: primes) {
			if (div.compareTo(val) >= 0) return null;
			if (val.mod(div).equals(zero)) return div.toString();
		}
		return null;
	}
}
