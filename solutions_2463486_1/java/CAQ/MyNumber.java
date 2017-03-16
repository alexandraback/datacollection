package gcj2013;

public class MyNumber {
	private int[] digits = new int[250];
	private int length = 0;

	// "12345" stores to [5, 4, 3, 2, 1, 0, 0, ...]
	public MyNumber(String s) {
		length = s.length();
		for (int i = 0; i < this.length; i++)
			digits[i] = s.charAt(this.length - i - 1) - '0';
	}

	public MyNumber(long l) {
		this(l + "");
	}

	Long longValue() {
		long v = 0;
		for (int i = length - 1; i >= 0; i--) {
			v = v * 10 + digits[i];
		}
		return v;
	}

	@Override
	public String toString() {
		StringBuffer sb = new StringBuffer();
		for (int i = length - 1; i >= 0; i--) {
			sb.append(digits[i]);
		}
		return sb.toString();
	}

	public int getDigit(int index) {
		return digits[index];
	}

	public int length() {
		return this.length;
	}

	boolean isPalindrome() {
		if (length == 1)
			return true;
		int k = length / 2;
		for (int i = 0; i < k; i++) {
			if (digits[i] != digits[length - i - 1])
				return false;
		}
		return true;
	}

	// sqrt(), then floor()
	public MyNumber sqrtFloor() {
		return new MyNumber(
				new Double(Math.floor(Math.sqrt(longValue()))).longValue());
	}

	// sqrt(), then ceil()
	public MyNumber sqrtCeil() {
		return new MyNumber(
				new Double(Math.ceil(Math.sqrt(longValue()))).longValue());
	}

	public MyNumber square() {
		long l = longValue();
		return new MyNumber(l * l);
	}

	// returns a palindrome that is greater than the given number
	public MyNumber nextPalindrome() {
		int k = length / 2;
		if (k == 0) { // 1 .. 9
			long val = longValue();
			return (val < 9 ? new MyNumber(val + 1) : new MyNumber(11));
		}
		String s = toString();
		String left = s.substring(0, k);
		String reverseLeft = "";
		for (int i = 0; i < k; i++) {
			reverseLeft = left.charAt(i) + reverseLeft;
		}
		if (length % 2 == 0) {
			String right = s.substring(k);
			if (new Long(right) < new Long(reverseLeft))
				// 123|320 => 123|321
				return new MyNumber(left + reverseLeft);
			String nextLeft = (new Long(left) + 1) + "";
			String reverseNextLeft = "";
			for (int i = 0; i < nextLeft.length(); i++) {
				reverseNextLeft = nextLeft.charAt(i) + reverseNextLeft;
			}
			if (nextLeft.length() > k)
				// 999|999 => 100|0|001
				return new MyNumber(nextLeft.substring(0, k) + "0"
						+ reverseNextLeft.substring(1));
			// 123|321, 123|322 => 124|421
			return new MyNumber(nextLeft + reverseNextLeft);
		} else {
			int middle = s.charAt(k) - '0';
			String right = s.substring(k + 1);
			if (new Long(right) < new Long(reverseLeft))
				// 123|4|320 => 123|4|321
				return new MyNumber(left + middle + reverseLeft);
			// try to increase the middle
			int nextMiddle = middle + 1;
			if (nextMiddle <= 9)
				// 123|4|321, 123|4|322 => 123|5|321
				return new MyNumber(left + nextMiddle + reverseLeft);
			// try to increase the left
			String nextLeft = (new Long(left) + 1) + "";
			String reverseNextLeft = "";
			for (int i = 0; i < nextLeft.length(); i++) {
				reverseNextLeft = nextLeft.charAt(i) + reverseNextLeft;
			}
			if (nextLeft.length() > k)
				// 999|9|999 => 1000|0001
				return new MyNumber(nextLeft + reverseNextLeft);
			// 123|9|321 => 124|0|421
			return new MyNumber(nextLeft + "0" + reverseNextLeft);
		}
	}

	/**
	 * check if the current number is less than (or equal to?) the parameter
	 * 
	 * @param n
	 * @param canEqual
	 *            if set to true, returns true when equal
	 * @return
	 */
	public boolean less(MyNumber n, boolean canEqual) {
		if (length < n.length)
			return true;
		if (length > n.length)
			return false;
		for (int i = length - 1; i >= 0; i--) {
			if (digits[i] < n.digits[i])
				return true;
			if (digits[i] > n.digits[i])
				return false;
		}
		// now equal
		return canEqual;
	}

}
