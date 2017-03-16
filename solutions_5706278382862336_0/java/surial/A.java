import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		sc.useDelimiter("[\\s/]+");
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			long p = sc.nextInt();
			long q = sc.nextInt();
			System.out.printf("Case #%d: %s\n", t + 1, calc(p, q));
		}
	}
	
	private static final BigDecimal BASE = BigDecimal.valueOf(1L<<40);
	
	private static String calc(long p, long q) {
		BigDecimal bd;
		BigInteger normalizedP;
		try {
			bd = BigDecimal.valueOf(p).multiply(BASE).divide(BigDecimal.valueOf(q));
			normalizedP = bd.toBigIntegerExact();
		} catch (ArithmeticException e) {
			return "impossible";
		}
		
		int plog = log2(Long.highestOneBit(normalizedP.longValue()));
		return "" + (40 - plog);
	}
	
	private static int log2(long input) {
		for (int r = 0; r < 64; r++) {
			if (1L<<r >= input) {
				return r;
			}
		}
		throw new IllegalArgumentException();
	}
}
