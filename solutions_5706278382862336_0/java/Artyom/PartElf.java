import java.util.Scanner;

public class PartElf {
	public int getNum(long p, long q) {
		long gcd = gcd(p, q);
		p /= gcd;
		q /= gcd;
		if ((q & (q - 1)) != 0) return -1;
		if (p >= q / 2) return 1;
		else return getNum(p, q / 2) + 1;
	}
	public static long gcd(long a, long b) {
		if (b > a) {
			long temp = a;
			a = b;
			b = temp;
		}
		if (b == 0) return a;
		return gcd(b, a % b);
	}
	public static void main(String[] args) {
		try (final Scanner in = new Scanner(System.in)) {
			final int t = Integer.parseInt(in.nextLine());
			for (int i = 1; i <= t; i++) {
				String[] tok = in.nextLine().split("/");
				long p = Long.parseLong(tok[0]);
				long q = Long.parseLong(tok[1]);
				int res = new PartElf().getNum(p, q);
				System.out.printf("Case #%s: %s%n", i, res >= 0 ? res : "impossible");
			}
		}
	}
}
