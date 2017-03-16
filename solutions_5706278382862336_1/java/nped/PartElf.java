import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;

public class PartElf {
	private static BufferedReader bufferedReader = new BufferedReader(
			new InputStreamReader(System.in));
	private static BigInteger TWO = new BigInteger("2");

	public static void main(String[] args) throws Exception {
		String line = bufferedReader.readLine();

		int cases = Integer.parseInt(line);

		for (int c = 1; c <= cases; c++) {
			solveCase(c);
		}
	}

	private static void solveCase(int c) throws Exception {
		String line = bufferedReader.readLine();
		String[] split = line.split("/");
		BigInteger P = new BigInteger(split[0]);
		BigInteger Q = new BigInteger(split[1]);

		int result = getMinGenerations(P.add(P), Q, 1);
		if (result == Integer.MAX_VALUE) {
			System.out.println("Case #" + c + ": impossible");
		} else {
			System.out.println("Case #" + c + ": " + result);
		}
	}

	private static int getMinGenerations(BigInteger P, BigInteger Q,
			int generations) {
		if (Q.remainder(TWO).compareTo(BigInteger.ZERO) > 0 || generations > 40) {
			return Integer.MAX_VALUE;
		}

		if (P.divide(Q).compareTo(BigInteger.ONE) >= 0) {
			try {
				BigDecimal r = new BigDecimal(P).divide(new BigDecimal(Q))
						.subtract(BigDecimal.ONE);
				if (r.equals(BigDecimal.ZERO)
						|| r.equals(BigDecimal.ONE)
						|| getMinGenerations((P.subtract(Q).multiply(TWO)), Q,
								generations) <= 40) {
					return generations;
				} else {
					return Integer.MAX_VALUE;
				}
			} catch (ArithmeticException e) {
				return Integer.MAX_VALUE;
			}
		} else {
			return getMinGenerations(P.add(P), Q, generations + 1);
		}
	}
}
