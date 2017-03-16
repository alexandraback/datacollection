import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class elf {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/elf_large.in"));
		PrintStream output = new PrintStream(new File("output/elf_large.out"));
		PrintStream out = output;
		int T = input.nextInt();
		input.nextLine();
		primary: for (int oncase = 1; oncase <= T; oncase++) {
			out.printf("Case #%d: ", oncase);
			String[] line = input.nextLine().split("/");
			BigInteger num = new BigInteger(line[0]);
			BigInteger den = new BigInteger(line[1]);
			BigInteger factor = gcd(num, den);
			num = num.divide(factor);
			den = den.divide(factor);
			if (!den.and(den.negate()).equals(den) || num.compareTo(den) > 0) {
				out.println("impossible");
			} else {
				BigInteger genUp = BigInteger.ZERO;
				while (num.compareTo(pow(BigInteger.valueOf(2), genUp)) >= 0) genUp = genUp.add(BigInteger.ONE);
				out.println(Math.max(1, den.toString(2).length() - genUp.longValue()-1));
			}
		}
		output.close();
	}
	
	public static BigInteger gcd(BigInteger a, BigInteger b) {
		return b.equals(BigInteger.ZERO) ? a : gcd(b, a.mod(b));
	}
	
	public static BigInteger pow(BigInteger base, BigInteger exp) {
		BigInteger res = base;
		BigInteger exp_ = exp;
		while (exp_.compareTo(BigInteger.ZERO) > 0) {
			res = res.multiply(base);
			exp_ = exp_.subtract(BigInteger.ONE);
		}
		return res;
	}
}