import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class PartElf {

	static {
		try {
			String input = "A-small-attempt2.in";
			String output = input.substring(0, input.lastIndexOf('.')) + ".out";
			System.setIn(new FileInputStream(input));
			 System.setOut(new PrintStream(new FileOutputStream(output),
			 true));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}
	}

	static long gcd(long m, long n) {
		for (long x; (x = m % n) != 0; m = n, n = x)
			;
		return n;
		// return m % n == 0 ? n : gcd(n, m % n);
	}

	static boolean ispow2(long v) {
		while (v > 1) {
			if (v % 2 == 1)
				return false;
			v = v >> 1;
		}
		return true;
	}

	static long lg(long v) {
		int l = 0;
		while (v > 1) {
			v = v >> 1;
			l++;
		}
		return l;
	}

	public static void main(String[] args) {
		try {
			Scanner input = new Scanner(System.in);
			for (int T = input.nextInt(), t = 1; t <= T; t++) {
				String v[] = input.next().split("/");
				long numer = Long.parseLong(v[0]);
				long denom = Long.parseLong(v[1]);

				// numer = denom - numer;
				long gcd = gcd(numer, denom);
				numer /= gcd;
				denom /= gcd;
				// System.out.println(numer + "/" + denom);
				if (ispow2(denom)) {
					int level = 1;
					while (true) {
						numer = numer << 1;
						if (numer >= denom)
							break;
						level++;
					}
					System.out.printf("Case #%d: %d\n", t, level);
				} else {
					System.out.printf("Case #%d: impossible\n", t);
				}

				// if (level > 0)
				// System.out.printf("Case #%d: %d\n", t, level);
				// else
				// System.out.printf("Case #%d: impossible\n", t);
			}
			input.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
