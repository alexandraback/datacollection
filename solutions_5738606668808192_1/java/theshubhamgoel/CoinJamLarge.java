import java.math.BigInteger;

public class CoinJamLarge {

	static BigInteger two = new BigInteger("2");

	public static void main(String[] args) {

		long count = 0;
		BigInteger number, divisior;
		String x = "10000100000000000000000000000001";
		BigInteger value[] = new BigInteger[9];
		System.out.println("Case #1:");
		while (count != 500) {
			for (int i = 0; i < value.length; i++) {
				value[i] = BigInteger.ZERO;
			}
			for (int i = 2; i <= 10; i++) {
				number = new BigInteger(x, i);
				if (number.isProbablePrime(1000000000)) {
					break;
				} else {
					divisior = getDivisior(number);
					if (!divisior.equals(BigInteger.ZERO) && !divisior.equals(number)) {
						value[i - 2] = divisior;
					}
				}
			}
			if (checkValue(value)) {
				System.out.print(x);
				for (int i = 0; i < value.length; i++) {
					System.out.print(" " + value[i]);
				}
				System.out.println();
				count++;
			}
			number = new BigInteger(x, 2);
			number = number.add(two);

			x = number.toString(2);
		}
	}

	private static boolean checkValue(BigInteger[] value) {
		for (BigInteger bigInteger : value) {
			if (bigInteger.equals(BigInteger.ZERO))
				return false;
		}
		return true;
	}

	private static BigInteger getDivisior(BigInteger number) {
		if (number.mod(two).equals(BigInteger.ZERO))
			return two;

		for (BigInteger i = new BigInteger("3"); i.multiply(i).compareTo(number) < 1; i = i.add(two)) {
			if (number.mod(i).equals(BigInteger.ZERO))
				return i;
			if (i.compareTo(new BigInteger("1000000")) == 1) {
				break;
			}
		}
		return BigInteger.ZERO;
	}

}
