import java.util.LinkedList;
import java.util.Scanner;
import java.math.BigInteger;

public class PartElf { 
	public static void main(String[] arguments) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		sc.nextLine();

		for (int i = 0; i < t; i++) {
			String[] line = sc.nextLine().split("/");

			long p = Long.parseLong(line[0]);
			long q = Long.parseLong(line[1]);

			BigInteger bigP = BigInteger.valueOf(p);
			BigInteger bigQ = BigInteger.valueOf(q);

			BigInteger bigGcd = bigP.gcd(bigQ);

			long gcd = bigGcd.longValue();

			p /= gcd;
			q /= gcd;

			// Assuming p/q is in simplest form.
			if ((q & (q - 1)) != 0) {
				System.out.printf("Case #%d: impossible\n", i + 1);
				continue;
			}

			int j;
			for (j = 0; p < q; j++) {
				q /= 2;
			}

			if (j > 40) {
				System.out.printf("Case #%d: impossible\n", i + 1);
				continue;
			}

			System.out.printf("Case #%d: %d\n", i + 1, j);
		}		
	}
}