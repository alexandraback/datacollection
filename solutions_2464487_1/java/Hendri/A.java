import java.util.*;
import java.math.*;

class A {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for (int tt = 1; tt <= T; tt++){
			System.out.print("Case #" + tt + ": ");
			long r = input.nextLong();
			long t = input.nextLong();
			BigInteger t1 = new BigInteger(t+"");
			BigInteger r1 = new BigInteger(r+"");
			BigInteger lo = BigInteger.ONE;
			BigInteger hi = new BigInteger(t+"");
			BigInteger need = r1.add(BigInteger.ONE).pow(2).subtract(r1.pow(2));
			while (lo.compareTo(hi) != 0) {
				BigInteger mid = hi.add(lo).add(BigInteger.ONE);
				mid = mid.divide(new BigInteger("2"));
				BigInteger temp = mid.subtract(BigInteger.ONE);
				temp = temp.multiply(new BigInteger("4"));
				BigInteger end = need.add(temp);
				BigInteger sum = need.add(end);
				sum = sum.divide(new BigInteger("2")).multiply(mid);
				if (sum.compareTo(t1) <= 0) {
					lo = mid;
				} else {
					hi = mid.subtract(BigInteger.ONE);
				}
			}
			System.out.println(lo);
		}
	}
}