package R0;

import java.io.*;
import java.util.*;

public class B {

	private static void solve(int TC) {
		int N = ni();
		int S = ni();
		int p = ni();
		int g[] = new int[N];
		for (int i = 0; i < g.length; i++)
			g[i] = ni();

		int ok = 3 * p - 2;
		int pok = ok - 2;
		if ( p == 1 )
			pok = 1;
		int ret = 0;
		for (int i : g) {
			if ( i >= ok ) {
				ret++;
				continue;
			}
			if ( S > 0 && i >= pok ) {
				ret++;
				S--;
			}
		}
		out.println(String.format("Case #%d: %d", TC, ret));
	}
	private static final boolean STDIO = false;
	private static final String TASK = "B";
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
			solve(i);
		}
	}

	private static int ni() {
		return sc.nextInt();
	}
}
