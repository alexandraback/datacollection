import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * Created by Kevin_2 on 5/11/14.
 */
public class Round1C_A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());

		for (int i = 0; i < T; i++) {

			String[] line = sc.nextLine().split("/");

			long n = Long.parseLong(line[0]);
			long d = Long.parseLong(line[1]);


			int result = result(n, d);

			System.out.println("Case #" + (i+1) + ": " + (result == -1 ? "impossible" : result));
		}
	}

	private static int result(long n, long d) {

		// get rid of powers of 2
		while ((n & 1) == 0 && (d & 1) == 0) {
			n >>= 1;
			d >>= 1;
		}

		// n is still even, d is not even.
		// d cannot be a power of 2.
		if ((n & 1) == 0) {
			return -1;
		}
		// otherwise:
		// n is not even, d may be even.

		String binN = Long.toBinaryString(n);
		String binD = Long.toBinaryString(d);

		// d still has a not-power-of-2 factor
		// see if n is divisible by that factor
		if (!Pattern.matches("10*", binD)) {

			String blah = binD.replaceFirst("0+$", "");
			long bla = Long.parseLong(blah, 2);

			// SANITY CHECK
			if (d % bla != 0) {
				throw new IllegalStateException();
			}

			if (n % bla == 0) {
				n /= bla;
				d /= bla;

				binN = Long.toBinaryString(n);
				binD = Long.toBinaryString(d);

				// SANITY CHECK
				if (!Pattern.matches("10*", binD))
					throw new IllegalStateException();
			}
			else {
				return -1;
			}
		}

		return binD.length() - binN.length();
	}
}
