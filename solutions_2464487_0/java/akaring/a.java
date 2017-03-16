import java.util.*;
import java.math.*;

class Main {
	static BigInteger two = BigInteger.valueOf(2);
	public static boolean check(BigInteger n, BigInteger r, BigInteger t) {
		BigInteger v = n.multiply(two).add(r.multiply(two)).subtract(BigInteger.ONE);
		v = v.multiply(n);
		return v.compareTo(t) <= 0;
	}
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for (int index = 1; index <= T; ++index) {
			BigInteger r = cin.nextBigInteger();
			BigInteger t = cin.nextBigInteger();
			BigInteger low = BigInteger.ZERO;
			BigInteger high = t;
			while (low.compareTo(high) < 0) {
				BigInteger mid = low.add(high).divide(two).add(BigInteger.ONE);
				if (check(mid, r, t) == true) {
					low = mid;
				} else {
					high = mid.subtract(BigInteger.ONE);
				}
			}
			System.out.println("Case #" + index + ": " + low);
		}
	}
}
