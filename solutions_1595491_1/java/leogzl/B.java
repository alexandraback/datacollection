import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	// public final static String IN_FILE = "B.in";
	// public final static String OUT_FILE = "B.out";

	// public final static String IN_FILE = "B-small-attempt0.in";
	// public final static String OUT_FILE = "B-small-attempt0.out";

	public final static String IN_FILE = "B-large.in";
	public final static String OUT_FILE = "B-large.out";

	private static Scanner IN;

	public static void main(String[] args) throws Exception {
		InputStream in = new FileInputStream(IN_FILE);
		PrintWriter out = new PrintWriter(new FileWriter(OUT_FILE));
		IN = new Scanner(in);

		int T = IN.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = IN.nextInt();
			int S = IN.nextInt();
			int p = IN.nextInt();

			int[] M = new int[N];
			for (int i = 0; i < N; i++) {
				M[i] = IN.nextInt();
			}

			int minP = p >= 2 ? p * 3 - 4 : p;
			int pp = p >= 1 ? p * 3 - 2 : p;
			Arrays.sort(M);
			int r = 0;

			// System.out.println(minP + " " + pp + " " + p);

			for (int i = 0; i < N; i++) {
				if (M[i] < minP)
					continue;
				if (M[i] < pp) {
					if (S <= 0) {
						continue;
					}
					S--;
				}
				r++;
			}

			out.println("Case #" + t + ": " + r);
		}

		out.flush();
		out.close();
		in.close();

	}
}
