import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class elf {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/elf_small.in"));
		PrintStream output = new PrintStream(new File("output/elf_small.out"));
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
			if (!den.and(den.negate()).equals(den)) {
				out.println("impossible");
			} else {
				int genUp = 0;
				while (num.compareTo(BigInteger.ONE.shiftLeft(genUp)) >= 0) genUp++;
				out.println(den.toString(2).length() - genUp);
			}
		}
		output.close();
	}
	
	public static BigInteger gcd(BigInteger a, BigInteger b) {
		return b.equals(BigInteger.ZERO) ? a : gcd(b, a.mod(b));
	}
}