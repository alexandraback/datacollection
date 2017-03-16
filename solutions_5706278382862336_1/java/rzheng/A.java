import java.math.BigInteger;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			String[] string = sc.next().split("/");
			long P = Long.parseLong(string[0]), Q = Long.parseLong(string[1]);
			long gcd = BigInteger.valueOf(P).gcd(BigInteger.valueOf(Q))
					.longValue();
			P /= gcd;
			Q /= gcd;
			if ((Q & -Q) == Q) {
				long answer = (long) (Math.log(Q) / Math.log(2));
				long a = 2;
				while (a < P) {
					answer--;
					a *= 2;
				}
				if (answer <= 40) {
					System.out.printf("Case #%d: %d\n", i, answer);
				} else {
					System.out.printf("Case #%d: impossible\n", i);
				}
			} else {
				System.out.printf("Case #%d: impossible\n", i);
			}
		}
		sc.close();
	}
}