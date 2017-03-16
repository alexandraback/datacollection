import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class A {

	private static long nod(long a, long b) {
		while (b != 0) {
			long t = a % b;
			a = b;
			b = t;
		}
		return a;
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			String s = in.next();
			StringBuffer cp = new StringBuffer();

			int i = 0;
			while (s.charAt(i) != '/') {
				cp.append(s.charAt(i));
				i++;
			}
			long p = Long.valueOf(cp.toString());
			i++;

			StringBuffer cq = new StringBuffer();
			while (i < s.length()) {
				cq.append(s.charAt(i));
				i++;
			}
			long q = Long.valueOf(cq.toString());

			long nod = nod(p, q);

			p /= nod;
			q /= nod;
			boolean found = true;
			long q1 = q;
			while (q1 != 1) {
				if ((q1 & 1) != 0) {
					found = false;
					break;
				}
				q1 >>= 1;
			}

			long count = 1;

			if (found) {
				found = false;
				while (count <= 40) {
					if ((2 * p - q >= 0) && (2 * p - q <= q)) {
						found = true;
						break;
					}
					p <<= 1;
					count++;
				}
			}

			out.println("Case #" + test + ": " + (found ? count : "impossible"));

		}

	}
}
