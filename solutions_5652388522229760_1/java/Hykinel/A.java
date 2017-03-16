import java.util.*;
import java.io.*;
import java.math.*;

public class A {

	static boolean[] seen;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);

		int keis = sc.nextInt();
		for (int kei = 1; kei <= keis; kei++) {
			long n = sc.nextLong();
			if (n == 0) {
				System.out.printf("Case #%d: INSOMNIA\n", kei);
				continue;
			}

			long num = n;
			int cnt = 1;
			seen = new boolean[10];
			// System.out.printf("Case %d\n", kei);
 			while (true) {
 				// System.out.println("NUM: " + num);
 				// System.out.println(Arrays.toString(seen));
				int nSeen = see(num);
				if (nSeen == 10) {
					System.out.printf("Case #%d: %d\n", kei, num);
					break;
				}
				cnt++;
				num += n;
			}
		}
	}

	static int see(long n) {
		while (n > 0) {
			int dig = (int) (n % 10);
			n /= 10;
			seen[dig] = true;
		}

		int sum = 0;
		for (int i = 0; i < seen.length; i++) {
			sum += seen[i] ? 1 : 0;
		}

		return sum;
	}
}