import java.util.*;

public class A {
	public static void main(String[] args) {
		new A();
	}

	public A() {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		input.nextLine();
		for (int n = 0; n < cases; n++) {
			String[] pair = input.nextLine().split("/");
			long p = Long.parseLong(pair[0]);
			long q = Long.parseLong(pair[1]);
			long gcd = gcd(p, q);
			p /= gcd;
			q /= gcd;
			if (Long.bitCount(q) == 1) {
				double v = ((double) q / p);
				System.out.println("Case #" + (n+1) + ": " + log2(v));
			} else {
				System.out.println("Case #" + (n+1) + ": impossible");
			}
		}
	}

	private long gcd(long u, long v) {
		if (v == 0) {
			return u;
		} else {
			return gcd(v, u % v);
		}
	}

	private int log2(double v) {
		return (int) Math.ceil(Math.log(v) / Math.log(2));
	}
}
