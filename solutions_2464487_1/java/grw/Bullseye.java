package codejam;

import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye extends CodeJam.Problem {

	public static void main(String[] args) throws Exception {
		CodeJam.runBatch(new Bullseye(), "A-large"); // "C-large", "C-small-attempt0"
	}

	@Override
	protected Object solveCase(Scanner scanner) {
		return count(readCase(scanner));
	}

	private static BigInteger TWO = BigInteger.valueOf(2L);
	private static BigInteger FOUR = TWO.multiply(TWO);
	private static BigInteger EIGHT = FOUR.multiply(TWO);
	
	private Object count(Long[] readCase) {
		BigInteger r = BigInteger.valueOf(readCase[0]);
		BigInteger t = BigInteger.valueOf(readCase[1]);
		BigInteger d = r.multiply(TWO).subtract(BigInteger.ONE);
		BigInteger delta = d.multiply(d).add(t.multiply(EIGHT));
		BigInteger deltaRoot = squareRoot(delta).floor;
		BigInteger b = BigInteger.ZERO.subtract(r.multiply(TWO)).add(BigInteger.ONE);
		BigInteger x1 = b.add(deltaRoot).divideAndRemainder(FOUR)[0];
		BigInteger x2 = b.subtract(deltaRoot).divideAndRemainder(FOUR)[0];
		if (x1.compareTo(x2)>0)
			return x1;
		else
			return x2;
	}

	private Long[] readCase(Scanner scanner) {
		long r, t;
		r = scanner.nextLong();
		t = scanner.nextLong();
		scanner.nextLine();
		Long[] p = new Long[2];
		p[0] = r;
		p[1] = t;
		return p;
	}
	
	private FloorAndCeil<PalindromicRoot> palindromicRoot(int base, BigInteger a) {
		String strA = a.toString(base);
		int len = strA.length();
		boolean even = len % 2 == 0;
		int take = (len + (even?0:1))/2;
		String p = strA.substring(0, take);
		PalindromicRoot proot = new PalindromicRoot(BigInteger.valueOf(base), even, new BigInteger(p));
		int cmp = proot.palindrome().compareTo(a);
		if (cmp == 0)
			return new FloorAndCeil<PalindromicRoot>(proot, proot);
		if (cmp > 0) {
			return new FloorAndCeil<PalindromicRoot>(proot.decrement(), proot);
		} else {
			return new FloorAndCeil<PalindromicRoot>(proot, proot.increment());
		}
	}

	public static boolean isPalindrome(int base, BigInteger a) {
		String strA = a.toString(base);
		int len = strA.length();
		boolean even = len % 2 == 0;
		int take = (len + (even?0:1))/2;
		for (int i = 0; i < take; i++)
			if (strA.charAt(i) != strA.charAt(len-1-i))
				return false;
		return true;
	}

	private static class PalindromicRoot implements Comparable<PalindromicRoot> {
		public final BigInteger base;
		public final int intBase;
		public final boolean even;
		public final BigInteger val;
		
		public PalindromicRoot(BigInteger b, boolean e, BigInteger v) {
			base = b;
			intBase = b.intValue();
			even = e;
			val = v;
		}
		
		public BigInteger palindrome() {
			String strVal = val.toString(intBase);
			int take = strVal.length() - (even?0:1);
			BigInteger r = val;
			for (int i = take-1; i >= 0; i--) {
				BigInteger digit = BigInteger.valueOf(strVal.charAt(i)-'0'); // TODO bases > 10 won't work
				r = r.multiply(base).add(digit);
			}
			return r;
		}

		public PalindromicRoot increment() {
			String strVal = val.toString(intBase);
			BigInteger valInc = val.add(BigInteger.ONE);
			String strValInc = valInc.toString(intBase);
			if (strVal.length() == strValInc.length())
				return new PalindromicRoot(base, even, valInc);
			if (even) {
				return new PalindromicRoot(base, false, valInc);
			} else {
				return new PalindromicRoot(base, true, valInc.divide(base));
			}
		}

		public PalindromicRoot decrement() {
			String strVal = val.toString(intBase);
			BigInteger valDec = val.subtract(BigInteger.ONE);
			if (even && valDec.equals(BigInteger.ZERO))
				return new PalindromicRoot(base, false, base.subtract(BigInteger.ONE));
			String strValDec = valDec.toString(intBase);
			if (strVal.length() == strValDec.length())
				return new PalindromicRoot(base, even, valDec);
			if (even) {
				return new PalindromicRoot(base, false, valDec.multiply(base).subtract(BigInteger.ONE));
			} else {
				return new PalindromicRoot(base, true, valDec);
			}
		}
		
		@Override
		public String toString() {
			return "" + intBase + "-" + (even?"E":"O") + "-" + val.toString(intBase);
		}

		@Override
		public int compareTo(PalindromicRoot o) {
			if (intBase != o.intBase)
				throw new UnsupportedOperationException();
			String strVal = val.toString(intBase);
			String strOVal = o.val.toString(intBase);
			int cmp = strVal.length() - strOVal.length();
			if (cmp == 0) {
				if (even == o.even) {
					cmp = val.compareTo(o.val);
				} else {
					cmp = even?1:-1;
				}
			}
			return cmp;
		}
	}

	private static class FloorAndCeil<T> {
		public final T floor, ceil;
		public FloorAndCeil(T f, T c) {
			floor = f;
			ceil = c;
		}
	}
	
	private FloorAndCeil<BigInteger> squareRoot(BigInteger a) {
		if (BigInteger.ZERO.equals(a))
			return new FloorAndCeil<BigInteger>(BigInteger.ZERO, BigInteger.ZERO);
		if (BigInteger.ONE.equals(a))
			return new FloorAndCeil<BigInteger>(BigInteger.ONE, BigInteger.ONE);
		BigInteger floor = BigInteger.ONE;
		BigInteger ceilPlusOne = floor.add(BigInteger.ONE);
		BigInteger ceil = a;
		while (!ceilPlusOne.equals(ceil)) {
			BigInteger mid = ceilPlusOne.add(ceil).shiftRight(1);
			int cmp = mid.pow(2).compareTo(a);
			if (cmp == 0)
				return new FloorAndCeil<BigInteger>(mid, mid);
			if (cmp > 0) {
				ceil = mid;
			} else {
				floor = mid;
				ceilPlusOne = floor.add(BigInteger.ONE);
			}
		}
		return new FloorAndCeil<BigInteger>(floor, ceil);
	}

}
