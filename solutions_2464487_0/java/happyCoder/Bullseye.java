import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {

	private BigInteger r;
	private BigInteger t;

	public Bullseye(BigInteger r, BigInteger t) {
		this.r = r;
		this.t = t;
	}

	public BigInteger bisection() {
		BigInteger l = BigInteger.ZERO;
		BigInteger h = t;
		BigInteger m = h.add(l).divide(BigInteger.valueOf(2));
		BigInteger v = t.subtract(r.add(m).multiply(BigInteger.valueOf(2))
				.subtract(BigInteger.ONE).multiply(m));
		while (v.compareTo(BigInteger.ZERO) != 0
				&& h.subtract(l).compareTo(BigInteger.ONE) > 0) {
			if (m == h) {
				l = m;
			} else if (m == l) {
				h = m;
			}
			if (v.compareTo(BigInteger.ZERO) < 0) {
				h = m;
			} else {
				l = m;
			}
			m = h.add(l).divide(BigInteger.valueOf(2));
			v = t.subtract(r.add(m).multiply(BigInteger.valueOf(2))
					.subtract(BigInteger.ONE).multiply(m));
		}
		if (v.compareTo(BigInteger.ZERO) == 0)
			return m;
		return l;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			for (int i = 1; i <= n; ++i) {
				BigInteger r = scanner.nextBigInteger();
				BigInteger t = scanner.nextBigInteger();
				System.out.printf("Case #%d: %s\n", i,
						new Bullseye(r, t).bisection());
			}
		}
	}

}
