package be.filip.coinjam;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class DigitSequence {

	private int[] digits;

	public DigitSequence(int[] tempDigits) {
		// Dangerous, should be copied
		this.digits = new int[tempDigits.length];

		for (int i = 0; i < tempDigits.length; i++) {
			this.digits[i] = tempDigits[i];
		}
	}

	public static DigitSequence fromNumberInBase(BigInteger big, int base) throws Exception {

		List<Integer> tempDigits = new LinkedList<>();

		BigInteger moduloNumber = BigInteger.valueOf(base);
		BigInteger remainder = big;

		while (remainder.compareTo(BigInteger.ZERO) > 0) {

			BigInteger tempNumber = remainder.mod(moduloNumber);

			if (tempNumber.compareTo(BigInteger.ZERO) < 0) {
				throw new Exception("Implementation error, tempNumber negative");
			}

			if (tempNumber.compareTo(moduloNumber) > 0) {
				throw new Exception("Implementation error tempNumber bigger than modulo number");
			}

			tempDigits.add(tempNumber.intValue());

			remainder = remainder.subtract(tempNumber);

			if (remainder.mod(moduloNumber).compareTo(BigInteger.ZERO) != 0) {
				throw new Exception("Implementation error");
			}

			remainder = remainder.divide(moduloNumber);
		}

		// Store them in reversed order
		int[] digitArray = new int[tempDigits.size()];
		for (int i = 0; i < digitArray.length; i++) {
			digitArray[i] = tempDigits.get(tempDigits.size() - 1 - i);
		}

		return new DigitSequence(digitArray);
	}

	/**
	 * Checks the following validity criteria: - Only contains 1's or 0's -
	 * First is a 1 and last is a 1 - The length is as it should be
	 * 
	 * @return
	 */
	public boolean isValid(int length) {

		boolean correctDigits = containsOnlyValids();
		boolean lengthIsCorrect = (length == this.digits.length);
		boolean firstAndLast = checkFirstAndLast();

		if (!correctDigits) {
			System.out.println("Wrong digits used");
		}
		if (!lengthIsCorrect) {
			System.out.println("Wrong length");
		}
		if (!firstAndLast) {
			System.out.println("Wrong first or last");
		}

		return correctDigits && lengthIsCorrect && firstAndLast;
	}

	private boolean checkFirstAndLast() {

		if (this.digits[0] == 1 && this.digits[this.digits.length - 1] == 1) {
			return true;
		} else {
			return false;
		}
	}

	private boolean containsOnlyValids() {
		for (int i = 0; i < this.digits.length; i++) {
			if (this.digits[i] != 0 && this.digits[i] != 1) {
				return false;
			}
		}
		return true;
	}

	public BigInteger valueInBase(int base) {

		BigInteger temp = BigInteger.valueOf(0);
		BigInteger bigBase = BigInteger.valueOf(base);

		for (int i = 0; i < digits.length; i++) {
			temp = temp.add(BigInteger.valueOf(digits[i]).multiply(bigBase.pow(this.digits.length - 1 - i)));
		}

		return temp;
	}

	/**
	 * Perform the multiplication and check that they are equal in all bases
	 * 
	 * @param seq2
	 * @return
	 * @throws Exception
	 */
	public DigitSequence multiply(DigitSequence seq2) throws Exception {
		DigitSequence prevResult = null;

		for (int base = 2; base <= 10; base++) {
			BigInteger product = valueInBase(base).multiply(seq2.valueInBase(base));
			DigitSequence resultSeq = fromNumberInBase(product, base);

			if (prevResult != null) {
				if (!prevResult.equals(resultSeq)) {
					throw new Exception(
							"Assumption error during multiplication of " + this.toString() + " and " + seq2.toString());
				}
			}
			prevResult = resultSeq;
		}

		return prevResult;
	}

	@Override
	public String toString() {

		StringBuilder builder = new StringBuilder();

		for (int i = 0; i < digits.length; i++) {
			builder.append(digits[i] + "");
		}

		return builder.toString();
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
		DigitSequence other = (DigitSequence) obj;
		if (!Arrays.equals(digits, other.digits))
			return false;
		return true;
	}

}
