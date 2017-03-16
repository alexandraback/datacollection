import java.io.PrintWriter;
import java.math.BigInteger;

public class CoinJam {

	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter("C-large.out");
		
		pw.println("Case #1:");
		
		int found = 0;
		for (long i = 0; found < 500 && i < Math.pow(2, 14); i++) {
			String bin = Long.toBinaryString(i);
			
			while (bin.length() < 30) {
				bin = "0" + bin;
			}
			
			bin = "1" + bin + "1";
			
			long[] divisors = new long[9];
			for (int base = 2; base <= 10; base++) {
				BigInteger q = new BigInteger(bin, base);
				
				long p = isPrime(q); 
				if (p != -1) {
					divisors[base - 2] = p;
				} else {
					break;
				}
			}
			
			if (divisors[8] != 0) {
				pw.printf("%s %d %d %d %d %d %d %d %d %d%n", bin, divisors[0], divisors[1], divisors[2], divisors[3], divisors[4], divisors[5], divisors[6], divisors[7], divisors[8]);
				System.out.printf("%s %d %d %d %d %d %d %d %d %d%n", bin, divisors[0], divisors[1], divisors[2], divisors[3], divisors[4], divisors[5], divisors[6], divisors[7], divisors[8]);
				found++;
			}
		}
		
		pw.close();
	}
	
	static long isPrime(BigInteger q) {
		if (q.equals(b(2)) || q.equals(b(3))) {
			return -1;
		}
		if (q.mod(b(2)).equals(b(0))) {
			return 2;
		}
		if (q.mod(b(3)).equals(b(0))) {
			return 3;
		}
		for (BigInteger i = b(6);
			i.compareTo(b(1000000)) < 0 &&
			i.subtract(b(1)).multiply(i.subtract(b(1))).compareTo(q) < 0;
			i = i.add(b(6))) {
			if (q.mod(i.subtract(b(1))).equals(b(0))) {
				return i.subtract(b(1)).longValue();
			}
			if (q.mod(i.add(b(1))).equals(b(0))) {
				return i.add(b(1)).longValue();
			}
		}
		return -1;
	}
	
	static BigInteger b(long i) {
		return new BigInteger("" + i);
	}
}
