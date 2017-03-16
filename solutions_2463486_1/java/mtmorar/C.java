import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		backtrackResults = new ArrayList<BigInteger>();
		allNumbers = new ArrayList<BigInteger>();
		allNumbers.add(new BigInteger("0"));
		allNumbers.add(new BigInteger("1"));
		allNumbers.add(new BigInteger("4"));
		allNumbers.add(new BigInteger("9"));
		for (int i = 2; i < 52; ++i) {
			findResultsOfLength(i);
		}

		Scanner in = new Scanner(System.in);
		int numTests = in.nextInt();
		for (int test = 1; test <= numTests; ++test) {
			BigInteger a = in.nextBigInteger(), b = in.nextBigInteger();
			int count = 0;
			for (BigInteger i : allNumbers) {
				if (i.compareTo(a) >= 0 && i.compareTo(b) <= 0) {
					++count;
				}
			}
			System.out.println("Case #" + test + ": " + count);
		}
	}

	public static ArrayList<BigInteger> allNumbers;

	public static void findResultsOfLength(int n) {
		digits = new int[(int)Math.ceil(n / 2.0)];
		backtrackResults.clear();
		backtrack(0, n);
		Collections.sort(backtrackResults);
		for (BigInteger i : backtrackResults) {
			allNumbers.add(i.multiply(i));
		}
	}

	public static ArrayList<BigInteger> backtrackResults;
	public static int[] digits;

	public static void backtrack(int level, int numberLength) {
		int[] _digits = {0, 1, 2};
		for (int d : _digits) {
			digits[level] = d;
			if (testNumber(digits, numberLength)) {
				if (level < digits.length - 1) {
					backtrack(level + 1, numberLength);
					digits[level + 1] = 0;
				} else {
					backtrackResults.add(makeNumber(digits, numberLength));
				}
			}
		}
	}

	public static boolean testNumber(int[] digits, int length) {
		if (digits[0] == 0) {
			return false;
		} else {
			BigInteger x = makeNumber(digits, length);
			return isPalindrome(x.multiply(x));
		}
	}

	public static boolean isPalindrome(BigInteger x) {
		char[] s = x.toString().toCharArray();
		int n = s.length;
		for (int i = 0; i < n / 2; ++i) {
			if (s[i] != s[n - 1 - i]) {
				return false;
			}
		}
		return true;
	}

	public static BigInteger makeNumber(int[] digits, int length) {
		int[] digitsReversed = new int[digits.length];
		int[] result = new int[length];
		for (int i = 0; i < digits.length; ++i) {
			digitsReversed[i] = digits[digits.length - 1 - i];
			result[i] = digits[i];
		}
		if (length == 2 * digits.length) {
			for (int i = 0; i < digitsReversed.length; ++i) {
				result[i + digits.length] = digitsReversed[i];
			}
		} else if (length == 2 * digits.length - 1) {
			for (int i = 1; i < digitsReversed.length; ++i) {
				result[i - 1 + digits.length] = digitsReversed[i];
			}
		} else {
			throw new RuntimeException("MWHAHA");
		}
		String result2 = "";
		for (int d : result) {
			result2 += d;
		}
		return new BigInteger(result2);
	}
}
