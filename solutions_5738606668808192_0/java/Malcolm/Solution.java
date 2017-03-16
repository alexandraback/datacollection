import java.lang.*;
import java.util.*;
import java.io.*;
import java.math.BigInteger;
import java.security.SecureRandom;

public class Solution {

	private BigInteger ONE = new BigInteger("1");
	private BigInteger TWO = new BigInteger("2");
	private BigInteger TEN = new BigInteger("10");
	private BigInteger min;
	private BigInteger max;

	public Solution(int strlen) {
		this.min = min(strlen);
		this.max = max(strlen);
	}

	private BigInteger min(int strlen) {
		return TWO.pow(strlen - 1).add(ONE);
	}

	private BigInteger max(int strlen) {
		if (strlen == 1) { return ONE; }
		return TWO.pow(strlen - 1).add(max(strlen - 1));
	}

	private List<BigInteger> getDivisors(BigInteger bigInt) {
		List<BigInteger> divisors = new ArrayList<BigInteger>();
		String coin = bigInt.toString(2);
		for (int radix = 2; radix <= 10; radix++) {
			BigInteger val = new BigInteger(coin, radix);
			if (val.isProbablePrime(20)) { return null; }
			BigInteger divisor = PollardRho.rho(val, 20);
			if (divisor.equals(val) || divisor.equals(ONE)) { return null; }
			divisors.add(divisor);
		}
		return divisors;
	}

	public void solve(long n) {
		int found = 0;
		for (BigInteger i = min; i.compareTo(max) <= 0; i = i.add(TWO)) {
			List<BigInteger> divisors = getDivisors(i);
			if (divisors != null) {
				StringBuilder sb = new StringBuilder();
				sb.append(i.toString(2));
				for (BigInteger d: divisors) {
					sb.append(" " + d);
				}
				System.out.println(sb.toString());
				found++;
			}
			if (found >= n) { return; }
		}
	}

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
			int t = scanner.nextInt();
			for (int i = 1; i <= t; i++) {
				int n = scanner.nextInt();
				int j = scanner.nextInt();
				System.out.println("case #" + i + ":");
				Solution solution = new Solution(n);
				solution.solve(j);
			}
		}
	}
}

/**
 * http://introcs.cs.princeton.edu/java/99crypto/PollardRho.java.html
 */
class PollardRho {
    private final static BigInteger ZERO = new BigInteger("0");
    private final static BigInteger ONE  = new BigInteger("1");
    private final static BigInteger TWO  = new BigInteger("2");
    private final static SecureRandom random = new SecureRandom();

    public static BigInteger rho(BigInteger N, int maxInterations) {
        BigInteger divisor;
        BigInteger c  = new BigInteger(N.bitLength(), random);
        BigInteger x  = new BigInteger(N.bitLength(), random);
        BigInteger xx = x;

        // check divisibility by 2
        if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;

		int steps = 0;
        do {
            x  =  x.multiply(x).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            divisor = x.subtract(xx).gcd(N);
        } while(steps++ < maxInterations && (divisor.compareTo(ONE)) == 0);

        return divisor;
    }
}
