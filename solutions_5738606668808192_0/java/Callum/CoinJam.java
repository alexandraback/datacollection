import java.io.PrintWriter;

public class CoinJam {

	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter("C-small.out");
		
		pw.println("Case #1:");
		
		int found = 0;
		for (long i = 0; found < 50 && i < Math.pow(2, 14); i++) {
			String bin = Long.toBinaryString(i);
			
			while (bin.length() < 14) {
				bin = "0" + bin;
			}
			
			bin = "1" + bin + "1";
			
			long[] divisors = new long[9];
			for (int base = 2; base <= 10; base++) {
				long q = Long.parseLong(bin, base);
				
				long p = isPrime(q); 
				if (p != -1) {
					divisors[base - 2] = p;
				} else {
					break;
				}
			}
			
			if (divisors[8] != 0) {
				pw.printf("%s %d %d %d %d %d %d %d %d %d%n", bin, divisors[0], divisors[1], divisors[2], divisors[3], divisors[4], divisors[5], divisors[6], divisors[7], divisors[8]);
				found++;
			}
		}
		
		pw.close();
	}
	
	static long isPrime(long l) {
		if (l == 2 || l == 3) {
			return -1;
		}
		if (l % 2 == 0) {
			return 2;
		}
		if (l % 3 == 0) {
			return 3;
		}
		for (long i = 6; (i - 1) <= Math.sqrt(l); i+=6) {
			if (l % (i - 1) == 0) {
				return i - 1;
			}
			if (l % (i + 1) == 0) {
				return i + 1;
			}
		}
		return -1;
	}
}
