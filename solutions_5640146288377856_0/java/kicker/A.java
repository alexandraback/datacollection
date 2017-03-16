package codejam2012.round1a;

import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.regex.Pattern;

public class A {

	Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
	static final String FILENAME = "A-small-attempt1";
	// static final String FILENAME = "A-small-attempt0";
	static final String IN = FILENAME + ".in";
	static final String OUT = FILENAME + ".out";
	PrintStream out;

	private void solve() {
		int R = sc.nextInt();
		int C = sc.nextInt();
		int W = sc.nextInt();
		int m = C / W;
		m=m*R;
		if (C % W!=0)
			m++;
		m=m+(W-1);
		out.print(m);
	}

	private void run() throws Exception {
		sc.useLocale(Locale.US);

		out = new PrintStream(new FileOutputStream(OUT));

		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sc.nextLine();
			out.print("Case #" + i + ": ");
			solve();
			out.println();
		}
		sc.close();
		out.close();
	}

	public static void main(String args[]) throws Exception {
		new A().run();
	}

}