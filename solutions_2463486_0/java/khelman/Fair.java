package pl.helman.codejam.fair;

import static java.math.BigInteger.ONE;
import static java.math.BigInteger.TEN;
import static java.math.BigInteger.ZERO;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class Fair {

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\cj\\fair.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter fo = new FileWriter("d:\\cj\\fair.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		mainLoop: for (int i = 1; i <= t; i++) {
			
			// read lawn size
			line = br.readLine().trim();
			String[] elems = line.split(" ");
			BigInteger a = new BigInteger(elems[0]);
			BigInteger b = new BigInteger(elems[1]);

			PalindromGenerator palindromGenerator = new PalindromGenerator();
			
			long ret = 0;
			while(true) {				
				BigInteger palindrom = palindromGenerator.nextPalindrom();
				
				BigInteger square = palindrom.multiply(palindrom);
				if (square.compareTo(b) > 0) {
					break;
				}
				
				if (square.compareTo(a) >= 0 && isPalindrome(square)) {
					ret++;
					System.out.println(square.toString());
				}
			}

			fo.write("Case #" + i + ": " + ret + "\n");
		}

		fr.close();
		fo.close();

	}
	
	private static boolean isPalindrome(BigInteger x) {
		
		String str = x.toString();

		for (int i = 0; 2 * i < str.length(); i++) {
			if (str.charAt(i) != str.charAt(str.length() - i - 1)) {
				return false;
			}
		}
		
		return true;
	}

	private static class PalindromGenerator {

		BigInteger xLimit = TEN;
		BigInteger x = ZERO;
		BigInteger nLimit = ONE;
		BigInteger n = ZERO;

		BigInteger nextPalindrom() {
			x = x.add(ONE);
			if (x.equals(xLimit)) {
				n = n.add(ONE);
				x = ZERO;
			}

			if (n.equals(nLimit)) {
				if (xLimit.equals(ONE)) {
					n = nLimit.divide(TEN);
					xLimit = TEN;
				} else {
					xLimit = ONE;
					nLimit = nLimit.multiply(TEN);
					
					System.out.println("(" + nLimit.toString().length() + ")");
				}
			}

			return n.multiply(nLimit).multiply(xLimit).add(x.multiply(nLimit))
					.add(reverseInteger(n));
		}

		private BigInteger reverseInteger(BigInteger x) {
			BigInteger ret = BigInteger.ZERO;

			while (!x.equals(BigInteger.ZERO)) {
				BigInteger[] divideAndRemainder = x
						.divideAndRemainder(BigInteger.TEN);
				ret = ret.multiply(BigInteger.TEN).add(divideAndRemainder[1]);
				x = divideAndRemainder[0];
			}

			return ret;
		}

	}

}
