package codejam.recyclednumbers;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class DigitsArray implements Comparable<DigitsArray> {

	private int[] digits;

	private DigitsArray() {
	}

	public DigitsArray(String numberAsString) {
		char[] charArray = numberAsString.toCharArray();
		this.digits = new int[charArray.length];
		for (int i = 0; i < digits.length; i++) {
			digits[i] = Integer.parseInt("" + charArray[i]);
		}
	}

	public DigitsArray(int[] digits) {
		this.digits = digits;
	}

	public DigitsArray(Integer number) {
		this(number.toString());
	}

	public int numberRecycles(DigitsArray minValue, DigitsArray maxValue) {
		Set<DigitsArray> correctRecycles = new HashSet<>();
		for (int i = 1; i < digits.length; i++) {
			if (digits[i] < digits[0] || digits[i] < minValue.digits[0]
					|| digits[i] > maxValue.digits[0]) {
				continue;
			}
			DigitsArray recycle = recycle(i);
			if (recycle.compareTo(this) > 0 && recycle.compareTo(minValue) >= 0
					&& recycle.compareTo(maxValue) <= 0) {
				correctRecycles.add(recycle);
			}
		}
		return correctRecycles.size();
	}

	private DigitsArray recycle(int recycleIndex) {
		DigitsArray result = new DigitsArray();
		int length = digits.length;
		result.digits = new int[length];
		for (int i = 0; i < length; i++) {
			result.digits[i] = digits[(i + recycleIndex) % length];
		}
		return result;
	}

	@Override
	public int compareTo(DigitsArray o) {
		if (digits.length > o.digits.length) {
			return 1;
		}
		if (digits.length < o.digits.length) {
			return -1;
		}
		for (int i = 0; i < digits.length; i++) {
			if (digits[i] > o.digits[i]) {
				return 1;
			}
			if (digits[i] < o.digits[i]) {
				return -1;
			}
		}
		return 0;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + Arrays.hashCode(digits);
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		DigitsArray other = (DigitsArray) obj;
		if (!Arrays.equals(digits, other.digits))
			return false;
		return true;
	}

}
