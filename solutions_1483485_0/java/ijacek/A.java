package R0;

import java.io.*;
import java.util.*;

public class A {

	private static final char map[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q',};

	private static void solve(int TC) {
		out.print(String.format("Case #%d: ", TC));
		String line = sc.nextLine();
		for (int i = 0; i < line.length(); i++) {
			char c = line.charAt(i);
			out.print(c == ' ' ? c : map[c - 'a']);
		}
		out.println("");
	}
	private static final boolean STDIO = false;
	private static final String TASK = "A";
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

		int TC = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= TC; i++) {
			solve(i);
		}
	}
}
