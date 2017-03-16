package R0;

import java.io.*;
import java.util.*;

public class C {

	private static final int res[] = new int[8];

	private static long check(int A, int B, int m, int c) {
		long ret = 0;

		for (int i = A; i < B; i++) {
			int x = i;
			for (int k = 0; k < c; k++) {
				res[k] = x = x / 10 + m * (x % 10);
				if ( x <= i || x > B )
					continue;

				boolean found = false;
				for (int j = 0; j < k && !found; j++)
					found = (res[j] == x);
				if ( !found )
					ret++;
			}
		}
		return ret;
	}

	private static long solve() {
		int A = ni();
		int B = ni();
		if ( B < 10 )
			return 0;
		if ( A == B )
			return 0;
		int m = 10;
		for (int i = 1; i < 7; i++) {
			if ( B < m * 10 )
				return check(A, B, m, i);
			m *= 10;
		}
		return 0;
	}
	private static final boolean STDIO = false;
	private static final String TASK = "C";
	private static final String ROUND = "R0";
	private static final String DATA = "sm";
	private static Scanner sc;
	private static PrintStream out;

	public static void main(String[] args) throws FileNotFoundException, IOException {
		Locale.setDefault(Locale.ENGLISH);

		String DATA_IN = String.format("tst/%s/%s.%s.in", ROUND, TASK, DATA);
		String DATA_OUT = String.format("tst/%s/%s.%s.out", ROUND, TASK, DATA);

		String str = null;
		if ( args.length > 0 )
			str = args[0];
		else if ( !STDIO )
			str = DATA_IN;
		sc = new Scanner((str != null) ? new FileInputStream(str) : System.in);

		str = null;
		if ( args.length > 1 )
			str = args[1];
		else if ( !STDIO )
			str = DATA_OUT;

		out = (str != null) ? new PrintStream(str) : System.out;

		int TC = ni();
		for (int i = 1; i <= TC; i++) {
			long ret = solve();
			out.println(String.format("Case #%d: %d", i, ret));
		}
	}

	private static int ni() {
		return sc.nextInt();
	}
}
