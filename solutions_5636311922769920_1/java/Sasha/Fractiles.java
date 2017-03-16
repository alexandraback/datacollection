import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class Fractiles {

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();

		for (int test = 1; test <= T; test++) {
			long k = in.nextLong();
			long c = in.nextLong();
			int s = in.nextInt();

			int checked = 0, used = 0;
			long[] res = new long[s];

			while (checked < k && used < s) {
				long p = 1;
				for (int i = 0; i < c; i++) {
					if (checked < k) {
						checked++;
						p = (p - 1) * k + checked;
					} else {
						p = (p - 1) * k + 1;
					}

				}
				res[used] = p;
				used++;
			}

			out.printf("Case #%d:", test);
			if (checked < k) {
				out.println(" IMPOSSIBLE");
			} else {
				for (int i = 0; i < used; i++) {
					out.printf(" %d", res[i]);
				}
				out.println();
			}
		}

	}
}
