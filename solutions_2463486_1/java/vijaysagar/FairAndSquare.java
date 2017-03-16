package in.codejam;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FairAndSquare {

	public static Scanner in;

	public static void main(String[] args) {
		in = new Scanner(System.in);
		in.useDelimiter("\\s+");
		int testCases = readNum();
		List<String> results = new ArrayList<String>();
		List<String> temp = new ArrayList<String>();
		for (int i = 1; i <= testCases; i++) {
			BigInteger A = new BigInteger(in.next());
			BigInteger B = new BigInteger(in.next());
			BigInteger start = findSquareRoot(A, BigInteger.ONE, A);
			BigInteger end = findSquareRoot(B, BigInteger.ONE, B);
			temp.add("Start="+start+";End"+end);
			BigInteger x = new BigInteger(start.toString());
			if(!isPalindrome(x))
				x = getNextPalindrome(x);
			long result = 0;
			while (x.compareTo(end) <= 0) {
				BigInteger t = x.multiply(x);
				if (isPalindrome(t) && t.compareTo(A)>=0 && t.compareTo(B)<=0) {
					temp.add((x+ " "+x.multiply(x)));
					result++;
				}
				x = getNextPalindrome(x);
			}
			results.add("Case #" + i + ": " + result);
		}
		for (String s : results)
			System.out.println(s);

	}

	// Find a smallest number x whose square is greater than or equal to current
	// num.
	public static BigInteger findSquareRoot(BigInteger number, BigInteger low,
			BigInteger high) {
		if (low.compareTo(high) > 0)
			return low;
		BigInteger mid = low.add(high);
		mid = mid.divide(BigInteger.valueOf(2));
		BigInteger temp = mid.multiply(mid);
		BigInteger mid2 = mid.add(BigInteger.ONE);
		mid2 = mid2.multiply(mid2);
		if (temp.compareTo(number) <= 0 && mid2.compareTo(number) > 0)
			return mid;
		if (temp.compareTo(number) < 0)
			return findSquareRoot(number, mid.add(BigInteger.ONE), high);
		else
			return findSquareRoot(number, low, mid.subtract(BigInteger.ONE));
	}

	public static int readNum() {
		int i = in.nextInt();
		return i;
	}

	public static BigInteger readBigInt() {
		String str = in.next();
		return new BigInteger(str);
	}

	public static BigInteger getNextPalindromeIfNotAlready(BigInteger bi) {
		BigInteger pal = getNextPalindrome(bi);
		while (pal.compareTo(bi) < 0) {
			pal = getNextPalindrome(pal);
		}
		return pal;
	}

	// This assumes that bi is a palindrome. If it is not, call twice.
	public static BigInteger getNextPalindrome(BigInteger bi) {
		if (bi.compareTo(BigInteger.valueOf(10)) < 0) {
			return getNextPalindrome(bi.longValue());
		}
		int length = bi.toString().length();
		if ((length % 2) == 0) {
			String msb = bi.toString().substring(0, length / 2);
			String lsb = bi.toString().substring(length / 2);
			BigInteger temp = new BigInteger(msb);
			if (!new StringBuffer(msb).reverse().toString().equals(lsb)) {
				BigInteger probResult = new BigInteger(msb
						+ new StringBuffer(msb).reverse());
				if (probResult.compareTo(bi) > 0)
					return probResult;
			}
			if (temp.add(BigInteger.ONE).toString().length() == msb.length()) {
				temp = temp.add(BigInteger.ONE);
				return new BigInteger(temp.toString()
						+ new StringBuffer(temp.toString()).reverse());
			} else {
				temp = temp.add(BigInteger.ONE);
				String s = temp.toString();
				msb = s.substring(0, s.length() - 1);
				return new BigInteger(msb + "0"
						+ new StringBuffer(msb).reverse());
			}
		} else {
			String msb = bi.toString().substring(0, length / 2);
			String lsb = bi.toString().substring(length / 2 + 1);
			BigInteger temp = new BigInteger(msb);
			int middleNum = Integer.parseInt(bi.toString().substring(
					length / 2, length / 2 + 1));
			if (!new StringBuffer(msb).reverse().toString().equals(lsb)) {
				BigInteger probResult = new BigInteger(msb + middleNum
						+ new StringBuffer(msb).reverse());
				if (probResult.compareTo(bi) > 0)
					return probResult;
			}
			if (middleNum == 9) {
				if (new BigInteger(msb).add(BigInteger.ONE).toString().length() == msb
						.length()) {
					temp = temp.add(BigInteger.ONE);
					return new BigInteger(temp.toString() + "0"
							+ new StringBuffer(temp.toString()).reverse());
				} else {
					temp = temp.add(BigInteger.ONE);
					return new BigInteger(temp.toString()
							+ new StringBuffer(temp.toString()).reverse());
				}
			} else {
				return new BigInteger(msb + (middleNum + 1)
						+ new StringBuffer(msb).reverse());
			}
		}
	}

	private static boolean isPalindrome(BigInteger bi) {
		if (bi.compareTo(BigInteger.valueOf(10)) < 0)
			return true;
		int length = bi.toString().length();
		if (length % 2 == 0) {
			String msb = bi.toString().substring(0, length / 2).trim();
			String lsb = new StringBuffer(bi.toString().substring(length / 2)
					.trim()).reverse().toString();
			if (msb.equals(lsb))
				return true;
		} else {
			String msb = bi.toString().substring(0, length / 2);
			String lsb = new StringBuffer(bi.toString()
					.substring(length / 2 + 1).trim()).reverse().toString();
			if (msb.equals(lsb))
				return true;
		}
		return false;
	}

	private static BigInteger getNextPalindrome(long longValue) {
		if (longValue < 9)
			return BigInteger.valueOf(longValue + 1);
		if (longValue == 9)
			return BigInteger.valueOf(11);
		return null;
	}
}
