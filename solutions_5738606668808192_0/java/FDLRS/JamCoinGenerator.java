package be.filip.coinjam;

import java.math.BigInteger;
import java.util.LinkedList;
import java.util.List;

public class JamCoinGenerator {

	public static List<String> generateJamCoins(int length, int numberOf) throws Exception {

		int lengthOfDivisor = (int) (2 + Math.ceil(Math.log(numberOf) / Math.log(2)));
		int lengthOfBaseNumber = length - lengthOfDivisor + 1;
		List<String> lines = new LinkedList<>();

		DigitSequence baseNumber = createBaseNumber(lengthOfBaseNumber);

		for (int i = 0; i < numberOf; i++) {

			DigitSequence divisor = createProductNumber(i, lengthOfDivisor);

			if (!divisor.isValid(lengthOfDivisor)) {
				throw new Exception("Wrong generated divisor");
			}

			DigitSequence product = baseNumber.multiply(divisor);

			if (!product.isValid(length)) {
				// System.out.println(product.valueInBase(10).toString());
				throw new Exception("It is not valid");
			} else {
				String line = "";
				line = line + product.valueInBase(10).toString();

				for (int base = 2; base <= 10; base++) {
					line = line + " " + divisor.valueInBase(base).toString();

					BigInteger sanityCheck = product.valueInBase(base).remainder(divisor.valueInBase(base));
					if (sanityCheck.compareTo(BigInteger.ZERO) != 0) {
						throw new Exception("Sanity check failed");
					}

				}

				lines.add(line);
			}
		}

		return lines;
	}

	public static DigitSequence createProductNumber(int i, int lengthOfDivisor) throws Exception {

		int value = (int) (i * 2 + 1 + Math.pow(2, lengthOfDivisor - 1));
		return DigitSequence.fromNumberInBase(BigInteger.valueOf(value), 2);
	}

	private static DigitSequence createBaseNumber(int lengthOfBaseNumber) {

		int digits[] = new int[lengthOfBaseNumber];

		for (int i = 0; i < digits.length; i++) {
			if (i == 0 || i == digits.length - 1) {
				digits[i] = 1;
			} else {
				digits[i] = 0;
			}
		}

		return new DigitSequence(digits);
	}

}
