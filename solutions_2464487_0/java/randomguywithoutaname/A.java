import java.math.BigInteger;
import java.util.Scanner;

class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int I = 0;
		while (I++ < N) {
			long r = in.nextLong(), t = in.nextLong();
			BigInteger R = BigInteger.valueOf(r), T = BigInteger.valueOf(t);
			long start = 0, end = (long) Math.pow(10, 18);
			while (end - start > 1) {
				long mid = (start + end)/2;
				BigInteger paint = BigInteger.valueOf(mid);
				paint = paint.multiply(BigInteger.valueOf(2).multiply(R.add(paint).add(BigInteger.ONE)).subtract(BigInteger.valueOf(3)));
				//System.out.println(mid + ": " + paint);
				if (paint.compareTo(T) <= 0) {
					start = mid;
				}
				else {
					end = mid;
				}
			}
			BigInteger paint = BigInteger.valueOf(end);
			paint = paint.multiply(BigInteger.valueOf(2).multiply(R.add(paint).add(BigInteger.valueOf(2))));
			if (paint.compareTo(T) > 0) {
				System.out.printf("Case #%d: %d\n", I, end - 1);
			}
			else {
				System.out.printf("Case #%d: %d\n", I, start - 1);
			}
		}

	}

}
