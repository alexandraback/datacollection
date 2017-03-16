import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;
import java.math.BigDecimal;
import java.math.MathContext;

public class ProblemA {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("A-small-attempt0.in"));
		FileWriter fstream = new FileWriter("A-small-attempt0.out");
		BufferedWriter out = new BufferedWriter(fstream);
		int numCases = in.nextInt();
		in.nextLine();
		for (int i = 0; i < numCases; i++) {
			String nextLine = in.nextLine();
			String[] strs = nextLine.split(" ");
			BigDecimal r = new BigDecimal(strs[0]), t = new BigDecimal(strs[1]);
			out.write("Case #" + String.valueOf(i + 1) + ": "
					+ String.valueOf(decideNum(r, t)) + "\n");
		}
		out.close();
		in.close();
	}

	public static BigInteger decideNum(BigDecimal r, BigDecimal t) {
		BigDecimal a = new BigDecimal("2"), b = r.multiply(new BigDecimal("2"))
				.add(new BigDecimal("3")), c = (r.multiply(new BigDecimal("2"))
				.add(new BigDecimal("1")).subtract(t));
		BigDecimal enumerator = b.multiply(new BigDecimal("-1")).add(
				sqrt(b.pow(2).subtract(
						a.multiply(c).multiply(new BigDecimal("4")))));
		BigDecimal denominator = a.multiply(new BigDecimal("2"));
		BigDecimal result = enumerator.divide(denominator);
		return result.toBigInteger().add(new BigInteger("1"));
	}

	public static BigDecimal sqrt(BigDecimal num) {
		if (num.compareTo(BigDecimal.ZERO) < 0) {
			return BigDecimal.ZERO;
		}
		BigDecimal x = num.divide(new BigDecimal("2"), MathContext.DECIMAL128);
		while (x.subtract(x = sqrtIteration(x, num)).abs()
				.compareTo(new BigDecimal("0.0000000001")) > 0)
			;
		return x;
	}

	private static BigDecimal sqrtIteration(BigDecimal x, BigDecimal n) {
		return x.add(n.divide(x, MathContext.DECIMAL128)).divide(
				new BigDecimal("2"), MathContext.DECIMAL128);
	}
}
