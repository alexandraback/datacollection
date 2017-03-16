import java.util.Arrays;

public class CoinJam {

	public static void main(String[] args) {

		long count = 0, number, divisior;
		String x = "1000000000000001";
		long value[] = new long[9];
		System.out.println("Case #1:");
		while (count != 50) {
			Arrays.fill(value, 0);
			for (int i = 2; i <= 10; i++) {
				number = Long.parseLong(x, i);
				divisior = getDivisior(number);
				if (divisior != 0 && divisior != number) {
					value[i - 2] = divisior;
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
			number = Long.parseLong(x, 2);
			number += 2;
			x = Long.toBinaryString(number);
		}
	}

	private static boolean checkValue(long[] value) {
		for (int i = 0; i < value.length; i++) {
			if (value[i] == 0)
				return false;
		}
		return true;
	}

	private static long getDivisior(long number) {
		if (number % 2 == 0)
			return 2;
		for (long i = 3; i * i <= number; i += 2) {
			if (number % i == 0)
				return i;
		}
		return 0;
	}

}
