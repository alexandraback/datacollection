import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Scanner;

public class ProblemCAttempt2 {	
	public static final BigInteger zero = BigInteger.valueOf(0);
	public static final BigInteger one = BigInteger.valueOf(1);
	public static final BigInteger two = BigInteger.valueOf(2);
	public static final BigInteger ten = BigInteger.valueOf(10);
	
	public static String next(String coin) {
		int n = coin.length();
		char[] nextCoin = coin.toCharArray();
		
		for (int i = n - 2; i > 0; i--) {
			if (coin.charAt(i) == '0') {
				nextCoin[i] = '1';
				break;
			} else if (coin.charAt(i) == '1') {
				nextCoin[i] = '0';
				if (i == 1) {
					//return null;
				}
			}
		}
		
		return new String(nextCoin);
	}
	
	public static BigInteger readBaseN(String coin, int base) {
		BigInteger num = zero;
		BigInteger base_ = BigInteger.valueOf(base);
		int n = coin.length();
		
		for (int i = 0; i < coin.length(); i++) {
			if (coin.charAt(i) == '1') {
				num = num.add(base_.pow(n - i - 1));
			}
		}
		
		return num;
	}
	
	public static void checkPrime(Hashtable<BigInteger, BigInteger> composites, HashSet<BigInteger> primes, BigInteger num, PrintWriter writer) {
		
		BigInteger factor = BigInteger.valueOf(2);
		boolean isPrime = true;
		
		while (factor.pow(2).compareTo(num) <= 0) {
			
			if (num.mod(factor).equals(zero)) {
				composites.put(num, factor);
				isPrime = false;
				break;
			}
			
			if (factor.equals(two)) {
				factor = factor.add(one);
			} else {
				factor = factor.add(two);
			}
		}
		
		if (isPrime) {
			primes.add(num);
		}
	}
	
	public static void next_case(long case_num, PrintWriter writer, Scanner scanner) {
		int n = scanner.nextInt();
		int j = scanner.nextInt();
		
		Hashtable<BigInteger, BigInteger> composites = new Hashtable<BigInteger, BigInteger>();
		HashSet<BigInteger> primes = new HashSet<BigInteger>();
		String coin = ten.pow(n - 1).add(one).toString();
		int count = 0;
		
		writer.println("Case #" + case_num + ":");
		
		while (count < j) {
			boolean is_valid = true;
			String proof = "";
			
			for (int base = 2; base <= 10; base++) {
				BigInteger num = readBaseN(coin, base);
				
				if (!composites.containsKey(num) && !primes.contains(num)) {
					checkPrime(composites, primes, num, writer);
				}
				
				if (composites.containsKey(num)) {
					proof += " " + composites.get(num);
				} else {
					is_valid = false;
					break;
				}
			}
			
			if (is_valid) {	
				writer.println(coin + proof);
				count++;
			}
			
			coin = next(coin);
		}
	}
	
	public static void main(String[] args) throws Exception {
		PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
		Scanner scanner = new Scanner(new File("input.in"));
		int t = scanner.nextInt();
		
		for (int i = 0; i < t; i++) {
			next_case(i+1, writer, scanner);
			
			if (i < t - 1) {
				writer.println("");
			}
		}
		
		writer.close();
		scanner.close();
	}
}
