
import static java.math.BigInteger.ONE;
import static java.math.BigInteger.TEN;
import static java.math.BigInteger.ZERO;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		InputStream in = System.in;
		PrintStream out = System.out;
		if (args.length > 0) {
			try {
				in = new FileInputStream(args[0]);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner scanner = new Scanner(in);
		int cases = scanner.nextInt();
		for (int c = 1; c <= cases; ++c) {
			
			
			BigInteger count = ZERO;
			BigInteger lowbound = scanner.nextBigInteger();
			BigInteger highbound = scanner.nextBigInteger();
			
			out.format("Case #%d: ",c);
			
			BigInteger base = lowBase(lowbound);
			
			BigInteger fns;
			boolean oddAbove = false;
			boolean evenAbove = false;
			boolean evenBelow = true;
			while (true) {
				fns = makePalindrome(base, true);
				fns = fns.pow(2);
				if (!oddAbove) {
					oddAbove = fns.compareTo(lowbound) >= 0;
				}
				if (fns.compareTo(highbound) > 0)
					break;
				if (oddAbove && isPalindrome(fns))
					count = count.add(ONE);
				
				fns = makePalindrome(base, false);
				fns = fns.pow(2);
				if (!evenAbove) {
					evenAbove = fns.compareTo(lowbound) >= 0;
				}
				if (evenBelow) {
					evenBelow = fns.compareTo(highbound) <= 0;
				}
				if (evenAbove && isPalindrome(fns) && evenBelow)
					count = count.add(ONE);
				base = base.add(ONE);
			}
			out.println(count);
		}
	}
	
	private static BigInteger lowBase(BigInteger low) {
		int bits = low.bitLength();
		bits = (bits + 3)/4 + 1;
		final BigInteger TWO = ONE.add(ONE);
		BigInteger result = ZERO;
		BigInteger tmp;
		for(; 0 <= bits; bits--) {
			tmp = result.add(TWO.pow(bits));
			if (makePalindrome(tmp, false).pow(2).compareTo(low) < 0)
				result = tmp;
		}
		return result.add(ONE);
	}
	
	private static BigInteger highBase(BigInteger high) {
		int bits = high.bitLength();
		return ONE.add(ONE).pow(bits/4+1);
	}
	
	private static BigInteger makePalindrome(BigInteger base, boolean oddDigits) {
		LinkedList<Integer> digits = new LinkedList<>();
		BigInteger[] v = new BigInteger[2];
		v[0] = base;
		while (!v[0].equals(ZERO)) {
			v = v[0].divideAndRemainder(TEN);
			digits.add(v[1].intValue());
		}
		Iterator<Integer> it = digits.iterator();
		if (oddDigits && it.hasNext()) {
			it.next();
		}
		while (it.hasNext()) {
			base = base.multiply(TEN);
			base = base.add(BigInteger.valueOf(it.next().intValue()));
		}
		return base;
	}
	
	private static boolean isPalindrome(BigInteger base) {
		LinkedList<Integer> digits = new LinkedList<>();
		BigInteger[] v = new BigInteger[2];
		v[0] = base;
		while (!v[0].equals(ZERO)) {
			v = v[0].divideAndRemainder(TEN);
			digits.add(v[1].intValue());
		}
		while (digits.size() > 1) {
			if (!digits.pollFirst().equals(digits.pollLast())) {
				return false;
			}
		}
		return true;
	}
}
